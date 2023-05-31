/////////////////////////////
// Jesús Losada Arauzo 1 B //
//                         //
// potencial_docente.cpp   //
/////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Fecha.h"
#include "Departamento.h"
#include "Profesor.h"
#include "Encargos.h"
#include "Adscripcion.h"

#include "VectorDepartamento.h"
#include "VectorProfesor.h"
#include "VectorEncargo.h"
#include "VectorAdscripcion.h"

#include "utils.h"

using namespace std;


/******************************************************************************/

string Cabecera (const char * titulo);

/******************************************************************************/

int main (int argc, char ** argv)
{
	
	cout.setf(ios::fixed);		
	cout.setf(ios::showpoint);


	if(argc != 2){
		
		cerr<<"Error numero de argumentos erroneos."<<endl;
		exit(1);
	
	}

	
	string arch_encargo;
	string arch_profesores;
	string arch_departamentos;
	string arch_adscripcion;
	
	//creamos un flujo de lectura para nuestro archivo
	ifstream fi (argv[1]);
	
	if(!fi){
		
		cerr<<"Error no se pudo abrir el fihero "<<argv[1]<<endl;
		exit(2);
		
	}
	
	
	string cad;
	    
    getline(fi,cad);
                  
	if(cad != "GESTION_DOCENTE"){
	
		cerr<<"Error el fichero de entrada está mal escrito."<<endl;
		exit(3);
	
	}
	
	//vamos a saltar los comentarios
	getline(fi,cad);                  
                  
    while(!fi.eof()){
    
    	while(cad[0]=='#'){
    	
    		getline(fi,cad);
    	}
    	
    	istringstream flujo_cad_primera (cad);
     
		string palabra;
		 
		 
		//le pasamos la primera palabra para ver si está correcta si no 
		//se sale del programa
		flujo_cad_primera >> palabra;
    	
    	
        if (palabra == "[ENCARGOS]") {
			
			flujo_cad_primera >> arch_encargo;
		
	
		} else if (palabra == "[DEPARTAMENTOS]") {
			
			flujo_cad_primera >> arch_departamentos;
			
			
		
		} else if (palabra == "[ADSCRIPCIONES]")  {
			
			flujo_cad_primera >> arch_adscripcion;
			
			
		} else if (palabra == "[PROFESORES]")  {
			
			flujo_cad_primera >> arch_profesores;
			
				
			
		} else {

			cerr<<"Cabecera para uno de los archivos erronea"<<endl;
			exit(4);
			
		}         
  
      
     	getline(fi,cad);
     
    } 
			

	//aqui ya estan todos los nombres de los ficheros

	fi.close();//cerramos el fichero porque ya tenemos los datos
	
	VectorDepartamento departamentos (arch_departamentos);
		
	VectorAdscripcion adscripciones (arch_adscripcion);
		
	VectorProfesor profesores (arch_profesores); 
	
	VectorEncargo encargos (arch_encargo);
	
	string espacio_dep, espacio_prof, espacio_ads, espacio_encar;
	
	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS:");
	cout << endl; 
	
	for(int i = 0; i < departamentos.GetUsados(); i++){
		
		if(i+1 < 10){
		
			espacio_dep =  " ";
			
		}else{
			
			espacio_dep = "";
		
		}
		
		cout<<espacio_dep<<i+1<<".- "<<departamentos.ToString(i)<<endl;
		
	}
	
	cout << endl;
	
	
	cout << endl; 
	cout << Cabecera ("PROFESORES:");
	cout << endl;
	 
	for(int i = 0; i < profesores.GetUsados(); i++){
		
		if(i+1 < 10){
		
			espacio_prof =  " ";
			
		}else{
			
			espacio_prof = "";
		
		}
		
		cout<<espacio_prof<<i+1<<".- "<<profesores.ToString(i);
		
	}
	
	cout << endl;
	
	
	cout << endl; 
	cout << Cabecera ("ENCARGOS:");
	cout << endl; 
	
	for(int i = 0; i < encargos.GetUsados(); i++){
		
		if(i+1 < 10){
		
			espacio_ads =  " ";
			
		}else{
		
			espacio_ads ="";	
			
		}
		
		cout<<espacio_ads<<i+1<<".- "<<encargos.ToString(i);
		
	}
	
	cout << endl;
	
	
	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES:");
	cout << endl; 
	
	for(int i = 0; i < adscripciones.GetUsados(); i++){
			
			if(i+1 < 10){
		
				espacio_encar =  " ";
			
			}else{
				
				espacio_encar = "";
			
			}
			
			cout<<espacio_encar<<i+1<<".- "<<adscripciones.ToString(i);
			
	}
		
	cout << endl;

	
	cout << endl; 
	cout << Cabecera ("POTENCIAL DOCENTE:");
	cout << endl; 
	
	//antes vamos a contar a los profesores y sacar el potencial de cada dep
	int * cuenta = new int [departamentos.GetUsados()];
	
	double * potencia = new double [departamentos.GetUsados()];
		
	for (int i = 1; i <= departamentos.GetUsados(); i++) {
	
		int contador = 0;
		
		double suma_potencial_departamentos = 0;

		for (int k = 1; k <= adscripciones.GetUsados(); k++) {
			
			if (adscripciones[k].GetID() == departamentos[i].GetId()) {
			    
			    contador++;
			    
			    
			    for(int l = 1; l <= profesores.GetUsados(); l++){
			    	
			    	if(adscripciones[k].GetDNI() == profesores[l].GetDNI()){ 
			    		
			    		for(int g = 1 ; g <= encargos.GetUsados(); g++){
			    			
			    			if(profesores[l].GetCate()==encargos[g].GetCate())
			    			{
			    				
			    				suma_potencial_departamentos += 
			    				stod(encargos[g].GetCreditos());		
			    					
			    			
			    			}
			    		
			    		
			    		}
			    	
			    	}
			    
			    
			    
			    }
			    
			}
		}

		cuenta[i - 1] = contador;
		
		potencia[i - 1] = suma_potencial_departamentos;
		
		
	}
		
	
	
	for(int i = 1 ; i <= departamentos.GetUsados() ; i++){
	
		cout<<departamentos[i].GetId()
		    <<" ---> Num.Profesores ="<<setw(4)<<cuenta[i-1]
		    <<"   Potencial = "<<setprecision(2)<<setw(8)<<potencia[i-1]<<endl;
		    
	}
	
	
	cout << endl; 
	cout << Cabecera ("MEDIAS POTENCIAL DOCENTE POR PROFESOR:");
	cout << endl; 
	
	double * poten_medio = new double [departamentos.GetUsados()];
	
	for(int i = 1 ; i <= departamentos.GetUsados() ; i++){
	
		cout<<departamentos[i].GetId()
		    <<" ---> Potencial medio = "<<setw(8)
		    <<setprecision(2)<<potencia[i-1] / cuenta[i-1]<<endl;
		
		poten_medio [i-1] = potencia[i-1] / cuenta[i-1];
	}
	
	cout << endl; 
	cout << Cabecera ("MEDIA GLOBAL:");
	cout << endl; 
	
	double suma_global = 0.0;
	
	//calculamos la suma de todos los potenciales
	for(int i = 0 ; i < departamentos.GetUsados(); i++){
		
		suma_global += potencia[i];
	
	}
	
	
	cout<<"Potencial medio global = "<<setw(8)<<setprecision(2)
	    <<suma_global/profesores.GetUsados()<<endl;
	
	double media_global = suma_global/profesores.GetUsados();
	
	//por debajo de la media y por arriba 
	
	cout<<"Departamentos con potencial por encima de la media:"<<endl;
	
	for(int i = 0 ; i < departamentos.GetUsados(); i++){
		
		if(media_global < poten_medio[i]){
			
			cout<<departamentos.ToString(i)<<"Potencial medio = "<<setw(6)
			    <<setprecision(2)<<poten_medio[i]<<endl;
		
		}
	
	
	}
	
	cout<<endl;
	
	cout<<"Departamentos con potencial por debajo de la media:"<<endl;
	
	for(int i = 0 ; i < departamentos.GetUsados(); i++){
		
		if(media_global > poten_medio[i]){
			
			cout<<departamentos.ToString(i)<<"Potencial medio = "<<setw(6)
			    <<setprecision(2)<<poten_medio[i]<<endl;
		
		}
	
	
	}
	
	
	delete[] cuenta;
	delete[] potencia;
	delete[] poten_medio;
	
	
	return 0;

}

/******************************************************************************/

string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 70; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}

/******************************************************************************/




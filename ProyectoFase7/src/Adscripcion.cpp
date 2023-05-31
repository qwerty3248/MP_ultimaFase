
#include "Adscripcion.h"

/************************************************************/
/************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo.
	
void Adscripcion::ReservarMemoria (const Adscripcion & otro){
	
	DNI=0;
	Id_depto=0;
	
	string dni = otro.GetDNI();
	string id = otro.GetID ();
	
	DNI = new char [dni.size()+1];
	Id_depto = new char [id.size()+1];
	
	


}


/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos

void Adscripcion::CopiarDatos (const Adscripcion & otro){
	ReservarMemoria (otro);
	
	string dni = otro.GetDNI(); 
	string id = otro.GetID();
	
	for (int i = 0 ; i < dni.size(); i++){
		DNI[i] = dni[i];
		
	}
	DNI[dni.size()] = '\0';
	
	for (int i = 0 ; i < id.size(); i++){
		Id_depto[i] = id[i];
		
	}
	Id_depto[id.size()] = '\0';	
	
		
}

/************************************************************/
/************************************************************/
// Libera memoria
void Adscripcion::LiberarMemoria (void){
	if (DNI){
		delete[] DNI;
		DNI = nullptr;
	}
	if(Id_depto){	
		delete[] Id_depto;
		Id_depto = nullptr;
	}

}


//constructor de la clase
//parametros: linea, de donde se extraen los datos de la clase
//            delimitador, caracter que funciona como limite de copia
//NOTA: primero el DNI y luego el depto
	
Adscripcion::Adscripcion(string linea, char delimitador ){
	int contador = 0;
	string aux = "\0";
	while(linea[contador]!=delimitador){
		aux.push_back(linea[contador]);
		contador++;
	}
	SetDNI(aux);
	contador++;
	aux = "\0";
	while(linea[contador] != delimitador){
		aux.push_back(linea[contador]);
		contador++;
	}
	SetID(aux);
	
}

//constructor de la clase
//parametros: otro, objeto que se va a copiar
	
Adscripcion::Adscripcion(const Adscripcion & otro){
	ReservarMemoria (otro);
	CopiarDatos (otro);


}

//constructor de la clase sin argumentos
	
Adscripcion::Adscripcion(){
	DNI = nullptr;
	Id_depto = nullptr;
	SetDNI("");
	SetID("");


}

//Destructor de la clase el cual libera le memoria de DNI y Id_depto
Adscripcion::~Adscripcion(){
	LiberarMemoria ();	

}

//Operador de asignacion =
	
Adscripcion& Adscripcion::operator= (const Adscripcion & otro){
	if(this != &otro)
		LiberarMemoria ();
		ReservarMemoria (otro);
		CopiarDatos (otro);
		
	return *this;

}

//funcion que convierte a string los datos de la clase.
	
string Adscripcion::ToString(){
	
	string cad = "\0";
	if(DNI != nullptr){
		cad = GetDNI()+" "+GetID();
	
	}else{
		cad = "VACIO";
	
	}
	
	return cad;

}

//metodo que hace una copia del objeto origen al objeto que es aplicado
//Parametros: origen (referencia), objeto al que se le va a hacer la 
//            copia profunda

void Adscripcion::Clona(const Adscripcion & origen){
	if (DNI){
		delete[] DNI;
		DNI = nullptr;
	}
	if(Id_depto){	
		delete[] Id_depto;
		Id_depto = nullptr;
	}
	
	SetDNI(origen.GetDNI());
	SetID(origen.GetID());


}


	
//funcion que pone el dni del profesor
void Adscripcion::SetDNI(string dnis){
	// uno más ya que es necesario el \0
	int tamanio = dnis.size() +1; 
	DNI = new char [tamanio];
	//calculo todos los datos del string 
	for (int i = 0 ; i < dnis.size(); i++){
		DNI[i] = dnis[i];
		
	}
	DNI[tamanio-1] = '\0';
	//ahora tendriamos en nuestra cadena clasica nuestro string	
}
	
//funcion que pone el id del departamento
void Adscripcion::SetID(string ids){
	// uno más ya que es necesario el \0
	int tamanio = ids.size() +1; 
	Id_depto = new char [tamanio];
	//calculo todos los datos del string 
	for (int i = 0 ; i < ids.size(); i++){
		Id_depto[i] = ids[i];
		
	}
	Id_depto[tamanio-1] = '\0';
	//ahora tendriamos en nuestra cadena clasica nuestro string	
}
	
//funcion que da el dni del profesor
string Adscripcion::GetDNI()const{
	string dni;
	int contador = 0;
	while(DNI[contador] != '\0'){
		//la funcion push_back pone en el string un elemento
		//al final del string
		dni.push_back(DNI[contador]);
		contador++;
	}
	return dni;	
}
	
//funcion que da el id del departamento
string Adscripcion::GetID ()const{
	string ids;
	int contador = 0;
	while(Id_depto[contador] != '\0'){
		//la funcion push_back pone en el string un elemento
		//al final del string
		ids.push_back(Id_depto[contador]);
		contador++;
	}
	return ids;	
}

//operadores << y >> para la clase departamento
	
ostream & operator << (ostream & out, const Adscripcion & d){
	
	Adscripcion aux = d;
	out << aux.ToString();
	
	return (out);


} 
	
istream & operator >> (istream & in , Adscripcion & d){

	string linea;
	
	getline(in,linea);
	
	d = Adscripcion(linea, '*');

	return (in);
	
}



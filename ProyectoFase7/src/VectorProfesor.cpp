#include "VectorProfesor.h"

/******************************************************************************/	
//La funcion reserva memoria para el vector profesor
//Parametros: otro, reservara tanta memoria como vaya a necesitar otro

	void VectorProfesor::ReservarMemoria
	                                      (const VectorProfesor & otro){
		
		profesores = new Profesor [otro.GetReservados()];
	
	
	
	}

/******************************************************************************/	
//La funcion libera memoria para del vector profesor
	
	void VectorProfesor::LiberarMemoria(){
		if(profesores != nullptr){
			delete [] profesores;
			profesores = nullptr;
		}
		usadas = 0;
		reservadas = 0;
	
	
	}

/******************************************************************************/	
//La funcion copia los datos de otro
//Parametros: otro, objeto de donde se van a copiar los datos
//NOTA: se tiene que haber reservado memoria anteriormente
	
	void VectorProfesor::CopiarDatos(const VectorProfesor & otro){
		usadas = otro.GetUsados();
		reservadas = otro.GetReservados();
		
		for(int i = 1 ; i <= usadas ; i++){
			profesores[i-1] = otro[i];
		
		}
	
	}

/******************************************************************************/	
//La funcion muestra el valor de una casilla
//Parametros: casilla, que parte del vector encargo se va a mostrar
//PRE: 0<=casilla<reservadas 
//Devuelve: el encargo que se encuentre en casilla
	
	Profesor & VectorProfesor::ValorCasilla (const int casilla)const
	{
		return profesores[casilla-1];
	
	}
	
/******************************************************************************/	
//cosntructor sin parametros, lo pone todo a 0 y el vector a nullptr

	VectorProfesor::VectorProfesor(){
		usadas = 0;
		reservadas = 0;
		profesores = nullptr;	
	
	
	}

/******************************************************************************/	
//Constructor que crea un vector apartir de un fichero nombre, si no esta con 
// buen formato devolvera un vector vacio

	VectorProfesor::VectorProfesor(const string & nombre){
		
		usadas = 0;
		reservadas = 0;
		profesores = nullptr;
		
		ifstream fi (nombre);
		
		if(!fi){
			
			cerr<<"Error no se puede abrir el fichero "+nombre<<endl;
			exit(1);
		
		}
		
		fi >> *this;
		
		fi.close();
		
	}

/******************************************************************************/	
//constructor con 1 parametro, crea un vector con tantas casilla como a_reservar
//Parametro: a_reservar, casilla que se quieren reservar para el vector de 
//           profesor
//PRE: 0<=a_reservar
	
	VectorProfesor::VectorProfesor(const int a_reservar){
		usadas = 0;
		profesores = new Profesor [a_reservar];
		reservadas  = a_reservar;	
	
	}

/******************************************************************************/	
//Constructor de copia, crea un objeto con todo lo que tenga otro
//Parametros: otro, objeto del cual se va a crear nuestro nuevo objeto
	
	VectorProfesor::VectorProfesor(const VectorProfesor & otro){
		ReservarMemoria(otro);
		CopiarDatos(otro);
	
	}

/******************************************************************************/	
//Desctructor, libera la memoria al final de la ejecucion del programa
	
	VectorProfesor::~VectorProfesor(){
		LiberarMemoria();
	
	}	

/******************************************************************************/	
//La funcion recoge el valor de reservados y lo muestra
//Parametros: Ninguno
//Devuelve: reservadas

	int VectorProfesor::GetReservados()const{
		return reservadas;
	
	}

/******************************************************************************/	
//La funcion recoge el valor de usadas y lo muestra
//Parametros: Ninguno
//Devuelve: usadas
	
	int VectorProfesor::GetUsados()const{
		return usadas;
	
	}

/******************************************************************************/	
//La funcion nos dice si esta vacio o no el objeto
//Parametros: Ninguno
//Devuelve: un bool que es true si está vacio (profesor = nullptr)
	
	bool VectorProfesor::Vacio ()const{
		bool vacio = false;
		
		if(!profesores){
			vacio = true;
		}
		
		return vacio;
	
	}

/******************************************************************************/	
//La funcion aniade al final del vector el nuevo profesor, si no hay 
//espacio lo redimension para que haya espacio mediante bloques
//Parametros: nuevo, es el profesor nuevo que va a aniadir al vector
//Devuelve: nada
	
	void VectorProfesor::Aniade(Profesor nuevo){
		if (usadas == reservadas){
			VectorProfesor aux (reservadas + BLOQUE);
			for(int i = 0 ; i < usadas ; i++){
				aux[i+1] = profesores[i];
			
			}
			*this = aux;
	
		}
		
		profesores[usadas] = nuevo;
		usadas++;	
	
	
	}

/******************************************************************************/	
//La funcion aniade un profesor en una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//            nuevo, el profesor que se va a aniadir al vector
//Devuelve: nada
//PRE: 0<=pos<reservadas
	
	void VectorProfesor::Inserta(const int pos, Profesor nuevo){
		for (int i = usadas - 1; i >= pos; i--){
			profesores[i+1] = profesores[i];
		}
		profesores[pos] = nuevo;
		usadas++;
	
	}

/******************************************************************************/	
//La funcion elimina el elemento de una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//Devuelve: nada
//PRE: 0<=pos<usadas
	
	void VectorProfesor::Eliminar(const int pos){
		for (int i = pos ; i < usadas-1; i++){
			profesores[i] = profesores[i+1];
		}
		usadas--;
		
	
	}

/******************************************************************************/	
//La funcion reajusta el vector para que usadas sea igual a capacidad
//Devuelve: nada

	void VectorProfesor::Reajustar(){
		if(usadas < reservadas){
			VectorProfesor aux (usadas);
			
			for(int i = 0; i < usadas ; i++){
				aux[i] = profesores[i];
			
			}
			
			*this = aux;
			
				
		
		
		}
	
	
	}

/******************************************************************************/	
//el operador pasa los datos al dato de la izquierda
//Parametros: otro, la parte derecha del operador de asignacion
	
	VectorProfesor & VectorProfesor::operator= 
	                                      (const VectorProfesor & otro){
		if(this != &otro){
			LiberarMemoria();
			ReservarMemoria(otro);	
			CopiarDatos(otro);
		}
		return (*this);
	
	}

/******************************************************************************/	
//los operadores () y [] muestran un encargo del vector
//Parametros: casilla, donde está el encargo a mostrar
//Devuelve: el profesor de la posicion casilla
//PRE: 1<= casilla <= usadas
	
	Profesor & VectorProfesor::operator[] (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Profesor & VectorProfesor::operator[] (const int casilla)const{
		return ValorCasilla(casilla);
	
	}
	
	Profesor & VectorProfesor::operator() (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Profesor & VectorProfesor::operator() (const int casilla)const{
		return ValorCasilla(casilla);
	
	}

/******************************************************************************/	
//los operadores  de suma
//version 1 [VectorProfesor] + [VectorProfesor]
//el nuevo vector tiene todos los profesores no repetidos	
	VectorProfesor operator+ 
	(const VectorProfesor & v1,const VectorProfesor & v2)
{
	VectorProfesor todos;
	todos = v1;
	
	for(int i = 1; i <= v2.GetUsados(); i++){
		if(!(todos && v2[i])){
			todos.Aniade(v2[i]);
		}
	
	}                    
	return todos;                                      
	                                      
	                                      
}

//version 2 [VectorProfesor] + [Profesor]
	VectorProfesor operator +
	(const VectorProfesor & v1,const Profesor & d1)
{
	VectorProfesor profesor;
	profesor.Aniade(d1);
	return (v1+profesor);                                	     
	                                     
}

//version 3 [Profesor] + [VectorProfesor]
	VectorProfesor operator+
	(const Profesor & d1, const VectorProfesor & v1)
{
	                                    
	return(v1+d1);	                                    
	                                    
	                                    
}

/******************************************************************************/	
//los operadores  de resta, quita teniendo en cuenta id_depto
//version 1 [VectorProfesor] - [VectorProfesor]
	
	VectorProfesor VectorProfesor::operator- 
	(const VectorProfesor & v1)
{
	VectorProfesor quitados;
	quitados = *this;
	for(int i = 0 ;  i < v1.GetUsados(); i++){
		if(quitados && v1[i+1]){
			for(int k = 0 ; k < usadas; k++){
				if(profesores[k].GetDNI() == v1[i+1].GetDNI()){
					quitados.Eliminar(k);
				}
			
			}
			
			
		}	
	
	
	}
	return (quitados);
	
}

//version 2 [VectorProfesor] - [Profesor]

	VectorProfesor VectorProfesor::operator- 
	(const Profesor & d1)
{
	VectorProfesor un_Profesor;
	un_Profesor.Aniade(d1);
	return (*this - un_Profesor);

}

//version 3 [VectorProfesor] - [string]
	VectorProfesor VectorProfesor::operator- (const string & id)
{
	Profesor ids;
	ids.SetDNI(id);
	return (*this - ids);
}

/******************************************************************************/	
//los operadores  de multiplicacion, contiene los datos comunes por id_depto
//version 1 [VectorProfesor] * [VectorProfesor]
	
	VectorProfesor VectorProfesor::operator*
	(const VectorProfesor & v1)
{
	VectorProfesor todos;
	VectorProfesor aux;
	todos = *this;
	
	for(int i = 1; i <= v1.usadas; i++){
		if(todos && v1[i]){
			aux.Aniade(v1[i]);
		}
	
	}
	
	return(aux);	
	
}

/******************************************************************************/	
//los operadores  &&, devuelve true si está contenido ese Profesor,
//todo el vector o está el id, se compara por el id_depto
//version 1 [VectorProfesor] && [VectorProfesor]
	
	bool operator&& (const VectorProfesor & v1, 
	                 const VectorProfesor & v2 )
{
	bool iguales = true;
	for(int i = 1; i <= v1.usadas && iguales; i++){
		for(int k = 1 ; k <= v2.usadas && iguales; k++){
			if(v1[i].GetDNI() != v2[i].GetDNI()){
				iguales = false;
			}
		
		}
	
	
	}
	return iguales;               
	                        
	                        
}
//version 2 [VectorProfesor] && [Profesor]

	bool operator&& (const VectorProfesor & v1,
	    	         const Profesor & d1)
{
	bool esta = false;
	for(int i = 1;  i <= v1.GetUsados() && !esta; i++ ){
		if(v1[i].GetDNI() == d1.GetDNI()){
			esta = true;		
		
		}
	
	}
		                        
	return (esta);	                        
	                        
	                        
}

//version 3 [Profesor] && [VectorProfesor]

	bool operator&& (const Profesor & d1,
	                 const VectorProfesor & v1)
{
		                                     
	return (v1 && d1);	                                     
	                                     
}

//version 4 [VectorProfesor] && [string]

	bool operator&& (const VectorProfesor & v1,
	                 const string id)
{
	                                     
	  Profesor un_id;
	  un_id.SetDNI(id);                                  
	  return(v1 && un_id);                                   
	                                     
}

//version 5 [string] && [VectorProfesor]

	bool operator&& (const string & id,
	                 const VectorProfesor & v1)
{
	                                     
	return (v1 && id);                        
	                                    	                                     
}


/******************************************************************************/	
//los operadores  de sumaigual
//version 1 [VectorProfesor] += [VectorProfesor]	
	VectorProfesor & VectorProfesor::operator+= 
	(const VectorProfesor & v1)
{
	VectorProfesor todos;
	VectorProfesor aux = *this;
	todos = aux + v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorProfesor] += [Profesor]
	VectorProfesor & VectorProfesor::operator+= 
	(const Profesor & d1)
{
	VectorProfesor un_Profesor;
	un_Profesor.Aniade(d1);
	return (*this += un_Profesor);	
	
}
	                                    
/******************************************************************************/	
//los operadores  de restaigual
//version 1 [VectorProfesor] -= [VectorProfesor]	
	VectorProfesor & VectorProfesor::operator-= 
	(const VectorProfesor & v1)
{
	VectorProfesor todos;
	VectorProfesor aux = *this;
	todos = aux - v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorProfesor] -= [Profesor]
	VectorProfesor & VectorProfesor::operator-= 
	(const Profesor & d1)
{
	VectorProfesor un_profesor;
	un_profesor.Aniade(d1);
	return(*this -= un_profesor);	
	
}

/******************************************************************************/	
//este metodo saca un string del bloque completo que hay en el vector
//Devuelve: un string en bloque con todo el contenido del vector
	
	string VectorProfesor::ToString(){
		string aux = "";
		for(int i = 0; i < usadas ; i++){
			aux += profesores[i].ToString() + "\n";
		
		}
		return aux;
	
	
	}

/******************************************************************************/	
//La funcion saca un string del profesor del vector que este en pos
//Parametros: pos, posicion donde se va a sacar el string
//Devuelve: string del profesor que este en pos del vector
//PRE: 0<=pos<usadas
	
	string VectorProfesor::ToString(const int pos){
		string aux = "";
		
		aux += profesores[pos].ToString() + "\n";
	
		return aux;	
	}	
	
/******************************************************************************/	
//operadores << y >> en el operador << tiene que estar el archivo en el formato
//correcto, es decir primero PROFESORES, luego los comentarios tienen que 
//llevar en la primera linea # y luego escrito correctamente cada departamento	
//en caso de que esto no se cumpla devolvera un vector vacio	
	
	istream & operator >> (istream & in, VectorProfesor & v){
		
		string cad;
		
		v = VectorProfesor ();
		
		getline(in, cad);//lectura de la primera fila
		
		if(cad == "PROFESORES"){
		
			getline(in,cad);//lectura adelantada
			
			while(cad[0] == '#'){
			
				getline(in,cad);
				
			}//salimos cuando tenemos la primera linea que contiene
			//departamentos
			
			Profesor nuevo_primero (cad, '*');
			
			v.Aniade(nuevo_primero);
			
			getline(in,cad);
			
			while(!in.eof()){
			
				Profesor nuevos (cad, '*');
				
				v += nuevos;
				
				getline(in,cad);
				
			}
			
		
		}
	
		return (in);
	}
	
	ostream & operator << (ostream & out, const VectorProfesor & v){
		
		VectorProfesor aux = v;
		
		out << aux.ToString();
	
		return (out);
	}

/******************************************************************************/	
//Funcion que recupera los datos de un vector de el fichero nombre, si no esta 
//de la forma correcta se devuelve un vector vacio
	
	void VectorProfesor::RecuperarVectorProfesor (const string & nombre) {
	                                               
			 *this = VectorProfesor (nombre);
			
			
			                                       
	}
/******************************************************************************/	
//Funcion que guarda en un fichero con nombre guardando el vector si está vacio
// no se crea el fichero
	
	void VectorProfesor::GuardarVectorProfesor(const string & nombre) const{
		
		if(!Vacio()){
		
			ofstream fo (nombre);
			
			if(!fo){
			
				cerr<<"No se puede crear el fichero "+nombre
				    <<endl;
				    
				exit(1);    
			
				}
			
			fo << "PROFESORES" << endl;
			fo << "# Los elementos de nuestro vector"<<endl;
			
			for(int i = 0; i < usadas ; i++  ){
				
				string dia = "", mes = "";
				
				if(stoi(profesores[i].GetNaci().GetDia()) < 10){
				
					dia += "0" + profesores[i].GetNaci().GetDia();
				
				}else{
				
					dia += profesores[i].GetNaci().GetDia();
				
				}
				
				if(stoi(profesores[i].GetNaci().GetMes()) < 10){
				
					mes += "0" + profesores[i].GetNaci().GetMes();
				
				}else{
				
					mes += profesores[i].GetNaci().GetMes();
				
				}
				
				
				fo << profesores[i].GetDNI()+'*'+
				      profesores[i].GetApellidos()+'*'+
				      profesores[i].GetNom()+'*'+
				      dia+'/'+mes+'/'+ profesores[i].GetNaci().GetAnio()+'*'+
				      profesores[i].GetCate()+'*'<<endl;
			
			}
			
			cerr<<"Se ha guardado el vector en "+nombre<<endl;
		
			fo.close();
		
			
		}
	
	}
		
	
	
	

#include "VectorAdscripcion.h"

/******************************************************************************/	
//La funcion reserva memoria para el vector adscripcion
//Parametros: otro, reservara tanta memoria como vaya a necesitar otro

	void VectorAdscripcion::ReservarMemoria
	                                      (const VectorAdscripcion & otro){
		
		int tam = otro.GetReservados();
		adscripciones = new Adscripcion [tam];
	
	
	
	}

/******************************************************************************/	
//La funcion libera memoria para del vector adscripcion
	
	void VectorAdscripcion::LiberarMemoria(){
		if(adscripciones != nullptr){
			delete [] adscripciones;
			adscripciones = nullptr;
		}
		usadas = 0;
		reservadas = 0;
	
	
	}

/******************************************************************************/	
//La funcion copia los datos de otro
//Parametros: otro, objeto de donde se van a copiar los datos
//NOTA: se tiene que haber reservado memoria anteriormente
	
	void VectorAdscripcion::CopiarDatos(const VectorAdscripcion & otro){
		reservadas = otro.GetReservados();
		
		for(int i = 1 ; i <= otro.GetUsados() ; i++){
			adscripciones[i-1] = otro[i];
		
		}
		usadas = otro.GetUsados();
	
	}

/******************************************************************************/	
//La funcion muestra el valor de una casilla
//Parametros: casilla, que parte del vector adscripcion se va a mostrar
//PRE: 0<=casilla<reservadas 
//Devuelve: la adscripcion que se encuentre en casilla 
	
	Adscripcion & VectorAdscripcion::ValorCasilla (const int casilla)const
	{
		return adscripciones[casilla-1];
	
	}
	
/******************************************************************************/	
//cosntructor sin parametros, lo pone todo a 0 y el vector a nullptr

	VectorAdscripcion::VectorAdscripcion(){
		usadas = 0;
		reservadas = 0;
		adscripciones = nullptr;	
	
	
	}

/******************************************************************************/	
//Constructor que crea un vector apartir de un fichero nombre, si no esta con 
// buen formato devolvera un vector vacio

	VectorAdscripcion::VectorAdscripcion(const string & nombre){
		
		usadas = 0;
		reservadas = 0;
		adscripciones = nullptr;
		
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
//           adscripciones
//PRE: 0<=a_reservar
	
	VectorAdscripcion::VectorAdscripcion(const int a_reservar){
		usadas = 0;
		adscripciones = new Adscripcion [a_reservar];
		reservadas  = a_reservar;	
	
	}

/******************************************************************************/	
//Constructor de copia, crea un objeto con todo lo que tenga otro
//Parametros: otro, objeto del cual se va a crear nuestro nuevo objeto
	
	VectorAdscripcion::VectorAdscripcion(const VectorAdscripcion & otro){
		ReservarMemoria(otro);
		CopiarDatos(otro);
	
	}

/******************************************************************************/	
//Desctructor, libera la memoria al final de la ejecucion del programa
	
	VectorAdscripcion::~VectorAdscripcion(){
		LiberarMemoria();
	
	}	

/******************************************************************************/	
//La funcion recoge el valor de reservados y lo muestra
//Parametros: Ninguno
//Devuelve: reservadas

	int VectorAdscripcion::GetReservados()const{
		return reservadas;
	
	}

/******************************************************************************/	
//La funcion recoge el valor de usadas y lo muestra
//Parametros: Ninguno
//Devuelve: usadas
	
	int VectorAdscripcion::GetUsados()const{
		return usadas;
	
	}

/******************************************************************************/	
//La funcion nos dice si esta vacio o no el objeto
//Parametros: Ninguno
//Devuelve: un bool que es true si está vacio (Adscripcion = nullptr)
		
	bool VectorAdscripcion::Vacio ()const{
		bool vacio = false;
		
		if(!adscripciones){
			vacio = true;
		}
		
		return vacio;
	
	}

/******************************************************************************/	
//La funcion aniade al final del vector la nueva adscripcion, si no hay 
//espacio lo redimension para que haya espacio mediante bloques
//Parametros: nuevo, es la adscripcion nueva que va a aniadir al vector
//Devuelve: nada
	
	void VectorAdscripcion::Aniade(Adscripcion nuevo){
		if (usadas == reservadas){
			VectorAdscripcion aux (reservadas + BLOQUE);
			for(int i = 0 ; i < usadas ; i++){
				aux[i] = adscripciones[i];
			
			}
			*this = aux;
	
		}
		
		adscripciones[usadas] = nuevo;
		usadas++;	
	
	
	}

/******************************************************************************/	
//La funcion aniade una adscripcion en una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//            nuevo, la adscripcion que se va a aniadir al vector
//Devuelve: nada
//PRE: 0<=pos<reservadas
	
	void VectorAdscripcion::Inserta(const int pos, Adscripcion nuevo){
		for (int i = usadas - 1; i >= pos; i--){
			adscripciones[i+1] = adscripciones[i];
		}
		adscripciones[pos] = nuevo;
		usadas++;
	
	}

/******************************************************************************/	
//La funcion elimina el elemento de una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//Devuelve: nada
//PRE: 0<=pos<usadas
	
	void VectorAdscripcion::Eliminar(const int pos){
		for (int i = pos ; i < usadas-1; i++){
			adscripciones[i] = adscripciones[i+1];
		}
		usadas--;
		
	
	}

/******************************************************************************/	
//La funcion reajusta el vector para que usadas sea igual a capacidad
//Devuelve: nada


	void VectorAdscripcion::Reajustar(){
		if(usadas < reservadas){
			VectorAdscripcion aux (usadas);
			
			for(int i = 0; i < usadas ; i++){
				aux[i] = adscripciones[i];
			
			}
			
			*this = aux;
			
				
		
		
		}
	
	
	}

/******************************************************************************/	
//el operador pasa los datos al dato de la izquierda
//Parametros: otro, la parte derecha del operador de asignacion
		
	VectorAdscripcion & VectorAdscripcion::operator= 
	                                      (const VectorAdscripcion & otro){
		if(this != &otro){
			LiberarMemoria();
			ReservarMemoria(otro);	
			CopiarDatos(otro);
		}
		return (*this);
	
	}

/******************************************************************************/	
//los operadores () y [] muestran una adscripcion del vector
//Parametros: casilla, donde está la adscripcion a mostrar
//Devuelve: la adscripcion de la posicion casilla
//PRE: 1<= casilla <= usadas
	
	Adscripcion & VectorAdscripcion::operator[] (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Adscripcion & VectorAdscripcion::operator[] (const int casilla)const{
		return ValorCasilla(casilla);
	
	}
	
	Adscripcion & VectorAdscripcion::operator() (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Adscripcion & VectorAdscripcion::operator() (const int casilla)const{
		return ValorCasilla(casilla);
	
	}


/******************************************************************************/	
//los operadores  de suma
//version 1 [VectorAdscripcion] + [VectorAdscripcion]
//el nuevo vector tiene todos los adscriciones no repetidos	
	VectorAdscripcion operator+ 
	(const VectorAdscripcion & v1,const VectorAdscripcion & v2)
{
	VectorAdscripcion todos;
	todos = v1;
	
	for(int i = 1; i <= v2.GetUsados(); i++){
		if(!(todos && v2[i])){
			todos.Aniade(v2[i]);
		}
	
	}                    
	return todos;                                      
	                                      
	                                      
}

//version 2 [VectorAdscripcion] + [Adscripcion]
	VectorAdscripcion operator +
	(const VectorAdscripcion & v1,const Adscripcion & d1)
{
	VectorAdscripcion adscrip;
	adscrip.Aniade(d1);
	return (v1+adscrip);                                	     
	                                     
}

//version 3 [Adscripcion] + [VectorAdscripcion]
	VectorAdscripcion operator+
	(const Adscripcion & d1, const VectorAdscripcion & v1)
{
	                                    
	return(v1+d1);	                                    
	                                    
	                                    
}

/******************************************************************************/	
//los operadores  de resta, quita teniendo en cuenta id_depto
//version 1 [VectorAdscripcion] - [VectorAdscripcion]
	
	VectorAdscripcion VectorAdscripcion::operator- 
	(const VectorAdscripcion & v1)
{
	VectorAdscripcion quitados;
	quitados = *this;
	for(int i = 0 ;  i < v1.GetUsados(); i++){
		if(quitados && v1[i+1]){
			for(int k = 0 ; k < usadas; k++){
				if(adscripciones[k].GetDNI() == v1[i+1].GetDNI()){
					quitados.Eliminar(k);
				}
			
			}
			
			
		}	
	
	
	}
	return (quitados);
	
}

//version 2 [VectorAdscripcion] - [Adscripcion]

	VectorAdscripcion VectorAdscripcion::operator- 
	(const Adscripcion & d1)
{
	VectorAdscripcion un_adscrip;
	un_adscrip.Aniade(d1);
	return (*this - un_adscrip);

}

//version 3 [VectorAdscripcion] - [string]
	VectorAdscripcion VectorAdscripcion::operator- (const string & id)
{
	Adscripcion ids;
	ids.SetDNI(id);
	return (*this - ids);
}

/******************************************************************************/	
//los operadores  de multiplicacion, contiene los datos comunes por id_depto
//version 1 [VectorAdscripcion] * [VectorAdscripcion]
	
	VectorAdscripcion VectorAdscripcion::operator*
	(const VectorAdscripcion & v1)
{
	VectorAdscripcion todos;
	VectorAdscripcion aux;
	todos = *this;
	
	for(int i = 1; i <= v1.usadas; i++){
		if(todos && v1[i]){
			aux.Aniade(v1[i]);
		}
	
	}
	
	return(aux);	
	
}

/******************************************************************************/	
//los operadores  &&, devuelve true si está contenido ese adscripcion,
//todo el vector o está el id, se compara por el id_depto
//version 1 [VectorAdscripcion] && [VectorAdscripcion]
	
	bool operator&& (const VectorAdscripcion & v1, 
	                 const VectorAdscripcion & v2 )
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
//version 2 [VectorAdscripcion] && [Adscripcion]

	bool operator&& (const VectorAdscripcion & v1,
	    	         const Adscripcion & d1)
{
	bool esta = false;
	for(int i = 1;  i <= v1.GetUsados() && !esta; i++ ){
		if(v1[i].GetDNI() == d1.GetDNI()){
			esta = true;		
		
		}
	
	}
		                        
	return (esta);	                        
	                        
	                        
}

//version 3 [Adscripcion] && [VectorAdscripcion]

	bool operator&& (const Adscripcion & d1,
	                 const VectorAdscripcion & v1)
{
		                                     
	return (v1 && d1);	                                     
	                                     
}

//version 4 [VectorAdscripcion] && [string]

	bool operator&& (const VectorAdscripcion & v1,
	                 const string id)
{
	                                     
	  Adscripcion un_id;
	  un_id.SetDNI(id);                                  
	  return(v1 && un_id);                                   
	                                     
}

//version 5 [string] && [VectorAdscripcion]

	bool operator&& (const string & id,
	                 const VectorAdscripcion & v1)
{
	                                     
	return (v1 && id);                        
	                                    	                                     
}


/******************************************************************************/	
//los operadores  de sumaigual
//version 1 [VectorAdscripcion] += [VectorAdscripcion]	
	VectorAdscripcion & VectorAdscripcion::operator+= 
	(const VectorAdscripcion & v1)
{
	VectorAdscripcion todos;
	VectorAdscripcion aux = *this;
	todos = aux + v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorAdscripcion] += [Adscripcion]
	VectorAdscripcion & VectorAdscripcion::operator+= 
	(const Adscripcion & d1)
{
	VectorAdscripcion un_adscrip;
	un_adscrip.Aniade(d1);
	return (*this += un_adscrip);	
	
}
	                                    
/******************************************************************************/	
//los operadores  de restaigual
//version 1 [VectorAdscripcion] -= [VectorAdscripcion]	
	VectorAdscripcion & VectorAdscripcion::operator-= 
	(const VectorAdscripcion & v1)
{
	VectorAdscripcion todos;
	VectorAdscripcion aux = *this;
	todos = aux - v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorAdscripcion] -= [Adscripcion]
	VectorAdscripcion & VectorAdscripcion::operator-= 
	(const Adscripcion & d1)
{
	VectorAdscripcion un_adscrip;
	un_adscrip.Aniade(d1);
	return(*this -= un_adscrip);	
	
}

/******************************************************************************/	
//este metodo saca un string del bloque completo que hay en el vector
//Devuelve: un string en bloque con todo el contenido del vector
	
	string VectorAdscripcion::ToString(){
		string aux = "";
		for(int i = 0; i < usadas ; i++){
			aux += adscripciones[i].ToString() + "\n";
		
		}
		return aux;
	
	
	}

/******************************************************************************/	
//La funcion saca un string de la adscripcion del vector que este en pos
//Parametros: pos, posicion donde se va a sacar el string
//Devuelve: string de la adscripcion que este en pos del vector
//PRE: 0<=pos<usadas
	
	string VectorAdscripcion::ToString(const int pos){
		string aux = "";
		
		aux += adscripciones[pos].ToString() + "\n";
	
	
	
		return aux;
	
	}
	
/******************************************************************************/	
//operadores << y >> en el operador << tiene que estar el archivo en el formato
//correcto, es decir primero DEPARTAMENTOS, luego los comentarios tienen que 
//llevar en la primera linea # y luego escrito correctamente cada departamento	
//en caso de que esto no se cumpla devolvera un vector vacio	
	
	istream & operator >> (istream & in, VectorAdscripcion & v){
		
		string cad;
		
		v = VectorAdscripcion ();
		
		getline(in, cad);//lectura de la primera fila
		
		if(cad == "ADSCRIPCIONES"){
		
			getline(in,cad);//lectura adelantada
			
			while(cad[0] == '#'){
			
				getline(in,cad);
				
			}//salimos cuando tenemos la primera linea que contiene
			//departamentos
			
			Adscripcion nuevo_primero (cad, '*');
			
			v.Aniade(nuevo_primero);
			
			getline(in,cad);
			
			while(!in.eof()){
			
				Adscripcion nuevos (cad, '*');
				
				v += nuevos;
				
				getline(in,cad);
				
			}
			
		
		}
	
		return (in);
	}
	
	ostream & operator << (ostream & out, const VectorAdscripcion & v){
		
		VectorAdscripcion aux = v;
		
		out << aux.ToString();
	
		return (out);
	}

/******************************************************************************/	
//Funcion que recupera los datos de un vector de el fichero nombre, si no esta 
//de la forma correcta se devuelve un vector vacio
	
	void VectorAdscripcion::RecuperarVectorAdscripcion
	                                               (const string & nombre) {
	                                               
			 *this = VectorAdscripcion (nombre);
			
			
			                                       
	}
/******************************************************************************/	
//Funcion que guarda en un fichero con nombre guardando el vector si está vacio
// no se crea el fichero
	
	void VectorAdscripcion::GuardarVectorAdscripcion 
	                                          (const string & nombre) const{
		
		if(!Vacio()){
		
			ofstream fo (nombre);
			
			if(!fo){
			
				cerr<<"No se puede crear el fichero "+nombre
				    <<endl;
				    
				exit(1);    
			
				}
			
			fo << "ADSCRIPCIONES" << endl;
			fo << "# Los elementos de nuestro vector"<<endl;
			
			for(int i = 0; i < usadas ; i++  ){
				
				fo << adscripciones[i].GetDNI()+'*'+
				      adscripciones[i].GetID()+'*'<<endl;
			
			}
			
			cerr<<"Se ha guardado el vector en "+nombre<<endl;
		
			fo.close();
		
			
		}
	
	}
		

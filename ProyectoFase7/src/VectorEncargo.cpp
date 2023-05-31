#include "VectorEncargo.h"

/******************************************************************************/	
//La funcion reserva memoria para el vector encargo
//Parametros: otro, reservara tanta memoria como vaya a necesitar otro

	void VectorEncargo::ReservarMemoria
	                                      (const VectorEncargo & otro){
		
		encargos = new Encargo [otro.GetReservados()];
	
	
	
	}

/******************************************************************************/	
//La funcion libera memoria para del vector encargo
	
	void VectorEncargo::LiberarMemoria(){
		if(encargos != nullptr){
			delete [] encargos;
			encargos = nullptr;
		}
		usadas = 0;
		reservadas = 0;
	
	
	}

/******************************************************************************/	
//Constructor que crea un vector apartir de un fichero nombre, si no esta con 
// buen formato devolvera un vector vacio

	VectorEncargo::VectorEncargo(const string & nombre){
		
		usadas = 0;
		reservadas = 0;
		encargos = nullptr;
		
		ifstream fi (nombre);
		
		if(!fi){
			
			cerr<<"Error no se puede abrir el fichero "+nombre<<endl;
			exit(1);
		
		}
		
		fi >> *this;
		
		fi.close();
		
	}
		

/******************************************************************************/	
//La funcion copia los datos de otro
//Parametros: otro, objeto de donde se van a copiar los datos
//NOTA: se tiene que haber reservado memoria anteriormente
	
	void VectorEncargo::CopiarDatos(const VectorEncargo & otro){
		usadas = otro.GetUsados();
		reservadas = otro.GetReservados();
		
		for(int i = 1 ; i <= usadas ; i++){
			encargos[i-1] = otro[i];
		
		}
	
	}

/******************************************************************************/	
//La funcion muestra el valor de una casilla
//Parametros: casilla, que parte del vector encargo se va a mostrar
//PRE: 0<=casilla<reservadas 
//Devuelve: el encargo que se encuentre en casilla
	
	Encargo & VectorEncargo::ValorCasilla (const int casilla)const
	{
		return encargos[casilla-1];
	
	}
	
/******************************************************************************/	
//cosntructor sin parametros, lo pone todo a 0 y el vector a nullptr

	VectorEncargo::VectorEncargo(){
		usadas = 0;
		reservadas = 0;
		encargos = nullptr;	
	
	
	}

/******************************************************************************/	
//constructor con 1 parametro, crea un vector con tantas casilla como a_reservar
//Parametro: a_reservar, casilla que se quieren reservar para el vector de 
//           encargo
//PRE: 0<=a_reservar
	
	VectorEncargo::VectorEncargo(const int a_reservar){
		usadas = 0;
		encargos = new Encargo [a_reservar];
		reservadas  = a_reservar;	
	
	}

/******************************************************************************/	
//constructor con 1 parametro, crea un vector con tantas casilla como a_reservar
//Parametro: a_reservar, casilla que se quieren reservar para el vector de 
//           encargo
//PRE: 0<=a_reservar
	
	VectorEncargo::VectorEncargo(const VectorEncargo & otro){
		ReservarMemoria(otro);
		CopiarDatos(otro);
	
	}
	
/******************************************************************************/	
//Desctructor, libera la memoria al final de la ejecucion del programa
		
	
	VectorEncargo::~VectorEncargo(){
		LiberarMemoria();
	
	}	

/******************************************************************************/	
//La funcion recoge el valor de reservados y lo muestra
//Parametros: Ninguno
//Devuelve: reservadas

	int VectorEncargo::GetReservados()const{
		return reservadas;
	
	}

/******************************************************************************/	
//La funcion recoge el valor de usadas y lo muestra
//Parametros: Ninguno
//Devuelve: usadas
	
	int VectorEncargo::GetUsados()const{
		return usadas;
	
	}

/******************************************************************************/	
//La funcion nos dice si esta vacio o no el objeto
//Parametros: Ninguno
//Devuelve: un bool que es true si está vacio (encargo = nullptr)
	
	bool VectorEncargo::Vacio ()const{
		bool vacio = false;
		
		if(!encargos){
			vacio = true;
		}
		
		return vacio;
	
	}

/******************************************************************************/	
//La funcion aniade al final del vector el nuevo encargo, si no hay 
//espacio lo redimension para que haya espacio mediante bloques
//Parametros: nuevo, es el encargo nuevo que va a aniadir al vector
//Devuelve: nada
	
	void VectorEncargo::Aniade(Encargo nuevo){
		if (usadas == reservadas){
			VectorEncargo aux (reservadas + BLOQUE);
			for(int i = 0 ; i < usadas ; i++){
				aux[i+1] = encargos[i];
			
			}
			*this = aux;
	
		}
		
		encargos[usadas] = nuevo;
		usadas++;	
	
	
	}

/******************************************************************************/	
//La funcion aniade un encargo en una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//            nuevo, el encargo que se va a aniadir al vector
//Devuelve: nada
//PRE: 0<=pos<reservadas
	
	void VectorEncargo::Inserta(const int pos, Encargo nuevo){
		for (int i = usadas - 1; i >= pos; i--){
			encargos[i+1] = encargos[i];
		}
		encargos[pos] = nuevo;
		usadas++;
	
	}

/******************************************************************************/	
//La funcion elimina el elemento de una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//Devuelve: nada
//PRE: 0<=pos<usadas
	
	void VectorEncargo::Eliminar(const int pos){
		for (int i = pos ; i < usadas-1; i++){
			encargos[i] = encargos[i+1];
		}
		usadas--;
		
	
	}

/******************************************************************************/	
//La funcion reajusta el vector para que usadas sea igual a capacidad
//Devuelve: nada

	void VectorEncargo::Reajustar(){
		if(usadas < reservadas){
			VectorEncargo aux (usadas);
			
			for(int i = 0; i < usadas ; i++){
				aux[i] = encargos[i];
			
			}
			
			*this = aux;
			
				
		
		
		}
	
	
	}

/******************************************************************************/	
//el operador pasa los datos al dato de la izquierda
//Parametros: otro, la parte derecha del operador de asignacion
	
	VectorEncargo & VectorEncargo::operator= 
	                                      (const VectorEncargo & otro){
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
//Devuelve: el encargo de la posicion casilla
//PRE: 1<= casilla <= usadas
	
	Encargo & VectorEncargo::operator[] (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Encargo & VectorEncargo::operator[] (const int casilla)const{
		return ValorCasilla(casilla);
	
	}
	
	Encargo & VectorEncargo::operator() (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Encargo & VectorEncargo::operator() (const int casilla)const{
		return ValorCasilla(casilla);
	
	}

/******************************************************************************/	
//los operadores  de suma
//version 1 [VectorEncargo] + [VectorEncargo]
//el nuevo vector tiene todos los profesores no repetidos	
	VectorEncargo operator+ 
	(const VectorEncargo & v1,const VectorEncargo & v2)
{
	VectorEncargo todos;
	todos = v1;
	
	for(int i = 1; i <= v2.GetUsados(); i++){
		if(!(todos && v2[i])){
			todos.Aniade(v2[i]);
		}
	
	}                    
	return todos;                                      
	                                      
	                                      
}

//version 2 [VectorEncargo] + [Profesor]
	VectorEncargo operator +
	(const VectorEncargo & v1,const Encargo & d1)
{
	VectorEncargo encargo;
	encargo.Aniade(d1);
	return (v1+encargo);                                	     
	                                     
}

//version 3 [Profesor] + [VectorEncargo]
	VectorEncargo operator+
	(const Encargo & d1, const VectorEncargo & v1)
{
	                                    
	return(v1+d1);	                                    
	                                    
	                                    
}

/******************************************************************************/	
//los operadores  de resta, quita teniendo en cuenta id_depto
//version 1 [VectorEncargo] - [VectorEncargo]
	
	VectorEncargo VectorEncargo::operator- 
	(const VectorEncargo & v1)
{
	VectorEncargo quitados;
	quitados = *this;
	for(int i = 0 ;  i < v1.GetUsados(); i++){
		if(quitados && v1[i+1]){
			for(int k = 0 ; k < usadas; k++){
				if(encargos[k].GetCate() == v1[i+1].GetCate()){
					quitados.Eliminar(k);
				}
			
			}
			
			
		}	
	
	
	}
	return (quitados);
	
}

//version 2 [VectorEncargo] - [Encargo]

	VectorEncargo VectorEncargo::operator- 
	(const Encargo & d1)
{
	VectorEncargo un_Encargo;
	un_Encargo.Aniade(d1);
	return (*this - un_Encargo);

}

//version 3 [VectorEncargo] - [string]
	VectorEncargo VectorEncargo::operator- (const string & id)
{
	Encargo ids;
	ids.SetCate(stoi(id));
	return (*this - ids);
}

/******************************************************************************/	
//los operadores  de multiplicacion, contiene los datos comunes por id_depto
//version 1 [VectorEncargo] * [VectorEncargo]
	
	VectorEncargo VectorEncargo::operator*
	(const VectorEncargo & v1)
{
	VectorEncargo todos;
	VectorEncargo aux;
	todos = *this;
	
	for(int i = 1; i <= v1.usadas; i++){
		if(todos && v1[i]){
			aux.Aniade(v1[i]);
		}
	
	}
	
	return(aux);	
	
}

/******************************************************************************/	
//los operadores  &&, devuelve true si está contenido ese Encargo,
//todo el vector o está el id, se compara por el encargo
//version 1 [VectorEncargo] && [VectorEncargo]
	
	bool operator&& (const VectorEncargo & v1, 
	                 const VectorEncargo & v2 )
{
	bool iguales = true;
	for(int i = 1; i <= v1.usadas && iguales; i++){
		for(int k = 1 ; k <= v2.usadas && iguales; k++){
			if(v1[i].GetCate() != v2[i].GetCate()){
				iguales = false;
			}
		
		}
	
	
	}
	return iguales;               
	                        
	                        
}
//version 2 [VectorEncargo] && [Encargo]

	bool operator&& (const VectorEncargo & v1,
	    	         const Encargo & d1)
{
	bool esta = false;
	for(int i = 1;  i <= v1.GetUsados() && !esta; i++ ){
		if(v1[i].GetCate() == d1.GetCate()){
			esta = true;		
		
		}
	
	}
		                        
	return (esta);	                        
	                        
	                        
}

//version 3 [Encargo] && [VectorEncargo]

	bool operator&& (const Encargo & d1,
	                 const VectorEncargo & v1)
{
		                                     
	return (v1 && d1);	                                     
	                                     
}

//version 4 [VectorEncargo] && [string]

	bool operator&& (const VectorEncargo & v1,
	                 const string id)
{
	                                     
	  Encargo un_id;
	  un_id.SetCate(stoi(id));                                  
	  return(v1 && un_id);                                   
	                                     
}

//version 5 [string] && [VectorEncargo]

	bool operator&& (const string & id,
	                 const VectorEncargo & v1)
{
	                                     
	return (v1 && id);                        
	                                    	                                     
}


/******************************************************************************/	
//los operadores  de sumaigual
//version 1 [VectorEncargo] += [VectorEncargo]	
	VectorEncargo & VectorEncargo::operator+= 
	(const VectorEncargo & v1)
{
	VectorEncargo todos;
	VectorEncargo aux = *this;
	todos = aux + v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorEncargo] += [Encargo]
	VectorEncargo & VectorEncargo::operator+= 
	(const Encargo & d1)
{
	VectorEncargo un_Encargo;
	un_Encargo.Aniade(d1);
	return (*this += un_Encargo);	
	
}
	                                    
/******************************************************************************/	
//los operadores  de restaigual
//version 1 [VectorEncargo] -= [VectorEncargo]	
	VectorEncargo & VectorEncargo::operator-= 
	(const VectorEncargo & v1)
{
	VectorEncargo todos;
	VectorEncargo aux = *this;
	todos = aux - v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorEncargo] -= [Encargo]
	VectorEncargo & VectorEncargo::operator-= 
	(const Encargo & d1)
{
	VectorEncargo un_encargo;
	un_encargo.Aniade(d1);
	return(*this -= un_encargo);	
	
}
	
/******************************************************************************/	
//este metodo saca un string del bloque completo que hay en el vector
//Devuelve: un string en bloque con todo el contenido del vector	
	
	string VectorEncargo::ToString(){
		string aux = "";
		for(int i = 0; i < usadas ; i++){
			aux += encargos[i].ToString() + "\n";
		
		}
		return aux;
	
	
	}

/******************************************************************************/	
//La funcion saca un string del encargo del vector que este en pos
//Parametros: pos, posicion donde se va a sacar el string
//Devuelve: string del encargo que este en pos del vector
//PRE: 0<=pos<usadas
	
	string VectorEncargo::ToString(const int pos){
		string aux = "";
		
		aux += encargos[pos].ToString() + "\n";
	
	
	
		return aux;
	
	}
	
/******************************************************************************/	
//operadores << y >> en el operador << tiene que estar el archivo en el formato
//correcto, es decir primero ENCARGOS, luego los comentarios tienen que 
//llevar en la primera linea # y luego escrito correctamente cada departamento	
//en caso de que esto no se cumpla devolvera un vector vacio	
	
	istream & operator >> (istream & in, VectorEncargo & v){
		
		string cad;
		
		v = VectorEncargo ();
		
		getline(in, cad);//lectura de la primera fila
		
		if(cad == "ENCARGOS"){
		
			getline(in,cad);//lectura adelantada
			
			while(cad[0] == '#'){
			
				getline(in,cad);
				
			}//salimos cuando tenemos la primera linea que contiene
			//departamentos
			
			Encargo nuevo_primero (cad, '*');
			
			v.Aniade(nuevo_primero);
			
			getline(in,cad);
			
			while(!in.eof()){
			
				Encargo nuevos (cad, '*');
				
				v += nuevos;
				
				getline(in,cad);
				
			}
			
		
		}
	
		return (in);
	}
	
	ostream & operator << (ostream & out, const VectorEncargo & v){
		
		VectorEncargo aux = v;
		
		out << aux.ToString();
	
		return (out);
	}

/******************************************************************************/	
//Funcion que recupera los datos de un vector de el fichero nombre, si no esta 
//de la forma correcta se devuelve un vector vacio
	
	void VectorEncargo::RecuperarVectorEncargo
	                                               (const string & nombre) {
	                                               
			 *this = VectorEncargo (nombre);
			
			
			                                       
	}
/******************************************************************************/	
//Funcion que guarda en un fichero con nombre guardando el vector si está vacio
// no se crea el fichero
	
	void VectorEncargo::GuardarVectorEncargo 
	                                          (const string & nombre) const{
		
		if(!Vacio()){
		
			ofstream fo (nombre);
			
			if(!fo){
			
				cerr<<"No se puede crear el fichero "+nombre
				    <<endl;
				    
				exit(1);    
			
				}
			
			fo << "ENCARGOS" << endl;
			fo << "# Los elementos de nuestro vector"<<endl;
			
			for(int i = 0; i < usadas ; i++  ){
				
				fo << encargos[i].GetCate()+'*'+
				      encargos[i].GetCreditos()+'*'<<endl;
			
			}
			
			cerr<<"Se ha guardado el vector en "+nombre<<endl;
		
			fo.close();
		
			
		}
	
	}
		

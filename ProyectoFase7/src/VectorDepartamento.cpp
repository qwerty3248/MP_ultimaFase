#include "VectorDepartamento.h"

/******************************************************************************/	
//La funcion reserva memoria para el vector departamentos
//Parametros: otro, reservara tanta memoria como vaya a necesitar otro

	void VectorDepartamento::ReservarMemoria
	                                      (const VectorDepartamento & otro){
		
		departamentos = new Departamento [otro.GetReservados()];
	
	
	
	}

/******************************************************************************/	
//La funcion libera memoria para del vector departamentos
	
	void VectorDepartamento::LiberarMemoria(){
		if(departamentos != nullptr){
			delete [] departamentos;
			departamentos = nullptr;
		}
		usadas = 0;
		reservadas = 0;
	
	
	}

/******************************************************************************/	
//La funcion copia los datos de otro
//Parametros: otro, objeto de donde se van a copiar los datos
//NOTA: se tiene que haber reservado memoria anteriormente

	
	void VectorDepartamento::CopiarDatos(const VectorDepartamento & otro){
		usadas = otro.GetUsados();
		reservadas = otro.GetReservados();
		
		for(int i = 1 ; i <= usadas ; i++){
			departamentos[i-1] = otro[i];
		
		}
	
	}

/******************************************************************************/	
//La funcion muestra el valor de una casilla
//Parametros: casilla, que parte del vector departamentos se va a mostrar
//PRE: 0<=casilla<reservadas 
//Devuelve: el departamento que se encuentre en casilla 
	
	Departamento & VectorDepartamento::ValorCasilla (const int casilla)const
	{
		return departamentos[casilla-1];
	
	}
	
/******************************************************************************/	
//cosntructor sin parametros, lo pone todo a 0 y el vector a nullptr

	VectorDepartamento::VectorDepartamento(){
		usadas = 0;
		reservadas = 0;
		departamentos = nullptr;	
	
	
	}

/******************************************************************************/	
//Constructor que crea un vector apartir de un fichero nombre, si no esta con 
// buen formato devolvera un vector vacio

	VectorDepartamento::VectorDepartamento(const string & nombre){
		
		usadas = 0;
		reservadas = 0;
		departamentos = nullptr;
		
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
//           departamentos
//PRE: 0<=a_reservar
	
	VectorDepartamento::VectorDepartamento(const int a_reservar){
		usadas = 0;
		departamentos = new Departamento [a_reservar];
		reservadas  = a_reservar;	
	
	}
	
/******************************************************************************/	
//Constructor de copia, crea un objeto con todo lo que tenga otro
//Parametros: otro, objeto del cual se va a crear nuestro nuevo objeto
	
	VectorDepartamento::VectorDepartamento(const VectorDepartamento & otro){
		ReservarMemoria(otro);
		CopiarDatos(otro);
	
	}
	
/******************************************************************************/	
//Desctructor, libera la memoria al final de la ejecucion del programa

	
	VectorDepartamento::~VectorDepartamento(){
		LiberarMemoria();
	
	}	

/******************************************************************************/	
//La funcion recoge el valor de reservados y lo muestra
//Parametros: Ninguno
//Devuelve: reservadas

	int VectorDepartamento::GetReservados()const{
		return reservadas;
	
	}
	
/******************************************************************************/	
//La funcion recoge el valor de usadas y lo muestra
//Parametros: Ninguno
//Devuelve: usadas
	
	int VectorDepartamento::GetUsados()const{
		return usadas;
	
	}

/******************************************************************************/	
//La funcion nos dice si esta vacio o no el objeto
//Parametros: Ninguno
//Devuelve: un bool que es true si está vacio (departamentos = nullptr)
	
	bool VectorDepartamento::Vacio ()const{
		bool vacio = false;
		
		if(!departamentos){
			vacio = true;
		}
		
		return vacio;
	
	}

/******************************************************************************/	
//La funcion aniade al final del vector el nuevo departamento, si no hay 
//espacio lo redimension para que haya espacio mediante bloques
//Parametros: nuevo, es el departamento nuevo que va a aniadir al vector
//Devuelve: nada
	
	void VectorDepartamento::Aniade(Departamento nuevo){
		if (usadas == reservadas){
			VectorDepartamento aux (reservadas + BLOQUE);
			for(int i = 0 ; i < usadas ; i++){
				aux[i+1] = departamentos[i];
			
			}
			*this = aux;
	
		}
		
		departamentos[usadas] = nuevo;
		usadas++;	
	
	
	}

/******************************************************************************/	
//La funcion aniade un departamento en una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//            nuevo, el departamento que se va a aniadir al vector
//Devuelve: nada
//PRE: 0<=pos<reservadas
	
	void VectorDepartamento::Inserta(const int pos, Departamento nuevo){
		for (int i = usadas - 1; i >= pos; i--){
			departamentos[i+1] = departamentos[i];
		}
		departamentos[pos] = nuevo;
		usadas++;
	
	}

/******************************************************************************/	
//La funcion elimina el elemento de una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//Devuelve: nada
//PRE: 0<=pos<usadas
	
	void VectorDepartamento::Eliminar(const int pos){
		for (int i = pos ; i < usadas-1; i++){
			departamentos[i] = departamentos[i+1];
		}
		usadas--;
		
	
	}

/******************************************************************************/	
//La funcion reajusta el vector para que usadas sea igual a capacidad
//Devuelve: nada

	void VectorDepartamento::Reajustar(){
		if(usadas < reservadas){
			VectorDepartamento aux (usadas);
			
			for(int i = 0; i < usadas ; i++){
				aux[i] = departamentos[i];
			
			}
			
			*this = aux;
			
				
		
		
		}
	
	
	}

/******************************************************************************/	
//el operador pasa los datos al dato de la izquierda
//Parametros: otro, la parte derecha del operador de asignacion
	
	VectorDepartamento & VectorDepartamento::operator= 
	                                      (const VectorDepartamento & otro){
		if(this != &otro){
			LiberarMemoria();
			ReservarMemoria(otro);	
			CopiarDatos(otro);
		}
		return (*this);
	
	}

/******************************************************************************/	
//los operadores () y [] muestran un departamento del vector
//Parametros: casilla, donde está el departamento a mostrar
//Devuelve: el departamaneto de la posicion casilla
//PRE: 1<= casilla <= usadas
	
	Departamento & VectorDepartamento::operator[] (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Departamento & VectorDepartamento::operator[] (const int casilla)const{
		return ValorCasilla(casilla);
	
	}
	
	Departamento & VectorDepartamento::operator() (const int casilla){
		return ValorCasilla(casilla);
	
	}
	Departamento & VectorDepartamento::operator() (const int casilla)const{
		return ValorCasilla(casilla);
	
	}
	
/******************************************************************************/	
//los operadores  de suma
//version 1 [VectorDepartamento] + [VectorDepartamento]
//el nuevo vector tiene todos los departamentos no repetidos	
	VectorDepartamento operator+ 
	(const VectorDepartamento & v1,const VectorDepartamento & v2)
{
	VectorDepartamento todos;
	todos = v1;
	
	for(int i = 1; i <= v2.GetUsados(); i++){
		if(!(todos && v2[i])){
			todos.Aniade(v2[i]);
		}
	
	}                    
	return todos;                                      
	                                      
	                                      
}

//version 2 [VectorDepartamento] + [Departamento]
	VectorDepartamento operator +
	(const VectorDepartamento & v1,const Departamento & d1)
{
	VectorDepartamento departamento;
	departamento.Aniade(d1);
	return (v1+departamento);                                	     
	                                     
}

//version 3 [Departamento] + [VectorDepartamento]
	VectorDepartamento operator+
	(const Departamento & d1, const VectorDepartamento & v1)
{
	                                    
	return(v1+d1);	                                    
	                                    
	                                    
}

/******************************************************************************/	
//los operadores  de resta, quita teniendo en cuenta id_depto
//version 1 [VectorDepartamento] - [VectorDepartamento]
	
	VectorDepartamento VectorDepartamento::operator- 
	(const VectorDepartamento & v1)
{
	VectorDepartamento quitados;
	quitados = *this;
	for(int i = 0 ;  i < v1.GetUsados(); i++){
		if(quitados && v1[i+1]){
			for(int k = 0 ; k < usadas; k++){
				if(departamentos[k].GetId() == v1[i+1].GetId()){
					quitados.Eliminar(k);
				}
			
			}
			
			
		}	
	
	
	}
	return (quitados);
	
}

//version 2 [VectorDepartamento] - [Departamento]

	VectorDepartamento VectorDepartamento::operator- 
	(const Departamento & d1)
{
	VectorDepartamento un_departamento;
	un_departamento.Aniade(d1);
	return (*this - un_departamento);

}

//version 3 [VectorDepartamento] - [string]
	VectorDepartamento VectorDepartamento::operator- (const string & id)
{
	Departamento ids;
	ids.SetId(id);
	return (*this - ids);
}

/******************************************************************************/	
//los operadores  de multiplicacion, contiene los datos comunes por id_depto
//version 1 [VectorDepartamento] * [VectorDepartamento]
	
	VectorDepartamento VectorDepartamento::operator*
	(const VectorDepartamento & v1)
{
	VectorDepartamento todos;
	VectorDepartamento aux;
	todos = *this;
	
	for(int i = 1; i <= v1.usadas; i++){
		if(todos && v1[i]){
			aux.Aniade(v1[i]);
		}
	
	}
	
	return(aux);	
	
}

/******************************************************************************/	
//los operadores  &&, devuelve true si está contenido ese departamento,
//todo el vector o está el id, se compara por el id_depto
//version 1 [VectorDepartamento] && [VectorDepartamento]
	
	bool operator&& (const VectorDepartamento & v1, 
	                 const VectorDepartamento & v2 )
{
	bool iguales = true;
	for(int i = 1; i <= v1.usadas && iguales; i++){
		for(int k = 1 ; k <= v2.usadas && iguales; k++){
			if(v1[i].GetId() != v2[i].GetId()){
				iguales = false;
			}
		
		}
	
	
	}
	return iguales;               
	                        
	                        
}
//version 2 [VectorDepartamento] && [Departamento]

	bool operator&& (const VectorDepartamento & v1,
	    	         const Departamento & d1)
{
	bool esta = false;
	for(int i = 1;  i <= v1.GetUsados() && !esta; i++ ){
		if(v1[i].GetId() == d1.GetId()){
			esta = true;		
		
		}
	
	}
		                        
	return (esta);	                        
	                        
	                        
}

//version 3 [Departamento] && [VectorDepartamento]

	bool operator&& (const Departamento & d1,
	                 const VectorDepartamento & v1)
{
		                                     
	return (v1 && d1);	                                     
	                                     
}

//version 4 [VectorDepartamento] && [string]

	bool operator&& (const VectorDepartamento & v1,
	                 const string id)
{
	                                     
	  Departamento un_id;
	  un_id.SetId(id);                                  
	  return(v1 && un_id);                                   
	                                     
}

//version 5 [string] && [VectorDepartamento]

	bool operator&& (const string & id,
	                 const VectorDepartamento & v1)
{
	                                     
	return (v1 && id);                        
	                                    	                                     
}


/******************************************************************************/	
//los operadores  de sumaigual
//version 1 [VectorDepartamento] += [VectorDepartamento]	
	VectorDepartamento & VectorDepartamento::operator+= 
	(const VectorDepartamento & v1)
{
	VectorDepartamento todos;
	VectorDepartamento aux = *this;
	todos = aux + v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorDepartamento] += [Departamento]
	VectorDepartamento & VectorDepartamento::operator+= 
	(const Departamento & d1)
{
	VectorDepartamento un_departamento;
	un_departamento.Aniade(d1);
	return (*this += un_departamento);	
	
}
	                                    
/******************************************************************************/	
//los operadores  de restaigual
//version 1 [VectorDepartamento] -= [VectorDepartamento]	
	VectorDepartamento & VectorDepartamento::operator-= 
	(const VectorDepartamento & v1)
{
	VectorDepartamento todos;
	VectorDepartamento aux = *this;
	todos = aux - v1;
	*this = todos;
	return (*this);	
}

//version 2 [VectorDepartamento] -= [Departamento]
	VectorDepartamento & VectorDepartamento::operator-= 
	(const Departamento & d1)
{
	VectorDepartamento un_departamento;
	un_departamento.Aniade(d1);
	return(*this -= un_departamento);	
	
}	

//version 3 [VectorDepartamento] -= [string]
	VectorDepartamento & VectorDepartamento::operator -= (const string & id)
	{
		Departamento ids;
		ids.SetId(id);
		return (*this -= ids);
	}

/******************************************************************************/	
//este metodo saca un string del bloque completo que hay en el vector
//Devuelve: un string en bloque con todo el contenido del vector
	
	string VectorDepartamento::ToString(){
		string aux = "";
		for(int i = 0; i < usadas ; i++){
			aux += departamentos[i].ToString() + "\n";
		
		}
		return aux;
	
	
	}

/******************************************************************************/	
//La funcion saca un string del departamento del vector que este en pos
//Parametros: pos, posicion donde se va a sacar el string
//Devuelve: string del departamento que este en pos del vector
//PRE: 0<=pos<usadas
	
	string VectorDepartamento::ToString(const int pos){
		string aux = "";
		
		aux += departamentos[pos].ToString() ;
	
	
	
		return aux;
	
	}

/******************************************************************************/	
//operadores << y >> en el operador << tiene que estar el archivo en el formato
//correcto, es decir primero DEPARTAMENTOS, luego los comentarios tienen que 
//llevar en la primera linea # y luego escrito correctamente cada departamento	
//en caso de que esto no se cumpla devolvera un vector vacio	
	
	istream & operator >> (istream & in, VectorDepartamento & v){
		
		string cad;
		
		v = VectorDepartamento ();
		
		getline(in, cad);//lectura de la primera fila
		
		if(cad == "DEPARTAMENTOS"){
		
			getline(in,cad);//lectura adelantada
			
			while(cad[0] == '#'){
			
				getline(in,cad);
				
			}//salimos cuando tenemos la primera linea que contiene
			//departamentos
			
			Departamento nuevo_primero (cad, '*');
			
			v.Aniade(nuevo_primero);
			
			getline(in,cad);
			
			while(!in.eof()){
			
				Departamento nuevos (cad, '*');
				
				v += nuevos;
				
				getline(in,cad);
				
			}
			
		
		}
	
		return (in);
	}
	
	ostream & operator << (ostream & out, const VectorDepartamento & v){
		
		VectorDepartamento aux = v;
		
		out << aux.ToString();
	
		return (out);
	}

/******************************************************************************/	
//Funcion que recupera los datos de un vector de el fichero nombre, si no esta 
//de la forma correcta se devuelve un vector vacio
	
	void VectorDepartamento::RecuperarVectorDepartamento 
	                                               (const string & nombre) {
	                                               
			 *this = VectorDepartamento (nombre);
			
			
			                                       
	}
/******************************************************************************/	
//Funcion que guarda en un fichero con nombre guardando el vector si está vacio
// no se crea el fichero
	
	void VectorDepartamento::GuardarVectorDepartamento 
	                                          (const string & nombre) const{
		
		if(!Vacio()){
		
			ofstream fo (nombre);
			
			if(!fo){
			
				cerr<<"No se puede crear el fichero "+nombre
				    <<endl;
				    
				exit(1);    
			
				}
			
			fo << "DEPARTAMENTOS" << endl;
			fo << "# Los elementos de nuestro vector"<<endl;
			
			for(int i = 0; i < usadas ; i++  ){
				
				fo << departamentos[i].GetId()+'*'+
				      departamentos[i].GetNombre()+'*'<<endl;
			
			}
			
			cerr<<"Se ha guardado el vector en "+nombre<<endl;
		
			fo.close();
		
			
		}
	
	}
	
	

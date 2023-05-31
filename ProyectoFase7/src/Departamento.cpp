
#include "Departamento.h"


/************************************************************/
/************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo.
	
void Departamento::ReservarMemoria (const Departamento & otro){
	
	Nombre = nullptr;
	Id_depto = nullptr;
	
	string nom = otro.GetNombre();
	string id = otro.GetId();
	
	Nombre = new char [nom.size()+1];
	Id_depto = new char [id.size()+1];
	
	


}


/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos

void Departamento::CopiarDatos (const Departamento & otro){
	
	LiberarMemoria();
	
	ReservarMemoria (otro);
	
	string nom = otro.GetNombre();
	string id = otro.GetId();
	
	for (int i = 0 ; i < nom.size(); i++){
		Nombre[i] = nom[i];
		
	}
	Nombre[nom.size()] = '\0';
	
	for (int i = 0 ; i < id.size(); i++){
		Id_depto[i] = id[i];
		
	}
	Id_depto[id.size()] = '\0';	
}

/************************************************************/
/************************************************************/
// Libera memoria
void Departamento::LiberarMemoria (void){
	if (Nombre){
		delete[] Nombre;
		Nombre = nullptr;
	}
	if(Id_depto){	 
		delete[] Id_depto;
		Id_depto = nullptr;	
	}

}

//constructor de la clase
//parametros: linea, de donde se extraen los datos de la clase
//            delimitador, caracter que funciona como limite de copia
//NOTA: Primero deben ir los ids y luego los nombres de los departamentos
	
Departamento::Departamento (string linea, char delimitador){
	int contador = 0;
	string id ; 
	string nombre ;
	while(linea[contador] != delimitador){
		id.push_back(linea[contador]);	
		contador++;
	}
	contador++;
	SetId(id);
	while(linea[contador] != delimitador){
		nombre.push_back(linea[contador]);
		contador++;
	}
	SetNom(nombre);
	
}

//constructor de la clase sin argumentos
	
Departamento::Departamento (){
	Nombre = nullptr;
	Id_depto = nullptr;
	SetNom("");
	SetId("");

}
	
//Constructor que crea un objeto apertir de otro
//Parametros: otro, el otro objeto que sirve de copia
	
Departamento::Departamento(const Departamento & otro){
	ReservarMemoria (otro);
	CopiarDatos (otro);




}

//Destructor de la clase que elimina la memoria de las variables
//privadas

Departamento::~Departamento(){
	LiberarMemoria ();
	
}	
	
//funcion que convierte a string los datos de la clase.
	
string Departamento::ToString(){
	string salida ="\0";
	if (Nombre != nullptr){
		salida += FormatString("("+GetId()+")",10) + 
		          FormatString(GetNombre(),25);
	
	}else{
		salida ="VACIO";
	
	}
	return salida;
}

//funcion que pone el id del departamento
void Departamento::SetId(string ids){
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

//Operador de asignacion =
	
Departamento& Departamento::operator= (const Departamento & otro){
	if(this != &otro){
		LiberarMemoria ();
		ReservarMemoria (otro);
		CopiarDatos (otro);
	}	
	return *this;

}
	
//funcion que pone el nombre del departamento
void Departamento::SetNom(string nombres){
	// uno más ya que es necesario el \0
	int tamanio = nombres.size() +1; 
	Nombre = new char [tamanio];
	//calculo todos los datos del string 
	for (int i = 0 ; i < nombres.size(); i++){
		Nombre[i] = nombres[i];
		
	}
	Nombre[tamanio-1] = '\0';
	//ahora tendriamos en nuestra cadena clasica nuestro string
	
}

	
//funcion que devuelve el id del departamento
string Departamento::GetId ()const{
	string id;
	int contador = 0;
	while(Id_depto[contador] != '\0'){
		//la funcion push_back pone en el string un elemento
		//al final del string
		id.push_back(Id_depto[contador]);
		contador++;
	}
	return id;	
} 
	
//funcion que devuelve el nombre del departamento	
string Departamento::GetNombre()const{
	string nombre;
	int contador = 0;
	while(Nombre[contador] != '\0'){
		//la funcion push_back pone en el string un elemento
		//al final del string
		nombre.push_back(Nombre[contador]);
		contador++;
	}
	return nombre;	
}

//metodo que hace una copia del objeto origen al objeto que es aplicado
//Parametros: origen (referencia), objeto al que se le va a hacer la 
//            copia profunda

void Departamento::Clona(const Departamento & origen){
	
	if (Nombre){
		delete[] Nombre;
		Nombre = nullptr;
	}
	if(Id_depto){	 
		delete[] Id_depto;
		Id_depto = nullptr;	
	}
	
	SetNom(origen.GetNombre());
	SetId(origen.GetId());

}

//operadores << y >> para la clase departamento
	
ostream & operator << (ostream & out, const Departamento & d){
	
	Departamento aux = d;
	out << aux.ToString();
	
	return (out);


} 
	
istream & operator >> (istream & in , Departamento & d){

	string linea;
	
	getline(in,linea);
	
	d = Departamento(linea, '*');

	return (in);
	
}



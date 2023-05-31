
#include "Profesor.h"
#include "Fecha.h"
#include <string>
#include <cstring>


/************************************************************/
/************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo.
	
void Profesor::ReservarMemoria (const Profesor & otro){
	
	DNI=0;
	Nombre=0;
	Apellidos=0;
	
	string dni = otro.GetDNI();
	string nombre = otro.GetNom();
	string apellidos = otro.GetApellidos();
	
	DNI = new char [dni.size()+1];
	Nombre = new char [nombre.size()+1];
	Apellidos = new char [apellidos.size()+1];
	
	


}


/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos

void Profesor::CopiarDatos (const Profesor & otro){
	ReservarMemoria (otro);
	
	string dni = otro.GetDNI();
	string nom = otro.GetNom();
	string apellidos = otro.GetApellidos();
	string cate = otro.GetCate();
	string aux = "\0";
	string dia = (otro.Nacimiento).GetDia();
	string mes = (otro.Nacimiento).GetMes();
	string anio = (otro.Nacimiento).GetAnio();
	
	for(int i = 0 ; i < dni.size(); i++){
		DNI[i] = dni[i];
	
	}
	DNI[dni.size()] = '\0';
	
	for (int i = 0 ; i < nom.size(); i++){
		Nombre[i] = nom[i];
		
	}
	Nombre[nom.size()] = '\0';
	
	for (int i = 0 ; i < apellidos.size(); i++){
		Apellidos[i] = apellidos[i];
		
	}
	Apellidos[apellidos.size()] = '\0';
	
	Nacimiento.SetDia(dia);
	Nacimiento.SetMes(mes);
	Nacimiento.SetAnio(anio);
	
	for (int i = 0 ; i < cate.size(); i++){
		aux[i] = cate[i];
		
	}
	Categoria = stoi(aux);
		
}

/************************************************************/
/************************************************************/
// Libera memoria
void Profesor::LiberarMemoria (void){
	if(DNI){
		delete [] DNI;
		DNI = nullptr;
	}
	if(Nombre){
		delete [] Nombre;
		Nombre = nullptr;
	}
	if(Apellidos){
		delete [] Apellidos;
		Apellidos = nullptr;
	}

}

//constructor de la clase
//parametros: linea, de donde se extraen los datos de la clase
//            delimitador, caracter que funciona como limite de copia
//NOTA: primero se debe poner el DNI, luego apellidos, nombre, fecha y
//      por ultimo la categoria si nop está entre uno y cinco se le 
//      pondra el valor 0.
	
Profesor::Profesor (string linea, char delimitador ){ 
	int contador= 0;
	string aux = "\0";
	while(linea[contador] != delimitador){
		aux += linea[contador];
		contador++;
	}
	SetDNI(aux);
	contador++;
	aux = "\0";
	while(linea[contador] != delimitador){
		aux += linea[contador]; 
		contador++;
	}
	SetApellidos(aux);
	contador++;
	aux = "\0";
	while(linea[contador] != delimitador){
		aux += linea[contador]; 
		contador++;
	}
	SetNom(aux);
	contador++;
	aux = "\0";
	while(linea[contador] != delimitador){
		aux += linea[contador]; 
		contador++;
	}
	SetNacimiento(aux);
	contador++;
	aux = "\0";
	while(linea[contador] != delimitador){
		aux += linea[contador]; 
		contador++;
	}
	int aux_cate = stoi(aux);
	if (aux_cate >= 1 && aux_cate <= 5) {
		SetCate(aux_cate);
	}else{
		//categoria a 0 sino está entre 1 y 5
		SetCate(0);
	}
}

//Constructor de copia
//Parametros: objeto que se va a copiar          		
	
Profesor::Profesor (const Profesor & otro ){

	ReservarMemoria (otro);

	CopiarDatos (otro);

}

//constructor de la clase sin parametros
	
Profesor::Profesor(){
	DNI = nullptr;
	Nombre = nullptr;
	Apellidos = nullptr;
	SetDNI("");
	SetNom("");
	SetApellidos("");
	Categoria = 0;
	Fecha aux;
	Nacimiento = aux;

}
	
//destructor que deja los datos privados que usan el memoria dinamica
//en esatdo vacio
Profesor::~Profesor(){
	LiberarMemoria ();
	
}

//Operador de asignacion =
	
Profesor& Profesor::operator= (const Profesor & otro){
	if(this != &otro){
		LiberarMemoria ();
		ReservarMemoria (otro);
		CopiarDatos (otro);
	}	
	return *this;

}
	
//funcion que convierte a string los datos de la clase.
	
string Profesor::ToString(){
	string salida = "\0";
	string NomComp = GetApellidos()+", "+GetNom();
	string dni = GetDNI();
	string fecha = GetNacimiento();
	string cate = GetCate();
	salida += FormatString(dni,10) +FormatString(NomComp,38);
	salida += FormatString(fecha,10) +FormatString(cate,1);
	string cadena = salida;
	if (DNI == nullptr){
		cadena = "VACIO";
	
	}
	return cadena;
}
	
 
//funcion que pone el DNI del profesor
void Profesor::SetDNI(string dnis){
	int tamanio = dnis.size()+1;
	DNI = new char [tamanio];
	//calculo todos los datos del string 
	for (int i = 0 ; i < tamanio-1; i++){
		DNI[i] = dnis[i];
		
	}
	DNI[tamanio-1] = '\0';
	//ahora tendriamos en nuestra cadena clasica nuestro string
		                              
		                               
	
}
	
	
//funcion que pone el nombre del profesor
void Profesor::SetNom(string nombres){
	int tamanio = nombres.size()+1;
	Nombre = new char[tamanio];
	//calculo todos los datos del string 
	for (int i = 0 ; i < tamanio-1; i++){
		Nombre[i] = nombres[i];
		
	}
	Nombre[tamanio-1] = '\0';
	//ahora tendriamos en nuestra cadena clasica nuestro string
}
	
//funcion que pone los apellidos del profesor
void Profesor::SetApellidos(string apellidos){
	//calculo todos los datos del string 
	int tamanio = apellidos.size()+1;
	Apellidos = new char [tamanio];
	for (int i = 0 ; i < tamanio-1; i++){
		Apellidos[i] = apellidos[i];
		
	}
	Apellidos[tamanio-1] = '\0';
	//ahora tendriamos en nuestra cadena clasica nuestro string
}
	
//funcion que pone la categoría del profesor
void Profesor::SetCate(int categorias){
	Categoria = categorias;
	
}
	
//funcion que pone la fecha de nacimineto del profesor
void Profesor::SetNacimiento (string nacimientos){
	Fecha Nacimientos (nacimientos);
		
	Nacimiento.SetDia(Nacimientos.GetDia());
	Nacimiento.SetMes(Nacimientos.GetMes());
	Nacimiento.SetAnio(Nacimientos.GetAnio());
		
			
}
	
//funcion que da el DNI del profesor
string Profesor::GetDNI()const{
	string dnis;
	int contador = 0;
	while(DNI[contador] != '\0'){
		//la funcion push_back pone en el string un elemento
		//al final del string
		dnis.push_back(DNI[contador]);
		contador++;
	}
	return dnis;
	
}
	
//funcion que da el nombre del profesor
string Profesor::GetNom()const{
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
	
//funcion que da los apellidos del profesor
string Profesor::GetApellidos ()const{
	string apellidos = "\0";
	int contador = 0;
	while(Apellidos[contador] != '\0'){
		//la funcion push_back pone en el string un elemento
		//al final del string
		apellidos.push_back(Apellidos[contador]);
		contador++;
	}
	return apellidos;
	
}
	
//funcion que da la categoría del profesor
string Profesor::GetCate()const{
	return FormatInt (Categoria, 1);
		
}
	
//funcion que da la fecha de nacimineto del profesor
string Profesor::GetNacimiento ()const{
	return Nacimiento.ToString();
}

//funcion que da la fecha de nacimineto del profesor en formato fecha
	Fecha & Profesor::GetNaci (){
	
		return Nacimiento;
	
	}

//metodo que hace una copia del objeto origen al objeto que es aplicado
//Parametros: origen (referencia), objeto al que se le va a hacer la 
//            copia profunda

void Profesor::Clona(const Profesor & origen){
	
	*this = origen;
	
	


}

//operadores << y >> para la clase departamento
	
ostream & operator << (ostream & out, const Profesor & d){
	
	Profesor aux = d;
	out << aux.ToString();
	
	return (out);


} 
	
istream & operator >> (istream & in , Profesor & d){

	string linea;
	
	getline(in,linea);
	
	d = Profesor(linea, '*');

	return (in);
	
}



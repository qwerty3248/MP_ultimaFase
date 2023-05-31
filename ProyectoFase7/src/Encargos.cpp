
#include "Encargos.h"


//constructor de la clase
//parametros: linea, de donde se extraen los datos de la clase
//            delimitador, caracter que funciona como limite de copia
//NOTA:Primero van las categorias y luego los creditos
	
Encargo::Encargo(string linea, char delimitador ){
		int contador = 0;
		string aux = "\0";
		while(linea[contador] != delimitador){
			aux += linea[contador];
			contador++;
		}
		int aux_cate = stoi(aux);
		if (aux_cate >= 1 && aux_cate <= 5){
			SetCate(aux_cate);
		}else{
			SetCate(0);
		}
		contador++;
		aux = "\0";
		while(linea[contador] != delimitador){
			aux += linea[contador];
			contador++;
		}
		SetCreditos(stod(aux));
		
}

//constructor de la clase sin parametros
	
Encargo::Encargo(){
	Categoria = 0;
	Creditos = 0;
}
	
//funcion que convierte a string los datos de la clase.
	
string Encargo::ToString(){
	string encar = "\0";
	encar += FormatString(GetCate(),2,TipoAlineacion::AlinDerecha) + 
	         FormatString(GetCreditos(),8,TipoAlineacion::AlinDerecha); 
	
	return encar;
}
	
//funcion que pone el DNI del profesor
void Encargo::SetCate(int categorias){
	Categoria = categorias;
}
	
//funcion que pone el nombre del profesor
void Encargo::SetCreditos(double creditos){
	Creditos = creditos;
}
	
//funcion que da la categoría del profesor
string Encargo::GetCate()const{
	return FormatInt(Categoria,1);
}
	
//funcion que da los creditos
string Encargo::GetCreditos ()const {
	return FormatDouble (Creditos,5,2);

}

//operadores << y >> para la clase departamento
	
ostream & operator << (ostream & out, const Encargo & d){
	
	Encargo aux = d;
	out << aux.ToString();
	
	return (out);


} 
	
istream & operator >> (istream & in , Encargo & d){

	string linea;
	
	getline(in,linea);
	
	d = Encargo(linea, '*');

	return (in);
	
}

	

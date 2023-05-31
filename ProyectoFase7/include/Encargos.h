
#include "utils.h"


#ifndef CLASEENCARGO
#define CLASEENCARGO

#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;


class Encargo {

private:
	int Categoria;
	double Creditos;
	
	
public:
	//constructor de la clase
	//parametros: linea, de donde se extraen los datos de la clase
	//            delimitador, caracter que funciona como limite de copia
	//NOTA:Primero van las categorias y luego los creditos
	
	Encargo(string linea, char delimitador = DELIMITADOR);
	
	//constructor de la clase sin parametros
	
	Encargo();
	
	//funcion que convierte a string los datos de la clase.
	
	string ToString();
	
	//funcion que pone el DNI del profesor
	void SetCate(int categorias);
	
	//funcion que pone el nombre del profesor
	void SetCreditos(double creditos);
	
	//funcion que da la categoría del profesor
	string GetCate() const;
	
	//funcion que da los creditos
	string GetCreditos () const ;
	
	//operadores << y >> para la clase departamento
	
	friend ostream & operator << (ostream & out, const Encargo & d);
	
	friend istream & operator >> (istream & in , Encargo & d);
	
};

#endif



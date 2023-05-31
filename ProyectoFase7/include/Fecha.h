

#include "utils.h"
#ifndef CLASEFECHA
#define CLASEFECHA 

#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;


class Fecha {

private:
	int dia;
	int mes;
	int anio;
	
	
public:
	//constructor de la clase
	//parametros: linea, de donde se extraen los datos de la clase
	//            delimitador, caracter que funciona como limite de copia
	
	Fecha (string linea, char delimitador = DELIMITADOR);
	
	//constructor de la clase sin parametros
	Fecha ();
	
	//funcion que convierte a string los datos de la clase.
	
	string ToString()const;
	
	//funcion que pone el dia de la fecha
	void SetDia(string dias);
	
	//funcion que pone el mes de la fecha
	void SetMes(string meses);
	
	//funcion que pone el año de la fecha
	void SetAnio (string anios);
	
	//funcion que da el dia de la fecha
	string GetDia()const;
	
	//funcion que da los meses de la fecha
	string GetMes()const;
	
	//funcion que da los años de la fecha
	string GetAnio ()const;
	
};

#endif















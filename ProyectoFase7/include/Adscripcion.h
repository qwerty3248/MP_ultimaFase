
#include "utils.h"


#ifndef CLASEADSCRIPCION
#define CLASEADSCRIPCION

#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;


class Adscripcion {

private:
	char * DNI;
	char * Id_depto;
	
	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	
	void ReservarMemoria (const Adscripcion & otro);
	
	/************************************************************/
	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Adscripcion & otro);
		
	/************************************************************/
	/************************************************************/
	// Libera memoria
	void LiberarMemoria (void);	
	
public:
	//constructor de la clase
	//parametros: linea, de donde se extraen los datos de la clase
	//            delimitador, caracter que funciona como limite de copia
	//NOTA: primero el DNI y luego el depto
	
	Adscripcion(string linea, char delimitador = DELIMITADOR);
	
	//constructor de la clase
	//parametros: otro, objeto que se va a copiar
	
	Adscripcion(const Adscripcion & otro);
	
	//constructor de la clase sin parametros
	
	Adscripcion();
	
	//Destructor de la clase el cual libera le memoria de DNI y Id_depto
	~Adscripcion();
	
	//Operador de asignacion =
	
	Adscripcion& operator= (const Adscripcion & otro);
	
	//metodo que hace una copia del objeto origen al objeto que es aplicado
	//Parametros: origen (referencia), objeto al que se le va a hacer la 
	//            copia profunda

	void Clona(const Adscripcion & origen);
	
	//funcion que convierte a string los datos de la clase.
	
	string ToString();
	
	//funcion que pone el dni del profesor
	void SetDNI(string dnis);
	
	//funcion que pone el id del departamento
	void SetID(string ids);
	
	//funcion que da el dni del profesor
	string GetDNI()const;
	
	//funcion que da el id del departamento
	string GetID ()const;
	
	//operadores << y >> para la clase departamento
	
	friend ostream & operator << (ostream & out, const Adscripcion & d);
	
	friend istream & operator >> (istream & in , Adscripcion & d);
	
};

#endif



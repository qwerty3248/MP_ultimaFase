

#include "utils.h"


#ifndef CLASEDEPARTAMENTO
#define CLASEDEPARTAMENTO 

#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;


class Departamento {

private:
	
	char * Nombre;
	char * Id_depto;
	
	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	
	void ReservarMemoria (const Departamento & otro);
	
	/************************************************************/
	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Departamento & otro);
		
	/************************************************************/
	/************************************************************/
	// Libera memoria
	void LiberarMemoria (void);	
	
public:
	//constructor de la clase
	//parametros: linea, de donde se extraen los datos de la clase
	//            delimitador, caracter que funciona como limite de copia
	//NOTA: Primero deben ir los ids y luego los nombres de los 
	//      departamentos
	
	Departamento (string linea, char delimitador = DELIMITADOR);
	
	//constructor de la clase sin parametros
	
	Departamento ();
	
	//Constructor que crea un objeto apertir de otro
	//Parametros: otro, el otro objeto que sirve de copia
	
	Departamento (const Departamento & otro);
	
	//Destructor de la clase que elimina la memoria de las variables
	//privadas
	~Departamento();
	
	//metodo que hace una copia del objeto origen al objeto que es aplicado
	//Parametros: origen (referencia), objeto al que se le va a hacer la 
	//            copia profunda

	void Clona(const Departamento & origen);
	
	//Operador de asignacion =
	
	Departamento& operator= (const Departamento & otro);
	
	//funcion que convierte a string los datos de la clase.
	
	string ToString();
	
	//funcion que pone el id del departamento
	void SetId (string ids);
	
	//funcion que pone el nombre del departamento
	void SetNom(string nombres);
	
	//funcion que devuelve el id del departamento
	string GetId ()const; 
	
	//funcion que devuelve el nombre del departamento	
	string GetNombre()const;	
	
	//operadores << y >> para la clase departamento
	
	friend ostream & operator << (ostream & out, const Departamento & d);
	
	friend istream & operator >> (istream & in , Departamento & d);

};

#endif



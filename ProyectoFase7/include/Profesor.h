
#include "utils.h"
#include "Fecha.h"

#ifndef CLASEPROFESOR
#define CLASEPROFESOR 

#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;


class Profesor {

private:
	
	char * DNI;
	char * Nombre;
	char * Apellidos;
	Fecha Nacimiento; //dd/mm/aaaa ClaseFecha.h 
	int Categoria;
	
	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	
	void ReservarMemoria (const Profesor & otro);
	
	/************************************************************/
	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	//
	// PRE: Se ha reservado memoria para los datos
	
	void CopiarDatos (const Profesor & otro);
	
	/************************************************************/
	/************************************************************/
	// Libera memoria
	void LiberarMemoria (void);
	
public:
	//constructor de la clase
	//parametros: linea, de donde se extraen los datos de la clase
	//            delimitador, caracter que funciona como limite de copia
	//NOTA: primero se debe poner el DNI, luego apellidos, nombre, fecha y
	//      por ultimo la categoria si nop está entre uno y cinco se le 
	//      pondra el valor 0.	
	
	Profesor(string linea, char delimitador = DELIMITADOR);
	
	//Constructor de copia
	//Parametros: objeto que se va a copiar          		
	
	Profesor (const Profesor & otro );
	
	//constructor de la clase sin parametros
	
	Profesor();
	
	//destructor que deja los datos privados que usan el memoria dinamica
	//en esatdo vacio
	
	~Profesor();
	
	//Operador de asignacion =
	
	Profesor & operator = (const Profesor & otro);
	
	//metodo que hace una copia del objeto origen al objeto que es aplicado
	//Parametros: origen (referencia), objeto al que se le va a hacer la 
	//            copia profunda
	
	void Clona (const Profesor & origen);
	
	//funcion que convierte a string los datos de la clase.
	
	string ToString();
	
	//funcion que pone el DNI del profesor
	void SetDNI(string dnis);
	
	//funcion que pone el nombre del profesor
	void SetNom(string nombres);
	
	//funcion que pone los apellidos del profesor
	void SetApellidos (string apellidos);
	
	//funcion que pone la categoría del profesor
	void SetCate(int categorias);
	
	//funcion que pone la fecha de nacimineto del profesor
	void SetNacimiento (string nacimientos);
	
	//funcion que da el DNI del profesor
	string GetDNI()const;
	
	//funcion que da el nombre del profesor
	string GetNom()const;
	
	//funcion que da los apellidos del profesor
	string GetApellidos ()const;
	
	//funcion que da la categoría del profesor
	string GetCate()const;
	
	//funcion que da la fecha de nacimineto del profesor
	string GetNacimiento ()const;
	
	//funcion que da la fecha de nacimineto del profesor en formato fecha
	Fecha & GetNaci ();
	
	//operadores << y >> para la clase departamento
	
	friend ostream & operator << (ostream & out, const Profesor & d);
	
	friend istream & operator >> (istream & in , Profesor & d);
	
};

#endif



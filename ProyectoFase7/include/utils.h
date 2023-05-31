//declaracion de las funciones utiles para el proyecto

#ifndef UTIL
#define UTIL

#include<string>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

const char DELIMITADOR = '*';

enum class TipoAlineacion {AlinIzquierda, AlinCentro, AlinDerecha};

//Funcion que da un string de un entero
//Parametros: numero,el entero que se quiere pasar a string
//            num_casillas, las casillas que va a tener ese string
//            relleno, si tiene el numero menos casillas que num_casillas se
//            rellena con relleno
//Devuelve: un string con relleno (si es necesario) y numero.
  
string FormatInt (int numero, int num_casillas, char relleno=' ');

/*****************************************************************************/


//Funcion que da un string de un double
//Parametros: numero,el double que se quiere pasar a string
//            num_casillas, las casillas que va a tener ese string
//            num_dec, cantidad de decimales que se quiere, si hay más de los
//            que tiene se rellenan con cero, si es 0 saca la parte entera
//            sin el . del double
//            relleno, si tiene el numero menos casillas que num_casillas se
//            rellena con relleno
//Devuelve: un string con relleno (si es necesario) y numero.

string FormatDouble (double numero, int num_casillas,
                     int num_dec, char relleno=' ');

/*****************************************************************************/


//Funcion que da un string de un string pero alineado
//Parametros: la_cadena, cadena a alinear
//            num_casillas, las casillas que va a tener ese string
//            alineacion, donde se va a alinear, a la izquierda pone espacios
//            en la izquierda, a la derecha, pone espacios a la derecha y en 
//            centro pone espacios en ambos lados
//            relleno, si tiene el numero menos casillas que num_casillas se
//            rellena con relleno
//Devuelve: un string con relleno (si es necesario) y la_cadena alineada.

string FormatString (string la_cadena, int num_casillas,
                     TipoAlineacion alineacion = TipoAlineacion::AlinIzquierda,
                     char relleno=' ');
                     
/*****************************************************************************/                     

#endif





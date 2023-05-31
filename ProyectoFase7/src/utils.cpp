
#include "utils.h"
#include <string>
using namespace std;

//Funcion que da un string de un entero
//Parametros: numero,el entero que se quiere pasar a string
//            num_casillas, las casillas que va a tener ese string
//            relleno, si tiene el numero menos casillas que num_casillas se
//            rellena con relleno
//Devuelve: un string con relleno (si es necesario) y numero.

string FormatInt (int numero, int num_casillas, char relleno){
	string cadena = "\0";
	int contador = 0, aux = numero, contador2 = 0;
	
	while (aux != 0) {
		contador++;
		aux = aux/10;
	}
	//contador tiene la cantidad de cifras de numero
	aux = numero;
	int * cifras = new int [contador];
	
	while (aux != 0) {
		cifras[contador2] = aux % 10;
		aux = aux/10;
		contador2++;
	}
	//tenemos las cifras pero desde al contrario, lo ponemos bien en 
	//otro vector 
	int * cifras2 = new int [contador];
	
	for (int i = 0 ; i < contador ; i++, contador2--) {
		cifras2[i] = cifras[contador2-1];
	}
	
	delete [] cifras;
	
	//contador no debería ser mayor que num_casillas, darle 2 casillas a un
	//numero de 3 cifras por ejemplo.
	if (contador != num_casillas){
		for (int i = 0 ; i < num_casillas-contador; i++ ) {
			cadena[i] = relleno;
		}
	}
	
	for (int i = num_casillas-contador ; i < num_casillas ; i++) {
		
		int numeros = cifras2[i];
		cadena += to_string(numeros);	
	}
	
	delete [] cifras2;
	
	return cadena;
}

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
                     int num_dec, char relleno){
                    	int entera = floor(numero);
                    	string cadena1 = "\0";
                    	string cadena = to_string(numero);
                    	string espacios = "\0";
                    	string decimas = "\0";
                    	string relleno1 = to_string(relleno);
                    	if (num_dec == 0) {
                    		//colocamos el relleno
                    		if (cadena.size() < num_casillas){
                    			int rellenos = cadena.size();
                    			while(rellenos != num_casillas){
     						espacios += relleno1;
     						rellenos++;
                    			}
                    		}
   				cadena1 += espacios;
   				cadena1 += to_string(entera);
                    			
                    	}else{
                    		//rellenamos los espacios de casillas
                    		if (cadena.size() < num_casillas){
                    			int rellenos = cadena.size();
                    			while(rellenos != num_casillas){
     						espacios += relleno1;
     						rellenos++;
                    			}
                    		}
                    		int num_aux = numero * (pow(10,num_dec));
                    		//cojo los decimales pero inversos
                    		int * decimales_inv = new int [num_dec];
                    		//metemos los decimales al reves en 
                    		//decimales_inv
                    		for (int i = 0 ; i < num_dec ; i++) {
                    			int resto = num_aux % 10;
                    			decimales_inv[i] = resto;
                    			num_aux = num_aux/10;
                    		
                    		}
				//les damos la vuelta
                    		int numeros_decima = num_dec-1;
                    		for (int i = 0 ; i < num_dec ; i++,
                    		     numeros_decima-- ){
                    			decimas = decimas +
                    			to_string(decimales_inv[numeros_decima]
                    			                                      );
                    		}
                    		delete[] decimales_inv;
                    		cadena1 += espacios + to_string(entera) +
                    		           "."+decimas;
                    	
                    	}
                    	
                    	return cadena1;
                    	}

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
                     TipoAlineacion alineacion ,
                     char relleno){
			
			string cadena = la_cadena;
			int tamanio = la_cadena.size();
			string aux;
			
			if (alineacion == TipoAlineacion::AlinIzquierda){
				if (tamanio < num_casillas){
					int aux1 = num_casillas - tamanio;
					aux.resize(aux1);
					aux.replace(0,aux1,aux1,relleno); 	
				}
				cadena = cadena+aux;
			
			
			}else if (alineacion == TipoAlineacion::AlinDerecha){
				if (tamanio < num_casillas){
					int aux1 = num_casillas - tamanio;
					aux.resize(aux1);
					aux.replace(0,aux1,aux1,relleno); 	
				}
				cadena = aux+cadena;
				
			
			
			}else{
				if (tamanio < num_casillas){
					int aux1 = num_casillas/2 - tamanio;
					aux.resize(aux1);
					aux.replace(0,aux1,aux1,relleno); 	
				}
				cadena = aux+cadena;
			
			
			}
			return cadena;
			
			
			                     
		                    
}                    
                  

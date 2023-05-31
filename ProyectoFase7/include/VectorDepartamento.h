
#include "Departamento.h"

#ifndef VECTORDEPARTAMENTO
#define VECTORDEPARTAMENTO
#include <cstdlib>
#include <sstream>
#include <fstream>

class VectorDepartamento{
	private:
	
	static const int BLOQUE = 30;
	
	Departamento * departamentos;
	int reservadas;
	int usadas;

/******************************************************************************/	
//La funcion reserva memoria para el vector departamentos
//Parametros: otro, reservara tanta memoria como vaya a necesitar otro
	
	void ReservarMemoria(const VectorDepartamento & otro);

/******************************************************************************/	
//La funcion libera memoria para del vector departamentos
	
	void LiberarMemoria();
	
/******************************************************************************/	
//La funcion copia los datos de otro
//Parametros: otro, objeto de donde se van a copiar los datos
//NOTA: se tiene que haber reservado memoria anteriormente
	
	void CopiarDatos(const VectorDepartamento & otro);

/******************************************************************************/	
//La funcion muestra el valor de una casilla
//Parametros: casilla, que parte del vector departamentos se va a mostrar
//PRE: 0<=casilla<reservadas 
//Devuelve: el departamento que se encuentre en casilla 
	
	Departamento & ValorCasilla (const int casilla)const;
	
	public:

/******************************************************************************/	
//cosntructor sin parametros, lo pone todo a 0 y el vector a nullptr

	VectorDepartamento();

/******************************************************************************/	
//Constructor que crea un vector apartir de un fichero nombre, si no esta con 
// buen formato devolvera un vector vacio

	VectorDepartamento(const string & nombre);

/******************************************************************************/	
//constructor con 1 parametro, crea un vector con tantas casilla como a_reservar
//Parametro: a_reservar, casilla que se quieren reservar para el vector de 
//           departamentos
//PRE: 0<=a_reservar
	
	VectorDepartamento(const int a_reservar);

/******************************************************************************/	
//Constructor de copia, crea un objeto con todo lo que tenga otro
//Parametros: otro, objeto del cual se va a crear nuestro nuevo objeto
	
	VectorDepartamento(const VectorDepartamento & otro);

/******************************************************************************/	
//Desctructor, libera la memoria al final de la ejecucion del programa
	
	~VectorDepartamento();	

/******************************************************************************/	
//La funcion recoge el valor de reservados y lo muestra
//Parametros: Ninguno
//Devuelve: reservadas

	int GetReservados()const;

/******************************************************************************/	
//La funcion recoge el valor de usadas y lo muestra
//Parametros: Ninguno
//Devuelve: usadas
	
	int GetUsados()const;

/******************************************************************************/	
//La funcion nos dice si esta vacio o no el objeto
//Parametros: Ninguno
//Devuelve: un bool que es true si está vacio (departamentos = nullptr)
	
	bool Vacio ()const;

/******************************************************************************/	
//La funcion aniade al final del vector el nuevo departamento, si no hay 
//espacio lo redimension para que haya espacio mediante bloques
//Parametros: nuevo, es el departamento nuevo que va a aniadir al vector
//Devuelve: nada
	
	void Aniade(Departamento nuevo);

/******************************************************************************/	
//La funcion aniade un departamento en una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//            nuevo, el departamento que se va a aniadir al vector
//Devuelve: nada
//PRE: 0<=pos<reservadas
	
	void Inserta(const int pos, Departamento nuevo);

/******************************************************************************/	
//La funcion elimina el elemento de una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//Devuelve: nada
//PRE: 0<=pos<usadas
	
	void Eliminar(const int pos);

/******************************************************************************/	
//La funcion reajusta el vector para que usadas sea igual a capacidad
//Devuelve: nada

	void Reajustar();

/******************************************************************************/	
//el operador pasa los datos al dato de la izquierda
//Parametros: otro, la parte derecha del operador de asignacion
	
	VectorDepartamento & operator= (const VectorDepartamento & otro);

/******************************************************************************/	
//los operadores () y [] muestran un departamento del vector
//Parametros: casilla, donde está el departamento a mostrar
//Devuelve: el departamaneto de la posicion casilla
//PRE: 1<= casilla <= usadas
	
	Departamento & operator[] (const int casilla);
	Departamento & operator[] (const int casilla)const;
	
	Departamento & operator() (const int casilla);
	Departamento & operator() (const int casilla)const;

/******************************************************************************/	
//los operadores  de suma
//version 1 [VectorDepartamento] + [VectorDepartamento]
//el nuevo vector tiene todos los departamentos no repetidos	
	friend VectorDepartamento operator+ (const VectorDepartamento & v1,
	                                      const VectorDepartamento & v2);

//version 2 [VectorDepartamento] + [Departamento]
	friend VectorDepartamento operator +(const VectorDepartamento & v1,
	                                     const Departamento & d1);

//version 3 [Departamento] + [VectorDepartamento]
	friend VectorDepartamento operator+(const Departamento & d1,
	                                    const VectorDepartamento & v1);

/******************************************************************************/	
//los operadores  de resta, quita teniendo en cuenta id_depto
//version 1 [VectorDepartamento] - [VectorDepartamento]
	
	VectorDepartamento operator- (const VectorDepartamento & v1);

//version 2 [VectorDepartamento] - [Departamento]

	VectorDepartamento operator- (const Departamento & d1);

//version 3 [VectorDepartamento] - [string]
	VectorDepartamento operator- (const string & id);

/******************************************************************************/	
//los operadores  de multiplicacion, contiene los datos comunes por id_depto
//version 1 [VectorDepartamento] * [VectorDepartamento]
	
	VectorDepartamento operator *(const VectorDepartamento & v1);

/******************************************************************************/	
//los operadores  &&, devuelve true si está contenido ese departamento,
//todo el vector o está el id, se compara por el id_depto
//version 1 [VectorDepartamento] && [VectorDepartamento]
	
	friend bool operator&& (const VectorDepartamento & v1, 
	                        const VectorDepartamento & v2 );
//version 2 [VectorDepartamento] && [Departamento]

	friend bool operator&& (const VectorDepartamento & v1,
	                        const Departamento & d1);

//version 3 [Departamento] && [VectorDepartamento]

	friend bool operator&& (const Departamento & d1,
	                        const VectorDepartamento & v1);

//version 4 [VectorDepartamento] && [string]

	friend bool operator&& (const VectorDepartamento & v1,
	                        const string id);

//version 5 [string] && [VectorDepartamento]

	friend bool operator&& (const string & id,
	                           const VectorDepartamento & v1);


/******************************************************************************/	
//los operadores  de sumaigual
//version 1 [VectorDepartamento] += [VectorDepartamento]	
	VectorDepartamento & operator+= (const VectorDepartamento & v1);

//version 2 [VectorDepartamento] += [Departamento]
	VectorDepartamento & operator+= (const Departamento & d1);
	                                    
/******************************************************************************/	
//los operadores  de restaigual
//version 1 [VectorDepartamento] -= [VectorDepartamento]	
	VectorDepartamento & operator-= (const VectorDepartamento & v1);

//version 2 [VectorDepartamento] -= [Departamento]
	VectorDepartamento & operator -= (const Departamento & d1);

//version 3 [VectorDepartamento] -= [string]
	VectorDepartamento & operator -= (const string & id); 
	                           
	                           	
/******************************************************************************/	
//este metodo saca un string del bloque completo que hay en el vector
//Devuelve: un string en bloque con todo el contenido del vector
	
	string ToString();

/******************************************************************************/	
//La funcion saca un string del departamento del vector que este en pos
//Parametros: pos, posicion donde se va a sacar el string
//Devuelve: string del departamento que este en pos del vector
//PRE: 0<=pos<usadas
	
	string ToString(const int pos);
	
	
	
/******************************************************************************/	
//operadores << y >> en el operador << tiene que estar el archivo en el formato
//correcto, es decir primero DEPARTAMENTOS, luego los comentarios tienen que 
//llevar en la primera linea # y luego escrito correctamente cada departamento	
//en caso de que esto no se cumpla devolvera un vector vacio	
	
	friend istream & operator >> (istream & in, VectorDepartamento & v);
	
	friend ostream & operator << (ostream & out, const VectorDepartamento & v);

/******************************************************************************/	
//Funcion que recupera los datos de un vector de el fichero nombre, si no esta 
//de la forma correcta se devuelve un vector vacio
	
	void RecuperarVectorDepartamento  (const string & nombre); 
	
/******************************************************************************/	
//Funcion que guarda en un fichero con nombre guardando el vector si está vacio
// no se crea el fichero
	
	void GuardarVectorDepartamento (const string & nombre) const;

};




#endif





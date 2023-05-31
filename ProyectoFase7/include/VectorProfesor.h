#include "Profesor.h"

#ifndef VECTORPROFESOR
#define VECTORPROFESOR

class VectorProfesor{
	private:
	
	static const int BLOQUE = 30;
	
	Profesor * profesores;
	int reservadas;
	int usadas;

/******************************************************************************/	
//La funcion reserva memoria para el vector profesor
//Parametros: otro, reservara tanta memoria como vaya a necesitar otro	
	
	void ReservarMemoria(const VectorProfesor & otro);

/******************************************************************************/	
//La funcion libera memoria para del vector profesor
	
	void LiberarMemoria();

/******************************************************************************/	
//La funcion copia los datos de otro
//Parametros: otro, objeto de donde se van a copiar los datos
//NOTA: se tiene que haber reservado memoria anteriormente
	
	void CopiarDatos(const VectorProfesor & otro);

/******************************************************************************/	
//La funcion muestra el valor de una casilla
//Parametros: casilla, que parte del vector encargo se va a mostrar
//PRE: 0<=casilla<reservadas 
//Devuelve: el encargo que se encuentre en casilla
	
	Profesor & ValorCasilla (const int casilla)const;
	
	public:

/******************************************************************************/	
//cosntructor sin parametros, lo pone todo a 0 y el vector a nullptr

	VectorProfesor();

/******************************************************************************/	
//Constructor que crea un vector apartir de un fichero nombre, si no esta con 
// buen formato devolvera un vector vacio

	VectorProfesor(const string & nombre);
	
/******************************************************************************/	
//constructor con 1 parametro, crea un vector con tantas casilla como a_reservar
//Parametro: a_reservar, casilla que se quieren reservar para el vector de 
//           profesor
//PRE: 0<=a_reservar	
	
	VectorProfesor(const int a_reservar);

/******************************************************************************/	
//Constructor de copia, crea un objeto con todo lo que tenga otro
//Parametros: otro, objeto del cual se va a crear nuestro nuevo objeto
		
	VectorProfesor(const VectorProfesor & otro);

/******************************************************************************/	
//Desctructor, libera la memoria al final de la ejecucion del programa
	
	~VectorProfesor();	

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
//Devuelve: un bool que es true si está vacio (profesor = nullptr)
	
	bool Vacio ()const;

/******************************************************************************/	
//La funcion aniade al final del vector el nuevo profesor, si no hay 
//espacio lo redimension para que haya espacio mediante bloques
//Parametros: nuevo, es el profesor nuevo que va a aniadir al vector
//Devuelve: nada
	
	void Aniade(Profesor nuevo);

/******************************************************************************/	
//La funcion aniade un profesor en una posicion dada
//Parametros: pos, posicion donde se va a aniadir
//            nuevo, el profesor que se va a aniadir al vector
//Devuelve: nada
//PRE: 0<=pos<reservadas
	
	void Inserta(const int pos, Profesor nuevo);

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
	
	VectorProfesor & operator= (const VectorProfesor & otro);

/******************************************************************************/	
//los operadores () y [] muestran un encargo del vector
//Parametros: casilla, donde está el encargo a mostrar
//Devuelve: el profesor de la posicion casilla
//PRE: 1<= casilla <= usadas
	
	Profesor & operator[] (const int casilla);
	Profesor & operator[] (const int casilla)const;
	
	Profesor & operator() (const int casilla);
	Profesor & operator() (const int casilla)const;

/******************************************************************************/	
//los operadores  de suma
//version 1 [VectorProfesor] + [VectorProfesor]
//el nuevo vector tiene todos los Profesores no repetidos	
	friend VectorProfesor operator+ (const VectorProfesor & v1,
	                                      const VectorProfesor & v2);

//version 2 [VectorProfesor] + [Profesor]
	friend VectorProfesor operator +(const VectorProfesor & v1,
	                                     const Profesor & d1);

//version 3 [Profesor] + [VectorProfesor]
	friend VectorProfesor operator+(const Profesor & d1,
	                                    const VectorProfesor & v1);

/******************************************************************************/	
//los operadores  de resta, quita teniendo en cuenta id_depto
//version 1 [VectorProfesor] - [VectorProfesor]
	
	VectorProfesor operator- (const VectorProfesor & v1);

//version 2 [VectorProfesor] - [Profesor]

	VectorProfesor operator- (const Profesor & d1);

//version 3 [VectorProfesor] - [string]
	VectorProfesor operator- (const string & id);

/******************************************************************************/	
//los operadores  de multiplicacion, contiene los datos comunes por id_depto
//version 1 [VectorProfesor] * [VectorProfesor]
	
	VectorProfesor operator *(const VectorProfesor & v1);

/******************************************************************************/	
//los operadores  &&, devuelve true si está contenido ese Profesor,
//todo el vector o está el id, se compara por el id_depto
//version 1 [VectorProfesor] && [VectorProfesor]
	
	friend bool operator&& (const VectorProfesor & v1, 
	                        const VectorProfesor & v2 );
//version 2 [VectorProfesor] && [Profesor]

	friend bool operator&& (const VectorProfesor & v1,
	                        const Profesor & d1);

//version 3 [Profesor] && [VectorProfesor]

	friend bool operator&& (const Profesor & d1,
	                        const VectorProfesor & v1);

//version 4 [VectorProfesor] && [string]

	friend bool operator&& (const VectorProfesor & v1,
	                        const string id);

//version 5 [string] && [VectorProfesor]

	friend bool operator&& (const string & id,
	                           const VectorProfesor & v1);


/******************************************************************************/	
//los operadores  de sumaigual
//version 1 [VectorProfesor] += [VectorProfesor]	
	VectorProfesor & operator+= (const VectorProfesor & v1);

//version 2 [VectorProfesor] += [Profesor]
	VectorProfesor & operator+= (const Profesor & d1);
	                                    
/******************************************************************************/	
//los operadores  de restaigual
//version 1 [VectorProfesor] -= [VectorProfesor]	
	VectorProfesor & operator-= (const VectorProfesor & v1);

//version 2 [VectorProfesor] -= [Profesor]
	VectorProfesor & operator -= (const Profesor & d1);

//version 3 [VectorProfesor] -= [string]
	VectorProfesor & operator -= (const string & id); 
	                           
	                           	
/******************************************************************************/	
//este metodo saca un string del bloque completo que hay en el vector
//Devuelve: un string en bloque con todo el contenido del vector
	
	string ToString();

/******************************************************************************/	
//La funcion saca un string del profesor del vector que este en pos
//Parametros: pos, posicion donde se va a sacar el string
//Devuelve: string del profesor que este en pos del vector
//PRE: 0<=pos<usadas
	
	string ToString(const int pos);

/******************************************************************************/	
//operadores << y >> en el operador << tiene que estar el archivo en el formato
//correcto, es decir primero PROFESORES, luego los comentarios tienen que 
//llevar en la primera linea # y luego escrito correctamente cada departamento	
//en caso de que esto no se cumpla devolvera un vector vacio	
	
	friend istream & operator >> (istream & in, VectorProfesor & v);
	
	friend ostream & operator << (ostream & out, const VectorProfesor & v);

/******************************************************************************/	
//Funcion que recupera los datos de un vector de el fichero nombre, si no esta 
//de la forma correcta se devuelve un vector vacio
	
	void RecuperarVectorProfesor (const string & nombre); 
	
/******************************************************************************/	
//Funcion que guarda en un fichero con nombre guardando el vector si está vacio
// no se crea el fichero
	
	void GuardarVectorProfesor (const string & nombre) const;

};



#endif





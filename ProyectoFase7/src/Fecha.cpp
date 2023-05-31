#include "Fecha.h"

//dd/mm/aaaa*

//constructor de la clase
//parametros: linea, de donde se extraen los datos de la clase
//            delimitador, caracter que funciona como limite de copia
//NOTA: debe de poner primero el dia, luego el mes y por ultimo el año.
	
Fecha::Fecha (string linea, char delimitador ){
	string cadena1 (linea,0,3);
	string cadena2 (linea,3,3);
	string cadena3 (linea,6,5);
	string Dias = "\0", Meses = "\0", Anios = "\0";
 	int dias, meses, anios, contador1 = 0, contador2 = 0, contador3 = 0;	
	while(cadena1[contador1] != '/'){
		Dias += cadena1[contador1];
		contador1++;
	}
	while(cadena2[contador2] != '/'){
		Meses += cadena2[contador2];
		contador2++;
	}	
	while(cadena3[contador3] != delimitador){
		Anios += cadena3[contador3];
		contador3++;
	}
	SetDia(Dias);
	SetMes(Meses);
	SetAnio(Anios);

}
	
//constructor de la clase sin parametros
Fecha::Fecha (){
	dia = 0;
	mes = 0;
	anio = 0;

}
	
//funcion que convierte a string los datos de la clase.
	
string Fecha::ToString()const{
	string salida = " ";
	string Mes;
	switch(mes){
	
		case 1 :
			Mes = "Ene";
			break;
		case 2 :
			Mes = "Feb";
			break;
		case 3 :
			Mes = "Mar";
			break;
		case 4 :
			Mes = "Abr";
			break;		
		case 5 :
			Mes = "May";
			break;
		case 6 :
			Mes = "Jun";
			break;
		case 7 :
			Mes = "Jul";
			break;
		case 8 :
			Mes = "Ago";
			break;
		case 9 :
			Mes = "Sep";
			break;
		case 10 :
			Mes = "Oct";
			break;
		case 11 :
			Mes = "Nov";
			break;
		case 12 :
			Mes = "Dic";
			break;
		default:
			Mes = "Nul";
			break;
		
	}
	
	string espacio ="";
	
	if(stoi(GetDia()) < 10){
		
		espacio = " ";
	
	}
	
	salida = salida+espacio+GetDia()+" "+Mes+" "+GetAnio()+" ";
	return salida;

}
	
//funcion que pone el dia de la fecha
void Fecha::SetDia(string dias){
	dia = stoi(dias);	

}
	
//funcion que pone el mes de la fecha
void Fecha::SetMes(string meses){
	mes = stoi(meses);


}

	
//funcion que pone el año de la fecha
void Fecha::SetAnio (string anios){
	anio = stoi(anios);


}
	
//funcion que da el dia de la fecha
string Fecha::GetDia()const{
	string cadenas;
	cadenas = to_string(dia);
	return cadenas;
	
}
	
//funcion que da los meses de la fecha
string Fecha::GetMes()const{
	string cadenas;
	cadenas = to_string(mes);
	return cadenas;

}
	
//funcion que da los años de la fecha
string Fecha::GetAnio ()const{
	string cadenas;
	cadenas = to_string(anio);
	return cadenas;

}
	







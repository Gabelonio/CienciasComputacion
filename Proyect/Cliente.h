#ifndef CLIENTE_H
#define CLIENTE_H
#include "lista.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include "Persona.h"
/*
	Estructuracion del resumen:
	* Nombre de paseador
	* Fecha
	* Hora 
	* Duracion (HORAS)
	* Actividad
	* Observaciones
*/
struct Resumen{
	string nombrePaseador;
	string fecha;
	string hora;
	int duracion;
	string actividad;
	string observaciones;
};

/*
	Estructuracion de cada perro:
	* Nombre
	* Fecha Nacimiento
	* Raza
	* Concentrado 
	* Tamaño
	* Lista de cada resumen 
*/
template <class T>
struct Mascota{
	string nombreMascota;
	string fechaDeNacimientoMas;
	string raza;
	string tipoConcentrado;
	char tam;
	lista<T> resumen;
};

class Cliente : public Persona{
	private:
		string localidad;
	public:
		Cliente();
		void setLocalidad(string localidad);
		string getLocalidad();
		Resumen resumen;
		Mascota<Resumen> mascota;
		lista< Mascota<Resumen> > listaMascota;
		void setNombrePaseador(string nombrePaseador);
		string getNombrePaseador();
		void setActividad(string actividad);
		string getActividad();
		void setDuracion(int duracion);
		int getDuracion();
		void setFecha(string fecha);
		string getFecha();
		void setHora(string hora);
		string getHora();
		void setObservaciones(string observaciones);
		string getObservaciones();
		void setNombreMascota(string nombreMascota);
		string getNombreMascota();
		void setFechaDeNacimientoMas(string fechaDeNacimientoMas);
		string getFechaDeNacimientoMas();
		void setTipoConcentrado(string tipoConcentrado);
		string getTipoConcentrado();
		void setRaza(string raza);
		string getRaza();
		void setTam(char tam);
		char getTam();
		Resumen getMascota();
};

Cliente::Cliente(){
	localidad = "";
}
/*
	Setters
*/
void Cliente::setLocalidad(string localidad){
	this -> localidad = localidad;
} 

void Cliente::setNombrePaseador(string nombrePaseador){
	this -> resumen.nombrePaseador = nombrePaseador;
}
 
void Cliente::setActividad(string actividad){
	this -> resumen.actividad = actividad;
}

void Cliente::setDuracion(int duracion){
	this -> resumen.duracion = duracion;
}

void Cliente::setFecha(string fecha){
	this -> resumen.fecha = fecha;
}

void Cliente::setHora(string hora){
	this -> resumen.hora = hora;
}

void Cliente::setObservaciones(string observaciones){
	this -> resumen.observaciones = observaciones;
}

void Cliente::setNombreMascota(string nombreMascota){
	this -> mascota.nombreMascota = nombreMascota;
}

void Cliente::setFechaDeNacimientoMas(string fechaDeNacimientoMas){
	this -> mascota.fechaDeNacimientoMas = fechaDeNacimientoMas;
}

void Cliente::setTipoConcentrado(string tipoConcentrado){
	this -> mascota.tipoConcentrado = tipoConcentrado;
}

void Cliente::setRaza(string raza){
	this -> mascota.raza = raza;
}

void Cliente::setTam(char tam){
	this -> mascota.tam = tam;
}

/*
	Getters
*/
string Cliente::getNombrePaseador(){
	return this -> resumen.nombrePaseador;
}

string Cliente::getLocalidad(){
	return this -> localidad;
}

string Cliente::getActividad(){
	return this -> resumen.actividad;
}

int Cliente::getDuracion(){
	return this -> resumen.duracion;
}

string Cliente::getFecha(){
	return this -> resumen.fecha;
}

string Cliente::getHora(){
	return this -> resumen.hora;
}

string Cliente::getObservaciones(){
	return this -> resumen.observaciones;
}


string Cliente::getNombreMascota(){
	return this -> mascota.nombreMascota;
}

string Cliente::getFechaDeNacimientoMas(){
	return this -> mascota.fechaDeNacimientoMas;
}


string Cliente::getTipoConcentrado(){
	return this -> mascota.tipoConcentrado;
}

string Cliente::getRaza(){
	return this -> mascota.raza;
}

char Cliente::getTam(){
	return this -> mascota.tam;
}

#endif

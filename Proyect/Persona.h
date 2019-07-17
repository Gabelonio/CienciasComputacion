#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Persona{
	private:
		string nombre;
		string apellido;
		string id;
		string genero;
	public:
		Persona();
		void setNombre(string nombre);
		string getNombre();
		void setApellido(string apellido);
		string getApellido();
		void setId(string id);
		string getId();
		void setGenero(string genero);
		string getGenero();
};

/*
	Funcion para inicializar los datos y evitar basura dentro de la informacion de persona
*/
Persona::Persona(){
	this -> nombre = "";
	this -> apellido = "";
	this -> id = "";
	this -> genero = "";
}

/*
	Setters
*/
void Persona::setNombre(string nombre){
	this -> nombre = nombre;
}

void Persona::setApellido(string apellido){
	this -> apellido = apellido;
}

void Persona::setId(string id){
	this -> id = id;
}

void Persona::setGenero(string genero){
	this -> genero = genero;
}

/*
	Getters 
*/
string Persona::getGenero(){
	return this -> genero;
}

string Persona::getId(){
	return this -> id;
}

string Persona::getNombre(){
	return this -> nombre;
}

string Persona::getApellido(){
	return this -> apellido;
}

#endif

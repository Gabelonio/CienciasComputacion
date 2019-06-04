#include <iostream>
#include "Lista.h"
using namespace std;
/*
	Proyecto Manejo de listas y plantillas.
	Nombres:
			Gabriel Esteban Castillo Ramírez - 20171020021
			Esteban Quintero Amaya -20171020022
*7

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Lista<int> x;
	Lista<float> y;
	Lista<char> z;
	
	x.insertar_nodo(1, 1);
	x.insertar_nodo(2, 2);
	x.insertar_nodo(3, 3);
	x.insertar_nodo(4, 4);
	x.insertar_nodo(3, 6);
	x.cambiar(4, 5);
	x.borrar_nodo(3);
	
	y.insertar_nodo(1, 2.5);
	y.insertar_nodo(2, 3.2);
	y.insertar_nodo(3, 4.1);
	y.insertar_nodo(4, 2.2);
	y.cambiar(2, 2.3);
	y.borrar_nodo(4);
	
	z.insertar_nodo(1, 'a');
	z.insertar_nodo(2, 'b');
	z.insertar_nodo(3, 'e');
	z.insertar_nodo(4, 'd');
	z.cambiar(3, 'c');
	z.borrar_nodo(1);
	
	cout<<"Impresion de la lista de enteros"<<endl<<endl; 
	for(int i=1; i<=x.getTam(); i++){
		cout<<x.buscar(i)<<" ";
	}
	cout<<endl;
	
	cout<<endl<<"Impresion de la lista de flotantes"<<endl<<endl;
	for(int i=1; i<=y.getTam(); i++){
		cout<<y.buscar(i)<<" ";
	}
	cout<<endl;
	
	cout<<endl<<"Impresion del arreglo de caracteres"<<endl<<endl;
	for(int i=1; i<=z.getTam(); i++){
		cout<<z.buscar(i)<<" ";
	}
	cout<<endl;
	
	return 0;
}

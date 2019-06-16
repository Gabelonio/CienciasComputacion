/*
	Proyecto Manejo de colas dobles.
	Nombres:
			Gabriel Esteban Castillo Ramírez - 20171020021
			Esteban Quintero Amaya -20171020022
*/
#include <iostream>
#include "Doblecola.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	        
	ColaDoble<int> lista;  
	               
	cout << " " << endl;   
	lista.insertar(3,'I');    
	lista.insertar(8,'D'); 
	lista.insertar(10,'I');
	lista.atender('D'); 
	lista.insertar(12,'D');
	lista.atender('I'); 
	lista.imprimir('I');  
	
	return 0;
}

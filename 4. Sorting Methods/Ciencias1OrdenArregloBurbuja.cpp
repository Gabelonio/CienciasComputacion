/*
Programa para realizar la organizacion de un arreglo de enteros
METODO DE BURBUJA
Gabriel Esteban Castillo Ramirez
22-04-2019
*/
#include <iostream>
#include <windows.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

using namespace std; 

void correrContador()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency fallo!\n";

    PCFreq = double(li.QuadPart)/1000.0; 	//Obtencion de microsegundos

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double obtenerContador()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void intercambio(int *arreglo, int anterior, int cambio){

	int pivot = arreglo[cambio];
	arreglo[cambio] = arreglo[anterior];
	arreglo[anterior] = pivot; 
}

void Burbuja(int *arreglo, int dimension){
	
	int i,j;
	
	for(i=dimension; i>=1; i--){

		for(j=1; j<i; j++)
			/*
			*	Comparación en el ordenamiento del arrreglo
			*/
			if(arreglo[j-1]>arreglo[j])
				/*
				*	Realización del intercambio en el arreglo
				*/
				intercambio(arreglo, j-1, j);		
	}
}

int main(){

	int dimension,i;
	int *a;
	
	cin>>dimension;
	
	a = new int[dimension];   //Creacion del arreglo a ordenar
	
	for(i=0;i<dimension;i++){
		a[i] = i+1;	  //Llenado del arreglo de menor a mayor
	}
	
	correrContador();	      //inicio del contador de milisegundos
	
	Burbuja(a,dimension);   //ordenamiento por seleccion
	
	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;
	delete []a;

	system("pause");
	
	return 0;
}



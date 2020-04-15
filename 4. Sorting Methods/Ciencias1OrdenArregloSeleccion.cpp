/*
Programa para realizar la organizacion de un arreglo de enteros
METODO DE SELECCION
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

void intercambio(int *arreglo, int minimo, int cambio){

	int pivot = arreglo[cambio];
	arreglo[cambio] = arreglo[minimo];
	arreglo[minimo] = pivot; 
}

void Seleccion(int *arreglo, int dimension){
	
	int i,j,minimo;
	
	for(i=0; i<dimension-1; i++){

		minimo = i;
		for(j=i+1; j<dimension; j++)
			/*
			*	Comparación en el ordenamiento del arrreglo
			*/
			if(arreglo[j]<arreglo[minimo])
				minimo=j;
		/*
		*	Realización del intercambio en el arreglo
		*/
		intercambio(arreglo, minimo, i);		
	}
}

int main(){

	int dimension,i;
	int *a;
	
	cin>>dimension;
	
	a = new int[dimension];   //Creacion del arreglo a ordenar
	
	for(i=0;i<dimension;i++){
		a[i] = dimension-i;	  //Llenado del arreglo de mayor a menor
	}
	correrContador();	      //inicio del contador de milisegundos
	
	Seleccion(a,dimension);   //ordenamiento por seleccion

	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;
	delete []a;

	system("pause");
	return 0;

}





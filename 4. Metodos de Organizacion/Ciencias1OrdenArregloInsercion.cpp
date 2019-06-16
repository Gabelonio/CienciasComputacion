/*
Programa para realizar la organizacion de un arreglo de enteros
METODO DE INSERCION
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

void Insercion(int *arreglo, int dimension){
	
	int i,j,pivot; 
	
	for(i=2; i<=dimension; i++){

		j = i-1;
		pivot = arreglo[j];
		/*
		*	Comparación en el ordenamiento del arrreglo
		*/
		while(j>0 && arreglo[j-1]>pivot){
			arreglo[j]=arreglo[j-1];	//primer medio intercambio en el arreglo
			j--; 
		}
		
		arreglo[j] = pivot;				//segundo medio intercambio en el arreglo		
	}
}

int main(){
	while(true){
		
	int dimension,i;
	int *a;
	
	cin>>dimension;
	
	a = new int[dimension];   //Creacion del arreglo a ordenar
	
	for(i=0;i<dimension;i++){
		a[i] = i+1;	  //Llenado del arreglo de menor a mayor
	}
			
	correrContador();		  //inicio del contador de milisegundos
	
	Insercion(a,dimension);   //ordenamiento por seleccion
	
	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;
	delete []a;
	
	}
	system("pause");
	return 0;
}


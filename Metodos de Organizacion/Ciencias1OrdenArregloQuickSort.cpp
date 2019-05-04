/*
Programa para realizar la organizacion de un arreglo de enteros
METODO QUICKSORT
Gabriel Esteban Castillo Ramirez
06-05-2019
*/
#include <windows.h>
#include <iostream>

double PCFreq = 0.0;
__int64 CounterStart = 0;

using namespace std;

void correrContador(){
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency fallo!\n";

    PCFreq = double(li.QuadPart)/1000.0; 	//Obtencion de microsegundos

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double obtenerContador(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void intercambio(int arreglo[], int numeroUno, int numeroDos){
	int pivot = arreglo[numeroUno];
	arreglo[numeroUno] = arreglo[numeroDos];
	arreglo[numeroDos] = pivot;
}

void OrdenRapido(int arreglo[], int izquierda, int derecha){

	int i,j,pivot;

	if(derecha>izquierda){
		pivot = arreglo[derecha];
		i = izquierda-1;
		j = derecha;
		for(;;){
				while(arreglo[++i]<pivot);	//1/2 comparaciones
				while(arreglo[--j]>pivot);	//1/2 comparaciones
				if(i>=j)
					break;
				intercambio(arreglo,i,j);			//1/2 intercambios
		}
		intercambio(arreglo, i, derecha);	//1/2 intercambios
		OrdenRapido(arreglo, izquierda, i-1);
		OrdenRapido(arreglo, i+1, derecha);

	}
}

int main(){

	int dimension,i;
	
	cout<<"Ingrese el tamano del arreglo: ";
	cin>>dimension;

	int a[dimension]; 		  //Creacion del arreglo a ordenar

	for(i=0;i<dimension;i++){
		a[i] = dimension-i;	  //Llenado del arreglo de mayor a menor
	}

	correrContador();

	OrdenRapido(a,0,dimension-1);   //ordenamiento por orden rapido

	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;	
	
	/*
	*	Impresion del arreglo
	*/

	for(i=0;i<dimension;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	system("pause");
	return 0;
}

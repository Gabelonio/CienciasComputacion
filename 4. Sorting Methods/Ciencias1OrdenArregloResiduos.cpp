/*
Programa para realizar la organizacion de un arreglo de enteros
METODO POR RESIDUOS (0 A 63)
Gabriel Esteban Castillo Ramirez
Esteban Quintero Amaya
10-05-2019
*/
#include <iostream>
#include <time.h>
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

struct tipoElemento{
	int numero;
	inline unsigned bits(int x,int k, int j){
		return (x>>k)&~(~0<<j);
	}
};

void intercambio(tipoElemento arreglo[], int numeroUno, int numeroDos){
	int pivot = arreglo[numeroUno].numero;
	arreglo[numeroUno].numero = arreglo[numeroDos].numero;
	arreglo[numeroDos].numero = pivot;
}

void ordenResiduos(tipoElemento a[], int izq, int der, int b){
   int i,j;
   if (der>izq && b>0){
	 	 i = izq;
		 j = der;
	   while(j!=i){
	   	 while(!a[i].bits(a[i].numero,b,1) && i<j){
			i++;
		 }
	     while( a[j].bits(a[j].numero,b,1) && j>i){
			j--;
		 }
	     intercambio(a, i, j);
	   }
	   if (!a[i].bits(a[i].numero,b,1)){
	   		j++;
	   }
	   ordenResiduos(a, izq, j-1, b-1);
	   ordenResiduos(a, j, der, b-1);
   }
}

int main(){

	srand(time(NULL));
	int dimension,i;

	cin>>dimension;

	tipoElemento a[dimension]; 		  //Creacion del arreglo a ordenar

	for(i=0;i<dimension;i++){
		a[i].numero = rand()%63;	  //Llenado del arreglo de mayor a menor
  	}

  	for(i=0;i<dimension;i++){
    	cout<<a[i].numero<<" ";
  	}
  	cout<<endl;

	correrContador();

	ordenResiduos(a,0,dimension-1,5);   //ordenamiento por seleccion

	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;	//fin del contador
	
	/*
	*	Impresion del arreglo
	*/

	for(i=0;i<dimension;i++){
		cout<<a[i].numero<<" ";
	}
	cout<<endl;

	return 0;

}

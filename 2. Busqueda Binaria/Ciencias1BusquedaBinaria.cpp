/*
Programa para realizar busqueda de un entero con
EL METODO BINARIO
Gabriel Esteban Castillo Ramirez
26-04-2019
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
 
bool busquedaBinaria(int *lista, int dimension, int elementoBusqueda){
	
	int primerIndice = 0,
		ultimoIndice = dimension-1,
		indiceMedio;
		
	bool isEncontrado = false; 
	
	/*
	*	Mientras el indice de busqueda no exceda el tamaño del arreglo
	*	y no se haya encontrado el objeto las iteraciones continuara
	*/
	while( primerIndice<=ultimoIndice && !isEncontrado ){		
		/*
		*	El indice medio sera la division sin aproximacion de 
		*   indice mayor y menor   
		*/
		indiceMedio = (int)((primerIndice+ultimoIndice)/2); 
		
		if(lista[indiceMedio] == elementoBusqueda){
			isEncontrado = true;
		}
		/*
		* 	Si el valor no se encuentra en la mitad,
		*	la busqueda se recorta en la mitad superior o
		*	inferior del arreglo dependiendo de donde 
		*	se encuentre el elemento a buscar
		*/
		else{
			if( elementoBusqueda < lista[indiceMedio])
				ultimoIndice = indiceMedio-1;
			else
				primerIndice = indiceMedio+1; 			
		}
		/* 
		*	Por tanto el peor caso siempre será el último índice o el
		*	índice anterior a la mitad del arreglo
		*/
	}
	return isEncontrado;
}

int main(){

	while(true){
	int dimension,i,elementoBusqueda;
	int *a;
	bool isElementoEncontrado;
	
	cin>>dimension;
	
	elementoBusqueda = dimension; //Peor caso para Busqueda Binaria
	
	a = new int[dimension];   
	
	for(i=0;i<dimension;i++){
		a[i] = i+1;	  //Llenado del arreglo de menor y mayor
	}
	
	correrContador();	      //inicio del contador de milisegundos
	
	isElementoEncontrado = busquedaBinaria(a, dimension, elementoBusqueda);   //busqueda binaria

	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;
	
	if(isElementoEncontrado)
		cout<<"El elemento "<<elementoBusqueda<<" fue encontrado"<<endl; 
	else
		cout<<"El elemento "<<elementoBusqueda<<" no fue encontrado"<<endl;
		 
	delete []a;

	}
	
	system("pause");
	return 0;

}




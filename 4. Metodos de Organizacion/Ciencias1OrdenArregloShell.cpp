/*
Programa para realizar la organizacion de un arreglo de enteros
METODO SHELL
Gabriel Esteban Castillo Ramirez
29-04-2019
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

void Shell(int arreglo[], int dimension){
	
	int i,j,h,pivot;
	
	for(h=1; h<=dimension/9; h = 3*h);
	
	for(h; h>0; h/=3){
		
		for(i=h; i<dimension ;i++){
			
			pivot = arreglo[i];
			j = i;
			/*
			*	Comparación en el ordenamiento del arrreglo
			*/ 
			while(j>=h && arreglo[j-h]>pivot){
				arreglo[j] = arreglo[j-h];	//Intercambio 1  en el arreglo
				j-=h;
			}
			arreglo[j] = pivot;				//Intercambio 2 en el arreglo				
		}		
	}		
}

int main(){

	int dimension,i;
	
	cin>>dimension;
	
	int a[dimension]; 		  //Creacion del arreglo a ordenar
	
	for(i=0;i<dimension;i++){
		a[i] = dimension-i;	  //Llenado del arreglo de mayor a menor
	}
	
	correrContador();	      //inicio del contador de milisegundos
	
	Shell(a,dimension);   //ordenamiento por seleccion

	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;	//fin del contador
	
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



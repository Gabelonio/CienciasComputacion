/*
Programa para realizar la organizacion de un arreglo de enteros
METODO POR RADIX (Numeros de 5 digitos)
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

struct nodoBase
{
	int numero;
	struct nodoBase *siguiente;
};

void ordenRadix(int a[], int dimension){
	int i,j;
	nodoBase *cubetas[5][10];
	nodoBase *nodoAux;
	int descomponedor = 10;
	int residuo;
	/*
	*	Inicializa todas los arreglos de listas a realizar
	*/
	for(i=0;i<5;i++){
		for(j=0;j<10;j++){
			cubetas[i][j] = NULL;
		}
	}
	/*
	* Realización de la primer cubeta
	*/
	for(j=0;j<dimension;j++){
		residuo = a[j]%10;
		nodoAux = new nodoBase;
		nodoAux->numero = a[j];
		nodoAux->siguiente = NULL;

		nodoBase *ptr = cubetas[0][residuo];

		if(cubetas[0][residuo] == NULL){
			cubetas[0][residuo] = nodoAux;
		}
		else{
			while(ptr->siguiente != NULL){
				ptr = ptr->siguiente;
			}
			ptr->siguiente = nodoAux;
		}
	}
	/*
	* Formación y ordenamiento de las cubetas restantes
	*/
	for(i = 1;i<5;i++){
		nodoAux = NULL ;
		descomponedor*=10;
		for(j=0;j<10;j++){
			while(cubetas[i-1][j]!=NULL){

				residuo = ((cubetas[i-1][j]->numero)%descomponedor)/(descomponedor/10);

				nodoAux = new nodoBase;
				nodoAux->numero = cubetas[i-1][j]->numero;

				nodoAux->siguiente = NULL;

				nodoBase *ptr = cubetas[i][residuo];

				if(cubetas[i][residuo] == NULL){
					cubetas[i][residuo] = nodoAux;
				}
				else{
					while(ptr->siguiente != NULL){
						ptr = ptr->siguiente;
					}
					ptr->siguiente = nodoAux;
				}

				cubetas[i-1][j] = cubetas[i-1][j]->siguiente;
			}
		}
	}

	int contador = 0;
	for(i = 0; i<10 ;i++){
		while(cubetas[4][i]!=NULL){
			a[contador]=cubetas[4][i]->numero;
			cubetas[4][i] = cubetas[4][i]->siguiente;
			contador++;
		}
	}

}

int main(){

	srand(time(NULL));
	int dimension,i;

	cin>>dimension;

	int a[dimension]; 		  //Creacion del arreglo a ordenar

	for(i=0;i<dimension;i++){
		a[i] = rand()%100000;	  //Llenado del arreglo de mayor a menor
  	}

  	for(i=0;i<dimension;i++){
  	  cout<<a[i]<<" ";
  	}
	cout<<endl<<endl;

	correrContador();
	
	ordenRadix(a,dimension);   //ordenamiento por seleccion

	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;	//fin del contador
	/*
	*	Impresion del arreglo
	*/

	for(i=0;i<dimension;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;

}

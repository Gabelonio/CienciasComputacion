/*
Programa para realizar la organizacion de un arreglo de enteros
METODO MERGE (a partir de ejercicio visto en Udin) 
Gabriel Esteban Castillo Ramirez
Esteban Quintero Amaya
17-05-2019
*/
#include <iostream>
#include <time.h>

using namespace std;

void MergeListas(int arreglo[], int inicioUno, int finUno, int inicioDos, int finDos){

	int inicioFinal = inicioUno;
	int finFinal = finDos;
	int indiceC = 0;
	int resultado[finFinal-inicioFinal];

	while((inicioUno<=finUno) && (inicioDos<=finDos) ){

		if(arreglo[inicioUno] < arreglo[inicioDos]){
			resultado[indiceC] = arreglo[inicioUno];
			inicioUno+=1;
		}
		else{
			resultado[indiceC] = arreglo[inicioDos];
			inicioDos+=1;
		}
		indiceC+=1;
	}

	if(inicioUno<=finUno){
		for(int i=inicioUno;i<=finUno;i++){
			resultado[indiceC] = arreglo[i];
			indiceC+=1;
		}
	}
	else{
		for(int i=inicioDos;i<=finDos;i++){
			resultado[indiceC] = arreglo[i];
			indiceC+=1;
		}
	}

	indiceC = 0;
	for(int i=inicioFinal;i<=finFinal;i++){
		arreglo[i] = resultado[indiceC];
		indiceC+=1;
	}

}
void Merge(int arreglo[], int primero, int ultimo){

	int mitad;

	if (primero < ultimo){
			 mitad = ( primero + ultimo ) / 2;
			 Merge( arreglo, primero, mitad );
			 Merge( arreglo, mitad + 1, ultimo );
			 MergeListas( arreglo, primero, mitad, mitad+1, ultimo);
	}
}

int main(){

	int dimension,i;

	cin>>dimension;

	int a[dimension]; 		  //Creacion del arreglo a ordenar

	for(i=0;i<dimension;i++){
		a[i] = dimension-i;	  //Llenado del arreglo de mayor a menor
	}

	Merge(a,0,dimension-1);   //ordenamiento por seleccion

	/*
	*	Impresion del arreglo
	*/

	for(i=0;i<dimension;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;

}

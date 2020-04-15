/*
Programa para realizar la suma de dos matrices
Gabriel Esteban Castillo Ramirez
03-05-2019
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

int **sumarMatrices(int **arregloUno, int **arregloDos, int filas,  int columnas){

	int **matrizResultado = new int*[filas];

	for(int i=0; i<filas; i++){
		
		matrizResultado[i] = new int[columnas];
		
		for(int j=0; j<columnas;j++){
			
			matrizResultado[i][j] = arregloUno[i][j]+arregloDos[i][j];	//Suma de cada elemento		
		}		
	}
	
	return matrizResultado; 		
}

int main(){

	int dimensionFilas,dimensionColumnas;
	
	cout<<"No.Filas: ";
	cin>>dimensionFilas;
	cout<<endl<<"No. Columnas: ";
	cin>>dimensionColumnas; 
	
	int **matrizUno = new int*[dimensionFilas];
	int **matrizDos = new int*[dimensionFilas];
	
	/*
	*	llenado de matrices
	*/
	for(int i=0;i<dimensionFilas;i++){
		
		matrizUno[i] = new int[dimensionColumnas];
		matrizDos[i] = new int[dimensionColumnas];
		
		for(int j=0;j<dimensionColumnas; j++){
			matrizUno[i][j] = i+j+1;
			matrizDos[i][j] = i+j+1;			
		}		
	}
	/*
	*	Impresión de matrices A y B
	*/
	for(int i=0;i<dimensionFilas;i++){
					
		for(int j=0;j<dimensionColumnas; j++){
			cout<<matrizUno[i][j]<<" "; 			
		}		
		cout<<endl; 
	}	
	
	for(int i=0;i<dimensionFilas;i++){
					
		for(int j=0;j<dimensionColumnas; j++){
			cout<<matrizDos[i][j]<<" ";			
		}
		cout<<endl; 		
	}	
	
	correrContador();
	
	int **matrizResultante = sumarMatrices(matrizUno,matrizDos,dimensionFilas,dimensionColumnas);
	
	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;	
	
	for(int i=0;i<dimensionFilas;i++){
			
		for(int j=0;j<dimensionColumnas; j++){
			cout<<matrizResultante[i][j]<<" ";			
		}		
		cout<<endl; 
	}

	system("pause");
	return 0;

}



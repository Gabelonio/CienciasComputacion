/*
Programa para realizar la multiplicacion de dos matrices
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

int **multiplicarMatrices(int **arregloUno, int **arregloDos, int filas,  int columnas){

	int **matrizResultado = new int*[filas];
	int suma = 0; 
	
	for(int i=0; i<filas; i++){ 				//Avance en filas
	
		matrizResultado[i] = new int[filas];	
		
		for(int j=0; j<filas;j++){				//Avance en columnas
			suma = 0;
			for(int k=0; k<columnas; k++){
				suma += arregloUno[i][k]*arregloDos[k][j];	//Multipliación por elementos y suma
			}
			matrizResultado[i][j] = suma;		
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
	
	/*
	*	Declaracion de matrices A=M*N / B=N*M
	*/
	int **matrizUno = new int*[dimensionFilas];
	int **matrizDos = new int*[dimensionColumnas];
	
	for(int i=0;i<dimensionFilas;i++)		
		matrizUno[i] = new int[dimensionColumnas];
	
	for(int i=0;i<dimensionColumnas;i++)				
		matrizDos[i] = new int[dimensionFilas];	
	
	/*
	*	Llenado de matrices
	*/
	for(int i=0;i<dimensionFilas;i++){
					
		for(int j=0;j<dimensionColumnas; j++){
			matrizUno[i][j] = i+j+1;
			matrizDos[j][i] = i+j+1;			
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
			cout<<matrizDos[j][i]<<" ";			
		}
		cout<<endl; 		
	}	
	
	correrContador();
	
	int **matrizResultante = multiplicarMatrices(matrizUno,matrizDos,dimensionFilas,dimensionColumnas);
	
	cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl;	

	for(int i=0;i<dimensionFilas;i++){
			
		for(int j=0;j<dimensionFilas; j++){
			cout<<matrizResultante[i][j]<<" ";			
		}		
		cout<<endl; 
	}

	system("pause");
	return 0;

}


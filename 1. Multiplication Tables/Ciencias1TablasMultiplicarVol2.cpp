/*
Programa para mostrar las tablas de multiplicar de n-1 No.2
Gabriel Esteban Castillo Ramirez
22-04-2019
*/
#include <iostream>

using namespace std; 

int main(){

	int n,i,j,sumadorBytes;
	int **a;
	/*
		Suma de los espacios de memoria en bytes para:
		Variables enteras
		Apuntador para enteros
	*/
	sumadorBytes = sizeof(i)+sizeof(j)+sizeof(n)+sizeof(**a);
	cin>>n;
	a=new int *[n];
	
	for(i=0;i<n;i++){
		
		a[i] = new int[n];
		//Suma de cada memoria en bytes por índice de apuntadores en el arreglo a
		sumadorBytes+= sizeof(a[i]);
		
		for(j=0;j<n;j++){
			
			a[i][j]=i*j;
			//Suma de cada memoria en bytes por subíndice de enteros en la matriz a
			sumadorBytes+= sizeof(a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			
			cout<<a[i][j];
		}
		
		cout<<endl;
		delete a[i];
	} 
	
	delete []a;
	cout<<endl<<"se han usado "<<sumadorBytes<<" bytes de memoria"<<endl;

	system("pause");
	return 0;
}

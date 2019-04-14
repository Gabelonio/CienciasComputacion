/*
Programa para mostrar las tablas de multiplicar de n-1
Gabriel Esteban Castillo Ramirez
22-04-2019
*/
#include <iostream>

using namespace std; 

int main(){

	int n,i,j,sumadorBytes;
	int *a;
	/*
		Suma de los espacios de memoria en bytes para:
		Variables enteras
		Apuntador para enteros
	*/
	sumadorBytes = sizeof(i)+sizeof(j)+sizeof(n)+sizeof(*a);
	cin>>n;
	
	for(i=0;i<n;i++){
		
		a = new int[n];
		
		for(j=0;j<n;j++){
			
			a[j]=j*i;
			cout<<a[j];
			//Suma de cada índice en el arreglo a
			sumadorBytes+= sizeof(a[j]);
		}
		
		cout<<endl; 
		delete []a;
	}
	
	cout<<endl<<"Se han usado "<<sumadorBytes<<" bytes de memoria"<<endl;

	system("pause");
	return 0;
}

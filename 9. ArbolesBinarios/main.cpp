#include <iostream>
#include "Binario.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
	Proyecto Manejo de arboles binarios
	Nombres:
			Gabriel Esteban Castillo Ramírez - 20171020021
			Esteban Quintero Amaya -20171020022
*/
 
int main(int argc, char** argv) { 
	int tam;
	
	cout<<"Bienvenido!"<<endl<<"Ingrese el tamaño del arreglo"<<endl;
	cin>>tam;
	cout<<endl;
	Binario listBin(tam);
	do{
		cout<<"Ingrese"<<endl;
		cout<<"1. Para ingresar un nuevo numero"<<endl;
		cout<<"2. Para eliminar un numero"<<endl;
		cout<<"3. Para buscar un numero"<<endl;
		cout<<"4. Para imprimir InOrden"<<endl;
		cout<<"5. Para imprimir PosOrden"<<endl;
		cout<<"6. Para imprimir PreOrden"<<endl;
		cout<<"7. Para imprimir Orden por Niveles"<<endl;
		cout<<"8. Para salir"<<endl; 
		cin>>tam;
		switch(tam){     
			case 1:{
				cout<<"Ingrese el numero"<<endl;
				cin>>tam;
				listBin.insertar(tam);
				/*
				listBin.insertar(100);   
				listBin.insertar(50);
				listBin.insertar(150);				
				listBin.insertar(30);
				listBin.insertar(75);  
				listBin.insertar(125);
				listBin.insertar(170);
				listBin.insertar(10);  
				listBin.insertar(60);
				listBin.insertar(90);
				listBin.insertar(140);  
				listBin.insertar(160);
				listBin.insertar(180);
				*/
				break;
			}
			case 2:{
				cout<<"Ingrese el numero a eliminar"<<endl;
				cin>>tam;
				listBin.eliminar(tam);
				break;
			}
			case 3:{
				cout<<"Ingrese el numero a buscar"<<endl;
				cin>>tam;
				listBin.buscar(tam);
				break;  
			}
			case 4:{
				listBin.inOrden(); 
				break;
			}
			case 5:{
				listBin.posOrden();   
				break;
			}
			case 6:{
				listBin.preOrden(); 
				break;
			}
			case 7:{
				listBin.nivelOrden();
				break;
			}
			case 8:{
				cout<<"Programa Finalizado"<<endl; 
				break;
			}
			default:{
				break;
			}
		}
		system("pause");  
		system("cls");
	}while(tam!=8);
	
	system("pause");
	return 0;
}  

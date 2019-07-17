#include <iostream>
#include <cstdlib>
/*

	Colas Prioritarias
	
	Esteban Quintero Amaya 20171020022
	Gabriel Castillo Ramirez 20171020021

*/

#include <vector>
#include <iterator>
#include "colap.h"
using namespace std;

int main()
{
    BinaryHeap<int> h;
    while (1)
    {
    	cout<<"\nCOLAS PRIORITARIAS\n"<<endl;
    	cout<<"Que deseas hacer?\n"<<endl;
        cout<<"1. Insertar un nuevo nodo"<<endl;
        cout<<"2. Imprimir la cola prioritaria"<<endl;
        cout<<"3. Atender cola"<<endl;
        cout<<"4. Salir\n"<<endl;
        int choice, element;
        cout<<"Ingresa una opcion: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        	
            cout<<"\nIngresa el dato: ";
            cin>>element;
            h.Insert(element);
            break;
        case 2:
            cout<<"\nImprimiento Cola Prioritaria:  ";
            h.DisplayHeap();
            break;
        case 3:
            cout<<"\nAtender: ";
            h.DeleteMin();
            break;
        case 4:
            exit(1);
        default:
            cout<<"\nOpcion Incorrecta"<<endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

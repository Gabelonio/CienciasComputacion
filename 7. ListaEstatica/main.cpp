/*
	Nombres: 
	Gabriel Esteban Castillo Ramirez - 20171020021
	Arley Esteban Quintero Amaya - 20171020022
*/
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include "Multilista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string retornarCarrera(int opc){
	switch(opc){
		case 1:{
			return "Electronica";
			break; 
		}
		case 2:{
			return "Industrial";
			break;
		}
		case 3:{
			return "Sistemas";
			break;
		}
		case 4:{
			return "Catastral";
			break;
		}
	}
}

string retornarHobby(int opc){
	switch(opc){
		case 1:{
			return "Danza";
			break; 
		}
		case 2:{
			return "Natacion";
			break;
		}
		case 3:{
			return "Basquet";
			break;
		}
		case 4:{
			return "Beisbol";
			break;
		}
	}
}
int main(int argc, char** argv) {
	int menu,submenu;
	int c;
	cout<<"Ingrese la cantidad de estudiantes"<<endl;
	cin>>c;
	Multilista central(10,c);
	          
	string nombres[] = {"Nombre","Electronica","Industrial","Sistemas","Catastral",
						"Danza","Natacion","Basquet","Beisbol","Edad"};
	central.initCabeceras(nombres);  
	estudiante *e = new estudiante;
	const size_t BUFFER_SIZE = 1024;
	char *nombre = new char[BUFFER_SIZE];
	estudiante *nuevo = new estudiante;
	nombre =  new char[BUFFER_SIZE];
	
	do{
		cout << "MENU" << endl;
		cout << "1. Ingresar un nuevo estudiante " << endl;
		cout << "2. Mostrar por nombre " << endl;
		cout << "3. Mostrar por edad " << endl;
		cout << "4. Mostrar por hobby " << endl;
		cout << "5. Mostrar por carrera " << endl;
		cout << "6. Borrar Registro " << endl;
		cout << "7. Buscar Registro " << endl;
		cout << "8. Salir " << endl;
		cin>>menu; 
		switch (menu){
			case 1:{
			
				cout<< "Inserte el nombre"<<endl;
				if(!central.isListaLlena()){
					char *nombre = new char[BUFFER_SIZE];
					nombre =  new char[BUFFER_SIZE];
					cout<< "Nombre: ";
					cin >> nombre;
					nuevo->nombre = nombre;
					cout<<endl<< "Edad: " ;
					cin >> menu;
					nuevo->edad = menu;
					cout<<endl<<" Carrera: ";
					cout<<endl<<"1. Electronica ";
					cout<<endl<<"2. Industrial";
					cout<<endl<<"3. Sistemas";
					cout<<endl<<"4. Catastral";
					cin>>menu;
					nuevo->carrera = retornarCarrera(menu);
					cout<<endl<<" Hobby: ";
					cout<<endl<<"1. Danza ";
					cout<<endl<<"2. Natacion";
					cout<<endl<<"3. Basquet";
					cout<<endl<<"4. Beisbol";
					cin >> menu;
					nuevo->hobby = retornarHobby(menu);
					central.insertarEstudiante(nuevo); 	
				}
				else{
					cout<<"Registro lleno, no se puede colocar mas registros"<<endl; 
				}
							  
				 /*  
				nuevo->nombre = "Raquel";
				nuevo->carrera = "Electronica";
				nuevo->hobby = "Danza";
				nuevo->edad = 23;  
				central.insertarEstudiante(nuevo);
				nuevo->nombre = "Jaime";
				nuevo->carrera = "Industrial";
				nuevo->hobby = "Natacion";
				nuevo->edad = 16;
				central.insertarEstudiante(nuevo);
				nuevo->nombre = "Arturo";
				nuevo->carrera = "Electronica";
				nuevo->hobby = "Basquet";
				nuevo->edad = 18;				
				central.insertarEstudiante(nuevo);			
				nuevo->nombre = "Andres";
				nuevo->carrera = "Catastral";
				nuevo->hobby = "Danza";
				nuevo->edad = 19;
				central.insertarEstudiante(nuevo);			
				nuevo->nombre = "Ariana";
				nuevo->carrera = "Sistemas"; 
				nuevo->hobby = "Basquet";
				nuevo->edad = 24;				           
				central.insertarEstudiante(nuevo);				
				nuevo->nombre = "Juanny";
				nuevo->carrera = "Industrial";
				nuevo->hobby = "Natacion";
				nuevo->edad = 20;
				central.insertarEstudiante(nuevo);  
				/* 
				nuevo->nombre = "MaryPaz";
				nuevo->carrera = "Sistemas";
				nuevo->hobby = "Danza";
				nuevo->edad = 19;
				central.insertarEstudiante(nuevo);		
				nuevo->nombre = "Italia";
				nuevo->carrera = "Catastral";
				nuevo->hobby = "Beisbol";
				nuevo->edad = 17;
				central.insertarEstudiante(nuevo);  
				nuevo->nombre = "Mario";
				nuevo->carrera = "Sistemas";
				nuevo->hobby = "Basquet";
				nuevo->edad = 21;
				central.insertarEstudiante(nuevo);  
				nuevo->nombre = "Pilar";
				nuevo->carrera = "Sistemas";
				nuevo->hobby = "Beisbol";
				nuevo->edad = 22;
				central.insertarEstudiante(nuevo); 
				*/
				break;
			}   
			case 2:{
				central.mostarEstudiantes(0);
				break;   
			}    
			case 3:{
				central.mostarEstudiantes(9);
				break;       
			}
			case 4:{
				cout<<" Ingrese el Hobby: "<<endl;
				cout<<"1. Danza " << endl;
				cout<<"2. Natacion " << endl;
				cout<<"3. Basquet " << endl;
				cout<<"4. Besibol" << endl;
				cout<<"0. Volver " << endl;
				cin>>menu;
				if(menu==0||menu<1||menu>4)
					break;    
				else  
					central.mostarEstudiantes(menu+4);
				break;
			}
			case 5:{
				cout<<" Ingrese la Carrera: "<<endl;
				cout<<"1. Electronica" << endl;
				cout<<"2. Industrial" << endl;
				cout<<"3. Sistemas" << endl;
				cout<<"4. Catastral" << endl;
				cout<<"0. Volver" << endl;
				cin>>menu;
				if(menu==0||menu<1||menu>4)
					break; 
				else        
					central.mostarEstudiantes(menu);
				break; 
			}
			case 6:{ 
				cout<<"Inserte el nombre del estudiante a eliminar: "<<endl;
				cin>>nombre;
				central.eliminarEstudiante(nombre);      
				break;
			} 
			case 7:{
				cout<<"Inserte el nombre del estudiante a buscar: "<<endl;
				cin>>nombre;
				central.buscarEstudiante(nombre);                  
				break;
			}
			case 8:{
				cout<<"Programa Finalizado!"<<endl;
				break;
			}
			default:{ 
			
				break; 
			}  
		}
		system("pause");
		system("cls");
	}while(menu!=8);
	return 0;
}   


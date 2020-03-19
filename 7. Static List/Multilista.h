/*
	Nombres: 
	Gabriel Esteban Castillo Ramirez - 20171020021
	Arley Esteban Quintero Amaya - 20171020022
*/
#ifndef MULTILISTA_H
#define MULTILISTA_H
#include <stddef.h>
#include <string.h>
using namespace std;

struct cabeza{
	string nombre; 
	int cab; 
};	//Definimos el nodo cabecera de nuestra lista

struct estudiante{
	int edad;
	char* nombre;
	string carrera, hobby;
	int sigNom, sigCar, sigHob, sigEdad;
};	 //Definimos el nodo estudiante de nuestra lista

class Multilista
{
	//Lista de cabezas por caracteristica
	cabeza *cabezas;
	//Cabeza de Lista de datos recibidos
	estudiante *est;
	
	int tamCab;
	int tamEst, posActual; 
	
	public:
		Multilista(int numCab, int numDatos){
			cabezas = new cabeza[numCab];
			est = new estudiante[numDatos];
			
			tamCab = numCab;
			tamEst = numDatos;
			for(int cont=0;cont<tamEst;cont++){
				est[cont].nombre = "";
				est[cont].carrera = "";
				est[cont].hobby = "";
				est[cont].edad = -1;
				est[cont].sigNom = -1; 
				est[cont].sigCar = -1;
				est[cont].sigHob = -1;
				est[cont].sigEdad = -1;				
			}
			posActual = 0; 
		}	//El constructor de nuestra Multilista
		/*
			Definicion de funciones
		*/
		/* Asignar los nombres de las cabeceras
		*/  
		void initCabeceras(string nombres[]){
			for(int i=0; i<tamCab; i++){
				cabezas[i].nombre = nombres[i];
				cabezas[i].cab = 0; 
			}
		}
		/* Agregar estudiante a Lista
		*/
		bool isListaLlena(){
			return posActual >= tamEst; 
		}
		bool isListaVacia(){
			return posActual == 0;
		}
		
		estudiante* buscar(int pos){
			int contador;
			contador = 0;
			estudiante *aux;
			if(pos == 0 || pos>tamEst){ 
				return NULL;
			}
			while(contador < pos && aux!=NULL){
				aux = &est[contador];
				contador++;
			}
			return aux;
		}
		/* Inserción de estudiante nuevo
		*/
		
		void insertarEstudiante(estudiante *insert){
			//Si la Lista de datos no esta vacio
			cout<<"Registro Exitoso!"<<endl;
			if(!isListaVacia()){
				crearSigNom(insert);
				crearSigCarr(insert);
				crearSigHob(insert);
				crearSigEdad(insert);
				
			}	
			//Si no tiene ni un elemento
			else{
				insert->sigEdad = 0;
				insert->sigNom = 0;
				//Agregar a lista de cabezas
				crearSigHob(insert);	//Hobby
				crearSigCarr(insert);	//Carrera
				
				cabezas[0].cab = posActual+1;	//Nombre
				cabezas[9].cab = posActual+1;	//Edad
			}
			//Agregar a lista de datos
			est[posActual] = *insert; 	
			posActual++;				
		}
			
		void crearSigNom(estudiante *e){
			estudiante *aux = e;
			estudiante *ref1,*ref2;
			
			int buscador = 0;
			
			
			ref1 = buscar(cabezas[0].cab);
			ref2 = ref1;
			//el nombre a comparar es menor al menor de la lista
			if(strcmp(aux->nombre,ref1->nombre) < 0){
				aux->sigNom = cabezas[0].cab;
				cabezas[0].cab = posActual+1;
			}
			//el nombre a comparar es mayor al menor de la lista
			else{
				//mientras los nombres sean menores al nombre a comparar, recorrer 
				while(ref1->sigNom !=0){
					ref2 = ref1;
					ref1 = buscar(ref1->sigNom);
					if(!(strcmp(ref1->nombre,aux->nombre) < 0)){
						break; 
					}				
				}
				aux->sigNom = ref2->sigNom;
				ref2->sigNom = posActual+1;
			}
				
		}
		void crearSigCarr(estudiante *e){
			int refCar;
			if(e->carrera.compare("Electronica")==0){
				refCar = 1;
			}
			if(e->carrera.compare("Industrial")==0){
				refCar = 2;
			}
			if(e->carrera.compare("Sistemas")==0){
				refCar = 3;
			}
			if(e->carrera.compare("Catastral")==0){
				refCar = 4;
			}
			//La cabecera de carrera esta vacia, se introduce el primer nodo
			if(cabezas[refCar].cab == 0){
				cabezas[refCar].cab = posActual+1; 
				e->sigCar = 0;
			}
			else{
				estudiante *aux;
				aux = buscar(cabezas[refCar].cab);
				while(aux->sigCar !=0){
					aux = buscar(aux->sigCar);
				}
				aux->sigCar = posActual+1; 
				e->sigCar = 0;
			}		
		}
		void crearSigHob(estudiante *e){
			int refHob;
			if((e->hobby.compare("Danza"))==0){
				refHob = 5;
			}
			if((e->hobby.compare("Natacion"))==0){
				refHob = 6;
			}
			if((e->hobby.compare("Basquet"))==0){
				refHob = 7;
			}
			if((e->hobby.compare("Beisbol"))==0){
				refHob = 8;
			}
			//La cabecera de carrera esta vacia, se introduce el primer nodo
			if(cabezas[refHob].cab == 0){
				cabezas[refHob].cab = posActual+1; 
				e->sigHob = 0;
			}
			else{
				estudiante *aux;
				aux = buscar(cabezas[refHob].cab);
				while(aux->sigHob !=0){
					aux = buscar(aux->sigHob);
				}
				aux->sigHob = posActual+1;
				e->sigHob = 0;
			}
			
		}
		
		void crearSigEdad(estudiante *e){
			estudiante *aux = e;
			estudiante *ref1,*ref2;
			int buscador = 0;

			
			ref1 = buscar(cabezas[9].cab);
			ref2 = ref1;
			//la edad a comparar es mayor a la cabeza
			if(ref1->edad < aux->edad){
				aux->sigEdad = cabezas[9].cab;
				cabezas[9].cab = posActual+1;
			}
			//la edad a comparar no es mayor a la cabeza
			else{
				//mientras las edades sean mayores a la edad a comparar, recorrer 				
				while(ref1->sigEdad !=0){
					ref2 = ref1;
					ref1 = buscar(ref1->sigEdad);
					if(!(ref1->edad > aux->edad)){
						break; 
					}				
				}
				aux->sigEdad = ref2->sigEdad;
				ref2->sigEdad = posActual+1;
			}
		}
		void buscarEstudiante(char *busqueda){
			estudiante aux = est[0];  
			int cont = 0;
			//Recorre el arreglo Estudiantes hasta encontrar el nombre con la busqueda
			while(cont < tamEst){
				if(strcmp(est[cont].nombre,busqueda) == 0 || cont == tamEst-1)
					break;
				aux = est[cont+1];
				cont++;
			}
			//No se ha encontrado el registro con ese nombre ¡
			if(cont == tamEst-1)
				cout<<"Nombre no Encontrado"<<endl;
			else{
				estudiante *aux;
				aux = &est[cont];
				cout<<"PERFIL DEL ESTUDIANTE"<<endl;
				cout<<"Nombre: "<<aux->nombre;
				cout<<"  "<<"Carrera: "<<aux->carrera;
				cout<<"  "<<"Hobby: "<<aux->hobby;
				cout<<"  "<<"Edad: "<<aux->edad;
				cout<<endl;
		 	}
		}
		void eliminarEstudiante(char *busqueda){
			estudiante aux = est[0];  
			int cont = 0;
			//Recorre el arreglo Estudiantes hasta encontrar el nombre con la busqueda
			while(cont < tamEst){
				if(strcmp(est[cont].nombre,busqueda) == 0 || cont == tamEst-1)
					break;
				aux = est[cont+1];
				cont++;
			}
			//No se ha encontrado el registro con ese nombre ¡
			if(cont == tamEst-1)
				cout<<"Nombre no Encontrado"<<endl;
			else{
				int buscador = 0;
				//Cambiando el siguiente Nombre del anterior que contenia al Registro encontrado
				if(cabezas[0].cab == cont+1){
					cabezas[0].cab = est[cont].sigNom;
				}
				else{
					for(buscador;buscador < tamEst; buscador++){
						if(est[buscador].sigNom == cont+1){
							est[buscador].sigNom = est[cont].sigNom;
							break;
						}
					}	
				}
				//Cambiando el siguiente Carrera del anterior que contenia al Registro encontrado
				bool isCabeza = false;
				for(int c=1;c<5;c++){
					if(cabezas[c].cab == cont+1){
						cabezas[c].cab = est[cont].sigCar;
						isCabeza = true;
						break; 
					}
				}
				if(!isCabeza){				
					buscador = 0;
					for(buscador;buscador < tamEst; buscador++){
						if(est[buscador].sigCar == cont+1){
							est[buscador].sigCar = est[cont].sigCar;
							break;
						}
					}
				}
				//Cambiando el siguiente Hobby del anterior que contenia al Registro encontrado
				isCabeza = false;
				for(int c=5;c<9;c++){
					if(cabezas[c].cab == cont+1){
						cabezas[c].cab = est[cont].sigHob;
						isCabeza= true;
						break; 
					}
				}
				if(!isCabeza){
					buscador = 0;
					for(buscador;buscador < tamEst; buscador++){
						if(est[buscador].sigHob == cont+1){
							est[buscador].sigHob = est[cont].sigHob;
							break;
						}
					}
				}
				//Cambiando el siguiente Edad del anterior que contenia al Registro encontrado
				if(cabezas[9].cab == cont+1){
					cabezas[9].cab = est[cont].sigEdad;
				}
				else{
					buscador = 0;
					for(buscador;buscador < tamEst; buscador++){
						if(est[buscador].sigEdad == cont+1){
							est[buscador].sigEdad = est[cont].sigEdad;
							break;
						}
					}	
				}
				cout<<"Estudiante Eliminado"<<endl;
				
				est[cont].nombre = "";
				est[cont].carrera = "";
				est[cont].hobby = "";
				est[cont].edad = -1;
				est[cont].sigNom = -1;
				est[cont].sigCar = -1;
				est[cont].sigHob = -1;
				est[cont].sigEdad = -1;
				
			}
		}

		
		void mostarEstudiantes(int cabeza){
			estudiante *aux = buscar(cabezas[cabeza].cab);
			cout<<"LISTA DE ESTUDIANTES"<<endl<<endl;
			while(aux!=NULL){
				cout<<"Nombre: "<<aux->nombre;
				cout<<"  "<<"Carrera: "<<aux->carrera;
				cout<<"  "<<"Hobby: "<<aux->hobby;
				cout<<"  "<<"Edad: "<<aux->edad;
				cout<<endl;
				if(cabeza == 0)
					aux = buscar(aux->sigNom);
				else if(cabeza == 9)
					aux = buscar(aux->sigEdad);
				else if(cabeza>=1 && cabeza<=4)
					aux = buscar(aux->sigCar);
				else
					aux = buscar(aux->sigHob);
			}
			cout<<"========================================================================="<<endl;
		}
		
	protected:
};

#endif

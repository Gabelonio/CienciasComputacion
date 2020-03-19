#ifndef LISTA_H
#define LISTA_H
#include <stddef.h>

template <class T>
struct nodo{
	T dato;
	nodo<T> *sig;
};					 //Definimos el nodo predeterminado de nuestra lista

template <class T>
class Lista
{
	nodo<T> *cabeza; //Definimos la cabeza de la lista 
	int tamanio;
	public:
		Lista(){
			cabeza =NULL;
			tamanio = 0; 
		}			//El constructor de nuestra lista
		/*
			Definicion de funciones
		*/
		/* Inserción de nodos
		*/
		void insertar_Final(T info){
			int contador = 0;
			
			nodo <T> *aux, *nuevo;
			
			nuevo= new nodo <T>;
			nuevo->dato=info;
			nuevo->sig= NULL;
			
			aux = cabeza;
			while(contador<tamanio && aux->sig!=NULL){
				aux = aux->sig;
				contador++; 
			}
			if(tamanio==0){ cabeza = nuevo;}
			else{ aux->sig = nuevo; }
		}
		void insertar_Inicio(T info){
			nodo <T> *nuevo;
			nuevo= new nodo <T>;
			nuevo->dato = info;
			nuevo->sig = cabeza;
			cabeza = nuevo;
		}
		void insertar_nodo(int pos, T info){
			
			/*
			* Inserción por final
			*/
			if(pos>tamanio){
				insertar_Final(info);
			}
			else{
				/*
				*	Inserción por inicio
				*/
				if(pos==1){
					insertar_Inicio(info);
				}
				/*
				*	Inserción por mitad
				*/
				else{
					nodo<T> *nuevo;
					nuevo = new nodo<T>;
					nuevo->dato = info;	
					int contador; 
					nodo <T> *aux;
					aux = cabeza;		
					contador = 1;
					
					while(contador < pos-1 && aux!=NULL){
						aux = aux->sig;
						contador++;
					}
					nuevo->sig = aux->sig;
					aux->sig = nuevo;				
				}
			}
			tamanio++;
		}
		/* Eliminación de nodos
		*/
		void borrar_Inicio(){
			nodo<T> *aux;
			aux = cabeza;
			cabeza = cabeza->sig;
			delete aux;
		}
		void borrar_Final(){
			nodo <T> *aux;//creando un nodo
			if(tamanio!=0){
				aux = cabeza;
				int i;
				for (i=1;i<tamanio-1; i++)
					aux=aux->sig;
				delete aux; 
			}
		}
		void borrar_nodo(int pos){
			/* 	Inicializacion del nodo auxiliar
			*/
			nodo <T> *aux;
			aux = cabeza;
			if(pos>tamanio){
				borrar_Final();
			}
			else{
				/*
				* 	Eliminación por inicio
				*/
				if(pos==1){
					borrar_Inicio();
				}
				/*
				*	Eliminación por mitad
				*/
				else{
					int contador;	
					contador = 1;
					while(contador < pos-1 && aux!=NULL){
						aux = aux->sig;
						contador++;
					}
					nodo <T> *pivot;
					pivot = aux->sig;
					aux->sig = pivot->sig;
					delete pivot;				
				}
			}
			tamanio--;
		}
		/* Busqueda de nodo
		*/
		T buscar(int pos){
			int contador;
			contador = 1;
			nodo <T> *aux;
			aux = cabeza;
			if(pos>tamanio)
				pos = tamanio;
			while(contador<pos && aux!=NULL){
				aux = aux->sig;
				contador++;
			}
			return aux->dato;
		}
		/* Modificación de un nodo
		*/
		void cambiar(int pos, T info){
			int contador;
			contador = 1;
			nodo <T> *aux;
			aux = cabeza;
			if(pos>tamanio)
				pos = tamanio;
			while(contador<pos && aux!=NULL){
				aux = aux->sig;
				contador++;
			}
			aux->dato = info;
		}
		int getTam(){
			return tamanio;
		}
	protected:
};

#endif

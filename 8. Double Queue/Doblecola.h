/*
	Proyecto Manejo de colas dobles.
	Nombres:
			Gabriel Esteban Castillo Ramírez - 20171020021
			Esteban Quintero Amaya -20171020022
*/
#ifndef DOBLECOLA_H
#define DOBLECOLA_H
//#include <stddef.h>
#include <iostream>
using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo<T> *sig,*ant;	//Nodo predeterminada para la lista doble
};

template <class T>
class ColaDoble
{
	public: 
   	 		ColaDoble (){
   	 			cIzq = new nodo <T>;
   	 			fIzq = new nodo <T>;
   	 			cDer = new nodo <T>;
   	 			fDer = new nodo <T>;
   	 			cIzq->sig = fIzq->ant = cDer->ant = fDer->sig = NULL;
   	 			tamanio = 0;
			}
			bool isListaVacia();
			void insertar(T dato, char pos);
			T atender(char pos);
			void imprimir(char pos); 
	private:
			nodo <T> *cIzq,*fIzq,*cDer,*fDer;
			int tamanio;  	  	
 };
 
 
template <class T>
bool ColaDoble <T>::isListaVacia(){
	return tamanio == 0;
} 

template <class T>
void ColaDoble <T>::insertar(T info, char pos){
	
	nodo <T> *nuevo;
	nuevo = new nodo <T>;
	nuevo->dato = info; 
	nuevo->sig = NULL; 
	nuevo->ant = nuevo; 
	if(isListaVacia()){ 
		fIzq->ant = nuevo;  
		fDer->sig = cIzq->sig = cDer->ant = nuevo;
		nuevo->ant = nuevo->sig = NULL; 
	}
	else{
		//Insertar por final Derecha el nuevo elemento 
		if(pos == 'D' || pos == 'd'){
			nuevo->ant = NULL;
			nuevo->sig = fDer->sig;
			fDer->sig->ant = nuevo;
			fDer->sig = nuevo;
			cIzq->sig = nuevo; 
		} 
		//Insertar por final Izquierda el nuevo elemento
		if(pos == 'I' || pos == 'i'){
			nuevo->sig = NULL;
			nuevo->ant = fIzq->ant;
			fIzq->ant->sig = nuevo;
			fIzq->ant = nuevo;
			cDer->ant = nuevo; 
		}
	}
	tamanio++; 
}


template <class T>
T ColaDoble <T>::atender(char pos){
	
	T retorno;
	nodo <T> *aux;
	aux = new nodo <T>;
	if(isListaVacia()) {
		cout<<"No hay elementos que atender"<<endl; 
		return 0; 
	}
	else{
		if(tamanio == 1){
			aux = cIzq->sig;
			cIzq->sig = fIzq->ant = cDer->ant = fDer->sig = NULL;		
		}
		else{
			//Atiende por inicio Derecha el nuevo elemento 
			if(pos == 'D' || pos == 'd'){
				aux = cDer->ant;
				cDer->ant = fIzq->ant =aux->ant;
				cDer->ant->sig = NULL;
			} 
			//Atiende por inicio Izquierda el nuevo elemento
			if(pos == 'I' || pos == 'i'){
				aux = cIzq->sig;
				cIzq->sig = fDer->sig =aux->sig;
				cIzq->sig->ant = NULL;			
			}	
		}	
	}
	retorno = aux->dato;
	tamanio--;
	delete aux;
	return retorno; 
}

template <class T>

void ColaDoble <T>::imprimir(char pos){
	nodo <T> *aux; 
	if(isListaVacia()){
		cout<<"No hay elementos que imprimir"<<endl; 
	}
	else{ 
		//Imprime dsde la cabeza derecha
		if(pos == 'D' || pos == 'd'){
			aux = cDer->ant;
			while(aux!=NULL){
				cout<<aux->dato<<" ";
				aux = aux->ant;
			}
		} 
		//Imprime desde la cabeza izquierda
		if(pos == 'I' || pos == 'i'){		
			aux = cIzq->sig; 
			while(aux!=NULL){
				cout<<aux->dato<<" ";
				aux = aux->sig;
			}
		}
	}
	cout<<endl;
}

#endif

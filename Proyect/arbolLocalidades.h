#ifndef ARBOLLOCALIDADES_H_
#define ARBOLLOCALIDADES_H_

#include <string.h>
#include <iostream>
#include "Localidad.h"
#define null 0

using namespace std;

class arbolLocalidades {
	
	Localidad* raiz; 
	
private:
		int altura(Localidad *N);
		int max(int a, int b);
		Localidad* newLocalidad(char* dato, int calleIn, int calleFin, int carrIn, int carrFin);
		Localidad* derRotar(Localidad *y);
		Localidad* izqRotar(Localidad *x);
		int getBalance(Localidad *N);
		Localidad* insert(Localidad* Localidad, char* nombre,int calleIn, int calleFin, int carrIn, int carrFin);
		Localidad* minValorLocalidad(Localidad* Localidad);
		Localidad* deleteLocalidad(Localidad* root, char* nombre);
		void preOrder(Localidad *root); 
		void inOrder(Localidad *root);
		bool localidadExiste(Localidad *nodo,char* busqueda); 
		bool ubicacionExiste(Localidad *nodo,int calle, int carrera);
public:
	arbolLocalidades(){	
		raiz = NULL; 
	}
	void agregarLocalidad(char* nombre,int calleIn, int calleFin, int carrIn, int carrFin);
	void preOrden();
	void inOrden(); 
	bool localidadExiste(char* busqueda);
	bool ubicacionExiste(int calle,int carrera);
}; 

/*
	Funciones para obtener alturas de nodos y valores maximos para realizar comparaciones entre alturas
	Funcion para obtener el balance (diferencia entre alturas para sus ramas)
*/
int arbolLocalidades::altura(Localidad *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->altura;  
}  
 
int arbolLocalidades::max(int a, int b)  
{  
    return (a > b)? a : b;  
}  

int arbolLocalidades::getBalance(Localidad *N)  
{  
    if (N == NULL)  
        return 0;  
    return altura(N->izq) - altura(N->der);  
}
/*
	Verificar que la localidad existe para cuando se realize una busqueda por nombre dentro del arbol
*/
bool arbolLocalidades::localidadExiste(char* busqueda){
	return localidadExiste(raiz,busqueda);
}
bool arbolLocalidades::localidadExiste(Localidad *nodo,char* busqueda){

	if(nodo!=NULL){
		if(strcmp(busqueda,nodo->nombre) == 0){
			return true; 
		}
		else{
			return localidadExiste(nodo->izq,busqueda)||localidadExiste(nodo->der,busqueda);
		}
	}
	return false; 
}
/*
	Funcion para validar las direcciones que puedan ingresarse definidas por una interseccion de calle y carrera
*/
bool arbolLocalidades::ubicacionExiste(int calle, int carrera){
	return ubicacionExiste(raiz,calle,carrera);
}
bool arbolLocalidades::ubicacionExiste(Localidad *nodo,int calle, int carrera){
	if(nodo!=NULL){
		if(nodo->calleInicio > calle && nodo->calleFin < calle && nodo->carreraFin < carrera && nodo->carreraInicio > carrera){
			return true; 
		}
		else{
			return ubicacionExiste(nodo->izq,calle,carrera)||ubicacionExiste(nodo->der,calle,carrera);
		}
	}
	return false;
}
/*
	Funcion de creacion de un nuevo NODO localidad incluyendo sus limites entre calles y carreras	
*/
Localidad* arbolLocalidades::newLocalidad(char* dato, int calleIn, int calleFin, int carrIn, int carrFin)  
{  
    Localidad* localidad = new Localidad(); 
    localidad->nombre = dato; 
	localidad->calleInicio = calleIn;
	localidad->calleFin = calleFin;
	localidad->carreraInicio = carrIn;
	localidad->carreraFin = carrFin;  
    localidad->izq = NULL;  
    localidad->der = NULL;  
    localidad->altura = 1;
    return(localidad);  
}  
/*
	Funcion de insercion de nuevos nodos al arbol AVL, el cual incluye:
	* Validacion de nombres iguales
	* Ordenamiento por nombre
	* Rotaciones necesarias
*/
void arbolLocalidades::agregarLocalidad(char* nombre,int calleIn, int calleFin, int carrIn, int carrFin){
	raiz = insert(raiz, nombre, calleIn, calleFin, carrIn, carrFin);
}

Localidad* arbolLocalidades::insert(Localidad* Localidad, char* nombre,int calleIn, int calleFin, int carrIn, int carrFin){ 
  
 	
   	// Crea el nuevo nodo donde se encuentre vacio 
    if (Localidad == NULL)  
        return newLocalidad(nombre,calleIn,calleFin,carrIn,carrFin);  
    if ((strcmp(nombre,Localidad->nombre) < 0))  
        Localidad->izq = insert(Localidad->izq, nombre,calleIn,calleFin,carrIn,carrFin);  
    else if ((strcmp(nombre,Localidad->nombre) > 0))  
        Localidad->der = insert(Localidad->der, nombre,calleIn,calleFin,carrIn,carrFin);  
    else // Validacion de nombres iguales
        return Localidad;  
  
    //   Obtencion de la altura desde el nodo a crear
    Localidad->altura = 1 + max(altura(Localidad->izq),  
                           altura(Localidad->der));  
  
    /* 
		Obtiene el balance para verificar siempre cuando este se desequilibre  
	*/
    int balance = getBalance(Localidad);  
  
    // Caso rotacion izquierda - izquierda  
    if (balance > 1 && (strcmp(nombre,Localidad->izq->nombre) < 0))  
        return derRotar(Localidad);  
  
    // Caso rotacion derecha - derecha
	if (balance < -1 && (strcmp(nombre,Localidad->der->nombre) > 0))   
        return izqRotar(Localidad);  
  
    // Caso rotacion izquierda - derecha
    if (balance > 1 && (strcmp(nombre,Localidad->izq->nombre) > 0))  
    {  
        Localidad->izq = izqRotar(Localidad->izq);  
        return derRotar(Localidad);  
    }  
  
    // Caso rotacion derecha - izquierda
    if (balance < -1 && (strcmp(nombre,Localidad->der->nombre) < 0))  
    {  
        Localidad->der = derRotar(Localidad->der);  
        return izqRotar(Localidad);  
    }  
  	
    return Localidad;  
}  

/*
	Funciones para realizar las rotaciones necesarias para equilibrar el arbol
*/   
Localidad* arbolLocalidades::derRotar(Localidad *y){  
    Localidad *x = y->izq;  
    Localidad *T2 = x->der;  
  
    // Realizacion de la rotacion  
    x->der = y;  
    y->izq = T2;  
  
    // Actualizando alturas  
    y->altura = max(altura(y->izq),  
                    altura(y->der)) + 1;  
    x->altura = max(altura(x->izq),  
                    altura(x->der)) + 1;  
    return x;  
}  
  
Localidad* arbolLocalidades::izqRotar(Localidad *x)  
{  
    Localidad *y = x->der;  
    Localidad *T2 = y->izq;  
  
    // Realizacion de la rotacion
    y->izq = x;  
    x->der = T2;  
  
    // Actualizando alturas  
    x->altura = max(altura(x->izq),  
                    altura(x->der)) + 1;  
    y->altura = max(altura(y->izq),  
                    altura(y->der)) + 1;  
  
    return y;  
}  



void arbolLocalidades::inOrden(){
	inOrder(raiz);
}

void arbolLocalidades::preOrden(){
	preOrder(raiz);
}


//obtiene el valor de derecha mas a la izquierda
Localidad* arbolLocalidades::minValorLocalidad(Localidad* localidad){  
    Localidad* current = localidad;  
  
    //loop down to find the izqmost leaf 
    while (current->izq != NULL)  
        current = current->izq;  
  
    return current;  
}  
/*
	Funcion para eliminar alguna localidad cuando esta lo requiera
*/  
Localidad* arbolLocalidades::deleteLocalidad(Localidad* root, char* nombre){  
      
    //Si es nulo no elimina nada
    if (root == NULL)  
        return root;  
  
    
    //Realiza busqueda por izquierda puesto que el nombre a buscar es menor al que estamos comparando
    if (strcmp(nombre,root->nombre) < 0) 
        root->izq = deleteLocalidad(root->izq, nombre);  
    //Realiza busqueda por derecha puesto que el nombre a buscar es mayor al que estamos comparando
    else if(strcmp(nombre,root->nombre) > 0)  
        root->der = deleteLocalidad(root->der, nombre);  
    // Cuando encuentra, empieza el proceso de eliminacion
    else{  
        // Eliminacion con uno o sin hijos
        if( (root->izq == NULL) || 
            (root->der == NULL) ){  
            Localidad *temp = root->izq ?  
                         root->izq :  
                         root->der;  
  
            // Sin hijos  
            if (temp == NULL){  
                temp = root;  
                root = NULL;  
            }  
            //Con un hijo 
            else   
            *root = *temp; 
        }  
        else{  
            //Mira el de derecha mas a la izquierda
            Localidad* temp = minValorLocalidad(root->der);  
  
            // copia los hijos y contenido
            root->nombre = temp->nombre;  
  
            // borra al elemento que estaba en derecha mas a la izquierda  
            root->der = deleteLocalidad(root->der,temp->nombre);  
        }  
    }  
  
    if (root == NULL)  
    return root;  
    
    /*
    	Realiza el proceso de equilibrio
    */
    root->altura = 1 + max(altura(root->izq),  
                           altura(root->der));  
  
    
    int balance = getBalance(root);  
  
    if (balance > 1 &&  
        getBalance(root->izq) >= 0)  
        return derRotar(root);  
   
    if (balance > 1 &&  
        getBalance(root->izq) < 0)  
    {  
        root->izq = izqRotar(root->izq);  
        return derRotar(root);  
    }  
  
    if (balance < -1 &&  
        getBalance(root->der) <= 0)  
        return izqRotar(root);  
  
    if (balance < -1 &&  
        getBalance(root->der) > 0)  
    {  
        root->der = derRotar(root->der);  
        return izqRotar(root);  
    }  
  
    return root;  
}  
  
// Funcion para imprimir en orden distintos el arbol
void arbolLocalidades::preOrder(Localidad *root)  
{  
    if(root != NULL)  
    {  
        cout << root->nombre << " ";  
        preOrder(root->izq);  
        preOrder(root->der);  
    }  
}

void arbolLocalidades::inOrder(Localidad *root) {
	if (root != null) {
		this->inOrder(root->izq);
		cout << root->nombre << " ";
		this->inOrder(root->der);
	}

}

#endif 

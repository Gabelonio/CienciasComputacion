/*
Programa: "Problema de las N Reinas usando Backtracking"
Fuente : https://www.thecrazyprogrammer.com/2015/03/c-program-for-n-queens-problem-using-backtracking.html
Gabriel Esteban Castillo Ramirez
Esteban Quintero Amaya
24-05-2019
*/
#include<stdio.h>
#include<math.h>
#include<iostream>
#include <windows.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

int count;

using namespace std; 

void correrContador()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency fallo!\n";

    PCFreq = double(li.QuadPart)/1000.0;  //Obtencion de microsegundos

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double obtenerContador()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

/*funcion para verificar conflictos
Si no hay conflictos para la posicion deseada retorna 1 si no  retorna 0*/
int place(int row,int column,int board[])
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //verificando conflictos diagonales y axiales
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; 
}
 
//funcion para verificar la posicion correcta de la reina
void queen(int row,int n,int board[]) 
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column,board))
  	{y
   		board[row]=column; //si no hay conflictos coloca a la reina
   		if(row==n) 
    	count++; // Suma otra solucion
   	else //intenta con la proxima posicion
    queen(row+1,n,board);
  	}
 }
}
 
int main()
{
 int n;
 
 printf(" - Problema de N Reinas Usando Backtracking  -");
 printf("\n\nIngrese el numero de reinas:");
 scanf("%d",&n);
 
 int board[(int)pow(n,2)];
 void queen(int row,int n,int board[]);
 
 correrContador();
 queen(1,n,board);
 cout<<endl<<endl<<"Tiempo en milisegundos: "<<obtenerContador()<<endl; //fin del contador
 
 cout<<"Dimension del tablero: "<<sizeof(board) / sizeof(int)<<" Soluciones: "<<count<<endl; 

 return 0;
}



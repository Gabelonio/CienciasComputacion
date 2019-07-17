#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

class Localidad{
	public:
		/*
		Localidad(char *nombre,int calleInicio,int calleFin, int carreraInicio, int carreraFin){
			this->
		}
		Localidad(){
			
		} 
		*/
		char* nombre;
		int calleInicio,calleFin,carreraInicio,carreraFin; 
		Localidad *izq;
		Localidad *der;
		int altura;
};

#endif 


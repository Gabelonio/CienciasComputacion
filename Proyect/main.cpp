/*
	RAMA PRINCIPAL DE EJECUCION DEL PROYECTO
	NOMBRES:
		Gabriel Esteban Castillo Ramirez - 20171020021
		Kevin Andres Malaver Cobos - 20171020001
		Esteban Quintero Amaya - 20171020022
*/
#include <iostream>  
#include <time.h>
#include "arbolLocalidades.h"
#include "Localidad.h"
#include "Paseador.h"
#include "Cliente.h"
#include "Fecha.h"
#include "lista.h"

using namespace std;

//template <class T>
struct InfLocalidades{
	char* nombre;
	int calleInicio,calleFin,carreraInicio,carreraFin; 
//	lista<T> sucursales;
};
/*
template <class T, class S>
struct Sucursal{
	string nombreSucursal,nombreGerente;
	int calle,carrera;
	lista<T> paseadores;
	lista<S> clientes;
	Paseador paseador;
	Cliente cliente;
	Sucursal< Cliente, Paseador> sucursal;
	lista< Sucursal< Cliente, Paseador> > listaSucursal;
	cliente.mascota.resumen.insertar_inicio(cliente.resumen);
	cliente.listaMascota.insertar_inicio(cliente.mascota);
	sucursal.clientes.insertar_inicio(cliente);
	sucursal.paseadores.insertar_inicio(paseador);
	listaSucursal.insertar_inicio(sucursal);
	
};
*/
time_t theTime = time(NULL);
struct tm *aTiempo = localtime(&theTime);

//Validacion para un String que solo debe tener numeros
bool es_numero(string s){ 
   for(int i = 0; i < s.length(); i++)
      if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') ) 
			return false;
   return true;
}

/*
	Funciones utiles para desplegar los distintos menus de seleccion de opciones
*/
int desplegarMenuModificacionDatos(){
	int opc;
	do{
		cout<<"Presione: "<<endl;
		cout<<"1. Para menu de Clientes"<<endl;
		cout<<"2. Para menu de Sucursales"<<endl;
		cout<<"3. Para menu de Paseadores"<<endl;
		cin>>opc;	
	}while(opc<1||opc>3);
	return opc;   
}
int desplegarSubMenuModificacionDatos(){
	int opc; 
	do{
		cout<<"Presione: "<<endl;
		cout<<"1. Para ingresar "<<endl;
		cout<<"2. Para eliminar"<<endl;
		cout<<"3. Para editar"<<endl;
		cin>>opc;
	}while(opc<1||opc>3);
	return opc;
}
int desplegarMenuConsultas(){
	int opc;
	do{ 
		cout<<"Presione: "<<endl;
		cout<<"1. Para ingresar un area y observar las sucursales que podrian hacerse cargo de perros"<<endl;
		cout<<"2. Para ingresar un horario y localidad y mostrar los paseadores que podrian estar disponibles"<<endl;
		cout<<"3. Para ingresar un horario y un cliente y mostrar los paseadores que podrian hacerse cargo de sus perros"<<endl;
		cout<<"4. Para ingresar una localidad y una raza de perro y mostrar todos los clientes que poseen perros de dicha raza"<<endl;
		cout<<"5. Para ingresar un paseador y un rango de tiempo y mostrar toda la informacion de los perros paseados por dicho paseador"<<endl;
		cout<<"6. Para ingresar un perro y un rango de tiempo y mostrar toda la informacion de sus paseos"<<endl; 
		cout<<"7. Para ingresar una localidad y un tamano para mostrar los perros de dicho tamano adscritos a la localidad"<<endl;
		cout<<"8. Para ingresar un rango de edad y mostrar la informacion de los perros pertenecientes al rango"<<endl;
		cin>>opc;
	}while(opc<1||opc>8);
	return opc; 
}	


InfLocalidades LOCALIDADES[17];

int main(int argc, char **argv) { 
	  
	/*
		Inicializacion del mapa de las localidades existentes en el software:
		* Nombre
		* CalleInicio = limite Norte
		* CalleFin = limite Sur
		* CarreraInicio = limite Occidente
		* CarreraFin = limite Oriente 
	*/
	LOCALIDADES[0].nombre = "Suba"; LOCALIDADES[0].calleInicio = 247; LOCALIDADES[0].calleFin = 100; LOCALIDADES[0].carreraInicio = 24; LOCALIDADES[0].carreraFin = 1; 
	LOCALIDADES[1].nombre = "Chapinero"; LOCALIDADES[1].calleInicio = 99; LOCALIDADES[1].calleFin = 39; LOCALIDADES[1].carreraInicio = 14; LOCALIDADES[1].carreraFin = 1; 
	LOCALIDADES[2].nombre = "Santa_fe"; LOCALIDADES[2].calleInicio = 38; LOCALIDADES[2].calleFin = 1; LOCALIDADES[2].carreraInicio = 14; LOCALIDADES[2].carreraFin = 1; 
	LOCALIDADES[3].nombre = "San_cristobal"; LOCALIDADES[3].calleInicio = -1; LOCALIDADES[3].calleFin = -53; LOCALIDADES[3].carreraInicio = 10; LOCALIDADES[3].carreraFin = -13; 
	LOCALIDADES[4].nombre = "Usme"; LOCALIDADES[4].calleInicio = -54; LOCALIDADES[4].calleFin = -116; LOCALIDADES[4].carreraInicio = 5; LOCALIDADES[4].carreraFin = -13; 
	LOCALIDADES[5].nombre = "Rafael_Uribe"; LOCALIDADES[5].calleInicio = -22; LOCALIDADES[5].calleFin = -53; LOCALIDADES[5].carreraInicio = 30; LOCALIDADES[5].carreraFin = 11; 
	LOCALIDADES[6].nombre = "Antonio_Narino"; LOCALIDADES[6].calleInicio = -1; LOCALIDADES[6].calleFin = -21; LOCALIDADES[6].carreraInicio = 30; LOCALIDADES[6].carreraFin = 11; 
	LOCALIDADES[7].nombre = "Martires"; LOCALIDADES[7].calleInicio = 26; LOCALIDADES[7].calleFin = 1; LOCALIDADES[7].carreraInicio = 30; LOCALIDADES[7].carreraFin = 15; 
	LOCALIDADES[8].nombre = "Teusaquillo"; LOCALIDADES[8].calleInicio = 63; LOCALIDADES[8].calleFin = 27; LOCALIDADES[8].carreraInicio = 68; LOCALIDADES[8].carreraFin = 15; 
	LOCALIDADES[9].nombre = "Barrios_unidos"; LOCALIDADES[9].calleInicio = 99; LOCALIDADES[9].calleFin = 64; LOCALIDADES[9].carreraInicio = 68; LOCALIDADES[9].carreraFin = 15; 
	LOCALIDADES[10].nombre = "Suba"; LOCALIDADES[10].calleInicio = 247; LOCALIDADES[10].calleFin = 100; LOCALIDADES[10].carreraInicio = 160; LOCALIDADES[10].carreraFin = 25; 
	LOCALIDADES[11].nombre = "Engativa"; LOCALIDADES[11].calleInicio = 99; LOCALIDADES[11].calleFin = 26; LOCALIDADES[11].carreraInicio = 126; LOCALIDADES[11].carreraFin = 69; 
	LOCALIDADES[12].nombre = "Puente_aranda"; LOCALIDADES[12].calleInicio = 26; LOCALIDADES[12].calleFin = -45; LOCALIDADES[12].carreraInicio = 68; LOCALIDADES[12].carreraFin = 31; 
	LOCALIDADES[13].nombre = "Tunjuelito"; LOCALIDADES[13].calleInicio = -46; LOCALIDADES[13].calleFin = -56; LOCALIDADES[13].carreraInicio = 68; LOCALIDADES[13].carreraFin = 31; 
	LOCALIDADES[14].nombre = "Bosa"; LOCALIDADES[14].calleInicio = -57; LOCALIDADES[14].calleFin = -88; LOCALIDADES[14].carreraInicio = 107; LOCALIDADES[14].carreraFin = 63; 
	LOCALIDADES[15].nombre = "Kennedy"; LOCALIDADES[15].calleInicio = 17; LOCALIDADES[15].calleFin = -56; LOCALIDADES[15].carreraInicio = 107; LOCALIDADES[15].carreraFin = 69; 
	LOCALIDADES[16].nombre = "Fontibon"; LOCALIDADES[16].calleInicio = 25; LOCALIDADES[16].calleFin = 18; LOCALIDADES[16].carreraInicio = 138; LOCALIDADES[16].carreraFin = 69; 

	//Formacion del arbol, util para busquedas, comparaciones y validaciones al momento de ingresar nuevos registros
	arbolLocalidades arbolAVLLocal;
	
		         
	for(int i=0;i<17;i++){
		arbolAVLLocal.agregarLocalidad(LOCALIDADES[i].nombre,
									   LOCALIDADES[i].calleInicio,
									   LOCALIDADES[i].calleFin,
									   LOCALIDADES[i].carreraInicio,
									   LOCALIDADES[i].carreraFin
									   ); 		
	}
	
	int opc = 0;
	const size_t BUFFER_SIZE = 1024;
	char *texto = new char[BUFFER_SIZE];
	
	
	do{
		cout<<"Bienvenido al software de Paseadores de perros Cesar Millan :V"<<endl;
		cout<<"Menu: Seleccione"<<endl<<"1. Para realizar consultas"<<endl;
		cout<<"2. Para ingresar, editar o eliminar informacion"<<endl;
		cout<<"3. Para realizar la simulacion de paseo de perros"<<endl;
		cout<<"4. Para salir del programa"<<endl; 
		cin>>opc;
		switch(opc){
			case 1:{
				switch(desplegarMenuConsultas()){
					case 1:{
						
						break;
					}
					case 2:{
						
						break;
					}
					case 3:{
						
						break;
					}
					case 4:{
						
						break;
					}
					case 5:{
						
						break;
					}
					case 6:{
						
						break;
					}
					case 7:{
						
						break;
					}
					case 8:{
						
						break;
					}
				}
				break;
			}
			case 2:{
				int tipoDato;
				tipoDato = desplegarMenuModificacionDatos();
													 
				switch(tipoDato){
					case 1:{
						cout<<"1";
						switch(desplegarSubMenuModificacionDatos()){
							case 1:{
								int cantidadPerros;
								Cliente cliente;
								cout<<"Ingrese el nombre: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								cliente.setNombre(texto);
								
								cout<<endl<<"Ingrese el apellido: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								cliente.setApellido(texto);
								
								do{
									cout<<endl<<"Ingrese el numero de Cedula: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									if(!es_numero(texto)){
										cout<<"debe ingresar numeros"<<endl;
									}
								}while(!es_numero(texto));
								//VERIFICAR QUE SEA UNICO!!!
							    cliente.setId(texto);
								
								do{
									cout<<"Seleccione una opcion para ingresar su genero:"<<endl;
									cout<<"1. Femenino"<<endl;
									cout<<"2. Masculino"<<endl;
									cin>>opc; 
								}while(opc<1||opc>2);
								if(opc==1)
									cliente.setGenero("F");
								else
									cliente.setGenero("M");
								
								//Verificacion del ingreso de una localidad valida
								bool localidadValida; 
								do{
									localidadValida = true;
									cout<<endl<<"Ingrese el nombre de la localidad: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;  
									if(!arbolAVLLocal.localidadExiste(texto)){
										cout<<"Localidad no encontrada"<<endl;
										localidadValida = false; 
									}
								}while(!localidadValida);
								
								cliente.setLocalidad(texto);
								
								cout<<"Ingrese la cantidad de perros: ";
								cin>>cantidadPerros; 
								
								/*
									Creacion e introduccion de la lista de perros para el cliente
								*/
								for(int i=1;i<=cantidadPerros;i++){
									cout<<"Perro Numero: "<<i<<endl;
									cout<<"Ingrese el nombre: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setNombreMascota(texto);
									cout<<"Ingrese la fecha de nacimiento DD/MM/AAAA: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setFechaDeNacimientoMas(texto);
									cout<<"Ingrese la raza: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setRaza(texto);
									do{
										cout<<"Seleccione una opcion para ingresar su tamanio:"<<endl;
										cout<<"1. Pequenio"<<endl;
										cout<<"2. Mediano"<<endl;
										cout<<"3. Grande"<<endl;
										cin>>opc; 
									}while(opc<1||opc>3);
									switch(opc){
										case 1:{
											cliente.setTam('p');
											break;
										}
										case 2:{
											cliente.setTam('m');
											break;
										}
										case 3:{
											cliente.setTam('g');
											break;
										}
									}
									cout<<"Ingrese el tipo de concentrado de consume: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setTipoConcentrado(texto); 
									cliente.listaMascota.insertar_final(cliente.mascota); 
								}			
								
								break;
							}
							case 2:{
								//Borrar cliente
								break;
							}
							case 3:{
								//Editar cliente
								break;
							}
						}
						break;
					}
					case 2:{
						
						cout<<"2";
						switch(desplegarSubMenuModificacionDatos()){
							case 1:{
								//Crear sucursal
								break;
							}
							case 2:{
								//Borrar sucursal
								break;
							}
							case 3:{
								//Editar sucursal
								break;
							}
						}
						break;
					}
					case 3:{
						
						cout<<"3";
						switch(desplegarSubMenuModificacionDatos()){
							case 1:{
								int dia,mes,anio;
								int calle, carrera; 
								Paseador paseador;
								cout<<"Ingrese el nombre: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								paseador.setNombre(texto);
								cout<<endl<<"Ingrese el apellido: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								paseador.setApellido(texto);
								do{
									cout<<endl<<"Seleccione una opcion para el tipo de identificacion:"<<endl;
									cout<<"1. Cedula de ciudadania"<<endl;
									cout<<"2. Cedula de extrangeria"<<endl;
									cin>>opc; 
								}while(opc<1||opc>2);
								if(opc==1)
									paseador.setTipoId("CC");
								else
									paseador.setTipoId("CE");
									
								do{
									cout<<endl<<"Ingrese el numero de Cedula: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									if(!es_numero(texto)){
										cout<<"debe ingresar numeros"<<endl;
									}
								}while(!es_numero(texto));
								
								//VERIFICAR QUE SEA UNICO !!!
								
								paseador.setId(texto);
								do{
									cout<<"Seleccione una opcion para ingresar su genero:"<<endl;
									cout<<"1. Femenino"<<endl;
									cout<<"2. Masculino"<<endl;
									cin>>opc; 
								}while(opc<1||opc>2);
								if(opc==1)
									paseador.setGenero("F");
								else
									paseador.setTipoId("M");
									
								do{
									cout<<endl<<"Ingrese el numero de Telefono: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									if(!es_numero(texto)){
										cout<<"debe ingresar numeros"<<endl;
									}
								}while(!es_numero(texto));
								
								paseador.setTelefono(texto);
								cout<<endl<<"Ingrese el correo electronico: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								//VERIFICAR QUE CONTENGA ARROBA Y PUNTO
								paseador.setEmail(texto); 
								
								cout<<endl<<"Ingrese la fecha de nacimiento: ";
								cout<<endl<<"Dia: ";
								cin>>dia;
								cout<<endl<<"Mes: ";
								cin>>mes; 
								cout<<endl<<"Anio: ";
								cin>>anio;
								
								//Crea variables con la fecha actual para realizar la comparacion de mayoria de edad
								int diaActual = aTiempo->tm_mday;
								int mesActual = aTiempo->tm_mon + 1; 
								int anioActual = aTiempo->tm_year + 1900;
								
								//Creacion de las estructuras Fecha 
								Date dt1 = {dia, mes, anio}; 
								Date dt2 = {diaActual, mesActual, anioActual}; 
								
								//Comparacion para comprobar mayoria de edad
								if((getDifference(dt1, dt2)/365)<18){
									cout<<"No se permiten edades menores a 18"<<endl; 	
								}
								else{ 		
									paseador.setEdad(getDifference(dt1, dt2)/365);  
									
									cout<<endl<<"Ingrese el pais de nacimiento: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									paseador.setPais(texto); 
									
									cout<<endl<<"Ingrese la ciudad de nacimiento: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									paseador.setCiudad(texto); 
									
									/*
										Verificacion de la validez de la direccion colocada
										No puede estar por fuera del mapa propuesto 
									*/
									bool ubicacionValida; 
									do{
										ubicacionValida = true; 
										cout<<endl<<"Ingrese la calle de residencia: ";
										cin>>calle;
										
										cout<<endl<<"Ingrese la carrera de residencia: ";
										cin>>carrera;
										
										if(!arbolAVLLocal.ubicacionExiste(calle,carrera)){
											cout<<"Direccion no valida"<<endl;
											ubicacionValida = false; 
										}
											
									}while(!ubicacionValida);
									
									
									/*
										 donde es la localidad
									*/
									
									cout<<endl<<"Ingrese el barrio de residencia: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									paseador.setBarrio(texto);
									
									  
								}
															
								//Crear paseador
								break;
							}
							case 2:{
								//Borrar paseador
								break;
							}
							case 3:{
								//Editar paseador
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 3:{
				//Simulacion
				break;
			}
			case 4:{
				//Aqui hay que poner el guardado de los datos
				cout<<"Programa Finalizado"<<endl;
				break;
			}
			default:{
				cout<<"Comando incorrecto"<<endl;
				break;
			}
		} 
	 system("pause");
	 system("cls");
	}while(opc!=4); 

	//arbolAVLLocal.preOrden();
	arbolAVLLocal.inOrden();
	
	return 0;	
}

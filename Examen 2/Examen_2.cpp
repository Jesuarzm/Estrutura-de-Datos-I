#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct 	nodoPersona
{
    int idPersona;
    string nombre;
	nodoPersona *sig;
};

struct 	nodoHabitaciones
{
    int idHabitacion;
    string tamano;
	nodoHabitaciones *sig;
};

typedef struct nodoPersona *listaPersonas;
typedef struct nodoHabitaciones *listaHabitaciones;

nodoPersona *crearPersona(int id, string name)
{
	nodoPersona *aux = new (struct nodoPersona);
	aux->idPersona=id;
    aux->nombre=name;
	aux->sig=NULL;
	return aux;
}

nodoHabitaciones *crearHabitacion(int id, string name)
{
	nodoHabitaciones *aux = new (struct nodoHabitaciones);
	aux->idHabitacion=id;
    aux->tamano=name;
	aux->sig=NULL;
	return aux;
}
void agregarPersona(listaPersonas &cab,int id, string name)
{
	listaPersonas aux;
	nodoPersona *nuevo;
	nuevo=crearPersona(id, name);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		aux->sig=nuevo;
	}
    
}
void agregarHabitacion(listaHabitaciones &cab, int id, string size)
{
	nodoHabitaciones *nuevo;
	nuevo=crearHabitacion(id, size);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		nuevo->sig=cab;
		cab=nuevo;
	}
}
nodoHabitaciones *SacarHabitacion(listaHabitaciones &cab)
{
	nodoHabitaciones *aux;
	
	if(cab==NULL)
	{
	 cout <<"Cola vacia"<<endl;
	 return NULL;
	}
	else
	{
		aux=cab;
		cab=cab->sig;
		aux->sig=NULL;
		return aux;
	}
}
void MostrarP(listaPersonas cab)
{
	listaPersonas aux;
	
	if(cab==NULL)
	cout <<"Lista vaica"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout <<"Id: "<<aux->idPersona<<endl;
			cout <<"Nombre: "<<aux->nombre<<endl;
			cout <<"------------------------------"<<endl;
			aux=aux->sig;
		}
	}
}
void MostrarH(listaHabitaciones cab)
{
	listaHabitaciones aux;
	
	if(cab==NULL)
	cout <<"Lista vaica"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout <<"\nHabitacion: "<<aux->idHabitacion << endl;
            cout <<"Tamaño: "<<aux->tamano << endl;
            cout <<"---------------------->";  
			aux=aux->sig;
		}
	}
}
int main()
{

    bool estado = true;

	listaPersonas personas=NULL;
    listaHabitaciones habitaciones=NULL;
	agregarPersona(personas,1,"Jesuar");
	agregarPersona(personas,2,"Ash");
    agregarHabitacion(habitaciones,517,"Grande");
    agregarHabitacion(habitaciones,518,"Grande");
    agregarHabitacion(habitaciones,519,"Grande");
    agregarHabitacion(habitaciones,520,"Grande");
    agregarHabitacion(habitaciones,521,"Grande");

    do{
        int opc = 0;
		system("clear");
        cout << "Menu:" << endl;
        cout << "***********" << endl;
        cout << "1: Mostar Clientes" << endl;
        cout << "2:  Mostar Habitaciones " << endl;
    
        cout << "3:  Asignar Habitacion" << endl;
        cout << "11: SALIR" << endl;
        
		cout << "\nOpcion:" << endl;
        
        cin >> opc;

		if (opc == 1){
			system("clear");
            MostrarP(personas);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
        if (opc == 2){
			system("clear");
            MostrarH(habitaciones);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
        if (opc == 3){
			system("clear");
            SacarHabitacion(habitaciones)->idHabitacion;
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
        if (!(opc > 0 and opc < 3)){
			system("clear");
			cout << "Ingresar una opcion valida:" << endl;
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		
	}while (estado == true);

	
}
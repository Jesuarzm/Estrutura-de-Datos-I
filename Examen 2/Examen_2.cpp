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
	listaHabitaciones aux;
	nodoHabitaciones *nuevo;
	nuevo=crearHabitacion(id, size);
	
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
			cout <<"Habitacion: "<<aux->idHabitacion<<" -->";
            cout <<"Tamaño: "<<aux->tamano<<" -->" << endl;
            cout <<"--------------->";  
			aux=aux->sig;
		}
	}
}
int main()
{
	listaPersonas personas=NULL;
    listaHabitaciones habitaciones=NULL;
	agregarPersona(personas,1,"Jesuar");
	agregarPersona(personas,2,"Ash");
    agregarHabitacion(habitaciones,521,"Grande");
    agregarHabitacion(habitaciones,520,"Grande");
    agregarHabitacion(habitaciones,519,"Grande");
    agregarHabitacion(habitaciones,518,"Grande");
    agregarHabitacion(habitaciones,517,"Grande");
	MostrarP(personas);
    MostrarH(habitaciones);
	
}
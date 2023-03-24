#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodoProceso
{
	int memoria;
	nodoProceso *sig;
};
typedef struct nodoProceso *lista;

nodoProceso *crearNodo(int mem)
{
	nodoProceso *aux = new (struct nodoProceso);
	aux->memoria=mem;
	aux->sig=NULL;
	return aux;
}

void Poner(lista &cab, int mem)
{
	lista aux;
	nodoProceso *nuevo;
	nuevo=crearNodo(mem);
	
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

nodoProceso *Sacar(lista &cab)
{
	nodoProceso *aux;
	
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

void Mostrar(lista cab)
{
	lista aux;
	
	if(cab==NULL)
	cout <<"Lista vaica"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout <<"Memoria: "<<aux->memoria<<" -->";
			aux=aux->sig;
		}
	}
}

void Mayor(lista &cab)
{
	int mayor;
	nodoProceso *aux;
	lista colaAux=NULL;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=Sacar(cab);
		mayor=aux->memoria;
		while(aux!=NULL)
		{
			if(mayor < aux->memoria)
			mayor=aux->memoria;
			
			Poner(colaAux,aux->memoria);
			aux=Sacar(cab);
		}
	}
	//Mostrar(colaAux);
	cout <<"La memoria mayor es:"<<mayor<<endl;
	
	aux=Sacar(colaAux);
	while(aux!=NULL)
	{
		
		Poner(cab,aux->memoria);
		aux=Sacar(colaAux);
	}
}

int main()
{
	lista Cola=NULL;
	Poner(Cola,35);
	Poner(Cola,45);
	Poner(Cola,7);
	Poner(Cola,105);
	//Mostrar(Cola);
	cout <<endl;
	system("Pause");
	Mayor(Cola);
	Mostrar(Cola);
	cout <<endl;
	system("Pause");
	cout <<"Memoria procesada:"<<Sacar(Cola)->memoria<<endl;
	Mostrar(Cola);
	system("Pause");
	cout <<"Memoria procesada:"<<Sacar(Cola)->memoria<<endl;
	Mostrar(Cola);
	system("Pause");
	cout <<"Memoria procesada:"<<Sacar(Cola)->memoria<<endl;
	Mostrar(Cola);
	system("Pause");
	
	
	
}
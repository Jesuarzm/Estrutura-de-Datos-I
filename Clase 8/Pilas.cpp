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

void Poner(lista &cab,int mem)
{
	nodoProceso *nuevo;
	nuevo=crearNodo(mem);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		nuevo->sig=cab;
		cab=nuevo;
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
			cout <<"Memoria: "<<aux->memoria<<endl;
			cout <<"------------------------------"<<endl;
			aux=aux->sig;
		}
	}
}
void ContarParesImpares(lista cab)
{
	nodoProceso *aux;
	int contP,contI;
	lista auxP=NULL;
	
	if(cab==NULL)
	cout <<"Lista vacia";
	else
	{
		aux=Sacar(cab);
		while(aux!=NULL)
		{
			if(aux->memoria%2==0)
			contP=contP+1;
			else
			contI=contI+1;
			
		Poner(auxP,aux->memoria);		
		aux=Sacar(cab);		
		}	
	}
	
	cout<<"Total de pares: "<<contP<<endl;
	cout<<"Total de impares: "<<contI<<endl;
	
}

int main()
{
	lista Pila=NULL;
	Poner(Pila,20);
	Poner(Pila,45);
	Poner(Pila,50);
	Poner(Pila,65);
	Poner(Pila,80);
	Mostrar(Pila);
	system("Pause");
	ContarParesImpares(Pila);
	/*cout <<"Memoria procesada:"<<Sacar(Pila)->memoria<<endl;
	Mostrar(Pila);
	system("Pause");
	cout <<"Memoria procesada:"<<Sacar(Pila)->memoria<<endl;
	Mostrar(Pila);
	system("Pause");*/
	
}
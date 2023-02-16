#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoArticulo
{
	string nombre;
	int codigo;	
	int cantidad;
	double precio;
	nodoArticulo *sig;
	nodoArticulo *ant;
};
typedef struct nodoArticulo *lista;

nodoArticulo *crearNodo(string n,int cod,int can,
                       double precio)
{
	nodoArticulo *aux = new (struct nodoArticulo);
	aux->nombre=n;
	aux->codigo=cod;
	aux->cantidad=can;
	aux->precio=precio;
	aux->sig=NULL;
	aux->ant=NULL;
	
	return aux;
}
 
void agregarFinal(lista &cabeza,string n,int cod,
                  int ca,double pre)
{
	nodoArticulo *nuevo;
	lista aux;
	
	nuevo=crearNodo(n,cod,ca,pre);
	
	if(cabeza==NULL)
	{
		cabeza=nuevo;
		cabeza->sig=cabeza;
		cabeza->ant=cabeza;
	}
	else
	{
		aux=cabeza;
		while(aux->sig!=cabeza)
		aux=aux->sig;
		
		aux->sig=nuevo;
		nuevo->sig=cabeza;
		nuevo->ant=aux;
		cabeza->ant=nuevo;
			
	}
}

void borrarArticulo(lista &cabeza, int cod)
{
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		if(aux->codigo==cod)
		{
			cabeza=aux->sig;
			cabeza->ant=aux->ant;
			aux->ant->sig=cabeza;
			aux->sig=NULL;
			aux->ant=NULL;
			free(aux);
			aux=cabeza;
		}
		else
		{
			aux=cabeza;
			do
			{
				if(aux->codigo==cod && aux->sig!=cabeza)
				{
					aux->ant->sig=aux->sig;
					aux->sig->ant=aux->ant;
					aux->sig=NULL;
					aux->ant=NULL;
					free(aux);
					aux=cabeza;
					
				}
				else
				if(aux->codigo==cod && aux->sig==cabeza)
				{
					cabeza->ant=aux->ant;
					aux->ant->sig=cabeza;
					aux->sig=NULL;
					aux->ant=NULL;
					free(aux);
					aux=cabeza;
					
				}
				
				
				aux=aux->sig;
			}
			while(aux!=cabeza);
		}
	}
}

void mostrarLista(lista cabeza)
{
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		do
		{
			cout<<"Nombre:" <<aux->nombre<<endl;
			cout<<"Codigo:" <<aux->codigo<<endl;
			cout<<"Precio:" <<aux->precio<<endl;
			cout<<"Cantidad:" <<aux->cantidad<<endl;
			cout <<"******************************"<<endl;
			aux=aux->sig;
		}
		while(aux!=cabeza);
	}
}

void modificarLista(lista cabeza,int cod,int can)
{
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		do
		{
			if(aux->codigo==cod)
			aux->cantidad=can;
			
			aux=aux->sig;
		}
		while(aux!=cabeza);
	}
}

int main()
{
	lista LDC=NULL;
	agregarFinal(LDC,"coca cola",101,4,1000);
	agregarFinal(LDC,"fanta",102,4,1000);
	agregarFinal(LDC,"pepsi",103,4,1000);
	mostrarLista(LDC);
	system("read -p '$*'");
	borrarArticulo(LDC,103);
	system("clear");
	mostrarLista(LDC);
	system("read -p '$*'");
	modificarLista(LDC,102,8);
	system("clear");
	mostrarLista(LDC);
	system("read -p '$*'");

}
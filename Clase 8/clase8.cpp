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
void Menor(lista &cab)
{
	int menor;
	nodoProceso *aux;
	lista colaAux=NULL;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=Sacar(cab);
		menor=aux->memoria;
		while(aux!=NULL)
		{
			if(menor > aux->memoria)
			menor=aux->memoria;
			
			Poner(colaAux,aux->memoria);
			aux=Sacar(cab);
		}
	}
	//Mostrar(colaAux);
	cout <<"La memoria menor es:"<<menor<<endl;
	
	aux=Sacar(colaAux);
	while(aux!=NULL)
	{
		
		Poner(cab,aux->memoria);
		aux=Sacar(colaAux);
	}
}

void MenorAMayor(lista &cab)
{
	int menor;
	nodoProceso *aux;
	lista colaAux=NULL;
	
	if(cab==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=Sacar(cab);
		menor=aux->memoria;
		while(aux!=NULL)
		{
			if(menor > aux->memoria){
				menor=aux->memoria;
				Poner(colaAux,aux->memoria);	
			}
			
			aux=Sacar(cab);
		}
	}
	
	
	aux=Sacar(colaAux);
	while(aux!=NULL)
	{
		
		Poner(cab,aux->memoria);
		aux=Sacar(colaAux);
	}
}
void MostrarPares(lista cab)
{
	lista aux;
	
	if(cab==NULL)
	cout <<"No hay pares"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			if((aux->memoria%2)==0){
			cout <<"Pares: "<<aux->memoria<<" -->" << endl;	
			}
			aux=aux->sig;
		}
	}
}
void Promedio(lista cab)
{
	lista aux;
	int promedio, cont;
	if(cab==NULL)
	cout <<"No hay pares"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cont++;
			
			promedio=promedio+aux->memoria;
			
			aux=aux->sig;
		}
		promedio= promedio / cont;
		cout << "Promedio: " << promedio << endl;
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
	cout <<endl;
	Menor(Cola);
	cout <<endl;
	Mostrar(Cola);
	cout <<endl;
	system("Pause");
	
	/*cout <<"Memoria procesada:"<<Sacar(Cola)->memoria<<endl;
	Mostrar(Cola);
	system("Pause");
	cout <<"Memoria procesada:"<<Sacar(Cola)->memoria<<endl;
	Mostrar(Cola);
	system("Pause");
	cout <<"Memoria procesada:"<<Sacar(Cola)->memoria<<endl;
	Mostrar(Cola);
	system("Pause");*/
	
	
	
}

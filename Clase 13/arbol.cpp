#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct nodoArbol {
    int numero;
    nodoArbol *izq;
    nodoArbol *der;
};

typedef struct nodoArbol *arbol;

nodoArbol *crearNodo(int num)
{
	nodoArbol *aux = new (struct nodoArbol);
	aux->numero=num;
	aux->der=NULL;
	aux->izq=NULL;
	return aux;
}

void insertar(arbol &cab,int x)
{				//aux->der,85
	nodoArbol *nuevo;
	arbol aux;
	
	if(cab==NULL)
	{
	nuevo=crearNodo(x);	
	cab=nuevo;
	}
	
	else
	{
	  	aux=cab;
	  	if(x > aux->numero)
	  	insertar(aux->der,x);
	  	else
	  	insertar(aux->izq,x);	
	}	
}
//Preorden,postorden,inorden
//Preorden=RID
//PostOrden=IDR
//InOrden=IRD
void inOrden(arbol raiz)
{
    if (raiz != NULL)
    {
        inOrden(raiz->izq);
        cout <<"->"<<raiz->numero;
        inOrden(raiz->der);
        //8,10,15,25,32,35,60,79,85,90,96
    }
}
void preOrden(arbol raiz)
{
    if (raiz != NULL)
    {
		cout <<"->"<<raiz->numero;
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void postOrden(arbol raiz)
{
    if (raiz != NULL)
    {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        cout <<"->"<<raiz->numero;
    }
}

void verarbol(arbol raiz, int nro)// total de nodos del arbol
{
 int i;
 if(raiz==NULL)
 return;
 	verarbol(raiz->der,nro+1);
 	
	for(i=0;i<nro;i++)
    cout<<"->";
    
	cout<<raiz->numero<<endl;
 
 	verarbol(raiz->izq,nro+1);
}

void verarbolEspejo(arbol raiz, int nro)// total de nodos del arbol
{
 int i;
 if(raiz==NULL)
 return;
 	verarbolEspejo(raiz->izq,nro+1);
 	
    for(i=0;i<nro;i++)
    cout<<"*****";
    
	cout<<raiz->numero<<endl;
 
 	verarbolEspejo(raiz->der,nro+1);
}

int contarMultiplos3(arbol raiz)
{ int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			if(raiz->numero % 3 == 0)
			{
		   	 cont=cont+1;
			}
	
		}

	return cont+contarMultiplos3(raiz->izq)+contarMultiplos3(raiz->der);
}
void buscarMayores(arbol raiz,int x)
{
		
		if(raiz==NULL)
		return;
		else
		{
			if(raiz->numero > x)
			{
			 cout << "Numero: " << raiz->numero <<endl;
			}
	
		}
	buscarMayores(raiz->der,x);
	buscarMayores(raiz->izq,x);
}

int contarMayores(arbol raiz,int x)
{ int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			if(raiz->numero > x)
			{
			 cont=cont+1;
			}
	
		}

	return cont+contarMayores(raiz->der,x)+contarMayores(raiz->izq,x);
}

int contarMenores(arbol raiz,int x)
{ int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			if(raiz->numero <  x)
			{
			 cont=cont+1;
			}
	
		}

	return cont+contarMenores(raiz->izq,x)+contarMenores(raiz->der,x);
}

void buscarMenores(arbol raiz,int x)
{
		
		if(raiz==NULL)
		return;
		else
		{
			if(raiz->numero < x)
			{
			 cout << "Numero: " << raiz->numero <<endl;
			}
	
		}
	buscarMenores(raiz->der,x);
	buscarMenores(raiz->izq,x);
}
void buscarImpares(arbol raiz)
{
		
		if(raiz==NULL)
		return;
		else
		{
			if(raiz->numero % 2!=0)
			{
			 cout << "Numero impar: " << raiz->numero <<endl;
			}
	
		}
	buscarImpares(raiz->der);
	buscarImpares(raiz->izq);
}

int contarImpares(arbol raiz)
{	int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			if(raiz->numero % 2!=0)
			{
			 cont=cont+ 1;
			}
	
		}

	return cont+contarImpares(raiz->der)+contarImpares(raiz->izq);
}
void buscarPares(arbol raiz)
{
		
		if(raiz==NULL)
		return;
		else
		{
			if(raiz->numero % 2==0)
			{
			 cout << "Numero par: " << raiz->numero <<endl;
			}
	
		}
	buscarPares(raiz->der);
	buscarPares(raiz->izq);
}

int contarPares(arbol raiz)
{	int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			if(raiz->numero % 2==0)
			{
			 cont=cont+ 1;
			}
	
		}

	return cont+contarPares(raiz->der)+contarPares(raiz->izq);
}

int contar(arbol raiz)
{	int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			 cont=cont+ 1;
		}

	return cont+contar(raiz->der)+contar(raiz->izq);
}

int sumar(arbol raiz)
{	int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			 cont=cont+ raiz->numero;
		}

	return cont+sumar(raiz->der)+sumar(raiz->izq);
}

int obtenerRaiz(arbol raiz)
{
		if(raiz==NULL)
		return 0;
		else
		{
			 return raiz->numero;
		}
}

arbol unirArbol(arbol izq, arbol der)
{
	arbol centro;
	
    if(izq==NULL) 
	return der;
    if(der==NULL) 
	return izq;

    centro = unirArbol(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(arbol &raiz, int x)
{
	arbol aux;
	
     if(raiz==NULL) 
	 return;// No hace nada simplemnte se sale

     if(x<raiz->numero)
         elimina(raiz->izq, x);
     else 
	 if(x>raiz->numero)
       elimina(raiz->der, x);
     else
     {
         aux = raiz;
         raiz = unirArbol(raiz->izq, raiz->der);
         delete aux;
     }
}
void RDD (arbol &p)
	{
		arbol aux=NULL;
		    
			aux=p->der;
			p->der=NULL;
			aux->izq = p;
			p=aux;
	}
void RII (arbol &p)
	{
		arbol aux=NULL;
		    
			aux=p->izq;
			p->izq=NULL;
			aux->der = p;
			p=aux;
	}
void RDI (arbol &p)
	{
		arbol aux=NULL;
		    
		aux=p->der->izq;
		aux->der=p->der;
		p->der=NULL;
		aux->izq=p;
		aux->der->izq=NULL;
		p=aux;
		
	}
	
void RID (arbol &p)
	{
		arbol aux=NULL;
		    
		aux=p->izq->der;
		aux->izq=p->izq;
		p->izq=NULL;
		aux->der=p;
		aux->izq->der=NULL;
		p=aux;
		
	}

int main()
{
	arbol Arb=NULL;
	
	insertar(Arb,65);
	insertar(Arb,58);
	insertar(Arb,79);
	insertar(Arb,91);
	insertar(Arb,96);
	insertar(Arb,43);
	insertar(Arb,45);	
	insertar(Arb,46);
	insertar(Arb,25);
	insertar(Arb,32);
	insertar(Arb,12);
	insertar(Arb,14);
	
	verarbol(Arb,10);
	cout << "El total de pares es: " << contarPares(Arb) << endl;//cantidad de margen o espacio de nodo raiz con respecto ala orientaci�n del arbol
    cout << "El total de nodos es: " << contar(Arb) << endl;//cantidad de margen o espacio de nodo raiz con respecto ala orientaci�n del arbol
    cout << "La suma total es: " << sumar(Arb) << endl;//cantidad de margen o espacio de nodo raiz con respecto ala orientaci�n del arbol
    cout << "El promedio: " << sumar(Arb)/contar(Arb) << endl;//cantidad de margen o espacio de nodo raiz con respecto ala orientaci�n del arbol
    
	// verarbolEspejo(Arb,2);
	//cout <<"Cantidad 3: "<<contarMultiplos3(Arb)<<endl;
	//cout <<"Mostrar numeros impares: " <<endl;
    //buscarImpares(Arb);
	//cout <<"Total de nodos impares: " << contarImpares(Arb) <<endl;
	//cout <<"Mostrar numeros pares: " <<endl;
	//buscarPares(Arb);
	//cout <<"Total de nodos Pares: " << contarPares(Arb) <<endl;
	//cout <<"Total de nodos en el arbol: " << contar(Arb) <<endl;
	
	//cout <<"Total de nodos mayores a la raiz: " << contarMayores(Arb,obtenerRaiz(Arb)) <<endl;
    //buscarMayores(Arb,obtenerRaiz(Arb));
    
   	//cout <<"Total de nodos menores a la raiz: " << contarMenores(Arb,obtenerRaiz(Arb)) <<endl;
    //buscarMenores(Arb,obtenerRaiz(Arb));
	
	
	
	//Metodos de rotaci�n 
	//rotaci�n II
	//rotaci�n ID
	//rotaci�n DD
	//rotaci�n DI
	//insertar(Arb,58);
	//insertar(Arb,45);
	//insertar(Arb,53);
	//verarbol(Arb,2);
	//RID(Arb);
	//verarbol(Arb,2);
	//system("pause");
	
}
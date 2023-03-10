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

nodoProceso *crearNodo(int mem){

    nodoProceso *aux = new (struct nodoProceso);
    aux->memoria=mem;
    aux->sig=NULL;

    return aux;
}
void Poner(lista &cab, int mem){

    nodoProceso *nuevo;
    nuevo=crearNodo(mem);
    
    if(cab==NULL){
    	cab=nuevo;
	}else{
		nuevo->sig=cab;
		cab=nuevo;
	}

}
nodoProceso *sacar(lista &cab){

    nodoProceso  *aux;
    if (cab == NULL)
    {
        cout << "Cola vacias" << endl;
        return NULL;
    }else{
        aux=cab;
        cab=cab->sig;
        aux->sig=NULL;
        return aux;
    }
 }
 
 void contarPares(lista &cab){
 	int par;
	 lista aux;
    if (cab==NULL)
    {
        cout << "Lista Vacia" << endl;
    }else{
        aux=cab;
        while (aux!=NULL)
        {
            if((aux->memoria%2)==0){
            	par++;
			}
            aux=aux->sig;
        }
		cout << "Pares: " << par << endl;        
    }
    
 	
 }
 void Mostrar(lista cab){
    
    lista aux;
    if (cab==NULL)
    {
        cout << "Lista Vacia" << endl;
    }else{
        aux=cab;
        while (aux!=NULL)
        {
            cout << "Memoria: " << aux->memoria<< endl;
            cout << "-----------------------" << endl;
            aux=aux->sig;
        }        
    }
    
 }
 int main(){
 	lista Pila = NULL;
 	Poner(Pila, 25);
 	Poner(Pila, 34);
 	Poner(Pila, 43);
 	Poner(Pila, 64);
 	Poner(Pila, 31);
 	Poner(Pila, 54);
 	Poner(Pila, 54);
 	Poner(Pila, 54);
 	
 	Mostrar(Pila);
 	system("pause");
 	
    cout << "Memoria en proceso: " << sacar(Pila)->memoria << endl;
    contarPares(Pila);
 	
 	
 }

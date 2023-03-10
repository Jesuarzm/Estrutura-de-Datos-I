#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
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
void poner(lista &cab, int mem){

    lista aux;
    nodoProceso *nuevo;
    nuevo = crearNodo(mem);

    if(cab == NULL){
        cab=nuevo;
    }else{
        aux=cab;
        while (aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
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
void mayor(lista cab){
    int mayor;
    nodoProceso *aux;
    lista colaAux=NULL;
    if (cab==NULL)
    {
        cout << "Lista Vacia" << endl;
    }else{
        aux=sacar(cab);
        mayor=aux->memoria;
        while (aux!=NULL)
        {
            mayor=aux->memoria;
        }
        aux=sacar(cab);
    }
    cout << "La memoria mayor es: " << mayor;
 }
 void mostra(lista cab){
    
    lista aux;
    if (cab==NULL)
    {
        cout << "Lista Vacia" << endl;
    }else{
        aux=cab;
        while (aux!=NULL)
        {
            cout << "Memoria: " << aux->memoria << "-->";
            aux=aux->sig;
        }        
    }
    
 }

 int main(){

    lista miLista;

    poner(miLista, 100);
    poner(miLista, 300);
    poner(miLista, 200);
    poner(miLista, 400);
    
    mostra(miLista);
    system("read -rp $'Press [Enter] to continue...\n' key");

    cout << "Memoria en proceso" << sacar(miLista)->memoria << endl;

 }

 

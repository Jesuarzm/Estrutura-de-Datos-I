#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodoProceso
{
    string nombre;
    int memoria;
    nodoProceso *sig;
    nodoProceso *ant;
};

typedef struct nodoProceso *lista;

nodoProceso *crearNodo (string n, int m){
    nodoProceso *aux = new (struct nodoProceso);
    aux->nombre=n;
    aux->memoria=m;
    aux->sig=NULL;
    aux->ant=NULL;
    
    return aux;
};

void agregarFinal(lista &cabeza, string n, int m){
    lista aux;
    nodoProceso *nuevo;
    nuevo=crearNodo(n,m);

    if(cabeza==NULL){
        cabeza=nuevo;
    }else{
        aux=cabeza;
        while (aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        
            aux->sig=nuevo;
            nuevo->ant=aux;
    }
}
void agregarInicio(lista &cabeza, string n, int m){
    nodoProceso *nuevo;
    nuevo=crearNodo(n,m);
    if (cabeza==NULL){
        cabeza=nuevo;
    }else{
        nuevo->sig=cabeza;
        nuevo->ant=nuevo;
        cabeza=nuevo;
    }
  
};

void mostrar(lista cabeza){
    lista aux;
    if (cabeza==NULL)
    {
        cout << "Lista Vacia" << endl;
    }else{
        aux=cabeza;
        while (aux!=NULL)
        {
            cout << "Proceso: " << aux->nombre << endl;
            cout << "Memoria: " << aux->memoria << "MB" << endl;
            cout << "******************************" << endl;
            aux=aux->sig;
        }
        
    }
};

int main(){
    lista ListaC=NULL;
    agregarFinal(ListaC,"Chrome",1000);
    agregarFinal(ListaC,"Spotify",300);
    agregarFinal(ListaC,"Photoshop",3000);


    agregarInicio(ListaC,"Chrome",1000);
    agregarInicio(ListaC,"Spotify",300);
    agregarInicio(ListaC,"Photoshop",3000);

    mostrar(ListaC);
    system("pause");
};

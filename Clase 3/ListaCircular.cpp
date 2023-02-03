#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodoTiquete
{
    string nombre;
    int tiquete;
    nodoTiquete *sig;
};

typedef struct nodoTiquete *lista;

nodoTiquete *crearNodo (string n, int t){
    nodoTiquete *aux = new (struct nodoTiquete);
    aux->nombre=n;
    aux->tiquete=t;
    aux->sig=NULL;
    return aux;
};

void agregarFinal(lista &cabeza, string n, int t){
    lista aux;
    nodoTiquete *nuevo;
    nuevo=crearNodo(n,t);

    if(cabeza==NULL){
        cabeza=nuevo;
        nuevo->sig=cabeza;
    }else{
        aux=cabeza;
        while (aux->sig!=cabeza){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->sig=cabeza;
    }

};

void mostrar(lista cabeza){
    lista aux;
    if(cabeza==NULL){
        cout << "Lista Vacias" << endl;
    }else{
        aux=cabeza;
        do{
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Tiqute: " << aux->tiquete << endl;
            aux=aux->sig;
        }while(aux!=cabeza);
    }
};

int main(){
    lista ListaC=NULL;
    agregarFinal(ListaC,"Carlos",1);
    agregarFinal(ListaC,"Pedro",2);
    agregarFinal(ListaC,"Lorem",3);
    agregarFinal(ListaC,"Ipsum",4);
    agregarFinal(ListaC,"Jesuar",5);

    mostrar(ListaC);
    system("pause");
}
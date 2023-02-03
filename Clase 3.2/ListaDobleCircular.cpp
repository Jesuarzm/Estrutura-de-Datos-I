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

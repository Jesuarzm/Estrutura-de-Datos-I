#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodoArticulo
{
    string articulo;
    int codigo;
    int cantidad;
    double precio;
    nodoArticulo *sig;
    nodoArticulo *ant;
};


typedef struct nodoArticulo *lista;

nodoArticulo *crearNodo (string name, int code, int cant, double prc){
    nodoArticulo *aux = new (struct nodoArticulo);
    aux->articulo=name;
    aux->codigo=code;
    aux->cantidad=cant;
    aux->precio=prc;
    aux->sig=NULL;
    aux->ant=NULL;
    
    return aux;
};

void agregarFinal(lista &cabeza, string name, int code, int cant, double prc){
    lista aux;
    nodoArticulo *nuevo;
    nuevo=crearNodo(name,code, cant, prc);

    if(cabeza==NULL){
        cabeza=nuevo;
        cabeza->sig=cabeza;
        cabeza->ant=cabeza;
    }else{
        aux=cabeza;
        while (aux->sig!=cabeza){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->ant=aux;
        nuevo->sig=cabeza;
        cabeza->ant=nuevo;
    }
};
void eliminar(lista &cabeza, int code){
    lista aux;
    if (cabeza==NULL)
    {
        cout << "LISTA VACIA" << endl;
    }else{
        aux=cabeza;
        if (aux->codigo==code)
        {
            cabeza=aux->sig;
            cabeza->ant=aux->ant;
            aux->ant->sig=cabeza;
            aux->sig=NULL;
            aux->ant=NULL;
            free(aux);
            aux=cabeza;
        }else{
            aux=cabeza;
            do
            {
                if (aux->codigo==code && aux->sig!=cabeza)
                {
                    aux->ant->sig=aux->sig;
                    aux->sig->ant=aux->ant;
                    aux->sig=NULL;
                    aux->ant=NULL;
                    free(aux);
                    aux=cabeza;
                }else{
                    if (aux->codigo==code && aux->sig!=cabeza){
                        cabeza->ant=aux->ant;
                        aux->ant->sig=cabeza;
                        aux->sig=NULL;
                        aux->ant=NULL;
                        free(aux);
                        aux=cabeza;
                    }
                }
                
                aux=aux->sig;
            } while (aux!=cabeza);
            
        }
        
    }
    
};

int main(){
    lista ListaC=NULL;
    agregarFinal(ListaC,"Arroz",1, 100, 2000);
    agregarFinal(ListaC,"Frijoles",2, 1000, 1500);
    agregarFinal(ListaC,"Pasta",3, 1000, 2500);
    agregarFinal(ListaC,"Chile",4, 200, 500);
	
};

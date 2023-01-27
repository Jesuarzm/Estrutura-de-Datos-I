#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodoPersona{
    string nombre;
    string apellido1;
    string apellido2;
    int aNacimiento;
    char genero;
    string provincia;
    int cedula;
    nodoPersona *siguiente;
};

typedef struct nodoPersona *lista;

nodoPersona *crearNodo(string n, string ap1, string ap2, int aNac, char g, string pro, int ced){

    nodoPersona *aux = new (struct nodoPersona);
    aux->nombre=n;
    aux->apellido1=ap1;
    aux->apellido2=ap2;
    aux->aNacimiento=aNac;
    aux->genero=g;
    aux->provincia=pro;
    aux->cedula=ced;
    aux->siguiente=NULL;
    return aux;
};
void agregarFinal(lista &cabeza, string n, string ap1, string ap2, int aNac, char g, string pro, int ced){

    nodoPersona *nuevo;
    nuevo=crearNodo(n,ap1,ap2,aNac,g,pro,ced);
    lista aux;
    if (cabeza == NULL)
        cabeza=nuevo;
    else{

        aux=cabeza;

            while (aux->siguiente!=NULL)
            aux=aux->siguiente;
        aux->siguiente=nuevo;

    }

};

void mostrarDatos(lista cabeza){
    lista aux;
    if (cabeza == NULL)
    {
        cout << "Lista Vacias" << endl;
    }
    else{
        aux=cabeza;
        while (aux!=NULL)
        {
            cout << "Nombre: " << aux->nombre<<endl;
            cout << "Apellido 1: " << aux->apellido1<<endl;
            cout << "Apellido 2: " << aux->apellido2<<endl;
            cout << "Fecha Naciemiento: " << aux->aNacimiento<<endl;
            cout << "Genero: " << aux->genero<<endl;
            cout << "Provincia: " << aux->provincia<<endl;
            cout << "Cedula" << aux->cedula<<endl;
            cout << "**********************************************" <<endl;
            aux=aux->siguiente;
        }
        
    }
    
};



int main(){
    
    lista List= NULL;
    agregarFinal(List, "Jesuar", "Miranda", "Zambrano", 2001, + 'm', "Chepe", 2345234);
    agregarFinal(List, "asdf", "Qwer", "asdf2", 2006, + 'm', "CArtago", 123497012);
    agregarFinal(List, "xczbzx", "Mizxcvranda", "Zambrasdfano", 1992, + 'm', "LIga", 12349034);
    agregarFinal(List, "oui", "nda", "Zambrano", 2001, + 'm', "lIMON", 12387);

};
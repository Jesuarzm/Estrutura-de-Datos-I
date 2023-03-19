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
    int edad;
    nodoPersona *siguiente;
};

typedef struct nodoPersona *lista;

nodoPersona *crearNodo(string n, string ap1, string ap2, int aNac, char g, string pro, int ced, int ed){

    nodoPersona *aux = new (struct nodoPersona);
    aux->nombre=n;
    aux->apellido1=ap1;
    aux->apellido2=ap2;
    aux->aNacimiento=aNac;
    aux->genero=g;
    aux->provincia=pro;
    aux->cedula=ced;
    aux->edad=ed;
    aux->siguiente=NULL;
    return aux;
};
void agregarFinal(lista &cabeza, string n, string ap1, string ap2, int aNac, char g, string pro, int ced){

    nodoPersona *nuevo;
    int ed = 2023 - aNac;
    nuevo=crearNodo(n,ap1,ap2,aNac,g,pro,ced, ed);
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
void modificarLista(lista cabeza,int ced, int ned){
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		do
		{
			if(aux->cedula==ced)
			aux->edad=ned;
			
			aux=aux->siguiente;
		}
		while(aux!=cabeza);
	}
}
void mostrarEdades(lista cabeza,int ed){
	lista aux;
    int cont = 0;
    if (cabeza == NULL)
    {
        cout << "Lista Vacias" << endl;
    }
    else{
        aux=cabeza;
        while (aux!=NULL)
        {
            if (aux->edad==ed)
            {
                cont++;
            }
            aux=aux->siguiente;
        }
        cout << "Hay " << cont 
        << " personas con la edad ingresada."<<endl;
    }
}
void contarPersonas(lista cabeza){
	lista aux;
    int cont = 0;
    if (cabeza == NULL)
    {
        cout << "Lista Vacias" << endl;
    }
    else{
        aux=cabeza;
        while (aux!=NULL)
        {
            if (aux->siguiente!=cabeza)
            {
                cont++;
            }
            aux=aux->siguiente;
        }
        cout << "Hay " << cont 
        << " personas."<<endl;
    }
}
void promedioEdad(lista cabeza){
	lista aux;
    int cont = 0, prom = 0;
    if (cabeza == NULL)
    {
        cout << "Lista Vacias" << endl;
    }
    else{
        aux=cabeza;
        while (aux!=NULL)
        {
            if (aux->siguiente!=cabeza)
            {
                cont++;
                prom+=aux->edad;
            }
            aux=aux->siguiente;
        }
        prom/=cont;
        cout << "El promedio de edad es: " << prom 
        <<endl;
    }
}
void personaProvincia(lista cabeza){
	lista aux;
    int cont = 0;
    int sj=0, ala=0, cart=0, her=0, lim=0, punt=0, guan=0;
    if (cabeza == NULL)
    {
        cout << "Lista Vacias" << endl;
    }
    else{
        aux=cabeza;
        while (aux!=NULL)
        {
            if (aux->provincia=="San Jose")
            {
                cont++;
                sj++;
            }
            if (aux->provincia=="Alajuela")
            {
                cont++;
                ala++;
            }
            if (aux->provincia=="Heredia")
            {
                cont++;
                her++;
            }
            if (aux->provincia=="Cartago")
            {
                cont++;
                cart++;
            }
            if (aux->provincia=="Puntarenas")
            {
                cont++;
                punt++;
            }
            if (aux->provincia=="Limon")
            {
                cont++;
                lim++;
            }
            if (aux->provincia=="Guanacasate")
            {
                cont++;
                guan++;
            }
            aux=aux->siguiente;
        }
        
        cout << "Las perseonas de San Jose son: " << sj <<endl;
        cout << "Las perseonas de Alajuela son: " << ala <<endl;
        cout << "Las perseonas de Heredia son: " << her <<endl;
        cout << "Las perseonas de Cartago son: " << cart <<endl;
        cout << "Las perseonas de Puntarenas son: " << punt <<endl;
        cout << "Las perseonas de Limon son: " << lim <<endl;
        cout << "Las perseonas de Guanacaste son: " << guan <<endl;
    }
}
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
            cout << "Edad: " << aux->edad << endl;
            cout << "**********************************************" <<endl;
            aux=aux->siguiente;
        }
        
    }
    
};



int main(){
    
    int edad;
    lista List= NULL;
    agregarFinal(List, "Jesuar", "Miranda", "Zambrano", 2001, + 'm', "San Jose", 2345234);
    agregarFinal(List, "asdf", "Qwer", "asdf2", 2006, + 'm', "Cartago", 123497012);
    agregarFinal(List, "xczbzx", "Mizxcvranda", "Zambrasdfano", 1992, + 'm', "Alajuela", 12349034);
    agregarFinal(List, "oui", "nda", "Zambrano", 2001, + 'm', "Limon", 12387);
    mostrarDatos(List);

    cout << "Por favor, ingrese la edad a busca:" << endl;
    cin >> edad;
    mostrarEdades(List, edad);
    contarPersonas(List);
    promedioEdad(List);
    personaProvincia(List);
};
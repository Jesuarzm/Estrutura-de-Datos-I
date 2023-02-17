#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoProceso
{
	string nombreProceso;
	int codigoProceso;	
	int memoriaProceso;
	string Estado;
	nodoProceso *sig;
	nodoProceso *ant;
};
typedef struct nodoProceso *lista;


nodoProceso *crearNodo(string n,int cod,int mem,
                       string est)
{
	nodoProceso *aux = new (struct nodoProceso);
	aux->nombreProceso=n;
	aux->codigoProceso=cod;
	aux->memoriaProceso=mem;
	aux->Estado=est;
	aux->sig=NULL;
	aux->ant=NULL;
	
	return aux;
};

void agregarFinal(lista &cabeza,string n,int cod,int mem,
                       string est)
{
	nodoProceso *nuevo;
	lista aux;
	
	nuevo=crearNodo(n,cod,mem,est);
	
	if(cabeza==NULL)
	{
		cabeza=nuevo;
		cabeza->sig=cabeza;
		cabeza->ant=cabeza;
	}
	else
	{
		aux=cabeza;
		while(aux->sig!=cabeza)
		aux=aux->sig;
		
		aux->sig=nuevo;
		nuevo->sig=cabeza;
		nuevo->ant=aux;
		cabeza->ant=nuevo;
			
	}
};
void agregarInicio(lista &cabeza,string n,int cod,int mem,
                       string est)
{
	nodoProceso *nuevo;
	lista aux;
	nuevo=crearNodo(n,cod,mem,est);
	
	nuevo=crearNodo(n,cod,mem,est);
	
	if(cabeza==NULL)
	{
		cabeza=nuevo;
		cabeza->sig=cabeza;
		cabeza->ant=cabeza;
	}
	else
	{
		aux=cabeza;
		while(aux->sig!=cabeza)
		aux=aux->sig;
		
        nuevo->ant=aux;
        aux->sig=nuevo;
        nuevo->sig=cabeza;
        cabeza=nuevo;
			
	}
};
void mostrarLista(lista cabeza)
{
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		do
		{
			cout<<"Nombre:" <<aux->nombreProceso<<endl;
			cout<<"Codigo:" <<aux->codigoProceso<<endl;
			cout<<"Memoria:" <<aux->memoriaProceso<<endl;
			cout<<"Estado:" <<aux->Estado<<endl;
			cout <<"******************************"<<endl;
			aux=aux->sig;
		}
		while(aux!=cabeza);
	}
};

bool consultaMemoria(lista cabeza){
    lista aux;
    int memoria=0;
    if(cabeza==NULL)
    return false;
	else
	{
        aux=cabeza;
		while(aux->sig!=cabeza){
		    aux=aux->sig;
            memoria= memoria + aux->memoriaProceso;
        }
        if (memoria > 500)
        {
            return true;
        }else{
            return false;
        }
    }
    
}
int main()
{
    bool estado = true;
	lista milista=NULL;
	agregarInicio(milista,"Chrome",1,100,"ACTIVO");
   
	agregarInicio(milista,"Code",2,80,"ACTIVO");
   
	agregarFinal(milista,"Spotify",3,40,"ACTIVO");
   
	agregarInicio(milista,"LOL",4,30,"ACTIVO");


        do{
        int opc = 0;
        cout << "Menu:" << endl;
        cout << "1: Agregar proceso" << endl;
        cout << "2: Administrdor de Memoria" << endl;
        cout << "3: Modificar Proceso" << endl;
        cout << "4: Mostar Procesos Activos" << endl;
        cout << "5: Mostrar Proceos Inactivos" << endl;
        
        cout << "6: SALIR" << endl;
        
        cin >> opc;

        if (opc == 1 && consultaMemoria(milista)==true)
        {
            string n;
            int cod, mem, opc2;

            cout << "Ingrese el nombre del proceso:" << endl;
            cin >> n;
            cout << "Ingrese el codifo del proceso:" << endl;
            cin >> cod;
            cout << "Ingrese el cosumo del proceso:" << endl;
            cin >> mem;
            cout << "¿El proceso esta activo? \n1:Si \n2:No" << endl;
            cin >> opc2;
            if (opc2 == 1)
            {
                agregarInicio(milista, n,cod, mem, "ACTIVO");
                opc=0;
            }else{
                agregarInicio(milista, n,cod, mem, "INACTIVO");
                opc=0;
            }
            
        }
        if (opc == 1 && consultaMemoria(milista)==false)
        {
            string n;
            int cod, mem, opc2;

            cout << "Ingrese el nombre del proceso:" << endl;
            cin >> n;
            cout << "Ingrese el codifo del proceso:" << endl;
            cin >> cod;
            cout << "Ingrese el cosumo del proceso:" << endl;
            cin >> mem;
            cout << "¿El proceso esta activo? \n1:Si \n2:No" << endl;
            cin >> opc2;
            if (opc2 == 1)
            {
                agregarFinal(milista, n,cod, mem, "ACTIVO");
                opc=0;
            }else{
                agregarFinal(milista, n,cod, mem, "INACTIVO");
                opc=0;
            }
            
        }
        if (opc==2)
        {
            mostrarLista(milista);
            opc=0;
        }
        
        if (opc == 6)
        {
            estado = false;
        }
        
        
        
    }while (estado==true);
    

};
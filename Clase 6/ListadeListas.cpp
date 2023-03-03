#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoPais{
	string nombre;
	nodoPais *sig;
};

struct nodoLetra{
	char letra;
	nodoLetra *sig;
	nodoPais *sigPais;
};

typedef struct nodoLetra *lista;

nodoLetra *crearNodo(char l){

	nodoLetra *aux = new (struct nodoLetra);
	aux->letra=l;
	aux->sig=NULL;
	aux->sigPais=NULL;

	return aux;
};

nodoPais *crearNodoPais(string p){
	
	nodoPais *aux = new (struct nodoPais);
	aux->nombre=p;
	aux->sig=NULL;

	return aux;
};

void ingresarFinal(lista &cabeza, char letra){

	nodoLetra *nuevo;
	lista aux;
	nuevo=crearNodo(letra);

	if (cabeza==NULL){
		cabeza=nuevo;
	}else{
		aux=cabeza;
		while (aux->sig!= NULL)
		{
			aux= aux->sig;
		}
		aux->sig=nuevo;
		
	}
	

};
void ingresarPais(lista &cabeza, string pais){

	lista aux;
	nodoPais *nuevo,*auxPais;
	nuevo=crearNodoPais(pais);

	if (cabeza==NULL)
	{
		cout << "Lista Vacias";
	}else{
		aux=cabeza;
		while (aux!=NULL)
		{
			if (aux->letra==pais[0])
			{
				if (aux->sigPais==NULL)	
				{
					aux->sigPais=nuevo;
				}else{
					auxPais=aux->sigPais;
					while (auxPais->sig!=NULL)
					{
						auxPais=auxPais->sig;
					}
					auxPais->sig=nuevo;
				}
				
			}
			
			aux=aux->sig;
		}
		
	}
	
};
void mostrarLista(lista cabeza){
	lista aux;
	nodoPais *auxP;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			cout << "++++++++++++++++" << endl;
			cout << "Letra: " << aux->letra << endl;
			if (aux->sigPais!=NULL)
			{
				auxP=aux->sigPais;
				while (auxP!=NULL)
				{
					cout << "Pais: " << auxP->nombre << endl;
					cout << "++++++++++++++++" << endl;
					auxP=auxP->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
void eliminarPais(lista cabeza, string pais){
	lista aux;
	nodoPais *auxP;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			if (aux->sigPais!=NULL)
			{
				auxP=aux->sigPais;
				while (auxP!=NULL)
				{
					if (auxP->nombre==pais)
					{
						aux->sigPais=NULL;
						free(auxP);
					}
					
					auxP=auxP->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
int main(){
	lista Lista=NULL;

	ingresarFinal(Lista, 'A');
	ingresarFinal(Lista, 'B');
	ingresarFinal(Lista, 'C');
	ingresarFinal(Lista, 'D');
	ingresarFinal(Lista, 'E');

	ingresarPais(Lista, "Argentina");
	ingresarPais(Lista, "Bolivia");
	ingresarPais(Lista, "Costa Rica");
	ingresarPais(Lista, "Dinamarca");
	ingresarPais(Lista, "Estados Unidos");

	mostrarLista(Lista);
	system("read -rp $'Press [Enter] to continue...\n' key");
	
	eliminarPais(Lista, "Argentina");

	eliminarPais(Lista, "Panama");
	eliminarPais(Lista, "Estados Unidos");

	mostrarLista(Lista);
	system("read -rp $'Press [Enter] to continue...\n' key");


	ingresarPais(Lista, "Argentina");
	mostrarLista(Lista);
	system("read -rp $'Press [Enter] to continue...\n' key");
	
};
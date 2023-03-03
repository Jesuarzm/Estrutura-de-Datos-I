#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodoUsuario{
    string nombre;
    string primerApellido;
    string segundoApellido;
    int telefono;
    int celular;
    int oficina;
    int cedula;
    string correo;
    string provincia;
    nodoUsuario *sig;
};

struct nodoAbecedario{
    char letra;
    nodoAbecedario *sig;
    nodoUsuario *sigUsuario;
};

typedef struct nodoAbecedario *lista;

nodoUsuario *crearNodoUsuario(string n, string prApellido, string segApellido, 
int tel, int cel, int ofi, int ced, string co,string prov){
    nodoUsuario *aux = new (struct nodoUsuario);
    aux->nombre=n;
    aux->primerApellido=prApellido;
    aux->segundoApellido=segApellido;
    aux->telefono=tel;
    aux->celular=cel;
    aux->oficina=ofi;
    aux->cedula=ced;
    aux->correo=co;
    aux->provincia=prov;

    return aux;
}

nodoAbecedario *crearNodo(char l){
    nodoAbecedario *aux = new (struct nodoAbecedario);
    aux->letra=l;
    aux->sig=NULL;
    aux->sigUsuario=NULL;

return aux;
}

void ingresarAbc(lista &cabeza, char letra){
    nodoAbecedario *nuevo;
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
}

void ingresarUsuario(lista &cabeza,string n, string prApellido, string segApellido, 
int tel, int cel, int ofi, int ced, string co,string prov){
    lista aux;
	nodoUsuario *nuevo,*auxUsuario;
	nuevo=crearNodoUsuario(n,prApellido, segApellido, tel, cel, ofi, ced, co, prov);

	if (cabeza==NULL)
	{
		cout << "Lista Vacias";
	}else{
		aux=cabeza;
		while (aux!=NULL)
		{
			if (aux->letra==prApellido[0])
			{
				if (aux->sigUsuario==NULL)	
				{
					aux->sigUsuario=nuevo;
				}else{
					auxUsuario=aux->sigUsuario;
					while (auxUsuario->sig!=NULL)
					{
						auxUsuario=auxUsuario->sig;
					}
					auxUsuario->sig=nuevo;
				}
				
			}
			
			aux=aux->sig;
		}
		
	}
}
void mostrarLista(lista cabeza){
	lista aux;
	nodoUsuario *auxUsr;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			cout << "++++++++++++++++" << endl;
			cout << "Letra: " << aux->letra << endl;
			if (aux->sigUsuario!=NULL)
			{
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL)
				{
					cout << "Nombre: " << auxUsr->nombre << endl;
                    cout << "Apellidos: " << auxUsr->primerApellido << " "<< auxUsr->segundoApellido << endl;
                    cout << "Telefonos: " << auxUsr->telefono << endl;
                    cout << "Correo: " << auxUsr->correo << endl;
                    cout << "Provincia: " << auxUsr->provincia << endl;

					cout << "++++++++++++++++" << endl;
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
int main(){
	lista Lista=NULL;

	ingresarAbc(Lista, 'A');
	ingresarAbc(Lista, 'B');
	ingresarAbc(Lista, 'C');
	ingresarAbc(Lista, 'D');
	ingresarAbc(Lista, 'E');
	ingresarAbc(Lista, 'F');
	ingresarAbc(Lista, 'G');
	ingresarAbc(Lista, 'H');
	ingresarAbc(Lista, 'I');
	ingresarAbc(Lista, 'J');
	ingresarAbc(Lista, 'K');
	ingresarAbc(Lista, 'L');
	ingresarAbc(Lista, 'M');
	ingresarAbc(Lista, 'N');
	ingresarAbc(Lista, 'O');
	ingresarAbc(Lista, 'P');
	ingresarAbc(Lista, 'Q');
	ingresarAbc(Lista, 'R');
	ingresarAbc(Lista, 'S');
	ingresarAbc(Lista, 'T');
	ingresarAbc(Lista, 'U');
	ingresarAbc(Lista, 'V');
	ingresarAbc(Lista, 'W');
	ingresarAbc(Lista, 'X');
	ingresarAbc(Lista, 'Y');
	ingresarAbc(Lista, 'Z');

    ingresarUsuario(Lista, "Jesuar", "Miranda", "Zambrano", 84092380,
    84092380 , 84092380, 82558001, "jesuarzambrano@hotmail.com", "CHepe");

    mostrarLista(Lista);

};
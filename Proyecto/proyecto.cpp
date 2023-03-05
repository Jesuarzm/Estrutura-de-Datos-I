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
void contarContatos(lista cabeza){
	lista aux;
	nodoUsuario *auxUsr;
	int cantUsr = 0;
	if(cabeza ==NULL){
		cout << "Sin contactos registrados." << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL)
			{
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL)
				{
					cantUsr++;
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		cout << "**********************" << endl;
		cout << "Cantidad de contactos: " << cantUsr << endl;
		cout << "**********************" << endl;
		
	}
};
void contarProvincia(lista cabeza, string prov){
	lista aux;
	nodoUsuario *auxUsr;
	int cantUsr = 0;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL)
			{
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL)
				{
					if (auxUsr->provincia == prov)
					{
						cantUsr++;
					}
					
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		cout << "**********************" << endl;
		cout << "Provincia: " << prov << endl;
		cout << "**********************" << endl;
		cout << "Cantidad de contactos: " << cantUsr << endl;
		cout << "**********************" << endl;
	}
};
void contarLetras(lista cabeza, char letra){
	lista aux;
	nodoUsuario *auxUsr;
	int cantUsr = 0;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL)
			{
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL)
				{
					if (auxUsr->primerApellido[0]== letra)
					{
						cantUsr++;
					}
					
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		cout << "**********************" << endl;
		cout << "Letra : " << letra << endl;
		cout << "**********************" << endl;
		cout << "Cantidad de contactos: " << cantUsr << endl;
		cout << "**********************" << endl;
	}
};
int main(){

	bool estado = true;
	
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

	
	
	do{
		char letraIn;
		string prov;
        int opc = 0;
		system("clear");
        cout << "Menu:" << endl;
        cout << "****** Contactos *****" << endl;
        cout << "1: Agregar " << endl;
        cout << "2: Borrar " << endl;
        cout << "3: Editar " << endl;
        cout << "****** Busqueda *****" << endl;
        cout << "4: Por numero" << endl;
        cout << "5: Por cedula" << endl;
        cout << "****** Reportes *****" << endl;
        cout << "6: Por Provincia" << endl;
        cout << "7: Contactos Registrados" << endl;
        cout << "8: Cantidad por provincia" << endl;
        cout << "9: Cantidad por inicial" << endl;
        cout << "*********************" << endl;
        cout << "10: SALIR" << endl;
        
        cin >> opc;

		if (opc == 7){
			system("clear");
			contarContatos(Lista);
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		if (opc == 8){
			system("clear");
			cout << "Ingresa la provincia a contar" << endl;
			cin >> prov;
			contarProvincia(Lista, prov);
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		if (opc == 9){
			system("clear");
			cout << "Ingresa la letra a contar" << endl;
			cin >> letraIn;
			contarLetras(Lista, letraIn);
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		
		if (opc == 10)
		{
			estado = false;
		}/*
		if (opc != 1 or 2 or 3 or 4 
		or 5 or 6 or 7 or 8 or 9 or 10){
			system("clear");
			cout << "Ingresar una opcion valida:" << endl;
			opc = 0;
		}*/
		
		
	}while (estado == true);
	
};
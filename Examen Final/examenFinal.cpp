#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct nodoArbol {
    char caracter;
    nodoArbol *izq;
    nodoArbol *der;
};


typedef struct nodoArbol *arbol;

nodoArbol *crearNodo(char num)
{
	nodoArbol *aux = new (struct nodoArbol);
	aux->caracter=num;
	aux->der=NULL;
	aux->izq=NULL;
	return aux;
}
void insertar(arbol &cab,char x){

	nodoArbol *nuevo;
	arbol aux;
	
	if(cab==NULL)
	{
	nuevo=crearNodo(x);	
	cab=nuevo;
	}
	
	else
	{
	  	aux=cab;
	  	if(x > aux->caracter)
	  	insertar(aux->der,x);
	  	else
	  	insertar(aux->izq,x);	
	}	
}
void verarbol(arbol raiz, char letra){
 int i;
 if(raiz==NULL)
 return;
 	verarbol(raiz->der,letra+1);
 	
	for(i=0;i<letra;i++)
    cout<<"->";
    
	cout<<" " << raiz->caracter<<endl;
 
 	verarbol(raiz->izq,letra+1);
}
void inOrden(arbol raiz)
{
    if (raiz != NULL)
    {
        inOrden(raiz->izq);
        cout <<"->"<<raiz->caracter;
        inOrden(raiz->der);
    }
}
int contarMayusculas(arbol raiz){
    int cont=0;
		
    if(raiz==NULL)
    return 0;
    else
    {
        if(raiz->caracter >= 65 and raiz-> caracter <= 90)
        {
        cont=cont+1;
        }

    }

	return cont+contarMayusculas(raiz->der)+contarMayusculas(raiz->izq);
}
int contarMinusculas(arbol raiz){
    int cont=0;
		
    if(raiz==NULL)
    return 0;
    else
    {
        if(raiz->caracter >= 97 and raiz-> caracter <= 122)
        {
        cont=cont+1;
        }

    }

	return cont+contarMinusculas(raiz->der)+contarMinusculas(raiz->izq);
}

void buscarDuplicados(arbol raiz, bool mayusculas[], bool minusculas[])
{
    if (raiz == NULL)
        return;

    if (raiz->caracter >= 'A' && raiz->caracter <= 'Z')
    {
        if (mayusculas[raiz->caracter - 'A'])
            cout << raiz->caracter << " esta duplicado en mayusculas." << endl;
        else
            mayusculas[raiz->caracter - 'A'] = true;
    }
    else if (raiz->caracter >= 'a' && raiz->caracter <= 'z')
    {
        if (minusculas[raiz->caracter - 'a'])
            cout << raiz->caracter << " esta duplicado en minusculas." << endl;
        else
            minusculas[raiz->caracter - 'a'] = true;
    }

    buscarDuplicados(raiz->izq, mayusculas, minusculas);
    buscarDuplicados(raiz->der, mayusculas, minusculas);
}

int contarLetras(arbol raiz) {
   int cont=0;
		
		if(raiz==NULL)
		return 0;
		else
		{
			 cont=cont+ 1;
		}

	return cont+contarLetras(raiz->der)+contarLetras(raiz->izq);
}

void marcarLetras(arbol raiz, bool letras[]) {
    if (raiz == NULL) {
        return;
    }

    // Si el caracter está en el rango de letras permitido, marcar en el arreglo
    if (raiz->caracter >= 'a' && raiz->caracter <= 'z') {
        letras[raiz->caracter - 'a'] = true;
    } else if (raiz->caracter >= 'A' && raiz->caracter <= 'Z') {
        letras[raiz->caracter - 'A'] = true;
    }

    marcarLetras(raiz->izq, letras);
    marcarLetras(raiz->der, letras);
}

void letrasEnPalabra(arbol raiz, string palabra) {
    // Arreglo de booleanos para representar las letras en el alfabeto
    bool letras[26] = {false};

    // Marcar las letras presentes en el árbol
    marcarLetras(raiz, letras);

    // Verificar si cada letra de la palabra está presente en el arreglo de letras
    for (char c : palabra) {
        if (c >= 'a' && c <= 'z') {
            if (letras[c - 'a']) {
                cout << c << " está en el árbol y en la palabra" << endl;
            } else {
                cout << c << " está en la palabra pero no en el árbol" << endl;
            }
        } else if (c >= 'A' && c <= 'Z') {
            if (letras[c - 'A']) {
                cout << c << " está en el árbol y en la palabra" << endl;
            } else {
                cout << c << " está en la palabra pero no en el árbol" << endl;
            }
        }
    }
}


int main(){

    arbol Arb=NULL;
    bool mayusculas[26] = {false};
    bool minusculas[26] = {false};
    string palabra;
    system("clear");
    cout << "Cacracteres ingresados: " << endl;
    insertar(Arb,'A');
    insertar(Arb,'A');
    insertar(Arb,'C');
	insertar(Arb,'B');
	insertar(Arb,'E');
    insertar(Arb,'D');
	insertar(Arb,'F');
	insertar(Arb,'E');

    verarbol(Arb,5);
    system("read -rp $'Press [Enter] to continue...\n' key");
			

    system("clear");
    cout << "Caracteres Ordenados" << endl;
    inOrden(Arb);

    cout << "\nMayor a Menor" << endl;
    system("read -rp $'Press [Enter] to continue...\n' key");

    system("clear");
    cout << "Total de letras mayusculas: " << contarMayusculas(Arb) << endl;

    system("read -rp $'Press [Enter] to continue...\n' key");

    system("clear");
    cout << "Total de letras mayusculas: " << contarMinusculas(Arb) << endl;

    system("read -rp $'Press [Enter] to continue...\n' key");

    system("clear");
    buscarDuplicados(Arb, mayusculas, minusculas);
    system("read -rp $'Press [Enter] to continue...\n' key");

    system("clear");
    cout << "Hay un total de: " << contarLetras(Arb) << " letras" << endl;
    system("read -rp $'Press [Enter] to continue...\n' key");

    system("clear");
    cout << "Porfavor ingrese una palabra" << endl;
    cin >> palabra;
    letrasEnPalabra(Arb, palabra);
    system("read -rp $'Press [Enter] to continue...\n' key");
}
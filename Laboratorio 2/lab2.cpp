#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct nodoArticulo{
    string nombreArticulo;
    int codigoProduto;
    int cantidad;
    double precio;
    nodoArticulo *sig;
    nodoArticulo *ant;
};

typedef struct nodoArticulo *lista;

nodoArticulo *crearArticulo (string nombreA, int codigoA, int cantA, double precioA){
    nodoArticulo *aux = new (struct nodoArticulo);
    aux->nombreArticulo=nombreA;
    aux->codigoProduto=codigoA;
    aux->cantidad=cantA;
    aux->precio=precioA;
    aux->sig=NULL;
    aux->ant=NULL;
    
    return aux;
};

void agregarFinal(lista &cabeza,string nombreA, int codigoA, int cantA, double precioA){
	nodoArticulo *nuevo;
	lista aux;
	
	nuevo=crearArticulo(nombreA, codigoA, cantA, precioA);
	
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
}
void borrarArticulo(lista &cabeza, int cod)
{
	lista aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		if(aux->codigoProduto==cod)
		{
			cabeza=aux->sig;
			cabeza->ant=aux->ant;
			aux->ant->sig=cabeza;
			aux->sig=NULL;
			aux->ant=NULL;
			free(aux);
			aux=cabeza;
		}
		else
		{
			aux=cabeza;
			do
			{
				if(aux->codigoProduto==cod && aux->sig!=cabeza)
				{
					aux->ant->sig=aux->sig;
					aux->sig->ant=aux->ant;
					aux->sig=NULL;
					aux->ant=NULL;
					free(aux);
					aux=cabeza;
					
				}
				else
				if(aux->codigoProduto==cod && aux->sig==cabeza)
				{
					cabeza->ant=aux->ant;
					aux->ant->sig=cabeza;
					aux->sig=NULL;
					aux->ant=NULL;
					free(aux);
					aux=cabeza;
					
				}
				
				
				aux=aux->sig;
			}
			while(aux!=cabeza);
		}
	}
}
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
			cout<<"Nombre:" <<aux->nombreArticulo<<endl;
			cout<<"Codigo:" <<aux->codigoProduto<<endl;
			cout<<"Precio:" <<aux->precio<<endl;
			cout<<"Cantidad:" <<aux->cantidad<<endl;
			cout <<"******************************"<<endl;
			aux=aux->sig;
		}
		while(aux!=cabeza);
	}
}
int main(){
    bool estado = true;
    lista miLista = NULL;

    cout << "Lista de productos" << endl;
    agregarFinal(miLista, "Arroz", 1, 100, 1400);
    agregarFinal(miLista, "Frijoles", 2, 100, 1700);
    agregarFinal(miLista, "Queso", 3, 100, 1000);
    mostrarLista(miLista);
    cout << "---------------------" << endl;
    cout << "Borrar elemento 2" << endl;
    cout << "---------------------" << endl;
    borrarArticulo(miLista, 2);
    mostrarLista(miLista);

    do{
        int opc = 0;
        string nomA ="";
        int codA=0;
        int cantA=0;
        double preA=0;
        system("clear");
        cout << "Menu:" << endl;
        cout << "****** Articulos *****" << endl;
        cout << "1: Agregar " << endl;
        cout << "2: Borrar " << endl;
        cout << "3: Modificar " << endl;
        cout << "****** Reportes *****" << endl;
        cout << "4: Mostrar Todos " << endl;
        cout << "5: Mostrar Por Codigo " << endl;
        cout << "6: Mostar Precios Totales " << endl;
        cout << "*********************" << endl;
        cout << "7: SALIR" << endl;
        
		cout << "\nOpcion:" << endl;
        
        cin >> opc; 

        if (opc == 1)
        {
            system("clear");
			cout << "Ingrese la descripcion del articulo " << endl;
			cin >> nomA;
            system("clear");
			cout << "Ingrese el codigo del articulo" << endl;
			cin >> codA;
            system("clear");
			cout << "Ingrese la cantidad del articulo " << endl;
			cin >> cantA;
            system("clear");
			cout << "Ingrese el precio del articulo " << endl;
			cin >> preA;
			agregarFinal(miLista, nomA, codA, cantA, preA);
			system("read -rp $'Press [Enter] to continue...\n' key");
        }
        if (opc == 2)
        {
            
        }
        if (opc == 3)
        {
            
        }
        if (opc == 4){
            system("clear");
            mostrarLista(miLista);
            system("read -rp $'Press [Enter] to continue...\n' key");
			
        }
        
        
        if (!(opc >= 0 and opc <= 7)){
			system("clear");
			cout << "Ingresar una opcion valida:" << endl;
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
              
    }while (estado == true);
    

}
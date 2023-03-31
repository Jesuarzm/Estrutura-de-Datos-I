#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct 	nodoPersona{
    int idPersona;
    string nombre;
	string correo;
	nodoPersona *sig;
};

struct 	nodoHabitaciones{
    int idHabitacion;
	int precio;
    string tamano;
	nodoHabitaciones *sig;
};
struct nodoLlegadas{
    int idHabitacion;
	int precio;
    string tamano;
	nodoLlegadas *sig;
};

typedef struct nodoPersona *listaPersonas;
typedef struct nodoHabitaciones *listaHabitaciones;
typedef struct nodoLlegadas *listaLlegadas;

nodoPersona *crearPersona(int id, string name, string mail)
{
	nodoPersona *aux = new (struct nodoPersona);
	aux->idPersona=id;
    aux->nombre=name;
	aux->correo=mail;
	aux->sig=NULL;
	return aux;
}

nodoHabitaciones *crearHabitacion(int id, string name, int price)
{
	nodoHabitaciones *aux = new (struct nodoHabitaciones);
	aux->idHabitacion=id;
	aux->precio=price;
    aux->tamano=name;
	aux->sig=NULL;
	return aux;
}
nodoLlegadas *crearReserva(int id, string name, int price)
{
	nodoLlegadas *aux = new (struct nodoLlegadas);
	aux->idHabitacion=id;
	aux->precio=price;
    aux->tamano=name;
	aux->sig=NULL;
	return aux;
}
void agregarPersona(listaPersonas &cab,int id, string name, string mail){

	listaPersonas aux;
	nodoPersona *nuevo;
	nuevo=crearPersona(id, name, mail);
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		aux->sig=nuevo;
	}
    
}
void agregarHabitacion(listaHabitaciones &cab, int id, string size, int price)
{
	listaHabitaciones aux;
	nodoHabitaciones *nuevo;
	nuevo=crearHabitacion(id, size, price);
	
	
	if(cab==NULL)
	cab=nuevo;
	else
	{
		aux=cab;
		while(aux->sig!=NULL)
		aux=aux->sig;
		
		aux->sig=nuevo;
	}
}
nodoHabitaciones *ocuparHabitacion(listaHabitaciones &cab, listaLlegadas &cab2){

	nodoHabitaciones *aux;
	listaLlegadas auxHab;
	nodoLlegadas *nuevo;

	if(cab==NULL)
	{
	 cout <<"Ninguna habitacion"<<endl;
	 return NULL;
	}
	else
	{
		aux=cab;
		cab=cab->sig;
		aux->sig=NULL;

	}
	nuevo=crearReserva(aux->idHabitacion, aux->tamano, aux->precio);
	if(cab2==NULL)
	cab2=nuevo;
	else
	{
		auxHab=cab2;
		while(auxHab->sig!=NULL)
		auxHab=auxHab->sig;
		
		auxHab->sig=nuevo;
	}
	return aux;
}
nodoLlegadas *desocuparHabitacion(listaLlegadas &cab, listaHabitaciones &cab2){

	nodoLlegadas *aux;
	listaHabitaciones auxHab;
	nodoHabitaciones *nuevo;
	if(cab==NULL)
	{
	 cout <<"No hay habitaciones ocupadas"<<endl;
	 return NULL;
	}
	else
	{
		aux=cab;
		cab=cab->sig;
		aux->sig=NULL;
		return aux;
	}

	nuevo=crearHabitacion(aux->idHabitacion, aux->tamano, aux->precio);
	if(cab2==NULL)
	cab2=nuevo;
	else
	{
		auxHab=cab2;
		while(auxHab->sig!=NULL)
		auxHab=auxHab->sig;
		
		auxHab->sig=nuevo;
	}
	return aux;
}
void MostrarP(listaPersonas cab)
{
	listaPersonas aux;
	
	if(cab==NULL)
	cout <<"Sin clientes registrados"<<endl;
	else
	{
		aux=cab;
		while(aux!=NULL)
		{
			cout <<"Id: "<<aux->idPersona<<endl;
			cout <<"Nombre: "<<aux->nombre<<endl;
			cout <<"Correo: "<<aux->correo<<endl;
			cout <<"------------------------------"<<endl;
			aux=aux->sig;
		}
	}
}
void MostrarH(listaHabitaciones cab)
{
	listaHabitaciones aux;
	
	if(cab==NULL)
	cout <<"Todas la habitaciones llenas"<<endl;
	else
	{
		aux=cab;
		cout << "<---------Habitacion a usar------------->" << endl;
		cout << "<---------|||||||||||||||||------------->" << endl;
		cout << "<---------vvvvvvvvvvvvvvvvv------------->" << endl;  
        while(aux!=NULL)
		{
			cout << "Habitacion: " << aux->idHabitacion << endl;
            cout << "Tamaño: " << aux->tamano << endl;
			cout <<"Precio: " << aux->precio << endl;
            cout << "<---------------------->" << endl;  
			aux=aux->sig;
		}
	}
}
void MostrarHOcup(listaLlegadas cab)
{
	listaLlegadas aux;
	
	if(cab==NULL)
	cout <<"Todas la habitaciones desocupadas"<<endl;
	else
	{
		aux=cab;
		cout << "<---------------------->" << endl;  
        while(aux!=NULL)
		{
			cout << "Habitacion: " << aux->idHabitacion << endl;
            cout << "Tamaño: " << aux->tamano << endl;
			cout <<"Precio: " << aux->precio << endl;
            cout << "<---------------------->" << endl;  
			aux=aux->sig;
		}
	}
}
int main()
{

    bool estado = true;

	listaPersonas personas=NULL;
    listaHabitaciones habitaciones=NULL;
	listaLlegadas llegadas = NULL;

	agregarPersona(personas,1,"Jesuar", "jzm@gmai.com");
	agregarPersona(personas,2,"Ash", "ash@gmail.com");
    agregarHabitacion(habitaciones,517,"Grande", 1000);
    agregarHabitacion(habitaciones,518,"Grande", 1000);
    agregarHabitacion(habitaciones,519,"Grande", 2000);
    agregarHabitacion(habitaciones,520,"Grande", 1500);
    agregarHabitacion(habitaciones,521,"Grande", 1700);

    do{
        int opc = 0;
		system("clear");
        cout << "****** Hotel Transilvania *****" << endl;
        cout << "Menu:" << endl;
        cout << "***** Cliente ******" << endl;
        cout << "1: Agregar " << endl;
        cout << "2: Eliminar " << endl;
		cout << "3: Mostrar Todos " << endl;
		

        cout << "***** Habitaciones ******" << endl;
        cout << "4: Agregar " << endl;
        cout << "5: Eliminar " << endl;
    
        
        cout << "***** Hospedaje ******" << endl;
        cout << "6: Nuevo" << endl;
        cout << "7: Terminar" << endl;

		cout << "***********" << endl;
		cout << "8: SALIR" << endl;
        
		cout << "\nOpcion:" << endl;
        
        cin >> opc;

		if (opc == 1)
		{
			int idUsr;
			string nameUsr, mailUsr;
			system("clear");
			cout << "Ingresar el numero de ID del usuario: " << endl;
			cin >> idUsr;

			system("clear");
			cout << "Ingresar el nombre del usuario: " << endl;
			cin >> nameUsr;


			system("clear");
			cout << "Ingresar el correo del usuario: " << endl;
			cin >> mailUsr;

			agregarPersona(personas, idUsr, nameUsr, mailUsr);

			opc =0;
		}
		

		if (opc == 3){
			system("clear");
            MostrarP(personas);
			opc =0;
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
		if (opc == 6)
		{
			int idUsr, idHab;
			system("clear");
			cout << "Ingrese del ID del cliente" << endl;
			cin >> idUsr;

			system("clear");
			cout << "Habitaciones disponibles: " << endl;
            MostrarH(habitaciones);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
            ocuparHabitacion(habitaciones, llegadas);


			opc = 0;
		}
		if (opc == 7){
			system("clear");
			MostrarHOcup(llegadas);
			system("read -rp $'Press [Enter] to continue...\n' key");

			desocuparHabitacion(llegadas, habitaciones);
		}
		
		
		if (opc == 8)
		{
			system("clear");
			estado = false;
		}
        if (!(opc >= 0 and opc <= 8)){
			system("clear");
			cout << "Ingresar una opcion valida:" << endl;
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		
	}while (estado == true);

	
}
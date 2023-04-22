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
void eliminarUsuario(lista cabeza, int cel){
	lista aux;
	nodoUsuario *auxUsr;
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
					if (auxUsr->celular==cel)
					{
						aux->sigUsuario=NULL;
						free(auxUsr);
					}
					
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
void modificarUsuario(lista cabeza, int ced, string nombre, string apellido1, string apellido2 ,int tel, int cel, int ofi){
	lista aux;
	nodoUsuario *auxUsr;
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
					if (auxUsr->cedula==ced)
					{
						auxUsr->nombre=nombre;
						auxUsr->primerApellido=apellido1;
						auxUsr->segundoApellido=apellido2;
						auxUsr->celular=cel;
						auxUsr->oficina=ofi;
						auxUsr->telefono=tel;
					}
					
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
void mostrarProvincia(lista cabeza, string prov){
	lista aux;
	nodoUsuario *auxUsr;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		cout << "++++++++++++++++" << endl;
		cout << "Provincia: " << prov << endl;
		cout << "++++++++++++++++" << endl;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL)
			{
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL)
				{
					if (auxUsr->provincia == prov){
					cout << "Cedula: " << auxUsr->cedula << endl;
                    cout << "Nombre: " << auxUsr->nombre << endl;
                    cout << "Apellidos: " << auxUsr->primerApellido << " "<< auxUsr->segundoApellido << endl;
                    cout << "Telefonos: " << auxUsr->telefono << endl;
                    cout << "Correo: " << auxUsr->correo << endl;
                    cout << "Provincia: " << auxUsr->provincia << endl;
					cout << "++++++++++++++++" << endl;
					}
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
void mostrarLetra(lista cabeza, char letra){
	lista aux;
	nodoUsuario *auxUsr;
	if(cabeza ==NULL){
		cout << "Lista Vacia" << endl;
	}else{
		aux=cabeza;
		cout << "++++++++++++++++" << endl;
		cout << "Letra: " << letra << endl;
		cout << "++++++++++++++++" << endl;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL){
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL){

					if (auxUsr->primerApellido[0]==letra){
					cout << "Cedula: " << auxUsr->cedula << endl;
					cout << "Nombre: " << auxUsr->nombre << endl;
                    cout << "Apellidos: " << auxUsr->primerApellido << " "<< auxUsr->segundoApellido << endl;
                    cout << "Telefonos: " << auxUsr->telefono << endl;
                    cout << "Correo: " << auxUsr->correo << endl;
                    cout << "Provincia: " << auxUsr->provincia << endl;
					cout << "++++++++++++++++" << endl;
					}
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
void buscarNumero(lista cabeza, int num){
	lista aux;
	nodoUsuario *auxUsr;
	if(cabeza ==NULL){
		cout << "No hay numero registrado con: "<< num << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL){
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL){

					if (auxUsr->celular==num){
					cout << "Cedula: " << auxUsr->cedula << endl;
					cout << "Nombre: " << auxUsr->nombre << endl;
                    cout << "Apellidos: " << auxUsr->primerApellido << " "<< auxUsr->segundoApellido << endl;
                    cout << "Telefonos: " << auxUsr->telefono << endl;
                    cout << "Correo: " << auxUsr->correo << endl;
                    cout << "Provincia: " << auxUsr->provincia << endl;
					cout << "++++++++++++++++" << endl;
					}
					auxUsr=auxUsr->sig;
				}
				
			}
			aux=aux->sig;
		}
		
	}
};
void buscarCedula(lista cabeza, int ced){
	lista aux;
	nodoUsuario *auxUsr;
	if(cabeza ==NULL){
		cout << "No hay numero registrado con: "<< ced << endl;
	}else{
		aux=cabeza;
		while (aux!=NULL){	
			if (aux->sigUsuario!=NULL){
				auxUsr=aux->sigUsuario;
				while (auxUsr!=NULL){

					if (auxUsr->cedula==ced){
					cout << "Cedula: " << auxUsr->cedula << endl;
					cout << "Nombre: " << auxUsr->nombre << endl;
                    cout << "Apellidos: " << auxUsr->primerApellido << " "<< auxUsr->segundoApellido << endl;
                    cout << "Telefonos: " << auxUsr->telefono << endl;
                    cout << "Correo: " << auxUsr->correo << endl;
                    cout << "Provincia: " << auxUsr->provincia << endl;
					cout << "++++++++++++++++" << endl;
					}
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
    84092380 , 84092380, 822558001, "jesuarzambrano@hotmail.com", "San José");

	
	
	do{
		char letraIn;
		string prov;
		string nombre, apl1,apl2,mail;
		int cel=0;
		int ofi=0;
		int tel=0;
		int ced=0;
		int num=0;
        int opc = 0;
		int opcProv=0;
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
		cout << "7: Por Inicial" << endl;
        cout << "8: Contactos Registrados" << endl;
        cout << "9: Cantidad por provincia" << endl;
        cout << "10: Cantidad por inicial" << endl;
        cout << "*********************" << endl;
        cout << "11: SALIR" << endl;
        
		cout << "\nOpcion:" << endl;
        
        cin >> opc;



		if (opc == 1){
			system("clear");
			cout << "Ingrese el nuevo nombre" << endl;
			cin >> nombre;
			system("clear");
			cout << "Ingrese el primer apellido" << endl;
			cin >> apl1;
			system("clear");
			cout << "Ingrese el segundo apellido" << endl;
			cin >> apl2;
			system("clear");
			cout << "Ingrese el telefono" << endl;
			cin >> tel;
			system("clear");
			cout << "Ingrese el celular" << endl;
			cin >> cel;
			system("clear");
			cout << "Ingrese el numero de cedula" << endl;
			cin >> ced;
			system("clear");
			cout << "Ingrese el correo electronico" << endl;
			cin >> mail;
			system("clear");
			cout << "Seleccione el numero de provincia" << endl;
			cout << "1: San José" << endl;	
			cout << "2: Alajuela" << endl;
			cout << "3: Cartago" << endl;
			cout << "4: Heredia" << endl;
			cout << "5: Puntarenas" << endl;
			cout << "6: Limón" << endl;
			cout << "7: Guanacaste" << endl;
			cin >> opcProv;
			system("clear");
			switch (opcProv){

			case 1:
				prov="San José";
				opcProv = 0;
				break;
			case 2:
				prov="Alajuela";
				opcProv = 0;
				break;
			case 3:
				prov="Cartago";
				opcProv = 0;
				break;
			case 4:
				prov="Heredia";
				opcProv = 0;
				break;
			case 5:
				prov="Puntarenas";
				opcProv = 0;
				break;
			case 6:
				prov="Limón";
				opcProv = 0;
				break;
			case 7:
				prov="Guanacaste";
				opcProv = 0;
				break;
			}
			ingresarUsuario(Lista,nombre,apl1,apl2,tel, cel, ofi, ced, mail, prov);
			cout << "Contacto regsitrado con exito!"<< endl;
			prov = "";
			nombre = "";
			apl1 ="";
			apl2 = "";
			mail= "";
			cel=0;
			ofi=0;
			tel=0;
			ced=0;
			num=0;
			opc = 0;
			opcProv=0;
			system("read -rp $'Press [Enter] to continue...\n' key");

			
		}
		if (opc == 2){
			system("clear");
			cout << "Ingrese el numero de celular a eliminar" << endl;
			cin >> cel;
			eliminarUsuario(Lista, cel);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
		if (opc == 3){
			system("clear");
			cout << "Ingrese el numero de cedula del usuario a modificar" << endl;
			cin >> ced;
			cout << "Ingrese el nuevo nombre de usuario" << endl;
			cin >> nombre;
			cout << "Ingrese el nuevo apellido paterno" << endl;
			cin >> apl1;
			cout << "Ingrese el nuevo apellido materno" << endl;
			cin>> apl2;
			cout << "Ingrese el nuevo numero de celular" << endl;
			cin >> cel;
			cout << "Ingrese el nuevo numero de oficina" << endl;
			cin >> ofi;
			cout << "Ingrese el nuevo numero de telefono" << endl;
			cin >> tel;
			
			modificarUsuario(Lista, ced, nombre, apl1, apl2, tel, cel,ofi);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
		if (opc == 4){
			system("clear");
			cout << "Ingrese el numero de telefono a buscar" << endl;
			cin >> num;
			buscarNumero(Lista, num);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}
		if (opc == 5){
			system("clear");
			cout << "Ingrese el numero de cedula a buscar" << endl;
			cin >> ced;
			buscarCedula(Lista, ced);
			system("read -rp $'Press [Enter] to continue...\n' key");
			
		}

		if (opc == 6){
			system("clear");

			cout << "Ingrese la provincia a imprimir" << endl;
			cout << "1: San José" << endl;
			cout << "2: Alajuela" << endl;
			cout << "3: Cartago" << endl;
			cout << "4: Heredia" << endl;
			cout << "5: Puntarenas" << endl;
			cout << "6: Limón" << endl;
			cout << "7: Guanacaste" << endl;

			
			cin >> opcProv;
			switch (opcProv){

			case 1:
				system("clear");
				mostrarProvincia(Lista, "San José");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 2:
				system("clear");
				mostrarProvincia(Lista, "Alajuela");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 3:
				system("clear");
				mostrarProvincia(Lista, "Cartago");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 4:
				system("clear");
				mostrarProvincia(Lista, "Heredia");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 5:
				system("clear");
				mostrarProvincia(Lista, "Puntarenas");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 6:
				system("clear");
				mostrarProvincia(Lista, "Limón");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 7:
				system("clear");
				mostrarProvincia(Lista, "Guanacaste");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			}
		}
		
		if (opc == 7){
			system("clear");
			cout << "Ingrese la inicial de nombres a imprimir:" << endl;
			cin >> letraIn;
			mostrarLetra(Lista, letraIn);
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		
		if (opc == 8){
			system("clear");
			contarContatos(Lista);
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		if (opc == 9){
			system("clear");
			
			cout << "Ingrese la provincia a imprimir" << endl;
			cout << "1: San José" << endl;
			cout << "2: Alajuela" << endl;
			cout << "3: Cartago" << endl;
			cout << "4: Heredia" << endl;
			cout << "5: Puntarenas" << endl;
			cout << "6: Limón" << endl;
			cout << "7: Guanacaste" << endl;

			
			cin >> opcProv;
			switch (opcProv){

			case 1:
				system("clear");
				contarProvincia(Lista, "San José");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 2:
				system("clear");
				contarProvincia(Lista, "Alajuela");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 3:
				system("clear");
				contarProvincia(Lista, "Cartago");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 4:
				system("clear");
				contarProvincia(Lista, "Heredia");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 5:
				system("clear");
				contarProvincia(Lista, "Puntarenas");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 6:
				system("clear");
				contarProvincia(Lista, "Limón");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			case 7:
				system("clear");
				contarProvincia(Lista, "Guanacaste");
				system("read -rp $'Press [Enter] to continue...\n' key");
				opcProv = 0;
				break;
			}
			
			opc = 0;
		}
		if (opc == 10){
			system("clear");
			cout << "Ingresa la letra a contar" << endl;
			cin >> letraIn;
			contarLetras(Lista, letraIn);
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		
		if (opc == 11)
		{
			estado = false;
		}
		if (!(opc >= 0 and opc < 12)){
			system("clear");
			cout << "Ingresar una opcion valida:" << endl;
			system("read -rp $'Press [Enter] to continue...\n' key");
			opc = 0;
		}
		
	}while (estado == true);
	
};
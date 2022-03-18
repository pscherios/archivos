#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char *nombrearch="tarea.dat";
struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
};
void add_estudiante();
void open_estudiante();
void mod_estudiante();
void buscar_cod();

int main(){
	open_estudiante();
	add_estudiante();
	mod_estudiante();
	return 0;
}

void buscar_cod(){
	FILE* archivo=fopen(nombrearch,"rb");
	int pos=0,indice=0,codi=0;
	cout<<"Ingrese el codigo: ";
	cin>>codi;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		if(estudiante.codigo==codi){
			cout<<"Codigo: "<<estudiante.codigo<<endl;
			cout<<"Nombre: "<<estudiante.nombre<<endl;
			cout<<"Apellido: "<<estudiante.apellido<<endl;
			cout<<"Telefono: "<<estudiante.telefono<<endl;
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
	}
	while(feof(archivo)==0);
	fclose(archivo);
}

void buscar_ind(){
	FILE* archivo=fopen(nombrearch,"rb");
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"-----"<<pos<<"-----"<<endl;
	fseek(archivo,pos*sizeof(Estudiante),SEEK_SET);
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombre: "<<estudiante.nombre<<endl;
	cout<<"Apellido: "<<estudiante.apellido<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	cout<<endl;
	fclose(archivo);
}

void open_estudiante(){
	system("cls");
	FILE* archivo=fopen(nombrearch,"rb");
	if(!archivo){
		archivo=fopen(nombrearch,"rb");
	}
	Estudiante estudiante;
	int registro=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-"<<endl;
	cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Telefono"<<"|"<<endl;
	do{
		cout<<"-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-"<<endl;
		cout<<registro<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellido<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		registro+=1;
	}
	while(feof(archivo)==0);
	cout<<endl;
	fclose(archivo);
}

void add_estudiante(){
	
	char continuar;
	FILE* archivo=fopen(nombrearch,"ab");
		Estudiante estudiante;
		string nombre,apellido;
		do{
			fflush(stdin);
			cout<<"Ingrese el Codigo:";cin>>estudiante.codigo;cin.ignore();
        	cout<<"Ingrese el Nombre:";
			getline(cin,nombre);
    		strcpy(estudiante.nombre, nombre.c_str()); 
			cout<<"Ingrese el Apellido:";getline(cin,apellido);
			strcpy(estudiante.apellido, apellido.c_str()); 
			cout<<"Ingrese el Telefono:";
			cin>>estudiante.telefono;
			cin.ignore();
			fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
			cout<<"Desea Agregar otro nombre s/n : ";
			cin>>continuar;
		} 
		while((continuar=='s') || (continuar=='S') );
		fclose(archivo);
		open_estudiante();
		buscar_cod();
}

void mod_estudiante(){
	
	FILE* archivo=fopen(nombrearch,"r+b");
	int id;
	string nombre,apellido;	
	Estudiante estudiante;
    cout << "Ingrese el ID que desea Modificar: ";
	cin >> id;
    fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );
	cout<<"Ingrese el Codigo:";
	cin>>estudiante.codigo;
    cin.ignore();
    cout<<"Ingrese el Nombre:";
	getline(cin,nombre);
    strcpy(estudiante.nombre, nombre.c_str()); 
	cout<<"Ingrese el Apellido:";
	getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str()); 
	cout<<"Ingrese el Telefono:";
	cin>>estudiante.telefono;
	cin.ignore();
	fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
	fclose(archivo);
	open_estudiante();
	system("PAUSE");
}



#include <vector>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


using namespace std;

void buscador();

//void gotoxy(int x, int y){
    //HANDLE hCon;
    //hCon= GetStdHandle(STD_OUTPUT_HANDLE);
    //COORD= dwPos;
    //dwPos.X= x;
    //dwPos.Y=y;
    //SetConsoleCursorPosition(hCon,dwPos);
//}

struct direccion{
    char departamento[50], municipio[20], direccion[20];
};

struct direccion direct;

struct datos{
    char nombre[40],apellido[40], correo[20],apuntes[20];
    int edad;
    struct direccion direct;
}persona[2];

int i;

int esDepartamentoColombia(const char *departamento) {
    // Lista de departamentos de Colombia
    const char *departamentosColombia[] = {
        "Amazonas", "Antioquia", "Arauca", "Atlántico", "Bolívar",
        "Boyacá", "Caldas", "Caquetá", "Casanare", "Cauca", "Cesar",
        "Chocó", "Córdoba", "Cundinamarca", "Guainía", "Guaviare",
        "Huila", "La Guajira", "Magdalena", "Meta", "Nariño", "Norte de Santander",
        "Putumayo", "Quindío", "Risaralda", "San Andrés y Providencia", "Santander",
        "Sucre", "Tolima", "Valle del Cauca", "Vaupés", "Vichada"
    };
    
    
    // Verificar si el departamento ingresado está en la lista
    for (int i = 0; i < sizeof(departamentosColombia); i++) {
        if (strcmp(departamento, departamentosColombia[i]) == 0) {
            return 1; // Departamento encontrado en la lista de Colombia
        }
    }

    return 0; // Departamento no encontrado en la lista de Colombia
}

int correos(const char *corr){
    const char *direccion_correo[]={"@gmail.com","@hotmail.com","@correo.uis.edu.co"};
    for (int i = 0; i < sizeof(direccion_correo); i++) {
        
        if (strcmp(corr, direccion_correo[i]) == 0) {
            return 1; // Departamento encontrado en la lista de Colombia
        }
    }
    return 0;
}

int main()
{
    //gotoxy(15,5);
    //printf("programa que toma datos los almacena y busca");
    
    
    FILE *archivo2;
    char path2[100]="busqueda.txt";
    archivo2 = fopen(path2, "w+");
    cout<<"ingrese la cantidad de datos que quiere almacenar"<<endl;
    int n;
    cin>>n;
    
    for (i=0; i<n;i++){
        
        time_t now = time(0);
        tm *time = localtime (&now);
    
        vector<string> dia;
        dia.push_back("Domingo");
        dia.push_back("Lunes");
        dia.push_back("Martes");
        dia.push_back("Miercoles");
        dia.push_back("Jueves");
        dia.push_back("Viernes");
        dia.push_back("Sabado");
    
        cout<<dia[time->tm_wday];
    
        vector<string> mes;
        mes.push_back("Enero");
        mes.push_back("Febrero");
        mes.push_back("Marzo");
        mes.push_back("Abril");
        mes.push_back("Mayo");
        mes.push_back("Junio");
        mes.push_back("Julio");
        mes.push_back("Agosto");
        mes.push_back("Septiembre");
        mes.push_back("Octubre");
        mes.push_back("Noviembre");
        mes.push_back("Diciembre");
    
        cout<<" "<< time->tm_mday<<" ";
        cout<<"de "<<mes[time->tm_mon];
    
        int year= 1900 + time->tm_year;
    
        cout<<" del año "<<year;
        cout<<" a las "<< time->tm_hour<<":"<<time->tm_min<<":"<<time->tm_sec<<"\n";
        
        cout<<"porfavor ingrese el nombre"<<endl;
        cin>>persona[i].nombre;
        
        cout<<"porfavor ingrese su apellido"<<endl;
        cin>>persona[i].apellido;
        
        cout<<"porfavor ingrese su edad"<<endl;
        cin>>persona[i].edad;
        
        cout<<"porfavor ingrese su correo electronico"<<endl;
        cin>>persona[i].correo;
        
        
        if(correos(persona[i].correo)){
            printf("El correo %s es valido.\n", persona[i].correo);
 
        } else{
            printf("El correo %s no es valido.\n", persona[i].correo);
        } 
        
        cout<<"porfavor ingrese el departamento de nacimiento"<<endl;
        cin>>persona[i].direct.departamento;
        
        struct direccion direct;
        
        if (esDepartamentoColombia(persona[i].direct.departamento)){
            printf("El departamento %s pertenece a Colombia.\n", persona[i].direct.departamento);
        }else {
            printf("El departamento %s no pertenece a Colombia.\n", persona[i].direct.departamento);
        }
            
        cout<<"porfavor ingrese el municipio de procedencia"<<endl;
        cin>>persona[i].direct.municipio;
        
        cout<<"porfavor ingrese su direccion de residencia"<<endl;
        cin>>persona[i].direct.direccion;
        
        cout<<"porfavor ingrese sus apuntes del dia de hoy"<<endl;
        cin>>persona[i].apuntes;
        
        getch();
        cout<<"\n//////////////////////////////////////////////////////////////////////////// \n \n";
    }
    
    
    int cont;
    cout<<" Presione:\n 1- Para realizar busqueda por nombre\n 2- pulse 2 para el apellido \n 3-busqueda por edad \n 4-busqueda por correo electronico\n 5-busqueda por departamento de nacimiento\n 6-busqueda por municipio de procedencia\n 7-busqueda por direccion de residencia\n 8-busqueda por apuntes del dia "<<endl;
    cin>>cont;
    switch(cont){
        case 1: char name[100];
                cout<<"ingrese el nombre a buscar"<<endl;
                cin>>name;
                for(i=0;i<n;i++){
                        
                    if ((name== persona[i].nombre)==0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
        case 2: char ape[100];
                cout<<"ingrese el apellido a buscar"<<endl;
                cin>>ape;
                for(i=0;i<n;i++){
                    if ((ape== persona[i].apellido)==0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
        case 3: int fecha;
                cout<<"ingrese la edad a buscar"<<endl;
                cin>>fecha;
                for(i=0;i<n;i++){
                    if((fecha== persona[i].edad)!=0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
        case 4:char corr[100];
                cout<<"ingrese el correo a buscar"<<endl;
                cin>>corr;
                for(i;i<n;i++){
                    if ((corr== persona[i].correo)==0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
        case 5: char dep[100];
                cout<<"ingrese el departamento a buscar"<<endl;
                cin>>dep;
                for(i;i<n;i++){
                    if ((dep== persona[i].direct.departamento)==0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
        case 6: char muni[100];
                cout<<"ingrese el municipio a buscar"<<endl;
                cin>>muni;
                    
                for(i;i<n;i++){
                    if ((muni== persona[i].direct.municipio)==0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
        case 7: char dir[40];
                cout<<"ingrese la direccion a buscar"<<endl;
                cin>>dir;
                for(i;i<n;i++){
                    if ((dir== persona[i].direct.direccion)==0){
                        cout<<persona[i].nombre<<"";
                        cout<<persona[i].apellido<<"";
                        cout<<"edad:"<<persona[i].edad;
                        cout<<persona[i].correo;
                        cout<<persona[i].direct.departamento;
                        cout<<persona[i].direct.municipio;
                        cout<<persona[i].direct.direccion;
                        cout<<persona[i].apuntes;
                    }
                }
                break;
                
        case 8: char apu[100];
                cout<<"ingrese los apuntes a buscar"<<endl;
                cin>>apu;
                for(i;i<n;i++){
                    if ((apu==persona[i].apuntes)==0){
                        for(i;i<8;i++){
                            cout<<persona[i].nombre<<"";
                            cout<<persona[i].apellido<<"";
                            cout<<"edad:"<<persona[i].edad;
                            cout<<persona[i].correo;
                            cout<<persona[i].direct.departamento;
                            cout<<persona[i].direct.municipio;
                            cout<<persona[i].direct.direccion;
                            cout<<persona[i].apuntes;
                        }
                
                    }
                }
                break;
                
    }        
    


}
    




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

int muni( const char *munic){
    
    const char *municipios[]={
        "Leticia", "Puerto nariño", "Cáceres", "Caucasia", "El bagre", "Nechí", "Terazá", "Zaragoza", "Caracolí", "Maceo",
        "Puerto berrío", "Puerto Nare", "Puerto triunfo", "Yondó", "Amalfi", "Anorí", "Cisneros", "Remedios", "San roque",
        "Santo domingo", "Segovia", "Vegachí", "Yalí", "Yolombó", "Angostura", "Belmira", "Briceño", "Campamento", "Carolina del príncipe",
        "Donmatías", "Entrerríos", "Gómez plata", "Guadalupe", "Ituango", "San andrés de cuerquia", "San josé de la montaña",
        "San pedro de los milagros", "Santa rosa de osos", "Toledo", "Valdivia", "Yurumal", "Abriaquí", "Santa fe de antioquia",
        "Anzá", "Armenia", "Buriticá", "Caicedo", "Cañasgordas", "Dabeiba", "Ebéjico", "Frontino", "Giraldo", "Heliconia", "Liborina",
        "Olaya", "Peque", "Sabanalarga", "San jerónimo", "Sopetrán", "Uramita", "Abejorral", "Alejanría", "Argelia", "El carmen de viboral",
        "Cocorná", "El peñol", "El retiro", "El santuario", "Granada", "Guarne", "Guatapé", "La ceja", "La unión", "Marinilla", "Nariño",
        "Rionegro", "San carlos", "San francisco", "San luis", "San rafael", "San vicente", "Sonsón", "Amagá", "Andes", "Angelópolis",
        "Betania", "Betulia", "Caramanta", "Ciudad bolivar", "Concordia", "Fredonia", "Hispania", "Jardín", "Jericó", "La pintada", "Montebello",
        "Pueblorrico", "Salgar", "Santa Bárbara", "Támesis", "Tarso", "Titiribí", "Urrao", "Valparaíso", "Venecia", "Apartadó", "Arboletes",
        "Carepa", "Chigorodó", "Murindó", "Mutatá","Necoclí", "San juan de urabá", "Turbó", "Vigía del fuerte", "Barbosa", "Bello", "Caldas",
        "Copacabana", "Envigado", "Girardota", "Itagüí", "La estrella", "Medellín", "Sabaneta", "Arauca", "Arauquita", "Cravo norte", 
        "Fuertul", "Puerto rondón", "Saravena", "Tame", "Barranquilla", "Baranoa", "Campo de la cruz", "Candelaria", "Galapa", "Juan de acosta",
        "Luruaco","Malambo", "Manatí", "Palmar de varela", "Piojó", "Polonuevo", "Ponedera", "Puerto colombia", "Repelón", "Sabanagrande", "Sabanalarga", "Santa lucía",
        "Santo tomás", "Soledad", "Suan", "Tubará", "Usiacurí", "Achí", "Altos del rosario", "Arenal", "Arjona", "Arroyohondo", "Barranco de loba",
        "Calamar", "Cantagallo", "El carmen de bolívar", "Cartagena de indias", "Cicuco", "Clemencia", "Córdoba", "El guamo", "El peñón", "Hatillo de loba",
        "Magangué", "Mahates", "Margarita", "María la baja", "Morales", "Norosí", "Pinillos", "Regidor", "Río viejo", "San cristóbal", "San estanislao", "San fernando", 
        "San jacinto", "San jacinto del cauca", "San juan nepomuceno", "San martín de loba", "San pablo", "Santa catalina", "Santa cruz mompox", "Santa rosa", "Santa rosa del sur",
        "Simití", "Soplaviento", "Talaigua nuevo", "Tiquisio", "Turbaco", "Turbaná", "Villanueva", "Zambrano", "Chiquiza", "Chivata", "Combita", "Cucaita", "Motavita", "Oicatá", "Samacá",
        "Siachoque", "Sora", "Soracá", "Sotaquirá", "Toca","Tunja", "Tuta", "Ventaquemada", "Chiscas", "El cocuy", "El espino", "Guacamayas", "Güicán", "Panqueba", "Labranzagrande",
        "Pajarito", "Paya", "Pisba", "Berbeo", "Campohermoso", "Miraflores", "Páez", "San eduardo", "Zetaquira", "Boyacá", "Ciénaga", "Jenesano", "Nuevo Colón", "Ramiriquí", "Rondón",
        "Tibaná", "Turmequé", "Úmbita", "Viracachá", "Chinavita", "Garagoa", "Macanal", "Pachavita", "San luis de gaceno", "Santa maría", "Boavita", "Covarachía", "La uvita", "San mateo",
        "Sativanorte", "Sativasur", "Soatá", "Susacón", "Tipacoque", "Briceño", "Buenavista", "Caldas", "Chiquinquirá", "Coper", "La victoria", "Maripí", "Muzo", "Otanche", "Pauna", "Quípama",
        "Saboyá", "San miguel de sema", "San pablo de borbur", "Tunuringuá", "Almeida", "Chivor", "Guateque", "Guayatá", "La capilla", "Somondoco", "Sutantenza", "Tenza", "Arcabuco", "Chitaraque", 
        "Gachantivá", "Moniquirá", "Ráquira", "Sáchica", "San josé de pare", "Santa sofía", "Santana", "Sutamarchán", "Tinjacá", "Tigüí", "Villa de leyva", "Aquitania", "Cuítiva", "Firavitoba", "Gámeza",
        "Iza", "Mongua", "Monguí", "Nobsa", "Pesca", "Sogamoso", "Tibasosa", "Tópaga", "Tota", "Belén", "Busbanzá", "Cerinza", "Corrales", "Duitama", "Floresta", "Paipa", "Santa rosa de viterbo", "Tutazá",
        "Betéitiva", "Chita", "Jericó", "Paz de río", "Socha", "Socotá", "Tasco", "Cubará", "Puerto Boyacá", "Filadelfia", "La merced", "Marmato", "Riosucio", "Supía", "Manzanares", "Marquetalia", "Marulanda",
        "Pensilvania", "Anserma", "Belalcázar", "Risaralda", "San josé", "Viterbo", "Chinchiná", "Manizales", "Neira", "Palestina", "Villamaría", "La dorada", "Norcasia", "Samaná", "Victoria", "Aguadas", "Aranzazu",
        "Pácora", "Salamina", "Albania", "Belen de los andaquies", "Cartagena del chairá", "Curillo", "El doncello", "El paujil", "Florencia", "La montañita", "Morelia", "Puerto milán", "Puerto rico", "San josé del fragua",
        "San vicente del caguán", "Solano", "Solita", "Valparaíso", "Aguazul", "Chámeza", "Hato corozal", "La salina", "Maní", "Monterrey", "Nunchía", "Orocué", "Paz de ariporo", "Pore", "Recetor", "Sabanalarga", "Sácama",
        "San luis del palenque", "Támara", "Tauramena", "Trinidad", "Villanueva", "Yopal", "Buenos aires", "Caloto", "Corinto", "Guachené", "Miranda", "Padilla", "Puerto tejada", "Santander de quilichao", "Suárez", "Villa rica",
        "Cajibío", "El tambo", "La sierra", "Morales", "Piendamó", "Popayán", "Rosas", "Sotará", "Timbío", "Almaguer", "Argelia", "Balboa", "Florencia", "La vega", "Mercaderes", "Patía", "Piamonte", "San sebastián", "Santa rosa",
        "Sucre", "Guapi", "López de micay", "Timbiquí", "Caldono", "Inzá", "Jambaló", "Páez", "Puracé-coconuco", "Silvia", "Toribío", "Totoró", "Acandí", "Alto Baudó", "Altrato", "Bagadó", "Bahía solano", "Bajo baudó", "Belém de bajirá",
        "Bojayá", "Carmen del darién", "Cértegui", "Condoto", "El cantón de san pablo", "El carmen de atrato", "El litoral de san juan", "Istmina", "Juradó", "Lloró", "Medio atrato", "Medio baudó", "Medio san juan", "Nóvita", "Nuquí", 
        "Quibdó", "Río iró", "Río quito", "Riosucio", "San josé del palmar", "Sipí", "Tadó", "Unguía", "Unión panamericana", "Ayapel", "Buenavista", "Canalete", "Cereté", "Chimá", "Chinú", "Ciénaga de oro", "Cotorra", "La apartada", 
        "Los córdobas", "Momil", "Montelíbano", "Montería", "Moñitos", "Planeta rica", "Pueblo nuevo", "Puerto escondido", "Puerto libertador", "Purísima", "Sahagún", "San andrés de sotavento", "San antero", "San bernardo del viento",
        "San carlos", "San josé de uré", "San pelayo", "Santa cruz de lorica", "Tierralta", "Tuchín", "Valencia", "Chocontá", "Machetá", "Manta", "Sesquilé", "Suesca", "Tibirita", "Villapinzón", "Agua de dios", "Girardot", "Guataquí", 
        "Jerusalén", "Nariño", "Nilo", "Ricaurte", "Tocaima", "Caparrapí", "Guaduas", "Puerto salgar", "Albán", "La peña", "La vega", "Nimaima", "Nocaima", "Quebradanegra", "San francisco", "Sasaima", "Supatá", "Útica", "Vergara", "Villeta",
        "Gachalá", "Gachetá", "Gama", "Guasca", "Guatavita", "Junín", "La calera", "Ubalá", "Beltrán", "Bituima", "Chaguaní", "Guayabal de síquima", "Pulí", "San juan de rioseco", "Vianí", "Medina", "Paratebueno", "Cáqueza", "Chipaque", "Choachí",
        "Fómeque", "Fosca", "Guayabetal", "Gutiérrez", "Quetame", "Ubaque", "Une", "El peñón", "La palma", "Pacho", "Paime", "San cayetano", "Topaipí", "Villagómez", "Yacopí", "Cajicá", "Chía", "Cogua", "Cota", "Gachancipá", "Nemocón", "Sopó", "Tabio",
        "Tenjo", "Tocancipá", "Zipaquirá", "Bojacá", "El rosal", "Facatativá", "Funza", "Madrid", "Mosquera", "Subachoque", "Zipacón", "Sibaté", "Soacha", "Arbeláez", "Cabrera", "Fusagasugá", "Granada", "Pandi", "Pasca", "San bernardo", "Silvania", "Tibacuy",
        "Venecia", "Anapoima", "Anolaima", "Apulo", "Cachipay", "El colegio", "La mesa", "Quipile", "San antonio de la tequendama", "Tena", "Viotá", "Carmen de carupa", "Cucunubá", "Fúquene", "Guachetá", "Lenguazaque", "Simijaca", "Susa", "Sutatausa", "Tausa", "Ubaté",
        "Barrancominas", "Inírida", "Calamar", "El retorno", "Miraflores", "San jose del guaviare", "Aipe", "Algeciras", "Baraya", "Campoalegre", "Colombia", "Hobo", "Íqira", "Neiva", "Palermo", "Rivera", "Santa maría", "Tello", "Teruel", "Villavieja", "Yaguará", "Agrado",
        "Altamira", "Garzón", "Gigante", "Guadalupe", "Pital", "Suaza", "Tarqui", "La argentina", "La plata", "Nátaga", "Paicol", "Tesalia", "Acevedo", "Elías", "Isnos", "Oporapa", "Palestina", "Pitalito", "Saladoblanco", "San agustín", "Timaná", "Albania", "Barrancas",
        "Dibulla", "Distracción", "El milino", "Fonseca", "Hatonuevo", "La jagua del pilar", "Maicao", "Manaure", "Riohacha", "San juan del cesar", "Uribia", "Urumita", "Villanueva", "Algarrobo", "Aracataca", "Ariguaní", "Cerro de san antonio", "Chibolo", "Ciénaga", "Concordia", 
        "El banco", "El piñón", "El retén", "Fundación", "Guamal", "Nueva granada", "Pedraza", "Pijiño del carmen", "Pivijay", "Plato", "Pueblo viejo", "Remolino", "Sabanas de san ángel", "Salamina", "San sebastián de buenavista", "Santa Ana", "Santa bárbara de pinto", "Santa marta",
        "San zenón", "Sitionuevo", "Tenerife", "Zapayán", "Zona bananera", "Acacías", "Barranca de Upía", "Cabuyaro", "Castilla la nueva", "Cubarral", "Cumaral", "El calvario", "El castillo", "El dorado", "Fuente de oro", "Granada", "Guamal", "La macarena", "Uribe", "Lejanías", "Mapiripán",
        "Mesetas", "Puerto concordia", "Puerto gaitán", "Puerto lleras", "Puerto lópez", "Puerto rico", "Restrepo", "San carlos de guaroa", "San juan de arama", "San juanito", "San martín", "Villavicencio", "Vista hermosa", "Barbacoas", "El charco", "Francisco pizarro", "La tola", "Magüí payán",
        "Mosquera", "Olaya herrera", "Roberto payán", "Santa bárbara", "Tumaco", "Aldana", "Contadero", "Córdoba", "Cuaspud", "Cumbal", "Funes", "Guachucal", "Gualmatán", "Iles", "Ipiales", "Potosi", "Puerres", "Pupiales", "Albán", "Arboleda", "Belén", "Colón", "El rosario", "El tablón de gómez",
        "La cruz", "La unión", "Leiva", "Policarpa", "San bernardo", "San lorenzo", "San pablo", "San pedro de cartago", "Taminango", "Buesaco", "Chachagüí", "Consacá", "El peñol", "El tambo", "La florida", "Nariño", "Pasto", "Sandoná", "Tangua", "Yacuanquer", "Ancuya", "Cumbitara", "Guaitarilla", 
        "Imués", "La llanada", "Linares", "Los andes", "Mallama", "Ospina", "Providencia", "Ricaurte", "Samaniego", "Santacruz", "Sapuyes", "Túquerres", "Arboledas", "Cucutilla", "Gramalote", "Lourdes", "Salazar de las palmas", "Santiago", "Villa caro", "Cúcuta", "La zulia", "Los patios", "Puerto santander",
        "San cayetano", "Villa del rosario", "Bucarasica", "El tarra", "Sardinita", "Tibú", "Ábrego", "Cáchira", "Convención", "El carmen", "Hacari", "La esperanza", "La playa de belén", "Ocaña", "San calixto", "Teorama", "Cácota", "Chitagá", "Mutiscua", "Pamplona", "Pamplonita", "Santo domingo de silos", "Bochalema",
        "Chinácota", "Durania", "Herrán", "Labateca", "Ragonvalia", "Toledo", "Colón", "Mocoa", "Orito", "Puerto asis", "Puerto caicedo", "Puerto guzmán", "Puerto lenguizamo", "San francisco", "San miguel", "Santiago", "Sibundoy", "Valle del guamuez", "Villagarzón", "Armenia", "Buenavista", "Calarcá", "Circasia", "Córdoba",
        "Filandia","Génova", "La tebaida", "Montenegro", "Pijao", "Quimbaya", "Salento", "Apía", "Balboa", "Belén de umbría", "Dosquebradas", "Guática", "La celia", "La virginira", "Marsella", "Mistrató", "Pereira", "Pueblo rico", "Quinchía", "Santa rosa de cabal", "Santuario", "Providencia", "Santa catalina", "Aguada", "Albania",
        "Aratoca", "Barbosa", "Barichara", "Barrancabermeja", "Betulia", "Bolívar", "Bucaramanga", "Cabrera", "California", "Capitanejo", "Carcasí", "Cepitá", "Cerrito", "Caralá", "Charta", "Chima", "Chipatá", "Cimitarra", "Concepción", "Confines", "Contratación", "Coromoro", "Curití", "El carmen de chucurí", "El guacamayo", "El peñón",
        "El playón", "Encino", "Enciso", "Florián", "Floridablanca", "Galán", "Girón", "Guaca", "Guadalupe", "Guapotá", "Guavatá", "Güepsa", "Hato", "Jesús maría", "Jordán", "La belleza", "La paz", "Landázuri", "Lebrija", "Los santos", "Macaravita", "Málaga", "Matanza", "Mogotes", "Molagavita", "Ocamonte", "Oiba", "Onzaga", "Palmar", 
        "Palmas del socorro", "Páramo", "Piedecuesta", "Pinchote", "Puente nacional", "Puerto parra", "Puerto wilches", "Rionegro", "Sabana de torres", "San andrés", "San benito", "San gil", "San joaquín", "San josé de miranda", "San miguel", "San vicente de chucurí", "Santa bárbara", "Santa helena del opón", "Simacota", "Socorro", "Suaita",
        "Sucre", "Suratá", "Tona", "Valle de san josé", "Vélez", "Vetas", "Villanueva", "Zapatoca", "Guaranda", "Majagual", "Sucre", "Chalán", "Colosó", "Morroa", "Ovejas", "Sincelejo", "Coveñas", "Palmito", "San onofre", "Santiago de tolú", "Toluviejo", "Buenavista", "Corozal", "El roble", "Galeras", "Los palmitos", "Sampués", "San juan de betulia",
        "San pedro", "Sincé", "Caimito", "La unión", "San benito de abad", "San marcos", "Alcalá", "Andalucía", "Ansermanuevo", "Argelia", "Bolívar", "Buenaventura", "Buga", "Bugalagrande", "Caicedonia", "Cali", "Calima, el darién", "Candelaria", "Cartago", "Dagua", "El águila", "El cairo", "El cerrito", "El dovio", "Florida", "Ginebra", "Guacarí", "Jamundí",
        "La cumbre", "La unión", "La victoria", "Obando", "Palmira", "Pradera", "Restrepo", "Riofrío", "Roldanillo", "San pedro", "Sevilla", "Toro", "Trujillo", "Tuluá", "Ulloa", "Versalles", "Vijes", "Yotoco", "Yumbo", "Zarzal", "Carurú", "Mitú", "Taraira", "Cumaribo", "La primavera", "Puerto carreño", "Santa rosalía"
    }; 
    
    for (int i = 0; i < sizeof(municipios);i++){
        if (strcmp(munic,municipios[i])==0){
            return 1; // Departamento encontrado en la lista de Colombia
        }
    }
    
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
        
        if (muni(persona[i].direct.municipio)){
            printf("El municipio %s pertenece a Colombia.\n", persona[i].direct.municipio);
        }else {
            printf("El municipio %s no pertenece a Colombia.\n", persona[i].direct.municipio);
        }
        
        
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
                for(i=0;i<7;i++){
                        
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
    





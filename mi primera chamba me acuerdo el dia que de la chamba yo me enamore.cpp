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
        "Huila", "La_guajira", "Magdalena", "Meta", "Nariño", "Norte_de_santander",
        "Putumayo", "Quindío", "Risaralda", "San_andrés_y_providencia", "Santander",
        "Sucre", "Tolima", "Valle_del_cauca", "Vaupés", "Vichada"
    };
    
    
    // Verificar si el departamento ingresado está en la lista
    for (int i = 0; i < sizeof(departamentosColombia); i++) {
        if (strcmp(departamento, departamentosColombia[i]) == 0) {
            return 1; // Departamento encontrado en la lista de Colombia
        }
        
    }
    return 0;
}

int muni( const char *munic){
    
    const char *municipios[]={
        "Leticia", "Puerto_nariño", "Cáceres", "Caucasia", "El bagre", "Nechí", "Terazá", "Zaragoza", "Caracolí", "Maceo",
        "Puerto_berrío", "Puerto_Nare", "Puerto_triunfo", "Yondó", "Amalfi", "Anorí", "Cisneros", "Remedios", "San_roque",
        "Santo_domingo", "Segovia", "Vegachí", "Yalí", "Yolombó", "Angostura", "Belmira", "Briceño", "Campamento", "Carolina_del_príncipe",
        "Donmatías", "Entrerríos", "Gómez_plata", "Guadalupe", "Ituango", "San_andrés_de_cuerquia", "San_josé_de_la_montaña",
        "San_pedro_de_los_milagros", "Santa_rosa_de_osos", "Toledo", "Valdivia", "Yurumal", "Abriaquí", "Santa_fe_de_antioquia",
        "Anzá", "Armenia", "Buriticá", "Caicedo", "Cañasgordas", "Dabeiba", "Ebéjico", "Frontino", "Giraldo", "Heliconia", "Liborina",
        "Olaya", "Peque", "Sabanalarga", "San_jerónimo", "Sopetrán", "Uramita", "Abejorral", "Alejanría", "Argelia", "El_carmen_de_viboral",
        "Cocorná", "El_peñol", "El_retiro", "El_santuario", "Granada", "Guarne", "Guatapé", "La_ceja", "La_unión", "Marinilla", "Nariño",
        "Rionegro", "San_carlos", "San_francisco", "San_luis", "San_rafael", "San_vicente", "Sonsón", "Amagá", "Andes", "Angelópolis",
        "Betania", "Betulia", "Caramanta", "Ciudad bolivar", "Concordia", "Fredonia", "Hispania", "Jardín", "Jericó", "La_pintada", "Montebello",
        "Pueblorrico", "Salgar", "Santa_Bárbara", "Támesis", "Tarso", "Titiribí", "Urrao", "Valparaíso", "Venecia", "Apartadó", "Arboletes",
        "Carepa", "Chigorodó", "Murindó", "Mutatá","Necoclí", "San_juan_de urabá", "Turbó", "Vigía_del_fuerte", "Barbosa", "Bello", "Caldas",
        "Copacabana", "Envigado", "Girardota", "Itagüí", "La_estrella", "Medellín", "Sabaneta", "Arauca", "Arauquita", "Cravo_norte", 
        "Fuertul", "Puerto_rondón", "Saravena", "Tame", "Barranquilla", "Baranoa", "Campo_de_la_cruz", "Candelaria", "Galapa", "Juan_de-acosta",
        "Luruaco","Malambo", "Manatí", "Palmar_de_varela", "Piojó", "Polonuevo", "Ponedera", "Puerto_colombia", "Repelón", "Sabanagrande", "Sabanalarga", "Santa_lucía",
        "Santo_tomás", "Soledad", "Suan", "Tubará", "Usiacurí", "Achí", "Altos_del_rosario", "Arenal", "Arjona", "Arroyohondo", "Barranco_de_loba",
        "Calamar", "Cantagallo", "El_carmen_de_bolívar", "Cartagena_de_indias", "Cicuco", "Clemencia", "Córdoba", "El_guamo", "El_peñón", "Hatillo_de_loba",
        "Magangué", "Mahates", "Margarita", "María_la_baja", "Morales", "Norosí", "Pinillos", "Regidor", "Río_viejo", "San_cristóbal", "San_estanislao", "San_fernando", 
        "San_jacinto", "San_jacinto_del_cauca", "San_juan_nepomuceno", "San_martín_de_loba", "San_pablo", "Santa_catalina", "Santa_cruz_mompox", "Santa_rosa", "Santa_rosa del_sur",
        "Simití", "Soplaviento", "Talaigua_nuevo", "Tiquisio", "Turbaco", "Turbaná", "Villanueva", "Zambrano", "Chiquiza", "Chivata", "Combita", "Cucaita", "Motavita", "Oicatá", "Samacá",
        "Siachoque", "Sora", "Soracá", "Sotaquirá", "Toca","Tunja", "Tuta", "Ventaquemada", "Chiscas", "El_cocuy", "El_espino", "Guacamayas", "Güicán", "Panqueba", "Labranzagrande",
        "Pajarito", "Paya", "Pisba", "Berbeo", "Campohermoso", "Miraflores", "Páez", "San_eduardo", "Zetaquira", "Boyacá", "Ciénaga", "Jenesano", "Nuevo_Colón", "Ramiriquí", "Rondón",
        "Tibaná", "Turmequé", "Úmbita", "Viracachá", "Chinavita", "Garagoa", "Macanal", "Pachavita", "San_luis_de_gaceno", "Santa_maría", "Boavita", "Covarachía", "La_uvita", "San_mateo",
        "Sativanorte", "Sativasur", "Soatá", "Susacón", "Tipacoque", "Briceño", "Buenavista", "Caldas", "Chiquinquirá", "Coper", "La_victoria", "Maripí", "Muzo", "Otanche", "Pauna", "Quípama",
        "Saboyá", "San_miguel_de_sema", "San_pablo_de_borbur", "Tunuringuá", "Almeida", "Chivor", "Guateque", "Guayatá", "La_capilla", "Somondoco", "Sutantenza", "Tenza", "Arcabuco", "Chitaraque", 
        "Gachantivá", "Moniquirá", "Ráquira", "Sáchica", "San_josé_de_pare", "Santa_sofía", "Santana", "Sutamarchán", "Tinjacá", "Tigüí", "Villa_de_leyva", "Aquitania", "Cuítiva", "Firavitoba", "Gámeza",
        "Iza", "Mongua", "Monguí", "Nobsa", "Pesca", "Sogamoso", "Tibasosa", "Tópaga", "Tota", "Belén", "Busbanzá", "Cerinza", "Corrales", "Duitama", "Floresta", "Paipa", "Santa_rosa_de_viterbo", "Tutazá",
        "Betéitiva", "Chita", "Jericó", "Paz_de_río", "Socha", "Socotá", "Tasco", "Cubará", "Puerto_Boyacá", "Filadelfia", "La_merced", "Marmato", "Riosucio", "Supía", "Manzanares", "Marquetalia", "Marulanda",
        "Pensilvania", "Anserma", "Belalcázar", "Risaralda", "San_josé", "Viterbo", "Chinchiná", "Manizales", "Neira", "Palestina", "Villamaría", "La_dorada", "Norcasia", "Samaná", "Victoria", "Aguadas", "Aranzazu",
        "Pácora", "Salamina", "Albania", "Belen_de_los andaquies", "Cartagena_del_chairá", "Curillo", "El_doncello", "El_paujil", "Florencia", "La_montañita", "Morelia", "Puerto_milán", "Puerto_rico", "San_josé_del_fragua",
        "San_vicente_del_caguán", "Solano", "Solita", "Valparaíso", "Aguazul", "Chámeza", "Hato_corozal", "La_salina", "Maní", "Monterrey", "Nunchía", "Orocué", "Paz_de_ariporo", "Pore", "Recetor", "Sabanalarga", "Sácama",
        "San_luis_del_palenque", "Támara", "Tauramena", "Trinidad", "Villanueva", "Yopal", "Buenos_aires", "Caloto", "Corinto", "Guachené", "Miranda", "Padilla", "Puerto tejada", "Santander_de_quilichao", "Suárez", "Villa_rica",
        "Cajibío", "El_tambo", "La_sierra", "Morales", "Piendamó", "Popayán", "Rosas", "Sotará", "Timbío", "Almaguer", "Argelia", "Balboa", "Florencia", "La_vega", "Mercaderes", "Patía", "Piamonte", "San_sebastián", "Santa_rosa",
        "Sucre", "Guapi", "López_de_micay", "Timbiquí", "Caldono", "Inzá", "Jambaló", "Páez", "Puracé_coconuco", "Silvia", "Toribío", "Totoró", "Acandí", "Alto_Baudó", "Altrato", "Bagadó", "Bahía_solano", "Bajo_baudó", "Belém_de_bajirá",
        "Bojayá", "Carmen_del_darién", "Cértegui", "Condoto", "El_cantón_de_san pablo", "El_carmen_de_atrato", "El_litoral_de_san_juan", "Istmina", "Juradó", "Lloró", "Medio_atrato", "Medio_baudó", "Medio_san_juan", "Nóvita", "Nuquí", 
        "Quibdó", "Río_iró", "Río_quito", "Riosucio", "San_josé_del_palmar", "Sipí", "Tadó", "Unguía", "Unión_panamericana", "Ayapel", "Buenavista", "Canalete", "Cereté", "Chimá", "Chinú", "Ciénaga_de_oro", "Cotorra", "La_apartada", 
        "Los_córdobas", "Momil", "Montelíbano", "Montería", "Moñitos", "Planeta_rica", "Pueblo_nuevo", "Puerto_escondido", "Puerto_libertador", "Purísima", "Sahagún", "San_andrés_de_sotavento", "San_antero", "San_bernardo_del_viento",
        "San_carlos", "San_josé_de_uré", "San_pelayo", "Santa_cruz_de_lorica", "Tierralta", "Tuchín", "Valencia", "Chocontá", "Machetá", "Manta", "Sesquilé", "Suesca", "Tibirita", "Villapinzón", "Agua_de_dios", "Girardot", "Guataquí", 
        "Jerusalén", "Nariño", "Nilo", "Ricaurte", "Tocaima", "Caparrapí", "Guaduas", "Puerto_salgar", "Albán", "La_peña", "La_vega", "Nimaima", "Nocaima", "Quebradanegra", "San_francisco", "Sasaima", "Supatá", "Útica", "Vergara", "Villeta",
        "Gachalá", "Gachetá", "Gama", "Guasca", "Guatavita", "Junín", "La_calera", "Ubalá", "Beltrán", "Bituima", "Chaguaní", "Guayabal_de_síquima", "Pulí", "San_juan_de_rioseco", "Vianí", "Medina", "Paratebueno", "Cáqueza", "Chipaque", "Choachí",
        "Fómeque", "Fosca", "Guayabetal", "Gutiérrez", "Quetame", "Ubaque", "Une", "El_peñón", "La_palma", "Pacho", "Paime", "San_cayetano", "Topaipí", "Villagómez", "Yacopí", "Cajicá", "Chía", "Cogua", "Cota", "Gachancipá", "Nemocón", "Sopó", "Tabio",
        "Tenjo", "Tocancipá", "Zipaquirá", "Bojacá", "El_rosal", "Facatativá", "Funza", "Madrid", "Mosquera", "Subachoque", "Zipacón", "Sibaté", "Soacha", "Arbeláez", "Cabrera", "Fusagasugá", "Granada", "Pandi", "Pasca", "San_bernardo", "Silvania", "Tibacuy",
        "Venecia", "Anapoima", "Anolaima", "Apulo", "Cachipay", "El_colegio", "La_mesa", "Quipile", "San_antonio_de_la_tequendama", "Tena", "Viotá", "Carmen_de_carupa", "Cucunubá", "Fúquene", "Guachetá", "Lenguazaque", "Simijaca", "Susa", "Sutatausa", "Tausa", "Ubaté",
        "Barrancominas", "Inírida", "Calamar", "El_retorno", "Miraflores", "San_jose_del_guaviare", "Aipe", "Algeciras", "Baraya", "Campoalegre", "Colombia", "Hobo", "Íqira", "Neiva", "Palermo", "Rivera", "Santa_maría", "Tello", "Teruel", "Villavieja", "Yaguará", "Agrado",
        "Altamira", "Garzón", "Gigante", "Guadalupe", "Pital", "Suaza", "Tarqui", "La_argentina", "La_plata", "Nátaga", "Paicol", "Tesalia", "Acevedo", "Elías", "Isnos", "Oporapa", "Palestina", "Pitalito", "Saladoblanco", "San_agustín", "Timaná", "Albania", "Barrancas",
        "Dibulla", "Distracción", "El_milino", "Fonseca", "Hatonuevo", "La_jagua_del_pilar", "Maicao", "Manaure", "Riohacha", "San_juan_del_cesar", "Uribia", "Urumita", "Villanueva", "Algarrobo", "Aracataca", "Ariguaní", "Cerro_de_san_antonio", "Chibolo", "Ciénaga", "Concordia", 
        "El_banco", "El_piñón", "El_retén", "Fundación", "Guamal", "Nueva_granada", "Pedraza", "Pijiño_del_carmen", "Pivijay", "Plato", "Pueblo_viejo", "Remolino", "Sabanas_de_san_ángel", "Salamina", "San_sebastián_de_buenavista", "Santa_Ana", "Santa_bárbara_de_pinto", "Santa_marta",
        "San_zenón", "Sitionuevo", "Tenerife", "Zapayán", "Zona_bananera", "Acacías", "Barranca_de_Upía", "Cabuyaro", "Castilla_la_nueva", "Cubarral", "Cumaral", "El_calvario", "El_castillo", "El_dorado", "Fuente_de_oro", "Granada", "Guamal", "La_macarena", "Uribe", "Lejanías", "Mapiripán",
        "Mesetas", "Puerto_concordia", "Puerto_gaitán", "Puerto_lleras", "Puerto_lópez", "Puerto_rico", "Restrepo", "San_carlos_de_guaroa", "San_juan_de_arama", "San_juanito", "San_martín", "Villavicencio", "Vista_hermosa", "Barbacoas", "El_charco", "Francisco_pizarro", "La_tola", "Magüí_payán",
        "Mosquera", "Olaya_herrera", "Roberto_payán", "Santa_bárbara", "Tumaco", "Aldana", "Contadero", "Córdoba", "Cuaspud", "Cumbal", "Funes", "Guachucal", "Gualmatán", "Iles", "Ipiales", "Potosi", "Puerres", "Pupiales", "Albán", "Arboleda", "Belén", "Colón", "El_rosario", "El_tablón_de_gómez",
        "La_cruz", "La_unión", "Leiva", "Policarpa", "San_bernardo", "San_lorenzo", "San_pablo", "San_pedro_de_cartago", "Taminango", "Buesaco", "Chachagüí", "Consacá", "El_peñol", "El_tambo", "La_florida", "Nariño", "Pasto", "Sandoná", "Tangua", "Yacuanquer", "Ancuya", "Cumbitara", "Guaitarilla", 
        "Imués", "La_llanada", "Linares", "Los_andes", "Mallama", "Ospina", "Providencia", "Ricaurte", "Samaniego", "Santacruz", "Sapuyes", "Túquerres", "Arboledas", "Cucutilla", "Gramalote", "Lourdes", "Salazar_de_las_palmas", "Santiago", "Villa_caro", "Cúcuta", "La_zulia", "Los_patios", "Puerto_santander",
        "San_cayetano", "Villa_del_rosario", "Bucarasica", "El_tarra", "Sardinita", "Tibú", "Ábrego", "Cáchira", "Convención", "El_carmen", "Hacari", "La_esperanza", "La_playa_de_belén", "Ocaña", "San_calixto", "Teorama", "Cácota", "Chitagá", "Mutiscua", "Pamplona", "Pamplonita", "Santo_domingo_de_silos", "Bochalema",
        "Chinácota", "Durania", "Herrán", "Labateca", "Ragonvalia", "Toledo", "Colón", "Mocoa", "Orito", "Puerto_asis", "Puerto_caicedo", "Puerto_guzmán", "Puerto_lenguizamo", "San_francisco", "San_miguel", "Santiago", "Sibundoy", "Valle_del_guamuez", "Villagarzón", "Armenia", "Buenavista", "Calarcá", "Circasia", "Córdoba",
        "Filandia","Génova", "La_tebaida", "Montenegro", "Pijao", "Quimbaya", "Salento", "Apía", "Balboa", "Belén_de_umbría", "Dosquebradas", "Guática", "La_celia", "La_virginira", "Marsella", "Mistrató", "Pereira", "Pueblo_rico", "Quinchía", "Santa_rosa_de_cabal", "Santuario", "Providencia", "Santa_catalina", "Aguada", "Albania",
        "Aratoca", "Barbosa", "Barichara", "Barrancabermeja", "Betulia", "Bolívar", "Bucaramanga", "Cabrera", "California", "Capitanejo", "Carcasí", "Cepitá", "Cerrito", "Caralá", "Charta", "Chima", "Chipatá", "Cimitarra", "Concepción", "Confines", "Contratación", "Coromoro", "Curití", "El_carmen_de_chucurí", "El_guacamayo", "El_peñón",
        "El_playón", "Encino", "Enciso", "Florián", "Floridablanca", "Galán", "Girón", "Guaca", "Guadalupe", "Guapotá", "Guavatá", "Güepsa", "Hato", "Jesús_maría", "Jordán", "La_belleza", "La_paz", "Landázuri", "Lebrija", "Los_santos", "Macaravita", "Málaga", "Matanza", "Mogotes", "Molagavita", "Ocamonte", "Oiba", "Onzaga", "Palmar", 
        "Palmas_del_socorro", "Páramo", "Piedecuesta", "Pinchote", "Puente_nacional", "Puerto_parra", "Puerto_wilches", "Rionegro", "Sabana_de_torres", "San_andrés", "San_benito", "San_gil", "San_joaquín", "San_josé_de_miranda", "San_miguel", "San_vicente_de_chucurí", "Santa_bárbara", "Santa_helena_del_opón", "Simacota", "Socorro", "Suaita",
        "Sucre", "Suratá", "Tona", "Valle_de_san josé", "Vélez", "Vetas", "Villanueva", "Zapatoca", "Guaranda", "Majagual", "Sucre", "Chalán", "Colosó", "Morroa", "Ovejas", "Sincelejo", "Coveñas", "Palmito", "San_onofre", "Santiago_de_tolú", "Toluviejo", "Buenavista", "Corozal", "El_roble", "Galeras", "Los_palmitos", "Sampués", "San_juan_de_betulia",
        "San_pedro", "Sincé", "Caimito", "La_unión", "San_benito_de_abad", "San_marcos", "Alcalá", "Andalucía", "Ansermanuevo", "Argelia", "Bolívar", "Buenaventura", "Buga", "Bugalagrande", "Caicedonia", "Cali", "Calima_el_darién", "Candelaria", "Cartago", "Dagua", "El_águila", "El_cairo", "El_cerrito", "El_dovio", "Florida", "Ginebra", "Guacarí", "Jamundí",
        "La_cumbre", "La_unión", "La_victoria", "Obando", "Palmira", "Pradera", "Restrepo", "Riofrío", "Roldanillo", "San_pedro", "Sevilla", "Toro", "Trujillo", "Tuluá", "Ulloa", "Versalles", "Vijes", "Yotoco", "Yumbo", "Zarzal", "Carurú", "Mitú", "Taraira", "Cumaribo", "La_primavera", "Puerto_carreño", "Santa_rosalía"
    }; 
    
    for (int i = 0; i < sizeof(municipios);i++){
        if (strcmp(munic,municipios[i])==0){
            return 1; // Departamento encontrado en la lista de Colombia
        }
        
     
    }
    return 0;
    
}

size_t position;

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
        
        cout<<"Porfavor ingrese el nombre"<<endl;
        cout<<"Debe ir unicamente la primera letra en mayúscula, de lo contrario habrán errores en la ejecución y lectura de datos"<<endl;

        cin>>persona[i].nombre;
        
        cout<<"Porfavor ingrese su apellido"<<endl;
        cout<<"Debe ir unicamente la primera letra en mayúscula, de lo contrario habrán errores en la ejecución y lectura de datos"<<endl;

        cin>>persona[i].apellido;
        
        cout<<"Porfavor ingrese su edad"<<endl;

        cin>>persona[i].edad;
        
        cout<<"Porfavor ingrese su correo electronico"<<endl;
        cin>>persona[i].correo;
        
        cout<<"Porfavor ingrese el departamento de nacimiento"<<endl;
        cout<<"Tenga en cuenta que no puede colocar espacios estos serán remplazados por un backslash, ejemplo: \n Valle_del_cauca"<<endl;
        cout<<"Debe ir unicamente la primera letra en mayúscula, de lo contrario habrán errores en la ejecución y lectura de datos"<<endl;
        cin>>persona[i].direct.departamento;
        
        struct direccion direct;
        
        if (esDepartamentoColombia(persona[i].direct.departamento)){
            printf("El departamento %s pertenece a Colombia.\n", persona[i].direct.departamento);
        }else {
            printf("El departamento %s no pertenece a Colombia.\n", persona[i].direct.departamento);
        }
            
        cout<<"Porfavor ingrese el municipio de procedencia"<<endl;
        cout<<"Tenga en cuenta que no puede colocar espacios estos serán remplazados por un backslash, ejemplo: \n La_calera"<<endl;
        cout<<"Debe ir unicamente la primera letra en mayúscula, de lo contrario habrán errores en la ejecución y lectura de datos"<<endl;

        cin>>persona[i].direct.municipio;
        
        if (muni(persona[i].direct.municipio)){
            printf("El municipio %s pertenece a Colombia.\n", persona[i].direct.municipio);
        }else {
            printf("El municipio %s no pertenece a Colombia.\n", persona[i].direct.municipio);
        }
        
        
        cout<<"Porfavor ingrese su direccion de residencia"<<endl;
        cin>>persona[i].direct.direccion;
        
        cout<<"Porfavor ingrese sus apuntes del dia de hoy"<<endl;
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
                        for(i;i<n;i++){
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
    

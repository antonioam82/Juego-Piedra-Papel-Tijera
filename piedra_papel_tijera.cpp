#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

void LimpiarPantalla(){
	if(system("cls") == -1){
		cout<<"Error al borrar la pantalla  :(";
	}
}

string computerOption(){
    srand(static_cast<unsigned int>(time(nullptr)));
    //lista de palabras
    vector<string> palabras = {
        "piedra", "papel", "tijera"
    };
    // indice aleatorio
    int indiceAleatorio = rand() % palabras.size();
    // Obtiene la palabra aleatoria
    string palabraAleatoria = palabras[indiceAleatorio];

    return palabraAleatoria;
}

string convertToLower(string word){
    for (char &caracter : word){
        caracter = tolower(caracter);
    };
    return word;
}

bool included(string elemento){
    bool esta_presente = false;
    vector<string> opciones = {"piedra","papel","tijera"};
    for (int i = 0; i < opciones.size(); i++){
        if (opciones[i] == elemento) {
            esta_presente = true;
            break;
        }
    }
    return esta_presente;
}

string enterOption(){
    bool esta;
    string option;
    cout << "Piedra, Papel o Tijera: "; cin >> option;

    return option;
}

bool conti(){
    string c;
    cout << "Desea continuar?: "; cin >> c;
    if(c == "Y" || c == "y"){
        LimpiarPantalla();
        return true;
    }else{
        cout << "BYE, BYE..." << endl;
        return false;
    };
}

void showScore(int v,int d,int e){
    cout << "\n---------------PUNTUACION----------------" << endl;
    cout << "VICTORIAS: " << v << " DERROTAS: " << d << " EMPATES: " << e << endl;
    cout << "-----------------------------------------\n" << endl;
};

int main()
{
    bool inclu;
    string opcion;
    string opcion_compu;
    int victorias = 0;
    int derrotas = 0;
    int empates = 0;
    bool continuar = true;

    //opcion = enterOption();
    while(continuar == true){
    cout << "-----------|JUGANDO A PIEDRA, PAPEL, TIJERA|-----------\n" << endl;
    opcion = convertToLower(enterOption());
    inclu = included(opcion);
    opcion_compu = computerOption();
    if(inclu == true){
        cout << "TU OPCION: " << opcion << endl;
        cout << "OPCION COMPU: " << opcion_compu << endl;
        if(opcion != opcion_compu){
            if(opcion == "piedra" && opcion_compu == "papel"){
                cout << "\nPERDISTE: papel envuelve piedra" << endl;
                derrotas++;
                showScore(victorias,derrotas,empates);
            }else if(opcion == "piedra" && opcion_compu == "tijera"){
                cout << "\nGANASTE: piedra machaca tijera" << endl;
                victorias++;
                showScore(victorias,derrotas,empates);
            }else if(opcion == "papel" && opcion_compu == "piedra"){
                cout << "\nGANASTE: papel envuelve piedra" << endl;
                victorias++;
                showScore(victorias,derrotas,empates);
            }else if(opcion == "papel" && opcion_compu == "tijera"){
                cout << "\nPERDISTE: tijera corta papel" << endl;
                derrotas++;
                showScore(victorias,derrotas,empates);
            }else if(opcion == "tijera" && opcion_compu == "piedra"){
                cout << "\nPERDISTE: piedra machaca tijera" << endl;
                derrotas++;
                showScore(victorias,derrotas,empates);
            }else{
                cout << "\nGANASTE: tijera corta papel" << endl;
                victorias++;
                showScore(victorias,derrotas,empates);
            }
        }else{
            cout << "\nEMPATE" << endl;
            empates++;
            showScore(victorias,derrotas,empates);
        }
    }else{
        cout << "\nOPCION NO VALIDA" << endl;
    };
    continuar = conti();
    };
    return 0;
}

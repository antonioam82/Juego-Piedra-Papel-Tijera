#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

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
    cout << "Piedra, Papel o tijera: "; cin >> option;

    return option;
}

int main()
{
    bool inclu;
    string opcion;
    string opcion_compu;

    //opcion = enterOption();
    opcion = convertToLower(enterOption());
    inclu = included(opcion);
    opcion_compu = computerOption();

    if(inclu == true){
        cout << "TU OPCION: " << opcion << endl;
        cout << "OPCION COMPU: " << opcion_compu << endl;
        if(opcion != opcion_compu){
            if(opcion == "piedra" && opcion_compu == "papel"){
                cout << "\nPERDISTE: papel envuelve piedra" << endl;
            }else if(opcion == "piedra" && opcion_compu == "tijera"){
                cout << "\nGANASTE: piedra machaca tijera" << endl;
            }else if(opcion == "papel" && opcion_compu == "piedra"){
                cout << "\nGANASTE: papel envuelve piedra" << endl;
            }else if(opcion == "papel" && opcion_compu == "tijera"){
                cout << "\nPERDISTE: tijera corta papel" << endl;
            }else if(opcion == "tijera" && opcion_compu == "piedra"){
                cout << "\nPERDISTE: piedra machaca tijera" << endl;
            }else{
                cout << "\nGANASTE: tijera corta papel" << endl;
            }
        }else{
            cout << "\nEMPATE" << endl;
        }
    }else{
        cout << "\nOPCION NO VALIDA" << endl;
    };
    return 0;
}

/*************************************************************
NOMBRE: Roberto perez Zamora
FECHA: 16/04/24
PROGRAMA: Actividad de programacion - 14.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Realizar la siguiente actividad, elaborar el juego del ahorcado con las siguiente condiciones

Tener un banco de al menos 20 palabras
La computadora va a elegir una al azar y el usuario debe adivinar el resultado
Si el usuario elige una vocal, se debe penalizar con 1 intento, es decir, tendrá una oportunidad menos
Contar el número de intentos por jugador
*************************************************************/

// Incluir bibliotecas necesarias
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para elegir una palabra al azar del banco de palabras
string elegirPalabraAleatoria(const vector<string> &bancoPalabras) {
    srand(time(0)); // Inicializar la semilla para generar números aleatorios
    int indice = rand() % bancoPalabras.size();
    return bancoPalabras[indice];
}

// Función para comprobar si una letra es vocal
bool esVocal(char letra) {
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
    return (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}

// Función para mostrar el estado actual de la palabra
void mostrarPalabra(const string &palabra, const vector<bool> &letrasAdivinadas) {
    for (size_t i = 0; i < palabra.length(); ++i) {
        if (letrasAdivinadas[i]) {
            cout << palabra[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    vector<string> bancoPalabras = {"hola", "adios", "perro", "gato", "casa", "computadora", "programacion", "codigo", "lenguaje", "escuela", "universidad", "telefono", "montaña", "avion", "camion", "ballena", "tigre", "elefante", "murcielago", "pajaro"};
    
    string palabraSecreta = elegirPalabraAleatoria(bancoPalabras);
    vector<bool> letrasAdivinadas(palabraSecreta.length(), false);
    int vidas = 10;
    int intentos = 0;
    
    cout << "Ur welcome to aorcado game" << endl;
    cout << "Anda bobo decime que dice la cosa." << endl;

    while (vidas > 0) {
        cout << "Vidas restantes: " << vidas << endl;
        mostrarPalabra(palabraSecreta, letrasAdivinadas);
        
        char intento;
        cout << "Introduce una letra: ";
        cin >> intento;

        
        
        bool letraAdivinada = false;
        for (size_t i = 0; i < palabraSecreta.length(); ++i) {
            if (palabraSecreta[i] == intento) {
                letrasAdivinadas[i] = true;
                letraAdivinada = true;
            }
        }
        
        if (!letraAdivinada) {
            vidas -= (esVocal(intento)) ? 1 : 2;
            cout << "La letra ingresada no está en la palabra. Pierdes " << ((esVocal(intento)) ? 1 : 2) << " vidas." << endl;
        }
        
        intentos++;

        // Funcion para penalizar si se usa una vocal
        if (esVocal(intento)) {
            vidas--;
            cout << "Ja chistosito vose habe usao la Vocal." << endl;
        }

        // Verificar si se ha adivinado la palabra
        bool palabraCompleta = true;
        for (size_t i = 0; i < letrasAdivinadas.size(); ++i) {
            if (!letrasAdivinadas[i]) {
                palabraCompleta = false;
                break;
            }
        }
        
        if (palabraCompleta) {
            cout << "Grande pibe te la sarpaste: '" << palabraSecreta << "' en " << intentos << " intentos." << endl;
            break;
        }
    }
    
    return 0;
}
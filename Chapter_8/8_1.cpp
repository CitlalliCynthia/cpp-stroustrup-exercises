#include <iostream>
#include <stdexcept> // Necesario para usar runtime_error si no usas la cabecera del libro
#include <string>

using namespace std;

// Esta es la definicion simplificada de la funcion error() que usa el libro
void error(string s) {
    throw runtime_error(s);
}

int main() {
    cout << "El programa va a lanzar una excepcion controlada...\n\n";

    // 1. Envolvemos la funcion peligrosa en un bloque try
    try {
        // Provocamos el error de forma directa
        error("Esto es un error de prueba no capturado!");

        // Esta linea nunca se ejecutara porque el error salta antes
        cout << "Este mensaje jamas se mostrara en pantalla.\n";
    }
    // 2. Atrapamos la excepcion para evitar que el programa muera
    catch (const runtime_error& e) {
        cout << "[EXCEPCION CAPTURADA CON EXITO]\n";
        cout << "Mensaje del error: " << e.what() << "\n\n";
    }

    // 3. El programa sigue vivo gracias al catch
    cout << "El programa continuo ejecutandose y termino de forma limpia.\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstring> // Necesario para strlen, strcmp y strcpy

/*
What does that list of differences mean in real code? For each array of char, vector<char>, 
list<char>, and string, define one with the value "Hello", pass it to a function as an argument, write
out the number of characters in the string passed, try to compare it to "Hello" in that function (to 
see if you really did pass "Hello"), and compare the argument to "Howdy" to see which would come first
in a dictionary. Copy the argument into another variable of the same type.
*/

using namespace std;

// 1. Función para char[] (recibe un puntero const char*)
void test_array(const char* s) {
    cout << "--- char[] ---\n";
    cout << "Caracteres: " << strlen(s) << "\n";

    if (strcmp(s, "Hello") == 0) cout << "Es igual a Hello\n";
    if (strcmp(s, "Howdy") < 0)  cout << "Va antes que Howdy en el diccionario\n";

    char copia[10];      // Debes asegurar manualmente que haya espacio suficiente
    strcpy(copia, s);    // No se puede hacer: char copia[] = s;
    cout << "Copia: " << copia << "\n\n";
}

// 2. Función para vector<char>
void test_vector(const vector<char>& v) {
    cout << "--- vector<char> ---\n";
    cout << "Caracteres: " << v.size() << "\n";

    vector<char> hello = { 'H', 'e', 'l', 'l', 'o' };
    vector<char> howdy = { 'H', 'o', 'w', 'd', 'y' };

    if (v == hello) cout << "Es igual a Hello\n";
    if (v < howdy)  cout << "Va antes que Howdy en el diccionario\n";

    vector<char> copia = v; // Copia directa con =
    cout << "Copia exitosa (tamano " << copia.size() << ")\n\n";
}

// 3. Función para list<char>
void test_list(const list<char>& l) {
    cout << "--- list<char> ---\n";
    cout << "Caracteres: " << l.size() << "\n";

    list<char> hello = { 'H', 'e', 'l', 'l', 'o' };
    list<char> howdy = { 'H', 'o', 'w', 'd', 'y' };

    if (l == hello) cout << "Es igual a Hello\n";
    if (l < howdy)  cout << "Va antes que Howdy en el diccionario\n";

    list<char> copia = l; // Copia directa con =
    cout << "Copia exitosa (tamano " << copia.size() << ")\n\n";
}

// 4. Función para std::string
void test_string(const string& s) {
    cout << "--- std::string ---\n";
    cout << "Caracteres: " << s.size() << "\n";

    if (s == "Hello") cout << "Es igual a Hello\n";
    if (s < "Howdy")  cout << "Va antes que Howdy en el diccionario\n";

    string copia = s; // Copia directa con =
    cout << "Copia: " << copia << "\n\n";
}

int main() {
    // Definición de las 4 variables con el valor "Hello"
    char arr[] = "Hello";
    vector<char> vec = { 'H', 'e', 'l', 'l', 'o' };
    list<char> lst = { 'H', 'e', 'l', 'l', 'o' };
    string str = "Hello";

    // Paso como argumento a sus respectivas funciones
    test_array(arr);
    test_vector(vec);
    test_list(lst);
    test_string(str);

    return 0;
}
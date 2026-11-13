#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Para std::equal y std::lexicographical_compare

/*
Do the previous Try this for an array of int, vector<int>, and list<int> each with the value { 1, 2,
3, 4, 5 }.
*/

using namespace std;

// 1. Función para int[] (requiere pasar el tamaño 'sz' manualmente)
void test_array(const int* a, int sz) {
    cout << "--- int[] ---\n";
    cout << "Elementos: " << sz << "\n";

    int ref_igual[] = { 1, 2, 3, 4, 5 };
    int ref_mayor[] = { 1, 2, 4, 0, 0 };

    // Comparación manual o usando algoritmos de <algorithm>
    if (equal(a, a + sz, ref_igual))
        cout << "Es igual a { 1, 2, 3, 4, 5 }\n";

    if (lexicographical_compare(a, a + sz, ref_mayor, ref_mayor + 5))
        cout << "Va antes que { 1, 2, 4, 0, 0 }\n";

    // Copia manual (no existe strcpy para enteros)
    int copia[5];
    for (int i = 0; i < sz; ++i) copia[i] = a[i];
    cout << "Copia exitosa (primer elemento: " << copia[0] << ")\n\n";
}

// 2. Función para vector<int>
void test_vector(const vector<int>& v) {
    cout << "--- vector<int> ---\n";
    cout << "Elementos: " << v.size() << "\n";

    vector<int> ref_igual = { 1, 2, 3, 4, 5 };
    vector<int> ref_mayor = { 1, 2, 4, 0, 0 };

    if (v == ref_igual) cout << "Es igual a { 1, 2, 3, 4, 5 }\n";
    if (v < ref_mayor)  cout << "Va antes que { 1, 2, 4, 0, 0 }\n";

    vector<int> copia = v;
    cout << "Copia exitosa (tamano: " << copia.size() << ")\n\n";
}

// 3. Función para list<int>
void test_list(const list<int>& l) {
    cout << "--- list<int> ---\n";
    cout << "Elementos: " << l.size() << "\n";

    list<int> ref_igual = { 1, 2, 3, 4, 5 };
    list<int> ref_mayor = { 1, 2, 4, 0, 0 };

    if (l == ref_igual) cout << "Es igual a { 1, 2, 3, 4, 5 }\n";
    if (l < ref_mayor)  cout << "Va antes que { 1, 2, 4, 0, 0 }\n";

    list<int> copia = l;
    cout << "Copia exitosa (tamano: " << copia.size() << ")\n\n";
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> vec = { 1, 2, 3, 4, 5 };
    list<int> lst = { 1, 2, 3, 4, 5 };

    // En main() sí podemos calcular el tamaño de arr con sizeof
    int sz = sizeof(arr) / sizeof(arr[0]);

    test_array(arr, sz);
    test_vector(vec);
    test_list(lst);

    return 0;
}
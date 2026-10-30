#include <iostream>
#include <vector>

// EJERCICIO 4
void print_array10(std::ostream& os, int* a) {
    for (int i = 0; i < 10; ++i) {
        os << a[i] << " ";
    }
    os << "\n";
}

// EJERCICIO 7
void print_array(std::ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i) {
        os << a[i] << " ";
    }
    os << "\n";
}

// EJERCICIO 10
void print_vector(std::ostream& os, const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << " ";
    }
    os << "\n";
}

int main() {
    // EJERCICIO 1
    int* array1 = new int[10];

    // EJERCICIO 2
    std::cout << "Ejercicio 2 (Arreglo inicializado por defecto):\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << "\n\n";

    // EJERCICIO 3
    delete[] array1;

    // EJERCICIO 5
    int* array5 = new int[10];
    for (int i = 0; i < 10; ++i) {
        array5[i] = 100 + i;
    }
    std::cout << "Ejercicio 5 (Usando print_array10):\n";
    print_array10(std::cout, array5);
    std::cout << "\n";

    // EJERCICIO 6
    int* array6 = new int[11];
    for (int i = 0; i < 11; ++i) {
        array6[i] = 100 + i;
    }
    std::cout << "Ejercicio 6 (Arreglo de 11 elementos):\n";

    for (int i = 0; i < 11; ++i) {
        std::cout << array6[i] << " ";
    }
    std::cout << "\n\n";

    // EJERCICIO 8
    int* array8 = new int[20];
    for (int i = 0; i < 20; ++i) {
        array8[i] = 100 + i;
    }
    std::cout << "Ejercicio 8 (Usando print_array con 20 elementos):\n";
    print_array(std::cout, array8, 20);
    std::cout << "\n";

    // EJERCICIO 9
    delete[] array5;
    delete[] array6;
    delete[] array8;

    // EJERCICIO 10
    std::cout << "Ejercicio 10 (Mismos datos pero usando std::vector):\n";

    std::vector<int> v5(10);
    for (int i = 0; i < 10; ++i) v5[i] = 100 + i;
    std::cout << "Vector de 10: ";
    print_vector(std::cout, v5);

    std::vector<int> v6(11);
    for (int i = 0; i < 11; ++i) v6[i] = 100 + i;
    std::cout << "Vector de 11: ";
    print_vector(std::cout, v6);

    std::vector<int> v20(20);
    for (int i = 0; i < 20; ++i) v20[i] = 100 + i;
    std::cout << "Vector de 20: ";
    print_vector(std::cout, v20);

    return 0;
}
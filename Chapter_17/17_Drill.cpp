#include <iostream>
#include <vector>

//1.4
void print_array(std::ostream& os, int* a) {
    for (int i = 0; i < 10; i++) {
        os << a[i] << " ";
    }
    os << "\n";
}

//1.7
void print_array(std::ostream& os, int* a, int n) {
    for (int i = 0; i < n; i++) {
        os << a[i] << " ";
    }
    os << "\n";
}

int main() {

    //1.1
    int* array1 = new int[10]();

    //1.2
    for (int i = 0; i < 10; i++) {
        std::cout << i[array1] << " ";
    }

    //1.3
    delete[] array1;

    //1.5
    std::cout << "\n";
    int* array2 = new int[10];
    int const iniVal = 100;
    for (int i = 0; i < 10; i++) {
        *(array2 + i) = iniVal + i;
        //std::cout << *(array2 + i) << " ";
    }
    print_array(std::cout, array2);

    //1.6
    int* array3 = new int[11];
    for (int i = 0; i < 11; i++) {
        *(array3 + i) = iniVal + i;
        //std::cout << *(array3 + i) << " ";
    }
    print_array(std::cout, array3, 11);

    //1.8
    int* array4 = new int[20];
    for (int i = 0; i < 20; i++) {
        *(array4 + i) = iniVal + i;
        //std::cout << *(array3 + i) << " ";
    }
    print_array(std::cout, array4, 20);

    //1.9
    delete[] array2;
    delete[] array3;
    delete[] array4;

    //1.10

    return 0;
}
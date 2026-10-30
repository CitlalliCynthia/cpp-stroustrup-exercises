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

//1.10
void print_vector(std::ostream& os, std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
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
    std::vector<int> vec(10);
    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] = iniVal + static_cast<int>(i);
    }
    print_vector(std::cout, vec);

    //2.1
    int* p1 = new int(7);

    //2.2
    std::cout << p1 << ": " << *p1 << "\n";

    //2.3
    int* array5 = new int[7];
    for (int i = 0; i < 7; i++) {
        array5[i] = 1 << i;
    }

    int* p2 = array5;

    //2.4
    std::cout << p2 << " == " << array5 << "\n";

    //2.5
    int* p3 = p2;

    //2.6
    p2 = p1;

    //2.7
    p2 = p3;

    //2.8
    std::cout << p1 << ": " << *p1 << "\n";
    std::cout << p2 << ": " << *p2 << "\n";

    //2.9
    delete p1;
    delete[] array5;

    //2.10
    int* array6 = new int[10];
    for (int i = 0; i < 10; i++) {
        array6[i] = 1 << i;
    }
    p1 = array6;

    //2.11
    int* array7 = new int[10];
    p2 = array7;

    //2.12
    for (int i = 0; i < 10; i++) {
        p2[i] = *(p1 + i);
        //std::cout << p2[i] << " ";
    }

    //2.13
    std::vector<int> vec1(10);
    for (size_t i = 0; i < vec1.size(); i++) {
        vec1[i] = 1 << i;
    }

    std::vector<int> vec2 = vec1;

    delete[] array6;
    delete[] array7;

    return 0;
}
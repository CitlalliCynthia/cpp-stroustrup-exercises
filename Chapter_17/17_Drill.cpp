#include <iostream>
#include <vector>

// PART 1 - EXERCISE 4
void print_array10(std::ostream& os, int* a) {
    for (int i = 0; i < 10; ++i) {
        os << a[i] << " ";
    }
    os << "\n";
}

// PART 1 - EXERCISE 7 / PART 2 - INTRO
void print_array(std::ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i) {
        os << a[i] << " ";
    }
    os << "\n";
}

// PART 1 - EXERCISE 10 / PART 2 - EXERCISE 13
void print_vector(std::ostream& os, const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << " ";
    }
    os << "\n";
}

int main() {
    // =========================================================================
    // PART 1
    // =========================================================================

    // PART 1 - EXERCISE 1
    int* array1 = new int[10];

    // PART 1 - EXERCISE 2
    std::cout << "--- PART 1 - EXERCISE 2 ---\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << "\n\n";

    // PART 1 - EXERCISE 3
    delete[] array1;

    // PART 1 - EXERCISE 5
    int* array5 = new int[10];
    for (int i = 0; i < 10; ++i) {
        array5[i] = 100 + i;
    }
    std::cout << "--- PART 1 - EXERCISE 5 ---\n";
    print_array10(std::cout, array5);
    std::cout << "\n";

    // PART 1 - EXERCISE 6
    int* array6 = new int[11];
    for (int i = 0; i < 11; ++i) {
        array6[i] = 100 + i;
    }
    std::cout << "--- PART 1 - EXERCISE 6 ---\n";
    for (int i = 0; i < 11; ++i) {
        std::cout << array6[i] << " ";
    }
    std::cout << "\n\n";

    // PART 1 - EXERCISE 8
    int* array8 = new int[20];
    for (int i = 0; i < 20; ++i) {
        array8[i] = 100 + i;
    }
    std::cout << "--- PART 1 - EXERCISE 8 ---\n";
    print_array(std::cout, array8, 20);
    std::cout << "\n";

    // PART 1 - EXERCISE 9
    delete[] array5;
    delete[] array6;
    delete[] array8;

    // PART 1 - EXERCISE 10
    std::cout << "--- PART 1 - EXERCISE 10 ---\n";
    std::vector<int> v5(10);
    for (int i = 0; i < 10; ++i) v5[i] = 100 + i;
    std::cout << "Vector 10: ";
    print_vector(std::cout, v5);

    std::vector<int> v6(11);
    for (int i = 0; i < 11; ++i) v6[i] = 100 + i;
    std::cout << "Vector 11: ";
    print_vector(std::cout, v6);

    std::vector<int> v20(20);
    for (int i = 0; i < 20; ++i) v20[i] = 100 + i;
    std::cout << "Vector 20: ";
    print_vector(std::cout, v20);
    std::cout << "\n";


    // =========================================================================
    // PART 2
    // =========================================================================

    // PART 2 - EXERCISE 1
    int* p1 = new int(7);

    // PART 2 - EXERCISE 2
    std::cout << "--- PART 2 - EXERCISE 2 ---\n";
    std::cout << "p1: " << p1 << "\n";
    std::cout << "*p1: " << *p1 << "\n\n";

    // PART 2 - EXERCISE 3
    int* p2 = new int[7];
    int val = 1;
    for (int i = 0; i < 7; ++i) {
        p2[i] = val;
        val *= 2;
    }

    // PART 2 - EXERCISE 4
    std::cout << "--- PART 2 - EXERCISE 4 ---\n";
    std::cout << "p2: ";
    print_array(std::cout, p2, 7);
    std::cout << "\n";

    // PART 2 - EXERCISE 5
    int* p3 = p2;

    // PART 2 - EXERCISE 6
    p2 = p1;

    // PART 2 - EXERCISE 7
    p2 = p3;

    // PART 2 - EXERCISE 8
    std::cout << "--- PART 2 - EXERCISE 8 ---\n";
    std::cout << "p1 points to: " << *p1 << "\n";
    std::cout << "p2 points to: ";
    print_array(std::cout, p2, 7);
    std::cout << "\n";

    // PART 2 - EXERCISE 9
    delete p1;
    delete[] p2;

    // PART 2 - EXERCISE 10
    p1 = new int[10];
    val = 1;
    for (int i = 0; i < 10; ++i) {
        p1[i] = val;
        val *= 2;
    }

    // PART 2 - EXERCISE 11
    p2 = new int[10];

    // PART 2 - EXERCISE 12
    for (int i = 0; i < 10; ++i) {
        p2[i] = p1[i];
    }
    std::cout << "--- PART 2 - EXERCISE 12 ---\n";
    std::cout << "p1 array: ";
    print_array(std::cout, p1, 10);
    std::cout << "p2 array: ";
    print_array(std::cout, p2, 10);
    std::cout << "\n";

    delete[] p1;
    delete[] p2;

    // PART 2 - EXERCISE 13
    std::cout << "--- PART 2 - EXERCISE 13 ---\n";
    std::vector<int> vec1(10);
    val = 1;
    for (int i = 0; i < 10; ++i) {
        vec1[i] = val;
        val *= 2;
    }
    std::vector<int> vec2(10);
    vec2 = vec1;
    std::cout << "vec1: ";
    print_vector(std::cout, vec1);
    std::cout << "vec2: ";
    print_vector(std::cout, vec2);

    return 0;
}
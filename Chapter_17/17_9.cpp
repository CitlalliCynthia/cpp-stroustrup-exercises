#include <iostream>

/*
9. Which way does the stack grow: up (toward higher addresses) or down (toward lower addresses)? Which way does the free store initially grow (that is, before you use delete)? Write a program to determine the answers.
*/

void checkStack(const int* mainDir) {
    int variableFunction = 0;
    std::cout << "--- STACK ---\n";
    std::cout << "Direction in main:    " << mainDir << "\n";
    std::cout << "Direction in function: " << &variableFunction << "\n";

    if (&variableFunction < mainDir) {
        std::cout << ">> STACK grows down (towards smaller directions).\n\n";
    }
    else {
        std::cout << ">> STACK grows up (towards bigger directions).\n\n";
    }
}

int main() {
    int mainVar = 0;

    checkStack(&mainVar);

    std::cout << "--- FREE STORE (HEAP) ---\n";
    int* ptr1 = new int;
    int* ptr2 = new int;
    int* ptr3 = new int;

    std::cout << "Direccion 1: " << ptr1 << "\n";
    std::cout << "Direccion 2: " << ptr2 << "\n";
    std::cout << "Direccion 3: " << ptr3 << "\n";

    if (ptr2 > ptr1) {
        std::cout << ">> FREE STORE grows up (towards bigger directions).\n";
    }
    else {
        std::cout << ">> FREE STORE grows down (towards smaller directions).\n";
    }

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
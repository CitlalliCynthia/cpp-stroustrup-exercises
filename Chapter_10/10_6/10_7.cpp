#include <iostream>
#include <vector>
#include <stdexcept>
#include "10_6.h"

/*
7. Make a version of the calculator from Chapter 7 that accepts Roman numerals rather than the usual Arabic ones, for example, XXI + CIV == CXXV.
*/

struct Operation {
    int operator1;
    int operator2;
    char operation;
};

int applyOperation(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) {
            throw std::runtime_error("Division by zero.");
        }
        return a / b;
    default: throw std::runtime_error("Not a valid operation!");
    }
}

Operation readExpression(std::istream& ist) {
    Operation temp;
    Roman::Roman_int roman;
    std::string operandSt1, operandSt2;

    ist >> operandSt1 >> temp.operation >> operandSt2;
    
    if (ist.fail()) throw std::runtime_error("Not a valid input.");

    //For first operator
    roman.setRomanChar(operandSt1);
    temp.operator1 = roman.as_int();

    //For second operator
    roman.setRomanChar(operandSt2);
    temp.operator2 = roman.as_int();

    return temp;
}

int main() {
    try {
        std::string userInput;
        std::cout << "Enter a Roman numeral binary expression separated by a space (Example, IV + I): ";
        Operation op = readExpression(std::cin);

        int result = applyOperation(op.operator1, op.operator2, op.operation);

        Roman::Roman_int romanResult(result);

        std::cout << "== " << romanResult << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }

    return 0;
}
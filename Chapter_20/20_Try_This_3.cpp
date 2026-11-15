#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstring> //To use strlen, strcmp y strcpy

/*
What does that list of differences mean in real code? For each array of char, vector<char>, 
list<char>, and string, define one with the value "Hello", pass it to a function as an argument, write
out the number of characters in the string passed, try to compare it to "Hello" in that function (to 
see if you really did pass "Hello"), and compare the argument to "Howdy" to see which would come first
in a dictionary. Copy the argument into another variable of the same type.
*/

void test_STL(const char* s) {
    
    std::cout << "\nThe char array has " << std::strlen(s) << " elements\n";

    if (std::strcmp(s, "Hello") == 0) std::cout << "It's equal to 'Hello'\n";
    if (std::strcmp(s, "Howdy") < 0) std::cout << "Hello comes before Howdy in the dictionary\n";

    char* copy = new char[std::strlen(s) + 1];
    strcpy_s(copy, std::strlen(s) + 1, s);
    std::cout << "Copy: " << copy << "\n";
    delete[] copy;
}

void test_STL(const std::vector<char>& s) {
    std::cout << "\nThe vector<char> has " << s.size() << " elements\n";

    std::vector<char> hello = { 'H', 'e', 'l', 'l', 'o' };
    std::vector<char> howdy = { 'H', 'o', 'w', 'd', 'y' };

    if(s == hello) std::cout << "It's equal to 'Hello'\n";
    if(s < howdy) std::cout << "Hello comes before Howdy in the dictionary\n";

    std::vector<char> copy(s);
    std::cout << "Copy: ";
    for (int i = 0; i < copy.size(); i++) std::cout << copy[i];
    std::cout << "\n";
}

void test_STL(const std::list<char>& s) {
    std::cout << "\nThe list<char> has " << s.size() << " elements\n";

    std::list<char> hello = { 'H', 'e', 'l', 'l', 'o' };
    std::list<char> howdy = { 'H', 'o', 'w', 'd', 'y' };

    if (s == hello) std::cout << "It's equal to 'Hello'\n";
    if (s < howdy) std::cout << "Hello comes before Howdy in the dictionary\n";

    std::list<char> copy(s);
    std::cout << "Copy: ";
    for (std::list<char>::const_iterator it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it;
    }
    std::cout << "\n";
}

void test_STL(const std::string& s) {
    std::cout << "\nThe string has " << s.length() << " elements\n";

    std::string hello("Hello");
    std::string howdy("Howdy");

    if (s == hello) std::cout << "It's equal to 'Hello'\n";
    if (s < howdy) std::cout << "Hello comes before Howdy in the dictionary\n";

    std::string copy(s);
    std::cout << "Copy: " << copy << "\n";
}

int main() {

    char arr[] = "Hello";
    std::vector<char> vec = { 'H', 'e', 'l', 'l', 'o' };
    std::list<char> lst = { 'H', 'e', 'l', 'l', 'o' };
    std::string str = "Hello";

    
    test_STL(arr);
    test_STL(vec);
    test_STL(lst);
    test_STL(str);
    
    return 0;
}
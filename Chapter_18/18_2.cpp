#include <iostream>

/*
2. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style
string x in s. Do not use any standard library functions. Do not use subscripting; use the dereference operator
* instead.
*/

char* findx(const char* s, const char* x) {
    if (s == NULL || x == NULL) return NULL;

    if (*x == '\0') return (char*)s;

    const char* fromS = s;
    const char* toFindX = x;

    while (*fromS) {
        const char* coincidence = fromS;

        while (*fromS != '\0' && *toFindX != '\0' && *fromS == *toFindX) {
            toFindX++;
            fromS++;
        }

        if (*toFindX == '\0') {
            return (char*)coincidence;
        }

        toFindX = x;
        fromS = coincidence;

        fromS++;
    }

    return NULL;
}

int main() {
    char array[] = "Hello woworld!";
    char toSearch[] = "wor";
    char* p = findx(array, toSearch);

    if (p != NULL) {
        std::cout << "Text since finding the coincidene: " << p << "\n";
    }
    else {
        std::cout << "No coincidence!\n";
    }

    return 0;
}
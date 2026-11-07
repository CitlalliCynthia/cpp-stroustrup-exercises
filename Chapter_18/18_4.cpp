#include <iostream>

/*
4. Consider what happens if you give strdup(), findx(), and strcmp() an argument that is not a C-style string.
Try it! First figure out how to get a char* that doesn’t point to a zero-terminated array of characters and then 
use it (never do this in real — non-experimental — code; it can create havoc). Try it with free-store-allocated 
and stack-allocated “fake C-style strings.” If the results still look reasonable, turn off debug mode. Redesign
and re-implement those three functions so that they take another argument giving the maximum number of elements
allowed in argument strings. Then, test that with correct C-style strings and “bad” strings.
*/

char* strdup1(const char* cString, int max_size) {
    if (cString == NULL || max_size <= 0) return NULL;

    const char* temp = cString;
    int size = 0;

    while (*temp && size < max_size) {
        size++;
        temp++;
    }

    char* newString = new char[size + 1];

    temp = cString;
    char* stringIterator = newString;
    int copied = 0;

    while (*temp && copied < size) {
        *stringIterator = *temp;
        temp++;
        stringIterator++;
        copied++;
    }

    *stringIterator = '\0';
    return newString;
}

char* findx(const char* s, const char* x, int max_size) {
    if (s == NULL || x == NULL || max_size <= 0) return NULL;
    if (*x == '\0') return (char*)s;

    const char* fromS = s;
    const char* toFindX = x;
    int countS = 0;

    while (*fromS && countS < max_size) {
        const char* coincidence = fromS;
        int subCountS = countS;

        while (*fromS != '\0' && *toFindX != '\0' && *fromS == *toFindX && subCountS < max_size) {
            toFindX++;
            fromS++;
            subCountS++;
        }

        if (*toFindX == '\0') {
            return (char*)coincidence;
        }

        toFindX = x;
        fromS = coincidence;
        fromS++;
        countS++;
    }

    return NULL;
}

int strcmp1(const char* s1, const char* s2, int max_size) {
    if (max_size <= 0) return 0;

    int count = 0;
    while (*s1 && *s2 && count < max_size) {
        if (*s1 != *s2) return *s1 - *s2;
        s1++;
        s2++;
        count++;
    }

    if (count == max_size) return 0;

    return *s1 - *s2;
}

int main() {
    char badStackArray[] = { 'h','e','l','l','o',' ','w','o','r','l','d','!' }; // 12 elements
    char badToSearch[] = { 'w','o','r' };                                      // 3 elements

    std::cout << "STACK\n";

    char* copyStack = strdup1(badStackArray, 12);
    if (copyStack) {
        std::cout << copyStack << "\n";
        delete[] copyStack;
    }

    char* matchStack = findx(badStackArray, badToSearch, 12);
    if (matchStack) {
        std::cout << "Coincidence found!\n";
    }
    else {
        std::cout << "No coincidence found!\n";
    }

    int cmpStack = strcmp1(badStackArray, badStackArray, 12);
    std::cout << "Result: " << cmpStack;

    //HEAP
    char* badHeapArray = new char[12] {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};

    std::cout << "HEAP\n";

    char* copyHeap = strdup1(badHeapArray, 12);
    if (copyHeap) {
        std::cout << copyHeap << "\n";
        delete[] copyHeap;
    }

    delete[] badHeapArray;

    return 0;
}
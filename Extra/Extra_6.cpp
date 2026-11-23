#include <iostream>
#include <vector>

//Variable sized arrays (HackerRank)

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int*> vec;

    for (int i = 0; i < n; i++) {
        int counter;
        std::cin >> counter;

        int* arr = new int[counter];
        int* p = arr;
        for (int j = 0; j < counter; j++) {
            int temp;
            std::cin >> temp;
            *p = temp;
            p++;
        }

        vec.push_back(arr);
    }

    for (int i = 0; i < q; i++) {
        int posVec, posArr;
        std::cin >> posVec >> posArr;

        std::cout << vec[posVec][posArr] << "\n";
    }

    return 0;
}
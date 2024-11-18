#include "Array.h"

#include <iostream>
#include <vector>


int main() {
    
    int sizeArr1, sizeArr2;
    std::cout << "\t\t--->WELCOME<---\n\n";

    std::cout << "Input size of arr1 -> "; std::cin >> sizeArr1;
    std::cout << "Input size of arr2 -> "; std::cin >> sizeArr2;
    std::cout << "\n\n";

    Array arr1(sizeArr1);
    Array arr2(sizeArr2);

    std::cout << "\t    --->Input arr1 data<---\n";
    arr1.Input();

    std::cout << "\t    --->Input arr2 data<---\n";
    arr2.Input();

    auto vec_intersec    = arr1.GetIntersection(arr2);
    auto vec_associative = arr1.GetAssociation(arr2);

    printVector(vec_intersec,    "Intersection of arr1 with arr2");
    printVector(vec_associative, "Association of arr1 with arr2");

    return 0;
}

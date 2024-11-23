#include "Classes.h"

#include <iostream>
#include <exception>
#include <ctime>
#include <random>


const int sizeN1 = 20;
const int sizeN2 = 10;
const int sizeN3 = 15;


// Функция для вывода массива
void PrintInfoArray(const float* array, size_t size) 
{
    std::cout << "{ ";
    for (size_t i = 0; i < size; ++i) {
        if (i > 0 && i % 5 == 0) 
            std::cout << "\n";
      
        std::cout << array[i];

        if (i < size - 1) 
            std::cout << ", ";
    }
    std::cout << " }\n";
}


int main() {

    setlocale(0, "");
    srand(static_cast<unsigned>(time(nullptr)));

    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(-10, 1);

    float LnArray[sizeN1]{};
    float RandomArray[sizeN2]{};
    float FormulaBasedArray[sizeN3]{}; // c(i) = a(i) - 1 / b(i)

    const float deltaX = 0.2f;
    float tempX = 0.2f;

    try 
    {
        // Заполнение массива LnArray
        for (int i = 0; i < sizeN1; ++i) {
            float result = tempX * tempX - 1;
            if ((result) > 0.0f) {
                LnArray[i] = std::log(result);
            }
            else
                LnArray[i] = 0.0f;
            tempX += deltaX;
        }
        std::cout << "\nLnArray = ";
        PrintInfoArray(LnArray, sizeN1);


        // Заполнение массива RandomArray
        for (int i = 0; i < sizeN2; ++i) {
            float value = distribution(generator);
            if (value > 0.0f) {
                throw GreaterZeroException("\nValue is greater than zero!");
            }
            RandomArray[i] = value;
        }
        std::cout << "\nRandomArray = ";
        PrintInfoArray(RandomArray, sizeN2);


        // Заполнение массива FormulaBasedArray
        if ((sizeN1 == sizeN2) && (sizeN2 == sizeN3)) {
            for (int i = 0; i < sizeN3; ++i) {
                if (RandomArray[i] == 0.0f) {
                    throw DivisionOnZeroException("\nException division by zero occurred!");
                }
                FormulaBasedArray[i] = LnArray[i] - (1 / RandomArray[i]);
            }
        }
        else {
            throw OutOfRangeException("Size of arrays are not equal!");
        }
        std::cout << "\nFormulaBasedArray = ";
        PrintInfoArray(FormulaBasedArray, sizeN3);

    }
    catch (const GreaterZeroException& exception) {
        std::cerr << "\n[EXCEPTION OCCURRED IN RANDOM_ARRAY] " << exception.what() << std::endl;
    }
    catch (const DivisionOnZeroException& exception) {
        std::cerr << "\n[EXCEPTION OCCURRED IN FORMULA_BASED_ARRAY] " << exception.what() << std::endl;
    }
    catch (const OutOfRangeException& exception) {
        std::cerr << "\n[EXCEPTION OCCURRED IN FORMULA_BASED_ARRAY] " << exception.what() << std::endl;
    }
    

    return 0;
}
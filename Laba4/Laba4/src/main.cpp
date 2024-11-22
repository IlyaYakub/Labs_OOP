/*
Для базовых классов «Двигатель», «Кузов», «Цвет» разработать
производный класс «Автомобиль». Содержимое классов продумать
самостоятельно.
*/


#include "Classes.h"
#include <iostream>


void printEngineInfo(const Engine& engine) 
{
    std::cout << "Двигатель:\n";
    std::cout << "\tТип: " << engine.getEgnineType() << "\n";
    std::cout << "\tМощность: " << engine.getEngineHorsepower() << " л.с.\n";
}


void printBodyInfo(const Body& body) 
{
    std::cout << "Кузов:\n";
    std::cout << "\tТип: " << body.getBodyType() << "\n";
    std::cout << "\tМатериал: " << body.getBodyMaterial() << "\n";
}


void printColorInfo(const Color& color)
{
    std::cout << "Цвет:\n";
    std::cout << "\tНазвание: " << color.getColorName() << "\n";
    std::cout << "\tКод: " << color.getColorCode() << "\n";
}

int main() {
    setlocale(0, "");

    Engine engine("V8", 450);
    Body body("Седан", "Алюминий");
    Color color("Красный", "#FF0000");

    std::cout << "Информация о компонентах автомобиля:\n";
    printEngineInfo(engine);
    printBodyInfo(body);
    printColorInfo(color);

    Car car(engine, body, color);

    std::cout << "\nИнформация об автомобиле:\n";
    car.printCarDetails();

    return 0;
}

/*
��� ������� ������� �����������, ������, ����� �����������
����������� ����� ������������. ���������� ������� ���������
��������������.
*/


#include "Classes.h"
#include <iostream>


void printEngineInfo(const Engine& engine) 
{
    std::cout << "���������:\n";
    std::cout << "\t���: " << engine.getEgnineType() << "\n";
    std::cout << "\t��������: " << engine.getEngineHorsepower() << " �.�.\n";
}


void printBodyInfo(const Body& body) 
{
    std::cout << "�����:\n";
    std::cout << "\t���: " << body.getBodyType() << "\n";
    std::cout << "\t��������: " << body.getBodyMaterial() << "\n";
}


void printColorInfo(const Color& color)
{
    std::cout << "����:\n";
    std::cout << "\t��������: " << color.getColorName() << "\n";
    std::cout << "\t���: " << color.getColorCode() << "\n";
}

int main() {
    setlocale(0, "");

    Engine engine("V8", 450);
    Body body("�����", "��������");
    Color color("�������", "#FF0000");

    std::cout << "���������� � ����������� ����������:\n";
    printEngineInfo(engine);
    printBodyInfo(body);
    printColorInfo(color);

    Car car(engine, body, color);

    std::cout << "\n���������� �� ����������:\n";
    car.printCarDetails();

    return 0;
}

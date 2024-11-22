#include "Classes.h"


Car::Car(
    const std::string& brand = "Undefined car brand",
    const std::string& model = "Undefined car model",
    double enginePower = 0, 
    int numSeats = 0)
{
    this->brand = brand;
    this->model = model;
    this->enginePower = enginePower;
    this->numSeats = numSeats;
}

double Car::calculateMaxSpeed() const 
{
    return enginePower * 2; // Примерная формула для вычисления максимальной скорости (км/ч)
}

void Car::printVehicleType() const
{
    std::cout << "Тип транспортного средства: Автомобиль\n";
    std::cout << "\tБренд: " << brand << "\n";
    std::cout << "\tМодель: " << model << "\n";
    std::cout << "\tМощность двигателя: " << enginePower << " л.с.\n";
    std::cout << "\tКоличество мест: " << numSeats << "\n";
}

// Реализация класса "Bicycle"
Bicycle::Bicycle(
    const std::string& brand = "Undefined bicycle brand",
    const std::string& type =  "Undefined bicycle type",
    int gearCount = 0)
    : brand(brand), type(type), gearCount(gearCount) // Применяем список инициализации
{
}

double Bicycle::calculateMaxSpeed() const 
{
    return gearCount * 5; // Примерная формула для вычисления максимальной скорости (км/ч)
}

void Bicycle::printVehicleType() const 
{
    std::cout << "Тип транспортного средства: Велосипед\n";
    std::cout << "\tБренд: " << brand                  << "\n";
    std::cout << "\tТип: " << type                     << "\n";
    std::cout << "\tКоличество передач: " << gearCount << "\n";
}

// Реализация класса "Airplane"
Airplane::Airplane(
    const std::string& airline = "Undefined airplane",
    const std::string& model = "Undefined airplane model",
    double engineThrust = 0,
    int capacity = 0)
    : airline(airline), model(model), engineThrust(engineThrust), capacity(capacity)
{
}

double Airplane::calculateMaxSpeed() const 
{
    return engineThrust * 10; // Примерная формула для вычисления максимальной скорости (км/ч)
}

void Airplane::printVehicleType() const 
{
    std::cout << "Тип транспортного средства: Самолёт\n";
    std::cout << "\tАвиакомпания: " << airline                  << "\n";
    std::cout << "\tМодель: " << model                          << "\n";
    std::cout << "\tТяга двигателя: " << engineThrust << " кН\n";
    std::cout << "\tПассажировместимость: " << capacity << " человек\n";
}
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
    return enginePower * 2; // ��������� ������� ��� ���������� ������������ �������� (��/�)
}

void Car::printVehicleType() const
{
    std::cout << "��� ������������� ��������: ����������\n";
    std::cout << "\t�����: " << brand << "\n";
    std::cout << "\t������: " << model << "\n";
    std::cout << "\t�������� ���������: " << enginePower << " �.�.\n";
    std::cout << "\t���������� ����: " << numSeats << "\n";
}

// ���������� ������ "Bicycle"
Bicycle::Bicycle(
    const std::string& brand = "Undefined bicycle brand",
    const std::string& type =  "Undefined bicycle type",
    int gearCount = 0)
    : brand(brand), type(type), gearCount(gearCount) // ��������� ������ �������������
{
}

double Bicycle::calculateMaxSpeed() const 
{
    return gearCount * 5; // ��������� ������� ��� ���������� ������������ �������� (��/�)
}

void Bicycle::printVehicleType() const 
{
    std::cout << "��� ������������� ��������: ���������\n";
    std::cout << "\t�����: " << brand                  << "\n";
    std::cout << "\t���: " << type                     << "\n";
    std::cout << "\t���������� �������: " << gearCount << "\n";
}

// ���������� ������ "Airplane"
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
    return engineThrust * 10; // ��������� ������� ��� ���������� ������������ �������� (��/�)
}

void Airplane::printVehicleType() const 
{
    std::cout << "��� ������������� ��������: ������\n";
    std::cout << "\t������������: " << airline                  << "\n";
    std::cout << "\t������: " << model                          << "\n";
    std::cout << "\t���� ���������: " << engineThrust << " ��\n";
    std::cout << "\t��������������������: " << capacity << " �������\n";
}
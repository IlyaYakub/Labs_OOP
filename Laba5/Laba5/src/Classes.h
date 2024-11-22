#pragma once

#include <string>
#include <iostream>


// Абстрактный класс "Vehicle"
class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual double calculateMaxSpeed() const = 0;
    virtual void printVehicleType()    const = 0;
};


// Класс "Car"
class Car : public Vehicle {
public:
    Car(const std::string& brand,
        const std::string& model,
        double enginePower,
        int numSeats);
    virtual ~Car() = default;

    double calculateMaxSpeed() const override;
    void printVehicleType()    const override;

private:
    std::string brand;
    std::string model;
    double      enginePower; // Horsepower
    int         numSeats;
};


// Класс "Bicycle"
class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& brand, 
            const std::string& type, 
            int gearCount);
    virtual ~Bicycle() = default;

    double calculateMaxSpeed() const override;
    void printVehicleType()    const override;

private:
    std::string brand;
    std::string type; 
    int         gearCount;
};


// Класс "Airplane"
class Airplane : public Vehicle {
public:
    Airplane(const std::string& airline,
             const std::string& model, 
             double engineThrust, 
             int capacity);
    ~Airplane() override = default;

    double calculateMaxSpeed() const override;
    void printVehicleType()    const override;

private:
    std::string airline;
    std::string model;
    double      engineThrust; // Thrust in kN
    int         capacity;
};

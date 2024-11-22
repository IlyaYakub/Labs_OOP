#pragma once

#include <string>
#include <iostream>


class Engine 
{
public:
    Engine();
    Engine(const std::string& type, int horsepower);

    const std::string& getEgnineType() const { return type;       }
    int getEngineHorsepower()          const { return horsepower; }

    void setEngineType(const std::string& type) { this->type = type;             }
    void setEngineHorsepower(int horsepower)    { this->horsepower = horsepower; }

private:
    std::string type;
    int horsepower;
};


class Body
{
public:
    Body();
    Body(const std::string& type, const std::string& material);

    const std::string& getBodyType()     const { return type;     }
    const std::string& getBodyMaterial() const { return material; }

    void setBodyType(const std::string& type)         { this->type = type;         }
    void setBodyMaterial(const std::string& material) { this->material = material; }

private:
    std::string type;
    std::string material;
};


class Color {
public:
    Color();
    Color(const std::string& name, const std::string& code);

    const std::string& getColorName() const { return name; }
    const std::string& getColorCode() const { return code; }

    void setColorName(const std::string& name) { this->name = name; }
    void setColorCode(const std::string& code) { this->code = code; }

private:
    std::string name;
    std::string code;
};


class Car : public Engine, Body, Color 
{
public:
    Car();
    Car(const Engine& engine, const Body& body, const Color& color);

    void printCarDetails() const;
};
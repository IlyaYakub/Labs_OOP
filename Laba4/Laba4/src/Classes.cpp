#include "Classes.h"

// Engine class implementation
Engine::Engine() : type("Unknown"), horsepower(0) 
{}

Engine::Engine(const std::string& type, int horsepower)
    : type(type), horsepower(horsepower)
{}


// Body class implementation
Body::Body() : type("Unknown"), material("Unknown")
{}

Body::Body(const std::string& type, const std::string& material)
    : type(type), material(material) 
{}


// Color class implementation
Color::Color() : name("Unknown"), code("#000000")
{}

Color::Color(const std::string& name, const std::string& code)
    : name(name), code(code)
{}


// Car class implementation
Car::Car() : Engine(), Body(), Color() 
{}

Car::Car(const Engine& engine, const Body& body, const Color& color)
    : Engine(engine), Body(body), Color(color) 
{}

void Car::printCarDetails() const 
{
    std::cout << "Car Details:"  << std::endl;
    std::cout << "\tEngine Type: " << getEgnineType()       << std::endl;
    std::cout << "\tHorsepower: "  << getEngineHorsepower() << std::endl;
    std::cout << "\tBody Type: "   << getBodyType()         << std::endl;
    std::cout << "\tMaterial: "    << getBodyMaterial()     << std::endl;
    std::cout << "\tColor Name: "  << getColorName()        << std::endl;
    std::cout << "\tColor Code: "  << getColorCode()        << std::endl;
}

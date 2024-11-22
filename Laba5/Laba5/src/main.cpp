#include "Classes.h"
#include <iostream>
#include <vector>


void printVehicleInfo(const Vehicle* vehicle) 
{
    vehicle->printVehicleType();
    std::cout << "Максимальная скорость: " << vehicle->calculateMaxSpeed() << " км/ч\n\n";
}


int main() {

    setlocale(0, "");

    Car      car("Toyota", "Camry", 300, 5);
    Bicycle  bicycle("Giant", "Mountain", 21);
    Airplane airplane("Aeroflot", "Boeing 737", 1200, 200);

    std::vector<Vehicle*> vehicles = { &car, &bicycle, &airplane };

    for (const auto& vehicle : vehicles) 
        printVehicleInfo(vehicle);

    return 0;
}

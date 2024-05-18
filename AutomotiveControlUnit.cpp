#include <iostream>

class EngineControlUnit {
private:
    bool autoJack;
    bool gripTires;
    bool infraredLights;

    void actuateHydraulicJacks();
    void activateGripTires();
    void activateInfraredLights();

public:
    EngineControlUnit();
    ~EngineControlUnit();

    void handleCommand(char command);
};

EngineControlUnit::EngineControlUnit() 
    : autoJack(false), gripTires(false), infraredLights(false) {}

EngineControlUnit::~EngineControlUnit() {}

void EngineControlUnit::actuateHydraulicJacks() {
    if (autoJack) {
        std::cout << "Hydraulic Jacks deactivated" << std::endl;
    } else {
        if (gripTires) {
            gripTires = false;
            std::cout << "Grip Tires deactivated" << std::endl;
        }
        std::cout << "Hydraulic Jacks activated" << std::endl;
    }
    autoJack = !autoJack;
}

void EngineControlUnit::activateGripTires() {
    if (gripTires) {
        std::cout << "Grip Tires deactivated" << std::endl;
    } else {
        if (autoJack) {
            std::cout << "Grip Tires cannot be activated while Hydraulic Jacks are deployed" << std::endl;
            return;
        }
        std::cout << "Grip Tires activated" << std::endl;
    }
    gripTires = !gripTires;
}

void EngineControlUnit::activateInfraredLights() {
    if (infraredLights) {
        std::cout << "Infrared Lights deactivated" << std::endl;
    } else {
        std::cout << "Infrared Lights activated" << std::endl;
    }
    infraredLights = !infraredLights;
}

void EngineControlUnit::handleCommand(char command) {
    switch (command) {
        case 'A':
            actuateHydraulicJacks();
            break;
        case 'B':
            activateGripTires();
            break;
        case 'E':
            activateInfraredLights();
            break;
        case 'X':
            std::cout << "Ignition turned off. Exiting program." << std::endl;
            exit(0);
        default:
            std::cout << "Invalid command" << std::endl;
    }
}

void displaySteeringWheel() {
    std::cout << "Steering Wheel Controls:\n";
    std::cout << "Press A: Actuate Hydraulic Jacks\n";
    std::cout << "Press B: Activate Grip Tires\n";
    std::cout << "Press E: Activate Infrared Lights\n";
    std::cout << "Press X: Turn off Ignition\n";
}

int main() {
    EngineControlUnit ecu;
    char command;

    while (true) {
        displaySteeringWheel();
        std::cout << "Enter command: ";
        std::cin >> command;
        ecu.handleCommand(command);
    }

    return 0;
}

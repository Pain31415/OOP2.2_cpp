#include "Reservoir.h"
#include <iostream>

// Constructors
Reservoir::Reservoir(const std::string& name) : name(name), width(0.0), length(0.0), maxDepth(0.0) {}

Reservoir::Reservoir(const std::string& name, double width, double length, double maxDepth)
    : name(name), width(width), length(length), maxDepth(maxDepth) {}

// Destructor
Reservoir::~Reservoir() {
    std::cout << "Object " << name << " deleted\n";
}

// Copy constructor
Reservoir::Reservoir(const Reservoir& other) : name(other.name), width(other.width), length(other.length), maxDepth(other.maxDepth) {
    std::cout << "Copy of object " << name << " created\n";
}

// Member functions
double Reservoir::calculateVolume() const {
    return width * length * maxDepth;
}

double Reservoir::calculateSurfaceArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {
    return name == other.name;
}

bool Reservoir::operator<(const Reservoir& other) const {
    return calculateSurfaceArea() < other.calculateSurfaceArea();
}

// Getter and Setter functions
void Reservoir::setName(const std::string& name) {
    this->name = name;
}

std::string Reservoir::getName() const {
    return name;
}

void Reservoir::setWidth(double width) {
    this->width = width;
}

double Reservoir::getWidth() const {
    return width;
}

void Reservoir::setLength(double length) {
    this->length = length;
}

double Reservoir::getLength() const {
    return length;
}

void Reservoir::setMaxDepth(double maxDepth) {
    this->maxDepth = maxDepth;
}

double Reservoir::getMaxDepth() const {
    return maxDepth;
}

// Display function
void Reservoir::displayInfo() const {
    std::cout << "Name: " << name << ", Width: " << width << ", Length: " << length << ", Max Depth: " << maxDepth << "\n";
}
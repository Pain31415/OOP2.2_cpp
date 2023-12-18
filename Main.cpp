#include <iostream>
#include <fstream>
#include "Reservoir.h"

int main() {
    system("chcp 1251");
    system("cls");

    Reservoir reservoirs[] = {
        Reservoir("Sea", 100.0, 200.0, 50.0),
        Reservoir("Pond", 30.0, 40.0, 10.0),
        Reservoir("Basin", 80.0, 150.0, 30.0)
    };

    // Display information about each reservoir
    for (const auto& reservoir : reservoirs) {
        reservoir.displayInfo();
    }

    // Write reservoir names to a text file
    std::ofstream outFile("reservoirs.txt");
    if (outFile.is_open()) {
        for (const auto& reservoir : reservoirs) {
            outFile << reservoir.getName() << "\n";
        }
        outFile.close();
        std::cout << "Reservoir names written to reservoirs.txt\n";
    }
    else {
        std::cerr << "Failed to open the file for writing\n";
    }

    // Write reservoir data to a binary file
    std::ofstream binaryOutFile("reservoirs.bin", std::ios::binary);
    if (binaryOutFile.is_open()) {
        for (const auto& reservoir : reservoirs) {
            binaryOutFile.write(reinterpret_cast<const char*>(&reservoir), sizeof(Reservoir));
        }
        binaryOutFile.close();
        std::cout << "Reservoir data written to reservoirs.bin\n";
    }
    else {
        std::cerr << "Failed to open the binary file for writing\n";
    }

    return 0;
}
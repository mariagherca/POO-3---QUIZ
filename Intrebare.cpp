#include "Intrebare.h"
#include <iostream>

void Intrebare::afiseaza() const {
    std::cout << text << "\n";
    for (size_t i = 0; i < variante.size(); ++i) {
        std::cout << i + 1 << ". " << variante[i] << "\n";
    }
}



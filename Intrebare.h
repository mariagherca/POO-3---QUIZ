#pragma once
#include <string>
#include <vector>

struct Intrebare {
    std::string text;
    std::vector<std::string> variante;
    int raspuns_corect;
    void afiseaza() const;
};

#pragma once
#include "Intrebare.h"
#include <vector>
#include <string>

class Quiz {
    std::vector<Intrebare> intrebari;
public:
    bool incarcaDinFisier(const std::string& numeFisier);
    std::vector<int> ruleaza() const;
};


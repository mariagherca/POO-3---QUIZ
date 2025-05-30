#include "Quiz.h"
#include <fstream>
#include <iostream>
#include <limits>

bool Quiz::incarcaDinFisier(const std::string& numeFisier) {
    std::ifstream in(numeFisier);
    if (!in) return false;
    std::string linie;
    while (std::getline(in, linie)) {
        Intrebare q;
        q.text = linie;
        int n;
        in >> n;
        in.ignore();
        for (int i = 0; i < n; ++i) {
            std::getline(in, linie);
            q.variante.push_back(linie);
        }
        in >> q.raspuns_corect;
        in.ignore();
        intrebari.push_back(q);
    }
    return true;
}

std::vector<int> Quiz::ruleaza() const {
    std::vector<int> scoruri;
    for (const auto& intrebare : intrebari) {
        intrebare.afiseaza();
        int raspuns;
        std::cout << "Raspunsul tau: ";
        while (!(std::cin >> raspuns) || raspuns < 1 || raspuns > (int)intrebare.variante.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Raspuns invalid. Incearca din nou: ";
        }
        scoruri.push_back((raspuns) == intrebare.raspuns_corect ? 1 : 0);
    }
    return scoruri;
}


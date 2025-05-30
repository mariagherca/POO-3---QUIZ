#pragma once
#include <iostream>
#include <vector>
#include <string>

// Template

template<typename T>
class Lectie {
    std::string titlu;
    T continut;
public:
    Lectie(const std::string& titlu, const T& continut) : titlu(titlu), continut(continut) {}

    void afiseazaContinut() const {
        std::cout << "Lectie: " << titlu << "\nContinut: " << continut << "\n";
    }

    const T& getContinut() const { return continut; }
    const std::string& getTitlu() const { return titlu; }
};

template<>
inline void Lectie<std::vector<std::string>>::afiseazaContinut() const {
    std::cout << "Lectie cu paragrafe:\n";
    for (const auto& p : getContinut()) std::cout << "- " << p << "\n";
}

template<typename T>
void afiseazaLectie(const Lectie<T>& l) {
    l.afiseazaContinut();
}

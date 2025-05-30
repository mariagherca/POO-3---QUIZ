#include "Progres.h"
#include <fstream>
#include <iostream>

void salveazaProgresul(const std::string& numeStudent, const std::string& materie, float procent) {
    std::ofstream out("progres.txt", std::ios::app);
    out << numeStudent << " " << materie << " " << procent << "\n";
}

void afiseazaProgres() {
    std::ifstream in("progres.txt");
    if (!in) {
        std::cout << "Nu exista progres salvat.\n";
        return;
    }

    std::string nume, materie;
    float procent;
    bool existaDate = false;

    while (in >> nume >> materie >> procent) {
        existaDate = true;
        std::cout << "Student: " << nume << ", Materie: " << materie << ", Progres: " << procent << "%\n";
    }

    if (!existaDate) {
        std::cout << "Nu exista progres salvat.\n";
    }
}

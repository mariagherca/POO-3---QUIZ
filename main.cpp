#include <iostream>
#include <string>
#include <vector>
#include "Observer.h"
#include "Evaluare.h"
#include "Quiz.h"
#include "Lectie.h"
#include "Progres.h"

int main() {
    std::string nume;
    std::cout << "Introdu numele studentului: ";
    std::getline(std::cin, nume);
    Student student(nume);
    EvaluarePunctaj evaluator;

    while (true) {
        std::cout << "\n===== MENIU PRINCIPAL =====\n";
        std::cout << "1. Quiz Geografie\n";
        std::cout << "2. Quiz Istorie\n";
        std::cout << "3. Quiz Biologie\n";
        std::cout << "4. Vezi progres\n";
        std::cout << "0. Iesire\nAlegeti: ";

        int opt;
        std::cin >> opt;
        std::cin.ignore();

        if (opt == 0) break;

        std::string fisier, materie;
        switch (opt) {
            case 1: fisier = "quiz_geografie.txt"; materie = "Geografie"; break;
            case 2: fisier = "quiz_istorie.txt"; materie = "Istorie"; break;
            case 3: fisier = "quiz_biologie.txt"; materie = "Biologie"; break;
            case 4: afiseazaProgres(); continue;
            default: std::cout << "Optiune invalida.\n"; continue;
        }

        Quiz q;
        if (!q.incarcaDinFisier(fisier)) {
            std::cout << "Eroare la deschiderea fisierului " << fisier << "\n";
            continue;
        }
        Lectie<Quiz> lQuiz("Quiz " + materie, q);
        std::cout << "\nIncepe quiz-ul: " << lQuiz.getTitlu() << "\n";
        std::vector<int> scoruri = lQuiz.getContinut().ruleaza();
        float scor = evaluator.calculeaza(scoruri);
        std::cout << "Scor: " << scor << "/" << scoruri.size() << "\n";
        float procent = (scor / scoruri.size()) * 100;
        student.update(procent);
        salveazaProgresul(student.getNume(), materie, procent);
    }
    return 0;
}

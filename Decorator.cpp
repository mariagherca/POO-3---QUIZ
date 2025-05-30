#include "Decorator.h"

LectieText::LectieText(std::string t) : text(std::move(t)) {}
void LectieText::afiseaza() const {
    std::cout << text << "\n";
}
LectieCuTimer::LectieCuTimer(std::shared_ptr<ILectie> b, int timp) : baza(std::move(b)), timpLimita(timp) {}
void LectieCuTimer::afiseaza() const {
    std::cout << "[Timp maxim: " << timpLimita << " minute]\n";
    baza->afiseaza();
}

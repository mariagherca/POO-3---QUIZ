#include "Observer.h"
#include <iostream>

Student::Student(const std::string& n) : nume(n) {}
void Student::update(float progres) {
    std::cout << nume << " a progresat la " << progres << "%\n";
}
const std::string& Student::getNume() const { return nume; }

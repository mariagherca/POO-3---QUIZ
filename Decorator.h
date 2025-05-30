#pragma once
#include <iostream>
#include <memory>
#include <string>

class ILectie {
public:
    virtual void afiseaza() const = 0;
    virtual ~ILectie() = default;
};

class LectieText : public ILectie {
    std::string text;
public:
    LectieText(std::string t);
    void afiseaza() const override;
};

class LectieCuTimer : public ILectie {
    std::shared_ptr<ILectie> baza;
    int timpLimita;
public:
    LectieCuTimer(std::shared_ptr<ILectie> b, int timp);
    void afiseaza() const override;
};

#pragma once
#include <string>

class Observer {
public:
    virtual void update(float progres) = 0;
    virtual ~Observer() = default;
};

class Student : public Observer {
    std::string nume;
public:
    Student(const std::string& n);
    void update(float progres) override;
    const std::string& getNume() const;
};

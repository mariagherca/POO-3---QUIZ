#pragma once
#include <vector>

class EvaluareStrategy {
public:
    virtual float calculeaza(const std::vector<int>& raspunsuri) const = 0;
    virtual ~EvaluareStrategy() = default;
};

class EvaluarePunctaj : public EvaluareStrategy {
public:
    float calculeaza(const std::vector<int>& raspunsuri) const override;
};

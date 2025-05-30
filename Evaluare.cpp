#include "Evaluare.h"
#include <numeric>

float EvaluarePunctaj::calculeaza(const std::vector<int>& raspunsuri) const {
    return std::accumulate(raspunsuri.begin(), raspunsuri.end(), 0.0f);
}

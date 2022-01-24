#include <random>

#include "utils.h"

namespace candy
{
    int Randint(int start, int end)
    {
        static std::random_device rd;
        static std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(start, end);
        return uni(rng);
    }
}
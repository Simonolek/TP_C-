#pragma once

#include <iostream>
#include <random>
#include <ctime>


#include "utilities.h"

	

int randomint(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>
#include "Player.hpp"

using std::string;

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

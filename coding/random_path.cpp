#include <iostream>
#include <cstdlib>

std::string array[10][10];

array generate_path(struct Vector{int x; int y;} start_pos;){
    // for some reason modulus makes it stay within a range
    // srand(time(0));

    std::cout << rand() % 10 << " ";
    return([x][y]);
}
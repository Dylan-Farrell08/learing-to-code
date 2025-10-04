#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <string>
#include <thread>
#include <chrono>
#include <cmath>
#include "random_path.cpp"
#include <map>
#include <cstdlib>
struct Vector{
    int x; 
    int y;
} velocity, position, old_pos;

enum key_press{
    w = 1,
    s = 2,
    a = 3,
    d = 4
} wasd;

bool running = true;
std::string screen[10][10] = {};
int size = -1;
std::string saved_place = "@";
std::string movement;

void print_screen(){
    //just a basic loop looking at all the code
    if (_WIN32){
        std::system("cls");
    } else {
        std::system("clear");
    };
    for (int i =  0;i < size;){
        for (std::string lines: screen[i]){
            std::cout << lines;
        };
        i++;
        std::cout << "\n";
    };
}
                             
void input_handeler(std::string input){
    if (input == "q"){
        std::cout << "stopping";
        running = false;
    };
    std::map<std::string, int> wasd = {
        {"w",1},{"s",2},{"a",3},{"d",4}
    };
    switch(wasd[input]){
        case 1: velocity.x = -1; break;
        case 2: velocity.x = 1; break;
        case 3: velocity.y = -1; break;
        case 4: velocity.y = 1; break;
    
    };
}

//there has to be a better way to do this 
//i can add in basic hitbox kinda stuff later by checking what
//position+velocity is 
void move_and_slide(){
    old_pos.x = position.x;
    old_pos.y = position.y;
    position.x = position.x + velocity.x;
    position.y = position.y + velocity.y; 
    if (abs(position.x) >= size){
        position.x = old_pos.x;        
    };
    if (abs(position.y) >= size){
        position.y = old_pos.y;        
    };
    screen[old_pos.x][old_pos.y] = saved_place; 
    saved_place = screen[position.x][position.y]; 
    screen[position.x][position.y] = "&";
    
}

int main() {
    std::cout << "please enter a grid size(it must be <10)";
    bool wrong_data = true;
    while (wrong_data){
        std::cin >> size;
        if (std::cin.fail()||size > 10){
            std::cin.clear();
            //weird command that ignores every line up until a character in this case newline
            std::cin.ignore(1000, '\n');
            std::cout << "invalid type";
        } else{
            wrong_data = false;
        };
    };
    // i need to figure out how to make sure that the data type is correct 
    for (int x = 0;size > x;x++){
        for (int y = 0;size > y; y++){
            screen[x][y] = ("@");
        };
    };
    srand(time(0));
    int x_rand = rand() % size;
    int y_rand = rand() % size;
    screen[x_rand][y_rand] = "&";
    position.x = x_rand;
    position.y = y_rand;
    print_screen();
    std::cout << generate_path(position);
    while (running == true){
        std::cin.ignore(1000, '\n');
        std::cin >> movement;
        velocity.x = 0;
        velocity.y = 0;
        input_handeler(movement);
        move_and_slide();
        print_screen();
        // makes it 60fps but basically useless because of stupid blocking inputs
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    };
    return 0;
}

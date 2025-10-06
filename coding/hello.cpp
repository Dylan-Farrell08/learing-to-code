// #include <cstdio>
#include <cstdlib>
#include <iostream>
// #include <iterator>
#include <string>
#include <thread>
#include <chrono>
// #include <cmath>
#include <map>
#include <cstdlib>
struct Vector{
    int x = 0; 
    int y = 0;
} velocity, position, old_pos, map_dir, map_pos, default_vec;

enum key_press{
    w = 1,
    s = 2,
    a = 3,
    d = 4
} wasd;
//holy guacamole dead space
std::string walls = "#", player = "&", deadspace = " ", end = "F";
bool running = true;
std::string screen[10][10] = {};
int size = -1, dir = 5;
std::string saved_place = "@";
std::string movement;

void print_screen(){
    //just a basic loop looking at all the doodads in the array
    if (false){
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

//fix ts in morning X2
bool checking_ahead(){
    map_dir = default_vec;
    switch(dir){
        case 0: map_dir.x = -1; break;
        case 1: map_dir.x = 1; break;
        case 2: map_dir.y = -1; break;
        case 3: map_dir.y = 1; break;
    };
    bool fine_to_go = false;
    if ((map_pos.x + map_dir.x) >= 0 && (map_pos.x + map_dir.x) <= size-1){
        if((map_pos.y + map_dir.y) >= 0 && (map_pos.y + map_dir.y) <= size-1){
            fine_to_go = true;
        };
    };
    if ((screen[map_pos.x + map_dir.x][map_pos.y + map_dir.y] == walls) && fine_to_go){
        map_pos.x = map_pos.x + map_dir.x;
        map_pos.y = map_pos.y + map_dir.y;
        screen[map_pos.x][map_pos.y] = deadspace;
        return true;
    } else {
        return false;
    };
}

void generate_path(){
    bool generating = true;
    map_pos = position;
    int last_move = 5;
    bool keep_gen;
    while (generating == true){
        keep_gen = false;
        map_dir = default_vec;
        dir = rand() % 4;
        for (int i = -1; i <= 3; i++){
            if (checking_ahead() == true && i != last_move){
                last_move = dir;
                i=5;
                keep_gen = true;
            };
            dir = i;
        };
        if (!keep_gen){
            generating = false;
            screen[map_pos.x][map_pos.y] = end;
        };
        print_screen();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
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
    if (position.x >= 0 && position.x < size){
        position.x = old_pos.x;        
    };
    if (position.y >= 0 &&position.y < size){
        position.y = old_pos.y;        
    };
    if (screen[position.x][position.y] == walls){
        position = old_pos;
    };
    screen[old_pos.x][old_pos.y] = saved_place; 
    saved_place = screen[position.x][position.y]; 
    screen[position.x][position.y] = player;
    
}

void new_level(){
    saved_place = "@";
    for (int x = 0;size > x;x++){
        for (int y = 0;size > y; y++){
            screen[x][y] = (walls);
        };
    };
    int x_rand = rand() % size;
    int y_rand = rand() % size;
    position.x = x_rand;
    position.y = y_rand;
    generate_path();
    screen[position.x][position.y] = player;
    print_screen();
}

int main() {
    srand(time(0));
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
    new_level();
    while (running == true){
        std::cin.ignore(1000, '\n');
        std::cin >> movement;
        velocity = default_vec;
        input_handeler(movement);
        move_and_slide();
        if (saved_place == "F"){
            new_level();
        };
        print_screen();
        // makes it 60fps but basically useless because of stupid blocking inputs
        // MAKE NON BLOCKING BEFORE PUTTING OUT YOUTUBE VIDEO BECAUSE IT'LL SEEM WAY COOLER
        // NO LONGER GOING FOR NON PLATFORM SPECIFIC CJUST MAKE IT WORK
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    };
    return 0;
}

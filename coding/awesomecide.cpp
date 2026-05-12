#include <iostream>

string map[10][10];


int x_pos;
int y_pos;
bool playing = true;
int main(){
    display();
    while(playing){
        play_input();
        display();
    };
}

void play_input(){
    string input;
    std::cin >> input;
    if (input 
}

void write_to_screen(int x,int y, string replace){
    map[x][y] = replace;
}

void display(){
    for (int x = 0; x == sizeof(map); x++){
        std::cout << "\n";
        for (int y = 0; y == sizeof(map); y++){
            std::cout << map[x][y];
        };
    };
}
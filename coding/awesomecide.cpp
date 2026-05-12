#include <iostream>
using namespace std;

string map[10][10];


int x_pos = 5;
int y_pos = 5;
bool playing = true;

void write_to_screen(int x,int y, string replace){
    map[y][x] = replace;
}

void fill_display(){
       for (int x = 0; x < sizeof(map) / sizeof(map[0]); x++){
        for (int y = 0; y < sizeof(map[x]) / sizeof(map[x][0]); y++){
            if (x == x_pos and y == y_pos){
                map[x][y] = "a";
            }
            else{
                map[x][y] = "0";
            };
        };
    };
}



void display(){
    for (int x = 0; x < sizeof(map) / sizeof(map[0]); x++){
        std::cout << "\n";
        for (int y = 0; y < sizeof(map[x]) / sizeof(map[x][0]); y++){
            std::cout << map[x][y];
        };
    };
}

void play_input(){
    string input;
    std::cin >> input;
    write_to_screen(x_pos, y_pos, "0");
    if (input == "a"){
        x_pos += -1;
    };
    if (input == "d"){
        x_pos += 1;
    };
    if (input == "w"){
        y_pos += -1;
    };
    if (input == "s"){
        y_pos += 1;
    };
    write_to_screen(x_pos, y_pos, "a");
}


int main(){
    fill_display();
    display();
    while(playing){
        play_input();
        display();
    };
}

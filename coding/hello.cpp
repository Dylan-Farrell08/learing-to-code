#include <algorithm>
#include <iostream>
#include <list>
#include <string>

std::list<std::string> fruits = {"cherr", "banana", "appl", "app"};
std::string current_fruit = "null";
std::string last_fruit;
std::list<std::string> ordered_fruit = {};
std::string null = "";
std::string index_list(int index, std::list<std::string> searching){
    int i = 0;
    std::string indexed_list = "nothing";
    for (std::string part: searching){
        if (i == index){
            indexed_list = part;
        };
        i++;
    };
    return (indexed_list);
}

int main() {
    for (int number=1; number < fruits.size(); number++){
        current_fruit  = index_list(number, fruits);
        last_fruit  = index_list(number - 1, fruits);
        if (last_fruit.length() <= current_fruit.length()){
            std::rotate()
        };
        std::cout << (number) << fruits.size();
        std::cout << "\n";
        for (std::string finished_fruits : fruits){
            std::cout << finished_fruits << " ";
        };
    };
    return 0;
}

#include <iostream>
#include <list>
#include <string>

std::list<std::string> fruits = {"cherry", "banana", "apple"};
std::string current_fruit = "null";
std::string last_fruit;
std::list<std::string> ordered_fruit;
int main() {
    for (std::string fruit : fruits){ 
        if (current_fruit != "null"){
            last_fruit = current_fruit;
            if (current_fruit.length() >= last_fruit.length()){
                std::cout << "ayay";
            };
        };
        current_fruit = fruit;
        std::cout << current_fruit << " ";
    }
    std::cout << fruits.size();
    std::cout << " Hello";
    return 0;
}
#include <iostream>
#include <list>
#include <string>

std::list<std::string> fruits = {"cherry", "banana", "apple"};
std::string current_fruit = "null";
std::string last_fruit;
std::list<std::string> ordered_fruit = {};
int main() {
    for (std::string fruit : fruits){ 
        current_fruit = fruit;
        if (current_fruit != "null"){
            last_fruit = current_fruit;
            if (current_fruit.length() >= last_fruit.length()){
                ordered_fruit.push_front(current_fruit);
            };
        };
        std::cout << current_fruit << " ";
    };
    std::cout << ordered_fruit;
    std::cout << " Hello";
    return 0;
}
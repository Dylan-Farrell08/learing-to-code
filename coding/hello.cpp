#include <algorithm>
#include <iostream>
#include <list>
#include <string>

std::list<std::string> fruits = {"cherr", "banana", "appl", "app"};
std::string current_fruit = "null";
std::string last_fruit;
std::list<std::string> ordered_fruit = {};
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

std::list<std::string> change(std::string first_part, std::string second_part, std::list<std::string> current_list){
    std::replace(current_list.begin(),current_list.end(), first_part, second_part);
    std::replace(current_list.begin(),current_list.end(), first_part, second_part);
}

int main() {
    for (int number=1; number < fruits.size(); number++){
        current_fruit  = index_list(number, fruits);
        last_fruit  = index_list(number - 1, fruits);
        if (last_fruit.length() <= current_fruit.length()){
            swap(current_fruit, last_fruit);
        };
        fruits = change(last_fruit, current_fruit, fruits);
        std::cout << (number) << fruits.size();
        std::cout << "\n";
        for (std::string finished_fruits : fruits){
            std::cout << finished_fruits << " ";
        };
    };
    return 0;
}

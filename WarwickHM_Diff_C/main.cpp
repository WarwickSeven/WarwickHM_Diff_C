#include <iostream>
#include <list>

template <typename T> void printContainer(const T &cnt) {
    for (auto i : cnt) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void addMidRange(std::list<double> &lst) {
    double sum = 0;
    for (auto i : lst) {
        sum += i;
    }
    lst.push_back(sum/lst.size());
}

int main() {
    std::list<double> myList { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printContainer(myList);
    addMidRange(myList);
    printContainer(myList);
    return 0;
}

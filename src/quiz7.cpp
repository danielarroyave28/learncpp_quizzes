
#include "../include/quiz_registry.h"
#include <iostream>
#include <string>
#include "../include/quiz7.h"

namespace quiz7 {

    int accumulate(int x) {
        static int sum {0};
        sum += x;
        return sum;
    }

    void run() {
        std::cout << "How many students are in your class? ";
        int students{};
        std::cin >> students;
        if (students > quiz7::maxClassSize)
            std::cout << "There are too many students in this class";
        else
            std::cout << "This class isn't too large";
    };

    void run2() {
        std::cout << accumulate(4) << '\n'; // prints 4
        std::cout << accumulate(3) << '\n'; // prints 7
        std::cout << accumulate(2) << '\n'; // prints 9
        std::cout << accumulate(1) << '\n'; // prints 10
    }


}


namespace {
    const bool registered = []() {
        auto& reg = QuizRegistry::get();

        reg["7"] = {"Quiz 7", quiz7::run};
        reg["7.1"] = {"Quiz 7.1", quiz7::run2};

        return true;
    }();
}
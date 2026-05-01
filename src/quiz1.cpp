#include <iostream>
#include "../include/quiz1.h"
#include "../include/quiz_registry.h"
namespace quiz1 {

    int add(int a, int b) {
        return a + b;
    }

    int sub(int a, int b) {
        return a - b;
    }

    void run() {
        std::cout << "Enter an integer:\n";
        int n{};
        std::cin >> n;

        std::cout << "Enter another integer:\n";
        int v{};
        std::cin >> v;

        std::cout << "sum = " << add(n, v)
                  << "\nsub = " << sub(n, v) << '\n';
    }
}

namespace {
    const bool registered = []() {
        auto& reg = QuizRegistry::get();

        reg["1"] = {"Quiz 1 - Calculator", quiz1::run};

        return true;
    }();
}
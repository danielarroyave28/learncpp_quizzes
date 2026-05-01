#include "../include/quiz4.h"
#include "../include/quiz_registry.h"
#include <iostream>

namespace quiz4 {

    // create function that add, sub, mult, divide

    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0) {
            std::cout << "divide by zero" << std::endl;
            return 0;
        }
        return a / b;
    }

    void run() {
        std::cout << "Enter a double value:\n";
        double n{};
        std::cin >> n;

        std::cout << "Enter another double value:\n";
        double v{};
        std::cin >> v;

        std::cout << "Enter +, -, * or /" << std::endl;
        char op{};
        std::cin >> op;

        switch (op) {
            case '+':
                std::cout << add(n, v) << std::endl;
                break;
            case '-':
                std::cout << subtract(n, v) << std::endl;
                break;
            case '*':
                std::cout << multiply(n, v) << std::endl;
                break;
            case '/':
                std::cout << divide(n, v) << std::endl;
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    double distance_fallen(int seconds, double height) {
        constexpr double gravity {9.8};
        double distance {};
        distance = height - (seconds*seconds * gravity)/2;
        return distance;
    }

    void printDistance(int t, double h) {
        if (distance_fallen(t, h) < 0) {
            std::cout << "At " << t << " the ball is on the ground" << std::endl;
        } else {
            std::cout << "At " << t << " seconds, the ball is at height: " << distance_fallen(t, h) << std::endl;
        }
    }

    double getTowerHeight() {
        std::cout << "Enter the height of the tower in meters: " << std::endl;
        double height {};
        std::cin >> height;
        return height;
    }

    void run2() {

        double height { getTowerHeight() };

        for (int a = 0; a < 6; a++) {
            printDistance(a, height);
        }

    }

}

namespace {
    const bool registered = []() {
        auto& reg = QuizRegistry::get();

        reg["4.1"] = {"Quiz 4 - Calculator", quiz4::run};
        reg["4.2"] = {"Quiz 4 - Part 2", quiz4::run2};

        return true;
    }();
}
#include "../include/quiz5.h"
#include "../include/quiz_registry.h"
#include <iostream>
#include <string>

namespace quiz6 {

    std::string_view getQuantityPhrase(int a) {
        // solution using conditional operator
        return   a < 0 ? "negative" :
                    a == 0 ? "no" :
                    a == 1 ? "a single" :
                    a == 2 ? "a couple of" :
                    a == 3 ? "a few" :
                             "many";
    };

    std::string_view getApplesPluralized(int b) {
        return b == 1 ? "apple" : "apples";
    };

    void run() {

        constexpr int maryApples { 3 };
        std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

        std::cout << "How many apples do you have? ";
        int numApples{};
        std::cin >> numApples;

        std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";
    }
}

namespace {
    const bool registered = []() {
        auto& reg = QuizRegistry::get();

        reg["6"] = {"Quiz 6", quiz6::run};

        return true;
    }();
}
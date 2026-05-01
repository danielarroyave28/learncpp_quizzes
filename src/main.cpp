#include <iostream>
#include "../include/quiz_registry.h"

int main() {
    auto& quizzes = QuizRegistry::get();

    std::cout << "Available quizzes:\n";

    for (const auto& [key, entry] : quizzes) {
        std::cout << key << " -> " << entry.name << '\n';
    }

    std::string choice{};
    std::cout << "Select a quiz: ";
    std::cin >> choice;

    if (quizzes.contains(choice)) {
        quizzes[choice].func();
    } else {
        std::cout << "Invalid choice\n";
    }

    return 0;
}
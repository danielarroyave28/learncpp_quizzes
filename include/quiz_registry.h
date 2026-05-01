#ifndef QUIZ_REGISTRY_H
#define QUIZ_REGISTRY_H

#include <map>
#include <functional>
#include <string>

struct QuizEntry {
    std::string name;
    std::function<void()> func;
};

class QuizRegistry {
public:
    static std::map<std::string, QuizEntry>& get() {
        static std::map<std::string, QuizEntry> instance;
        return instance;
    }
};

#endif
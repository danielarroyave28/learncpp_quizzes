#include "../include/quiz2.h"
#include "../include/quiz_registry.h"

namespace quiz2 {
    void run() {
        // there is no quiz 2
    }
}

namespace {
    const bool registered = []() {
        auto& reg = QuizRegistry::get();

        reg["2"] = {"Quiz 2 - Empty", quiz2::run};

        return true;
    }();
}
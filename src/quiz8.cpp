#include "../include/quiz8.h"
#include "../include/random.h"

#include "../include/quiz_registry.h"
#include <iostream>
#include <cassert>

namespace quiz8 {

    double getTowerHeight()
    {
        std::cout << "Enter the height of the tower in meters: ";
        double towerHeight{};
        std::cin >> towerHeight;
        return towerHeight;
    }

    double calculateBallHeight(double towerHeight, int seconds)
    {
        //const double gravity { 9.8 };

        // Using formula: s = (u * t) + (a * t^2) / 2
        // here u (initial velocity) = 0, so (u * t) = 0
        const double fallDistance { quiz8::gravity * (seconds * seconds) / 2.0 };
        const double ballHeight { towerHeight - fallDistance };

        // If the ball would be under the ground, place it on the ground
        if (ballHeight < 0.0)
            return 0.0;

        return ballHeight;
    }

    void printBallHeight(double ballHeight, int seconds)
    {
        if (ballHeight > 0.0)
            std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
        else
            std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
    }

    double calculateAndPrintBallHeight(double towerHeight, int seconds)
    {
        const double ballHeight{ calculateBallHeight(towerHeight, seconds) };
        printBallHeight(ballHeight, seconds);
        return ballHeight;
    }

    void run() {
        const double towerHeight{ getTowerHeight() };
        int seconds {0};
        while (calculateAndPrintBallHeight(towerHeight, seconds) > 0.0) {
            ++seconds;
        }

    };

    bool isPrime(int x) {

        if (x <= 1) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;

        for (int y = 3; y * y <= x; y += 2) {
            if (x % y == 0) return false;
        }

        return true;
    }

    void run2() {
        assert(!isPrime(0)); // terminate program if isPrime(0) is true
        assert(!isPrime(1));
        assert(isPrime(2));  // terminate program if isPrime(2) is false
        assert(isPrime(3));
        assert(!isPrime(4));
        assert(isPrime(5));
        assert(isPrime(7));
        assert(!isPrime(9));
        assert(isPrime(11));
        assert(isPrime(13));
        assert(!isPrime(15));
        assert(!isPrime(16));
        assert(isPrime(17));
        assert(isPrime(19));
        assert(isPrime(97));
        assert(!isPrime(99));
        assert(isPrime(13417));

        std::cout << "Success!\n";
    }

    double generateRandomNumber(int min, int max) {
        int number { Random::get(min, max) };
        return number;
    }

    bool compare(int x, int y) {
        return x == y;
    }

    int askGuess(int tries) {
        int guess {};
        std::cout << "Guess #" << tries << ":" << std::endl;
        std::cin >> guess;
        return guess;
    };

    bool playGame(int guesses, int min, int max) {
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is" << std::endl;
        const int number { Random::get(min, max) };

        for (int count {1}; count <= guesses; ++count) {
            std::cout << "Guess #" << count << ": ";
            int guess{};
            std::cin >> guess;

            if (guess > number)
                std::cout << "Your guess is too high.\n";
            else if (guess < number)
                std::cout << "Your guess is too low.\n";
            else // guess == number, so the user won
            {
                std::cout << "Correct! You win!\n";
                return true;
            }
        }
    }

    bool playAgain()
    {
        while (true)
        {
            char ch{};
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> ch;

            switch (ch)
            {
                case 'y': return true;
                case 'n': return false;
            }
        }
    };

    void run3() {
        do {
            constexpr int max { 100 };
            constexpr int min { 1 };
            constexpr int guesses { 7 };
            playGame(guesses, min, max);
        } while (playAgain());
        std::cout << "thanks for playing";
    }
}


namespace {
    const bool registered = []() {
        auto& reg = QuizRegistry::get();

        reg["8.1"] = {"Quiz 8.1", quiz8::run};
        reg["8.2"] = {"Quiz 8.2", quiz8::run2};
        reg["8.3"] = {"Quiz 8.3", quiz8::run3};

        return true;
    }();
}
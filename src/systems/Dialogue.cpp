#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Dialogue.hpp"

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;

// Prints a message with optional wait time (seconds)
void say(int wait_seconds, const string &message) {
    cout << message << endl;
    if (wait_seconds > 0)
        std::this_thread::sleep_for(std::chrono::seconds(wait_seconds));
}

// Variadic template function for asking multiple options
template<typename... Options>

int ask(const string &prompt, Options... opts) {
    say(2, prompt);

    vector<string> options{opts...};
    for (size_t i = 0; i < options.size(); ++i) {
        say(0, std::to_string(i + 1) + ") " + options[i]);
    }

    int choice = 1;
    string line;
    if (getline(cin, line)) {
        try {
            int input = std::stoi(line);
            if (input >= 1 && input <= static_cast<int>(options.size())) choice = input;
        } catch (...) {
            choice = 1; // fallback if conversion fails
        }
    }

    return choice - 1; // return index starting from 0
}

// Clears dialogue (just prints empty lines)
void clear_dialogue() {
    cout << endl << endl;
}

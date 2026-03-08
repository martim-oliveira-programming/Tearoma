#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using std::string;


void say(int wait_seconds, const string &message);

template<typename... Options>
int ask(const string &prompt, Options... opts) {
    say(2, prompt);

    std::vector<string> options{opts...};
    for (size_t i = 0; i < options.size(); ++i) {
        say(0, std::to_string(i + 1) + ") " + options[i]);
    }

    int choice = 1;
    string line;
    if (getline(std::cin, line)) {
        try {
            int input = std::stoi(line);
            if (input >= 1 && input <= static_cast<int>(options.size())) choice = input;
        } catch (...) {
            choice = 1;
        }
    }

    return choice - 1;
}

void clear_dialogue();

#endif

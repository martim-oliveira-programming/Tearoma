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

// Clears dialogue (just prints empty lines)
void clear_dialogue() {
    cout << endl << endl;
}

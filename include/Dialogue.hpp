#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <iostream>
#include <string>

using std::string;


void say(int wait_seconds, const string &message);
template<typename... Options>
int ask(const string &prompt, Options... opts);
void clear_dialogue();

#endif

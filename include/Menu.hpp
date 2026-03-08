#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>

using std::string;

#define TEAROMA_MAX_INPUT 20

enum GameState{
    QUIT = -1,
    MENU,
    PLAYING,
};

GameState menu_selection(void);
GameState new_game(void);
GameState continue_game(void);

string get_input(string prompt);

#endif

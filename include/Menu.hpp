#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Story.hpp"
#include "Npcs.hpp"

using std::string;
using std::vector;

#define TEAROMA_MAX_INPUT 20

enum GameState{
    QUIT = -1,
    MENU,
    PLAYING,
};

GameState menu_selection(void);
GameState new_game(void);
GameState confirm_load_save(Player& player, Story& story, vector<Npc>& npcs);
void print_save_data(Player& player, Story& story);

string get_input(string prompt);
#endif

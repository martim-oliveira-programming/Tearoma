#ifndef SAVE_HPP
#define SAVE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Player.hpp"
#include "Story.hpp"

using std::string;

#define SAVE_FILE "saves/save.json"


bool file_exists(const string &filename);
bool save_game(const string &filename, Player& player, Story& story, vector<Npc>& npcs);
bool load_game(const string &filename, Player& player, Story& story, vector<Npc>& npcs);
bool delete_save(const string &filename);


#endif

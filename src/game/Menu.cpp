#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Dialogue.hpp"
#include "Menu.hpp"
#include "Save.hpp"
#include "Player.hpp"

using std::string;

string get_input(string prompt){
    string choice;

    say(0,prompt);
    getline(std::cin, choice);
    return choice;
}

GameState menu_selection(void){
    int command = ask(
        "\nNewGame: Start a new game.\n"
        "Continue: Continue from last save\n"
        //"Commands: Show the game's commands\n"
        //"Options: Open the options menu\n"
        "QuitGame: Leave the game\n\n", "NewGame", "Continue", "QuitGame");

    switch(command){
        case 0:{
            return new_game();
        }
        case 1:{
            return PLAYING;
        }
        case 2:{
            return QUIT;
        }
        default:{
            say(1,"Invalid choice.\n");
            return menu_selection();
        }    
    }
}

GameState new_game(void){
    if(file_exists(SAVE_FILE)){
        int choice = ask(
            "A save file already exists. Do you want to overwrite it?", "Yes", "No");
        if (choice == 0){
            delete_save(SAVE_FILE);
            say(1, "Starting a new game...");
            return PLAYING;
        } else if (choice == 1){
            return MENU;
        }
        else{
            say(1,"Invalid choice.\n");
            return new_game();
        }
    }else{
        say(1, "Starting a new game...");
        return PLAYING;
    }
}

GameState confirm_load_save(Player& player, Story& story, vector<Npc>& npcs){
    print_save_data(player, story);
    int choice = ask(
        "This file already exists. Do you want to load it?", "Yes", "No");
        
        if (choice == 0){
        bool loaded = load_game(SAVE_FILE, player, story, npcs);

        if (!loaded) {
            say(1, "Failed to load save file. Returning to main menu...");
            return MENU;
        } else {
            say(1, "Save file loaded successfully. Continuing your adventure...");
            print_save_data(player, story);
        }
        return PLAYING;
    } else if (choice == 1){
        return MENU;
    }
    else{
        say(1,"Invalid choice.\n");
        return confirm_load_save(player, story, npcs);
    }
}

void print_save_data(Player& player, Story& story){
    say(1, "Name: " + player.get_name());
    say(0, "Chapter: " + std::to_string(story.get_chapter()));
}

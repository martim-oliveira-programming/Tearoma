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
    std::cin >> choice;
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

GameState continue_game(void){
    //TODO
    return MENU;
}

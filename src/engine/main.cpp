#include <iostream>
#include <string>
#include <time.h>
#include "Dialogue.hpp"
#include "Menu.hpp"
#include "Save.hpp"
#include "Player.hpp"
#include "Story.hpp"
#include "Npcs.hpp"
using std::string;

#define SAVE_FILE "save.json"

int main(void){
    srand(time(NULL)); // Seed the random number generator with the current time
    GameState state = MENU;
    vector<Npc> npcs;

    while(state != QUIT){
        switch(state){

            case MENU:{
                say(0,"\nWelcome to Tearoma Adventures what whould you like to do?\n");
                state = menu_selection();
                break;
            }
            case PLAYING:{
                if(!file_exists(SAVE_FILE)){
                    Player player = create_player();
                    Story story = Story(Prologue, vector<Story_Events>(), Initial);
                    save_game(SAVE_FILE, player, story, npcs);
                }



                break;
            }
        }
    }
}

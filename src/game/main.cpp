#include <iostream>
#include <string>
#include <time.h>
#include <optional>
#include "Dialogue.hpp"
#include "Menu.hpp"
#include "Save.hpp"
#include "Player.hpp"
#include "Story.hpp"
#include "Npcs.hpp"
using std::string;


int main(void){
    srand(time(NULL)); // Seed the random number generator with the current time
    GameState state = MENU;
    std::optional<Player> player;
    std::optional<Story> story;
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
                    player = create_player();
                    story = Story(Prologue, vector<Story_Events>(), Initial);
                    save_game(SAVE_FILE, *player, *story, npcs);
                }
                else{
                    // Create a placeholder player to load save data into
                    player = Player("", "", Boy);
                    story = Story(Prologue, vector<Story_Events>(), Initial);

                    bool loaded = load_game(SAVE_FILE, *player, *story, npcs);

                    if (!loaded) {
                        say(1, "Failed to load save file. Starting a new game...");
                        player = create_player();
                        story = Story(Prologue, vector<Story_Events>(), Initial);
                        save_game(SAVE_FILE, *player, *story, npcs);

                    } else {
                        say(1, "Save file loaded successfully. Continuing your adventure...");
                    }
                    state = confirm_load_save(*player, *story, npcs);
                    if (state == MENU) {
                        player.reset();
                        story.reset();
                        npcs.clear();
                    }
                    else {
                        say(0, "Story Chapter: " + std::to_string(story->get_chapter()));
                        say(0, "Starting game...");
                        story->play_chapter(*player, npcs);

                    }
                }



                break;
            }
            case QUIT:
                break;
        }
    }
}

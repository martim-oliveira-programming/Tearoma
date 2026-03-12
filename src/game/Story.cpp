#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Player.hpp"
#include "Story.hpp"
#include "Npcs.hpp"
#include "Dialogue.hpp"

using std::string;
using std::vector;


Story::Story(Story_Progression chapter, vector<Story_Events> events_occurred, Path_Choice path)
: chapter(chapter), events_occurred(events_occurred), path(path)
{
}

void Story::advance_chapter(){
        if(chapter != Epilogue){
            chapter = static_cast<Story_Progression>(static_cast<int>(chapter) + 1);
        }
    };

void Story::play_chapter(Player& player, vector<Npc>& npcs){
    switch(this->get_chapter()){
        case Prologue:{
            
            break;
        }
        case Chapter1:{
            say(0, "Chapter 1: The First Step");
            break;
        }

}
}

void Story::chapter1(Player& player, Story story,vector<Npc>& npcs){
    say(0, "Prologue: The Beginning of the End");
}

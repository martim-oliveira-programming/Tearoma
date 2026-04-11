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
            this->chapter1(player, *this);
            break;
        }
        case TheAcademy:{
            say(0, "Chapter2: The Academy");
            say(0,"IN DEVELOPMENT");
            break;
        }

}
}

void Story::chapter1(Player& player,Story story){
    string name = player.get_name();
    say(1, "Chapter1: Prologue");
    say(5,"It's a bright morning in the Tearoma Region. Everyone in Pinewood Town is still sleeping.\n");
    say(5,"The birds sing as the sun rises, just like any other day. Except it isn't just another day, at least not for" + name + ", who is starting the Academy today.\n");
    say(7,"The Tearoma Region is vast and diverse, filled with landscapes that range from frozen peaks to untamed wilderness.\nIt is also home to many creatures—some so rare and mysterious that, where we come from, they exist only in myths and old stories.\n");
    say(5,"The region is divided in three areas:\n");
    say(5,"The Frozen Mountains - Controlled by the Wolves of the North, a guild that focuses on protecting the region.\n");
    say(5,"Amestria - The part of the region where the capital, Shomei, is located. This is the heart of Tearoma, where the economy is at its strongest.\nThree clans dominate this area: the Raven, the Silver, and the Ferrari.\n");
    say(5,"The Wilds - The least technologically advanced subregion of Tearoma, filled with villages, farms, mines, and untamed land.\n");
    say(4,name +" doesn't know it yet, but he is about to take the first step into an entirely new world!\n");
    say(5,name +" wakes up. The clock says 07:03. He gets up and gets ready calmly as the classes start at 8:30 but he couldn't sleep with the excitement.\n???: Hey Lucas, come down for breakfast!!!\n");
    say(5,name +": Ok Mom I'm going! - I am finally starting training in the Academy;\nI'm going to be the best Knight of all time and then I can serve as one of the 10 Golden Swords with my Dad!\n");
    say(4,"Thomas Orizon, the first person from The Wilds to be honored by the King with the highest honor a Knight can receive, becoming one of the ten protectors of the King himself.\n");
    say(5,"Mom: What are thinking about? You seem apprehensive.\n"+ name +": Oh, nothing just really excited to get started on the Academy; The pancakes are great Mom thanks!\n");
    say(5,"Mom: Of course! Now finish getting ready so you won't be late!\n" + name + ": Isn't Dad coming to the Welcome ceremony?\n");
    say(5,"Mom: Sorry sweetie there was an important mission, so he won't be able to come.\n" + name + ": Really? And they couldn't send someone else? That sucks!\n");
    say(5,"Mom: I know. Come on let's go.\n" + name + ": All right! here I come!!\n");
    this->advance_chapter();
}

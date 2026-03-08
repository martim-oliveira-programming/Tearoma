#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Player.hpp"
#include "Story.hpp"

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

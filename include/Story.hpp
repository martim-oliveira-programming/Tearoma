#ifndef STORY_HPP
#define STORY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using std::string;
using std::vector;

enum Story_Progression { Prologue, Chapter1, Chapter2, Chapter3, Chapter4, Chapter5, Epilogue };

enum Story_Events { None, Event1, Event2, Event3, Event4, Event5 };//TODO: Change to actual events

enum Path_Choice {Initial, Dad, Mom};

class Story
{
private:
    Story_Progression chapter;
    vector<Story_Events> events_occurred;
    Path_Choice path;
public:
    Story() = default;
    Story(Story_Progression chapter, vector<Story_Events> events_occurred, Path_Choice path);
    ~Story() = default;
    //
    void advance_chapter();
    // Getters
    Story_Progression get_chapter() { return chapter; }
    vector<Story_Events> get_events_occurred() { return events_occurred; }
    Path_Choice get_path() { return path; }
    // Setters
    void set_chapter(Story_Progression new_chapter) { chapter = new_chapter; }
    void set_events_occurred(vector<Story_Events> new_events_occurred) { events_occurred = new_events_occurred; }
    void set_path(Path_Choice new_path) { path = new_path; }
};



#endif

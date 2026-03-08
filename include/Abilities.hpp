#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using std::string;
using std::vector;

class Ability
{
private:
    const int id;
    const string name;
    const string description;
    Rank rank;
    int damage;
    int mana_cost;
    const Elemental_Affinity affinity;
    const DNA dna_requirement;
    int turns_remaining_cooldown;
    vector<int> effect;
    const EFFECT_TYPE effect_type;
public:
    Ability(int id, string name, string description, Rank rank, int damage, int mana_cost, Elemental_Affinity affinity, DNA dna_requirement, int turns_remaining_cooldown, vector<int> effect, EFFECT_TYPE effect_type);
    ~Ability() = default;
    // Getters
    int get_id() { return id; }
    string get_name() { return name; }
};

enum DNA {
    All, // Can be learned by any other characters
    Inate, // Unique to the character no one else can learn it
    Zenin, // Only learned by Minamoto Clan members (Shadow Dog)
    Sharingan, // Only learned by Sharingan users 
    MS_1,//(Amaterasu)
    MS_2,//(Tsukuyomi)
};

enum Elemental_Affinity{
    BASE,
    FIRE,
    WATER,
    EARTH,
    AIR,
    ELECTIC,
    ICE,
    LAVA,
    STORM,
    LIGHT,
    DARK,
    ELEMENTAL_AFFINITY_COUNT, // Keep this as the last element to track the count of affinities
};

enum EFFECT_TYPE{
    NONE,
    BOOST,
    SUMMON,
    GROUP,
    PLUS,
    HEAL,
    COPY, 
    REVEAL,
    POISON,
    BURN,
    FREEZE,
    PARALYSE,
};

enum Rank{
    E,
    D,
    C,
    B,
    A,
    S,
};



#endif

#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using std::string;
using std::vector;

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
    string get_description() { return description; }
    Rank get_rank() { return rank; }
    int get_damage() { return damage; }
    int get_mana_cost() { return mana_cost; }
    Elemental_Affinity get_affinity() { return affinity; }
    DNA get_dna_requirement() { return dna_requirement; }
    int get_turns_remaining_cooldown() { return turns_remaining_cooldown; }
    vector<int> get_effect() { return effect; }
    EFFECT_TYPE get_effect_type() { return effect_type; }
    // Setters
    void set_rank(Rank new_rank) { rank = new_rank; }
    void set_damage(int new_damage) { damage = new_damage; }
    void set_mana_cost(int new_mana_cost) { mana_cost = new_mana_cost; }
    void set_turns_remaining_cooldown(int new_cooldown) { turns_remaining_cooldown = new_cooldown; }
};


#endif

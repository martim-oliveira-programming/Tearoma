#ifndef NPCS_HPP
#define NPCS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include "Abilities.hpp"

using std::string;
using std::vector;
using std::unique_ptr;

class Summon;

struct Stats
{
    int max_hp;
    int max_mana;
    int attack;
    int magic_attack;
    int weapon_attack;
    int defense;
    int magic_defense;
    int weapon_defense;
    int speed;
    int stealth;
    int preception;
    bool weapon_user;
    bool dual_wield;
    bool magic_user;
    int summon_capacity;
};

class Npc
{
protected:
    const int id;
    const string name;
    int age;
    vector<unique_ptr<Ability>> abilities;
    vector<unique_ptr<Summon>> summons;
    vector<Elemental_Affinity> mana_elements;
    Rank rank;
    int level;
    int exp_reward;
    int hp;
    int mana;
    Stats stats;

public:
    Npc(int id, string name, int age, vector<unique_ptr<Ability>> abilities, vector<unique_ptr<Summon>> summons, vector<Elemental_Affinity> mana_elements, Rank rank, int level, int exp_reward, int hp, int mana, int max_hp, int max_mana, int attack, int magic_attack, int weapon_attack, int defense, int magic_defense, int weapon_defense, int speed, int stealth, int preception, bool weapon_user, bool dual_wield, bool magic_user, int summon_capacity);
    virtual ~Npc() = default;
    
    // Getters
    int get_id() { return id; }
    string get_name() { return name; }
    int get_age() { return age; }
    const vector<unique_ptr<Ability>>& get_abilities() { return abilities; }
    const vector<unique_ptr<Summon>>& get_summons() { return summons; }
    vector<Elemental_Affinity> get_mana_elements() { return mana_elements; }
    Rank get_rank() { return rank; }
    int get_level() { return level; }
    int get_exp_reward() { return exp_reward; }
    int get_hp() { return hp; }
    int get_mana() { return mana; }
    Stats get_stats() { return stats; }
    
    // Setters
    void set_age(int new_age) { age = new_age; }
    void set_abilities(vector<unique_ptr<Ability>> new_abilities) { abilities = std::move(new_abilities); }
    void set_summons(vector<unique_ptr<Summon>> new_summons) { summons = std::move(new_summons); }
    void set_mana_elements(vector<Elemental_Affinity> new_mana_elements) { mana_elements = new_mana_elements; }
    void set_rank(Rank new_rank) { rank = new_rank; }
    void set_level(int new_level) { level = new_level; }
    void set_exp_reward(int new_exp_reward) { exp_reward = new_exp_reward; }
    void set_hp(int new_hp) { hp = new_hp; }
    void set_mana(int new_mana) { mana = new_mana; }
    void set_stats(Stats new_stats) { stats = new_stats; }
};

class Summon: public Npc
{
private:
    int bond_level;

public:
    Summon(int id, string name, int age, vector<unique_ptr<Ability>> abilities, vector<unique_ptr<Summon>> summons, vector<Elemental_Affinity> mana_elements, Rank rank, int level, int exp_reward, int hp, int mana, int max_hp, int max_mana, int attack, int magic_attack, int weapon_attack, int defense, int magic_defense, int weapon_defense, int speed, int stealth, int preception, bool weapon_user, bool dual_wield, bool magic_user, int summon_capacity, int bond_level);
    ~Summon()override = default;
    int get_bond_level() { return bond_level; }

};




#endif

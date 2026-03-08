#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unordered_set>
#include "Abilities.hpp"
#include "Items.hpp"
#include "Npcs.hpp"

using std::string;
using std::vector;
using std::unordered_set;

class Player
{
private:
    const string name;
    string hair_color;
    int age;
    const Gender gender;
    int money;
    int goodness;
    Builds build;
    Rank rank;
    int hunger;
    int level;
    int exp;
    int hp;
    int mana;
    int skill_points;
    bool heavenly_restriction;
    //
    vector<unique_ptr<Summon>> summons;
    vector<unique_ptr<Ability>> abilities;
    vector<unique_ptr<Item>> inventory_items;
    unordered_set<int> aquired_items;
    vector<Elemental_Affinity> mana_elements;
    vector<DNA> dna;
    //
    unique_ptr<Armour> armour_slots[4];
    unique_ptr<Weapon> weapon_slots[2];
    Stats stats;
    //
    vector<unique_ptr<Npc>> party_members;


public:
    Player(string name, string hair, Gender gender);
    ~Player() = default;
    Player(Player&& other) = default;
    Player& operator=(Player&& other) = default;
    //
    void player_will_be_heavenly_restricted();
    // Getters
    string get_name() { return name; }
    string get_hair_color() { return hair_color; }
    int get_age() { return age; }
    bool get_gender() { return gender; }
    int get_money() { return money; }
    int get_goodness() { return goodness; }
    Builds get_build() { return build; }
    Rank get_rank() { return rank; }
    int get_hunger() { return hunger; }
    int get_level() { return level; }
    int get_exp() { return exp; }
    int get_hp() { return hp; }
    int get_mana() { return mana; }
    int get_skill_points() { return skill_points; }
    bool get_heavenly_restriction() { return heavenly_restriction; }
    const vector<unique_ptr<Summon>>& get_summons() { return summons; }
    const vector<unique_ptr<Ability>>& get_abilities() { return abilities; }
    const vector<unique_ptr<Item>>& get_inventory_items() { return inventory_items; }
    const unordered_set<int>& get_aquired_items() { return aquired_items; }
    const vector<Elemental_Affinity>& get_mana_elements() { return mana_elements; }
    const vector<DNA>& get_dna() { return dna; }
    const vector<unique_ptr<Npc>>& get_party_members() { return party_members; }
    unique_ptr<Armour> get_armour_slot(int slot) { return move(armour_slots[slot]); }
    unique_ptr<Weapon> get_weapon_slot(int slot) { return move(weapon_slots[slot]); }
    const unique_ptr<Armour>& get_armour_slot_ref(int slot) { return armour_slots[slot]; }
    const unique_ptr<Weapon>& get_weapon_slot_ref(int slot) { return weapon_slots[slot]; }
    Stats get_stats() { return stats; }
    // Setters
    void set_hair_color(string new_hair_color) { hair_color = new_hair_color; }
    void set_age(int new_age) { age = new_age; }
    void set_money(int new_money) { money = new_money; }
    void set_goodness(int new_goodness) { goodness = new_goodness; }
    void set_build(Builds new_build) { build = new_build; }
    void set_rank(Rank new_rank) { rank = new_rank; }
    void set_hunger(int new_hunger) { hunger = new_hunger; }
    void set_level(int new_level) { level = new_level; }
    void set_exp(int new_exp) { exp = new_exp; }
    void set_hp(int new_hp) { hp = new_hp; }
    void set_mana(int new_mana) { mana = new_mana; }
    void set_skill_points(int new_skill_points) { skill_points = new_skill_points; }
    void set_heavenly_restriction(bool new_heavenly_restriction) { heavenly_restriction = new_heavenly_restriction; }
    void set_summons(vector<unique_ptr<Summon>> new_summons) { summons = new_summons; }
    void set_abilities(vector<unique_ptr<Ability>> new_abilities) { abilities = new_abilities; }
    void set_inventory_items(vector<unique_ptr<Item>> new_inventory_items) { inventory_items = new_inventory_items; }
    void set_aquired_items(unordered_set<int> new_aquired_items) { aquired_items = new_aquired_items; }
    void set_mana_elements(vector<Elemental_Affinity> new_mana_elements) { mana_elements = new_mana_elements; }
    void set_dna(vector<DNA> new_dna) { dna = new_dna; }
    void set_party_members(vector<unique_ptr<Npc>> new_party_members) { party_members = new_party_members; }
    void set_armour_slot(int slot, unique_ptr<Armour> new_armour) { armour_slots[slot] = move(new_armour); }
    void set_weapon_slot(int slot, unique_ptr<Weapon> new_weapon) { weapon_slots[slot] = move(new_weapon); }
    void set_stats(Stats new_stats) { stats = new_stats; }
};

enum Builds{
    Knight,
    Tank,
    Archer,
    Mage,
    Healer,
    Summoner,
    Assassin,
    Heavenly_Restricted,
    Ninja,
    Balanced,
};

enum Gender{ Boy , Girl };

Player create_player();

#endif

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Player.hpp"
#include "Utils.hpp"
#include "Menu.hpp"
#include "Dialogue.hpp"


using std::string;
using std::vector;


Player::Player(string name, string hair_color, Gender gender)
: name(name), hair_color(hair_color), gender(gender)
{   
    this->hunger = 0;
    this->money = 30;
    this->age = 15;
    this->goodness = 0;
    this->rank = E;
    this->level = 1;
    this->exp = 0;
    this->heavenly_restriction = false;
    this->party_members = vector<unique_ptr<Npc>>();
    this->summons = vector<unique_ptr<Summon>>();
    this->abilities = vector<unique_ptr<Ability>>();
    this->inventory_items = vector<unique_ptr<Item>>();
    this->aquired_items = unordered_set<int>();
    this->hp = stats.max_hp;
    this->mana = stats.max_mana;
    this->skill_points = 0;
    this->mana_elements = vector<Elemental_Affinity>() = {BASE};
    this->dna = vector<DNA>() = {All};
    this->build = Balanced;
    this->stats = Stats{100, 50, 10, 5, 0, 5, 0, 0, 5, 5, 5, true, false, true, 1};
    //Stats{max_hp, max_mana, attack, magic_attack, weapon_attack, defense, magic_defense, weapon_defense, speed, stealth, preception, weapon_user, dual_wield, magic_user, summon_capacity}
    this->player_will_be_heavenly_restricted();
    this->armour_slots[0] = nullptr;
    this->armour_slots[1] = nullptr;
    this->armour_slots[2] = nullptr;
    this->armour_slots[3] = nullptr;
    this->weapon_slots[0] = nullptr;
    this->weapon_slots[1] = nullptr;
}

void Player::player_will_be_heavenly_restricted() {
    int random_number = get_random_number(1, 100);
    if(random_number == 1){
        this->set_heavenly_restriction(true);
        this->set_build(Heavenly_Restricted);
    }
}

Player create_player(){
    string name = get_input("What is your name?\n");
    string hair_color = get_input("What is your hair color?\n");
    Gender gender = static_cast<Gender>(ask("What is your gender?", "Boy", "Girl"));
    return Player(name, hair_color, gender);
}

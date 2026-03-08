#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Story.hpp"

using std::string;
using std::vector;


enum Slot { Head, Chest, Legs, Boots };
enum Weapon_Slot { Main_Hand, Off_Hand , Both_Hands};

class Item
{
private:
    const string name;
    const string description;
    int price;
    const int id;

    public:
    Item(string name, string description, int price, int id);
    ~Item() = default;
    // Getters
    string get_name(){return name; }
    string get_description() { return description; }
    int get_price() { return price; }
    int get_id() { return id; }
    //Setters
    void set_price(int new_price) { price = new_price; }



};

class Weapon : public Item
{
private:
    int attack_bonus;
    int magic_attack_bonus;
    int weapon_attack_bonus;
    int defense_bonus;
    int magic_defense_bonus;
    int weapon_defense_bonus;
    int speed_bonus;
    Weapon_Slot slot;

public:
    Weapon(string name, string description, int price, int id, int attack_bonus, int magic_attack_bonus, int weapon_attack_bonus, int defense_bonus, int magic_defense_bonus, int weapon_defense_bonus, int speed_bonus, Weapon_Slot slot);
    ~Weapon() = default;
    // Getters
    int get_attack_bonus() { return attack_bonus; }
    int get_magic_attack_bonus() { return magic_attack_bonus; }
    int get_weapon_attack_bonus() { return weapon_attack_bonus; }
    int get_defense_bonus() { return defense_bonus; }
    int get_magic_defense_bonus() { return magic_defense_bonus; }
    int get_weapon_defense_bonus() { return weapon_defense_bonus; }
    int get_speed_bonus() { return speed_bonus; }
    Weapon_Slot get_slot() { return slot; }
    // Setters
    void set_attack_bonus(int new_attack_bonus) { attack_bonus = new_attack_bonus; }
    void set_magic_attack_bonus(int new_magic_attack_bonus) { magic_attack_bonus = new_magic_attack_bonus; }
    void set_weapon_attack_bonus(int new_weapon_attack_bonus) { weapon_attack_bonus = new_weapon_attack_bonus; }
    void set_defense_bonus(int new_defense_bonus) { defense_bonus = new_defense_bonus; }
    void set_magic_defense_bonus(int new_magic_defense_bonus) { magic_defense_bonus = new_magic_defense_bonus; }
    void set_weapon_defense_bonus(int new_weapon_defense_bonus) { weapon_defense_bonus = new_weapon_defense_bonus; }
    void set_speed_bonus(int new_speed_bonus) { speed_bonus = new_speed_bonus; }
    void set_slot(Weapon_Slot new_slot) { slot = new_slot; }
};


class Armour : public Item
{
private:
    int defense_bonus;
    int magic_defense_bonus;
    int weapon_defense_bonus;
    int speed_bonus;
    int stealth_bonus;
    Slot slot;

public:
    Armour(string name, string description, int price, int id, int defense_bonus, int magic_defense_bonus, int weapon_defense_bonus, int speed_bonus, int stealth_bonus, Slot slot);
    ~Armour() = default;
    // Getters
    int get_defense_bonus() { return defense_bonus; }
    int get_magic_defense_bonus() { return magic_defense_bonus; }
    int get_weapon_defense_bonus() { return weapon_defense_bonus; }
    int get_speed_bonus() { return speed_bonus; }
    int get_stealth_bonus() { return stealth_bonus; }
    Slot get_slot() { return slot; }
    // Setters
    void set_defense_bonus(int new_defense_bonus) { defense_bonus = new_defense_bonus; }
    void set_magic_defense_bonus(int new_magic_defense_bonus) { magic_defense_bonus = new_magic_defense_bonus; }
    void set_weapon_defense_bonus(int new_weapon_defense_bonus) { weapon_defense_bonus = new_weapon_defense_bonus; }
    void set_speed_bonus(int new_speed_bonus) { speed_bonus = new_speed_bonus; }
    void set_stealth_bonus(int new_stealth_bonus) { stealth_bonus = new_stealth_bonus; }

};

class Consumable : public Item
{
private:
    int heal_amount;
    int mana_restore_amount;
    int hunger_restore_amount;

public:
    Consumable(string name, string description, int price, int id, int heal_amount, int mana_restore_amount, int hunger_restore_amount);
    ~Consumable() = default;
    // Getters
    int get_heal_amount() { return heal_amount; }
    int get_mana_restore_amount() { return mana_restore_amount; }
    int get_hunger_restore_amount() { return hunger_restore_amount; }
    // Setters
    void set_heal_amount(int new_heal_amount) { heal_amount = new_heal_amount; }
    void set_mana_restore_amount(int new_mana_restore_amount) { mana_restore_amount = new_mana_restore_amount; }
    void set_hunger_restore_amount(int new_hunger_restore_amount) { hunger_restore_amount = new_hunger_restore_amount; }
};

class KeyItem : public Item
{
private:
    const Story_Events use_event;

public:
    KeyItem(string name, string description, int id, Story_Events use_event);
    ~KeyItem() = default;
    // Getters
    Story_Events get_use_event() { return use_event; }
};


#endif

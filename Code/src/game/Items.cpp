#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

#include "Player.hpp"
#include "Items.hpp"

using std::string;
using std::vector;

Item::Item(string name, string description, int price, int id) 
: name(name), description(description), price(price), id(id)
{
}

Weapon::Weapon(string name, string description, int price, int id, int attack_bonus, int magic_attack_bonus, int weapon_attack_bonus,int defense_bonus, int magic_defense_bonus, int weapon_defense_bonus, int speed_bonus, Weapon_Slot slot)
: Item(name, description, price, id), attack_bonus(attack_bonus), magic_attack_bonus(magic_attack_bonus), weapon_attack_bonus(weapon_attack_bonus), defense_bonus(defense_bonus), magic_defense_bonus(magic_defense_bonus), weapon_defense_bonus(weapon_defense_bonus), speed_bonus(speed_bonus), slot(slot)
{
}

Armour::Armour(string name, string description, int price, int id, int defense_bonus, int magic_defense_bonus, int weapon_defense_bonus, int speed_bonus, int stealth_bonus, Slot slot)
: Item(name, description, price, id), defense_bonus(defense_bonus), magic_defense_bonus(magic_defense_bonus), weapon_defense_bonus(weapon_defense_bonus), speed_bonus(speed_bonus), stealth_bonus(stealth_bonus), slot(slot)
{
}

Consumable::Consumable(string name, string description, int price, int id, int hp_restore, int mana_restore, int hunger_restore)
: Item(name, description, price, id), heal_amount(hp_restore), mana_restore_amount(mana_restore), hunger_restore_amount(hunger_restore)
{
}

KeyItem::KeyItem(string name, string description, int id, Story_Events use_event)
: Item(name, description, 0, id), use_event(use_event)
{
}

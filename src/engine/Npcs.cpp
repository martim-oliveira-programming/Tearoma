#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Npcs.hpp"

using std::string;
using std::vector;

Npc::Npc(int id, string name, int age, vector<unique_ptr<Ability>> abilities, vector<unique_ptr<Summon>> summons, vector<Elemental_Affinity> mana_elements, Rank rank, int level, int exp_reward, int hp, int mana, int max_hp, int max_mana, int attack, int magic_attack, int weapon_attack, int defense, int magic_defense, int weapon_defense, int speed, int stealth, int preception, bool weapon_user, bool dual_wield, bool magic_user, int summon_capacity)
: id(id), name(name), age(age), abilities(std::move(abilities)), summons(std::move(summons)), mana_elements(mana_elements), rank(rank), level(level), exp_reward(exp_reward), hp(hp), mana(mana), stats({max_hp, max_mana, attack, magic_attack, weapon_attack, defense, magic_defense, weapon_defense, speed, stealth, preception, weapon_user, dual_wield, magic_user, summon_capacity})
{
}

Summon::Summon(int id, string name, int age, vector<unique_ptr<Ability>> abilities, vector<unique_ptr<Summon>> summons, vector<Elemental_Affinity> mana_elements, Rank rank, int level, int exp_reward, int hp, int mana, int max_hp, int max_mana, int attack, int magic_attack, int weapon_attack, int defense, int magic_defense, int weapon_defense, int speed, int stealth, int preception, bool weapon_user, bool dual_wield, bool magic_user, int summon_capacity, int bond_level)
: Npc(id, name, age, std::move(abilities), std::move(summons), mana_elements, rank, level, exp_reward, hp, mana, max_hp, max_mana, attack, magic_attack, weapon_attack, defense, magic_defense, weapon_defense, speed, stealth, preception, weapon_user, dual_wield, magic_user, summon_capacity), bond_level(bond_level)
{
}


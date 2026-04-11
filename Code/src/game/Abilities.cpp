#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Player.hpp"

using std::string;
using std::vector;

Ability::Ability(int id, string name, string description, Rank rank, int damage, int mana_cost, Elemental_Affinity affinity, DNA dna_requirement, int turns_remaining_cooldown, vector<int> effect, EFFECT_TYPE effect_type)
: id(id), name(name), description(description), rank(rank), damage(damage), mana_cost(mana_cost), affinity(affinity), dna_requirement(dna_requirement), turns_remaining_cooldown(turns_remaining_cooldown), effect(effect), effect_type(effect_type)
{
}


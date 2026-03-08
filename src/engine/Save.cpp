#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include "Save.hpp"
#include "../../json-develop/single_include/nlohmann/json.hpp"

using std::string;
using std::ifstream;
using std::ofstream;
using json = nlohmann::json;


bool file_exists(const string &filename) {
    return std::filesystem::exists(filename);
}

// ── Serialization helpers ──

json stats_to_json(const Stats& s) {
    return {
        {"max_hp", s.max_hp}, {"max_mana", s.max_mana},
        {"attack", s.attack}, {"magic_attack", s.magic_attack},
        {"weapon_attack", s.weapon_attack}, {"defense", s.defense},
        {"magic_defense", s.magic_defense}, {"weapon_defense", s.weapon_defense},
        {"speed", s.speed}, {"stealth", s.stealth}, {"preception", s.preception},
        {"weapon_user", s.weapon_user}, {"dual_wield", s.dual_wield},
        {"magic_user", s.magic_user}, {"summon_capacity", s.summon_capacity}
    };
}

Stats json_to_stats(const json& j) {
    return Stats{
        j["max_hp"], j["max_mana"], j["attack"], j["magic_attack"],
        j["weapon_attack"], j["defense"], j["magic_defense"], j["weapon_defense"],
        j["speed"], j["stealth"], j["preception"],
        j["weapon_user"], j["dual_wield"], j["magic_user"], j["summon_capacity"]
    };
}

json player_to_json(Player& player) {
    json j;
    // Scalar fields
    j["name"]                 = player.get_name();
    j["hair_color"]           = player.get_hair_color();
    j["age"]                  = player.get_age();
    j["gender"]               = static_cast<int>(player.get_gender());
    j["money"]                = player.get_money();
    j["goodness"]             = player.get_goodness();
    j["build"]                = static_cast<int>(player.get_build());
    j["rank"]                 = static_cast<int>(player.get_rank());
    j["hunger"]               = player.get_hunger();
    j["level"]                = player.get_level();
    j["exp"]                  = player.get_exp();
    j["hp"]                   = player.get_hp();
    j["mana"]                 = player.get_mana();
    j["skill_points"]         = player.get_skill_points();
    j["heavenly_restriction"] = player.get_heavenly_restriction();
    j["stats"]                = stats_to_json(player.get_stats());

    // Abilities & items by ID
    json ability_ids = json::array();
    for (const auto& a : player.get_abilities())
        ability_ids.push_back(a->get_id());
    j["ability_ids"] = ability_ids;

    json item_ids = json::array();
    for (const auto& item : player.get_inventory_items())
        item_ids.push_back(item->get_id());
    j["inventory_item_ids"] = item_ids;

    json aquired = json::array();
    for (int id : player.get_aquired_items())
        aquired.push_back(id);
    j["aquired_items"] = aquired;

    // Summons & party by ID
    json summon_ids = json::array();
    for (const auto& s : player.get_summons())
        summon_ids.push_back(s->get_id());
    j["summon_ids"] = summon_ids;

    json party_ids = json::array();
    for (const auto& npc : player.get_party_members())
        party_ids.push_back(npc->get_id());
    j["party_member_ids"] = party_ids;

    // Enums as ints
    json elements = json::array();
    for (const auto& e : player.get_mana_elements())
        elements.push_back(static_cast<int>(e));
    j["mana_elements"] = elements;

    json dna_arr = json::array();
    for (const auto& d : player.get_dna())
        dna_arr.push_back(static_cast<int>(d));
    j["dna"] = dna_arr;

    // Armour & weapon slots by ID (-1 if empty)
    json armour = json::array();
    for (int i = 0; i < 4; i++) {
        const auto& slot = player.get_armour_slot_ref(i);
        armour.push_back(slot ? slot->get_id() : -1);
    }
    j["armour_slot_ids"] = armour;

    json weapons = json::array();
    for (int i = 0; i < 2; i++) {
        const auto& slot = player.get_weapon_slot_ref(i);
        weapons.push_back(slot ? slot->get_id() : -1);
    }
    j["weapon_slot_ids"] = weapons;

    return j;
}

json story_to_json(Story& story) {
    json j;
    j["chapter"] = static_cast<int>(story.get_chapter());
    j["path"]    = static_cast<int>(story.get_path());

    json events = json::array();
    for (const auto& e : story.get_events_occurred())
        events.push_back(static_cast<int>(e));
    j["events_occurred"] = events;

    return j;
}

json npc_to_json(Npc& npc) {
    json j;
    j["id"]         = npc.get_id();
    j["name"]       = npc.get_name();
    j["age"]        = npc.get_age();
    j["rank"]       = static_cast<int>(npc.get_rank());
    j["level"]      = npc.get_level();
    j["exp_reward"] = npc.get_exp_reward();
    j["hp"]         = npc.get_hp();
    j["mana"]       = npc.get_mana();
    j["stats"]      = stats_to_json(npc.get_stats());

    json ability_ids = json::array();
    for (const auto& a : npc.get_abilities())
        ability_ids.push_back(a->get_id());
    j["ability_ids"] = ability_ids;

    json summon_ids = json::array();
    for (const auto& s : npc.get_summons())
        summon_ids.push_back(s->get_id());
    j["summon_ids"] = summon_ids;

    json elements = json::array();
    for (const auto& e : npc.get_mana_elements())
        elements.push_back(static_cast<int>(e));
    j["mana_elements"] = elements;

    return j;
}

// ── Deserialization helpers ──

void load_player_from_json(const json& j, Player& player) {
    // Mutable scalar fields
    player.set_hair_color(j["hair_color"]);
    player.set_age(j["age"]);
    player.set_money(j["money"]);
    player.set_goodness(j["goodness"]);
    player.set_build(static_cast<Builds>(j["build"].get<int>()));
    player.set_rank(static_cast<Rank>(j["rank"].get<int>()));
    player.set_hunger(j["hunger"]);
    player.set_level(j["level"]);
    player.set_exp(j["exp"]);
    player.set_hp(j["hp"]);
    player.set_mana(j["mana"]);
    player.set_skill_points(j["skill_points"]);
    player.set_heavenly_restriction(j["heavenly_restriction"]);
    player.set_stats(json_to_stats(j["stats"]));

    // Aquired items (set of ints)
    unordered_set<int> aquired;
    for (const auto& id : j["aquired_items"])
        aquired.insert(id.get<int>());
    player.set_aquired_items(aquired);

    // Enums
    vector<Elemental_Affinity> elements;
    for (const auto& e : j["mana_elements"])
        elements.push_back(static_cast<Elemental_Affinity>(e.get<int>()));
    player.set_mana_elements(elements);

    vector<DNA> dna;
    for (const auto& d : j["dna"])
        dna.push_back(static_cast<DNA>(d.get<int>()));
    player.set_dna(dna);

    // NOTE: inventory_items, abilities, summons, party_members, armour and weapon slots
    // are saved by ID. Reconstruct them from your game's item/ability/npc registry using:
    //   j["inventory_item_ids"], j["ability_ids"], j["summon_ids"],
    //   j["party_member_ids"], j["armour_slot_ids"], j["weapon_slot_ids"]
}

void load_story_from_json(const json& j, Story& story) {
    story.set_chapter(static_cast<Story_Progression>(j["chapter"].get<int>()));
    story.set_path(static_cast<Path_Choice>(j["path"].get<int>()));

    vector<Story_Events> events;
    for (const auto& e : j["events_occurred"])
        events.push_back(static_cast<Story_Events>(e.get<int>()));
    story.set_events_occurred(events);
}

void load_npc_from_json(const json& j, Npc& npc) {
    npc.set_age(j["age"]);
    npc.set_rank(static_cast<Rank>(j["rank"].get<int>()));
    npc.set_level(j["level"]);
    npc.set_exp_reward(j["exp_reward"]);
    npc.set_hp(j["hp"]);
    npc.set_mana(j["mana"]);
    npc.set_stats(json_to_stats(j["stats"]));

    vector<Elemental_Affinity> elements;
    for (const auto& e : j["mana_elements"])
        elements.push_back(static_cast<Elemental_Affinity>(e.get<int>()));
    npc.set_mana_elements(elements);

    // NOTE: abilities and summons are saved by ID.
    // Reconstruct from your game's registry using:
    //   j["ability_ids"], j["summon_ids"]
}

// ── Main save / load ──

bool save_game(const string &filename, Player& player, Story& story, vector<Npc>& npcs) {
    json save;
    save["player"] = player_to_json(player);
    save["story"]  = story_to_json(story);

    save["npcs"] = json::array();
    for (auto& npc : npcs)
        save["npcs"].push_back(npc_to_json(npc));

    ofstream file(filename);
    if (!file.is_open()) return false;

    file << save.dump(4);
    return true;
}

bool load_game(const string &filename, Player& player, Story& story, vector<Npc>& npcs) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    json save = json::parse(file);

    load_player_from_json(save["player"], player);
    load_story_from_json(save["story"], story);

    for (size_t i = 0; i < save["npcs"].size() && i < npcs.size(); i++)
        load_npc_from_json(save["npcs"][i], npcs[i]);

    return true;
}

bool delete_save(const string &filename) {
    if (remove(filename.c_str()) == 0) {
        return true;
    }
    return false;
}

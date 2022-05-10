#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"
#include <string>
using namespace std;

namespace coup {
    class Player;
    class Game {

    public:
        vector<Player*> Players;
        unsigned int my_turn;
        bool game_start;
        Game();
        string turn();
        void next_in_turn();
        void add_player(Player* player);
        vector<string>players();
        string winner();
    };
}




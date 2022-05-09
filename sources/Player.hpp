#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"

using namespace std;

namespace coup {
    class Game;
    class Player{

    public:
        int coin;
        string name;
        bool in_play;
        string my_role;
        Game* game;
        string last_action;
        bool coup_three;
        Player* last_action_name;


        Player( Game &, const string& );
        void income();
        void foreign_aid();
        virtual void coup(Player &play);
        int coins() const;
        string role() const;

    };
}
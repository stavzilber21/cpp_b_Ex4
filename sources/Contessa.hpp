#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"
#pragma once
using namespace std;
namespace coup {
    class Contessa: public Player {


    public:
        Contessa( Game &game, const string& name);
        void block(Player &play);

    };
}
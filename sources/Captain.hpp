#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#pragma once
using namespace std;
namespace coup {
    class Captain: public Player {

    public:
        Captain ( Game &game, const string& name);
        void steal (Player& play);
        void block(Player& play);


    };
}
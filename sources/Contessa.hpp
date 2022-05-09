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
    private:
//        Game game;
        string str;
    public:
        Contessa( Game &game, const string& name);
        void block(Player &play);

    };
}
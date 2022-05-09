#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"


#pragma once
using namespace std;
namespace coup {
    class Ambassador: public Player {
    private:
//        Game *game;
    public:
        Ambassador( Game &game, const string& name);
        void transfer(Player &p1,Player &p2);
        void block(Player& play);
//        string role() override;

    };
}
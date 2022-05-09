#include "Contessa.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace coup {

    Contessa::Contessa( Game &game, const string& name): Player(game, name){
        this->my_role="Contessa";
    }

    void Contessa::block(Player &play){
        if(!this->in_play || !play.in_play){
            throw runtime_error("This player is not in the game");
        }
        if(play.my_role!="Assassin"){
            throw runtime_error("A countess can only block an assassin");
        }
        if(play.last_action!="coup"){
            throw runtime_error("Check that the previous assassin coup someone from the game");
        }
        if(!play.last_action_name->coup_three){
            throw runtime_error("He carried out a coup in 7 coins");
        }
        this->game->game_start=true;
        play.last_action_name->in_play= true;

        this->last_action_name = &play;
        this->last_action= "block";
    }

}
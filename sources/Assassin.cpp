#include "Assassin.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
namespace coup {
    Assassin::Assassin( Game &game, const string& name): Player(game,name){
        this->my_role="Assassin";
    }

    void Assassin::coup(Player& play){
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        if(this->game!=play.game){
            throw runtime_error("They are not in the same game");
        }
        if(!play.in_play){
            throw runtime_error("This player is not in the game");
        }
        const int eight = 8;
        const int three = 3;
        const int seven = 7;
        this->game->game_start=true;
        if(this->coin>=three){
            if(this->coin>=eight){
                this->coin-=seven;
                play.coup_three= false;
            }
            else{
                this->coin-=3;
                play.coup_three= true;
            }
            this->game->next_in_turn();
            play.in_play=false;
            this->last_action_name=&play;
            this->last_action="coup";
        }
        else{
            throw runtime_error("He does not have enough money");
        }



    }


}
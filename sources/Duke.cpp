#include <iostream>
#include <vector>
#include <string>
#include "Duke.hpp"
using namespace std;
namespace coup {

    Duke::Duke( Game &game, const string& name): Player(game, name){
        this->my_role="Duke";
    }

    void Duke::tax(){
        const int max_coins = 10;
        if(this->coin>=max_coins){
            throw runtime_error("It has more than 10 coins");
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        if(!this->in_play){
            throw runtime_error("This player is not in the game");
        }
        this->game->game_start=true;
        this->coin+=3;

        this->game->set_turn();
        this->last_action="tax";
        this->last_action_name=NULL;
    }

    void Duke::block(Player& play){
        if(this->game!=play.game){
            throw runtime_error("They are not in the same game");
        }

        if(!this->in_play || !play.in_play){
            throw runtime_error("This player is not in the game");
        }
        if(play.last_action!="foreign_aid"){
            throw runtime_error("The last action was not foreign_aid");
        }
        this->game->game_start=true;
        play.coin-=2;
        this->last_action="block";
        this->last_action_name=&play;

    }

}

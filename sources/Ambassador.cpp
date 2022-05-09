#include "Ambassador.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace coup {
    Ambassador::Ambassador( Game &game, const string& name): Player(game,name) {
        this->my_role= "Ambassador";
    }

    void Ambassador::transfer(Player &p1,Player &p2){
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        const int max_coins = 10;
        if(this->coin>=max_coins){
            throw runtime_error("It has more than 10 coins");
        }
        if(p1.game!=p2.game){
            throw runtime_error("They are not in the same game");
        }
        if(!p1.in_play || !p2.in_play){
            throw runtime_error("One of them is not in the game");
        }
        if(p1.coin<1){
            throw runtime_error("not enough money to transfer");
        }
        this->game->game_start=true;
        p1.coin--;
        p2.coin++;
        this->game->my_turn++;
        if(this->game->my_turn>= this->game->players().size()){
            this->game->my_turn=this->game->my_turn%this->game->players().size();
        }

        this->last_action="transfer";
        this->last_action_name=NULL;
    }

    void Ambassador::block(Player& play){
        if(this->game!=play.game){
            throw runtime_error("They are not in the same game");
        }
        if(!play.in_play){
            throw runtime_error("he is not in the game");
        }
        if(play.last_action!="steal"){
            throw runtime_error("The captain's last action was not theft");
        }
        this->game->game_start=true;
        play.coin-=2;
        play.last_action_name->coin+=2;

        this->last_action_name=&play;
        this->last_action="block";
    }


}
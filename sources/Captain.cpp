#include "Captain.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace coup {

    Captain::Captain( Game &game, const string& name): Player(game,name){
        this->my_role="Captain";
    }

    void Captain::steal (Player& play) {
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        if(!play.in_play){
            throw runtime_error("he is not in the game");
        }
        const int max_coins = 10;
        if(this->coin>=max_coins){
            throw runtime_error("It has more than 10 coins");
        }
        if(this->game!=play.game){
            throw runtime_error("They are not in the same game");
        }
        this->game->game_start=true;
        if(play.coin>=1){
            if(play.coin>=2){
                this->coin+=2;
                play.coin-=2;
            }
            else{
                this->coin+=1;
                play.coin-=1;
            }

            this->game->set_turn();
            this->last_action="steal";
            this->last_action_name=&play;
        }
        else{
            throw runtime_error("It has less than 1 coin");
        }

    }

    void Captain::block(Player& play){
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

        this->last_action_name = &play;
        this->last_action= "block";

    }

}
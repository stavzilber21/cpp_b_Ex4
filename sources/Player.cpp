
#include "Player.hpp"
using namespace std;

namespace coup {
    Player::Player( Game &_game, const string &name) {
        this->name=name;
        this->coin=0;
        this->last_action_name=NULL;
        this->in_play=true;
        this->coup_three=false;
        game=&_game;
        game->add_player(this);
        if(game->Players.size()>6){
            throw runtime_error("No more than 6 players are allowed");
        }
        if(game->game_start){
            throw runtime_error("The game has already started");
        }
    }
    void Player::income() {
        if(this->game->Players.size()<2 || this->game->Players.size()>6){
            throw runtime_error("Allowed between 2 and 6 players");
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        const int max_coins = 10;
        if(this->coin>=max_coins){
            throw runtime_error("It has more than 10 coins");
        }
        this->game->game_start=true;
        this->coin++;
        this->game->my_turn++;
        if(this->game->my_turn>= this->game->players().size()){
            this->game->my_turn=this->game->my_turn%this->game->players().size();
        }
        this->last_action_name=NULL;
        this->last_action="income";
    }

    void Player::foreign_aid() {
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        if(this->game->Players.size()<2 || this->game->Players.size()>6){
            throw runtime_error("Allowed between 2 and 6 players");
        }
        const int max_coins = 10;
        if(this->coin>=max_coins){
            throw runtime_error("It has more than 10 coins");
        }
        this->game->game_start=true;
        this->coin+=2;
        this->game->my_turn++;
        if(this->game->my_turn>= this->game->players().size()){
            this->game->my_turn=this->game->my_turn%this->game->players().size();
        }


        this->last_action="foreign_aid";
        this->last_action_name=NULL;
    }

    void Player::coup(Player &play) {
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        if(this->game!=play.game){
            throw runtime_error("They are not in the same game");
        }
        if(!play.in_play){
            throw runtime_error("This player is not in the game");
        }

        if(this->coin<7){
            throw runtime_error("He does not have enough money");
        }
        this->game->game_start=true;
        this->coin-=7;

        play.in_play= false;

        if(this->game->my_turn>= this->game->players().size()){
            this->game->my_turn=this->game->my_turn%this->game->players().size();
        }
        this->game->my_turn++;

        this->last_action="coup";
        this->last_action_name=&play;

    }
    int Player::coins() {
        return this->coin;
    }
    string Player::role(){
        return this->my_role;
    }
}
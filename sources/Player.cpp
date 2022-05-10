
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
        const int six = 6;
        game->add_player(this);
        if(game->Players.size()>six){
            throw runtime_error("No more than 6 players are allowed");
        }
        if(game->game_start){
            throw runtime_error("The game has already started");
        }
    }
    void Player::income() {
        const int six = 6;
        const int two = 2;
        if(this->game->Players.size()<two || this->game->Players.size()>six){
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

        this->game->next_in_turn();
        this->last_action_name=NULL;
        this->last_action="income";
    }

    void Player::foreign_aid() {
        if(!this->in_play){
            this->game->my_turn++;
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("This is not his turn");
        }
        const int six = 6;
        const int two = 2;
        if(this->game->Players.size()<two || this->game->Players.size()>six){
            throw runtime_error("Allowed between 2 and 6 players");
        }
        const int max_coins = 10;
        if(this->coin>=max_coins){
            throw runtime_error("It has more than 10 coins");
        }
        this->game->game_start=true;
        this->coin+=2;


        this->game->next_in_turn();
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
        const int seven = 7;
        if(this->coin<seven){
            throw runtime_error("He does not have enough money");
        }
        this->game->game_start=true;
        this->coin-=seven;

        play.in_play= false;

        this->game->next_in_turn();

        this->last_action="coup";
        this->last_action_name=&play;

    }
    int Player::coins()const {
        return this->coin;
    }
    string Player::role() const{
        return this->my_role;
    }
}
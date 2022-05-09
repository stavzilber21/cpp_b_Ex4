#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace coup {
    Game::Game(){
       my_turn=0;
       game_start= false;
    }


    void Game:: add_player(Player* player){
       Players.push_back(player);
    }

    string Game::turn(){
        if(this->Players.empty()){
            throw runtime_error("There are no players in the game");
        }

        return this->Players.at(unsigned (this->my_turn))->name;
    }
    void Game::set_turn(){
        if(my_turn == this->Players.size()-1) {
            my_turn = 0;
        }
        else {
            my_turn +=1;
        }
        if(!(this->Players.at((unsigned)this->my_turn)->in_play)) {
            this->set_turn();
        }
    }


    vector<string> Game:: players(){
        vector<string>name_players;
        for(Player *p : Players){
            if(p->in_play){
                name_players.push_back(p->name);
            }
        }
        return name_players;
    }
    string Game::winner(){
        if (this->players().size() != 1){
            throw runtime_error("There is more than one player in the game");
        }
        if(!this->game_start){
            throw runtime_error("The game has not started yet");
        }
        return this->players().at(0);
    }


}

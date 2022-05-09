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
        if(this->players().size()==0){
            throw runtime_error("There are no players in the game");
        }
        if(!this->Players.at(unsigned (this->my_turn) % unsigned (this->players().size()))->in_play){
            return this->Players.at(unsigned (this->my_turn))->name;
        }
        return this->Players.at(unsigned (this->my_turn) % unsigned (this->players().size()))->name;
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

#include <vector>
#include <fstream>
#include <iostream>

#include "../include/GameBoard.h"

GameBoard::GameBoard(){
    for(int x = 0; x < row_limit; x++){
        this->grid.push_back( std::vector<bool>() );
        // y represents the columns
        for(int y = 0; y < column_limit; y++){
            this->grid[x].push_back( false );
        }
    }
}

GameBoard::GameBoard( gridT initial_states ){
    if(initial_states.size() != row_limit){
		throw std::invalid_argument ("Invalid argument: the number of rows in the grid is incorrect!");
	}
    for(int x = 0; x < row_limit; x++){
        if(initial_states[x].size() != column_limit){
		    throw std::invalid_argument ("Invalid argument: the number of columns in the grid is incorrect!");
	    }        
    }
    this->grid = initial_states;
}

gridT GameBoard::getGrid(){
    return this->grid; 
}

/** Rules to determine whether a cell is populated or unpopulated
For a space that is 'populated':
    Each cell with one or no neighbors dies, as if by solitude.
    Each cell with four or more neighbors dies, as if by overpopulation.
    Each cell with two or three neighbors survives.
For a space that is 'empty' or 'unpopulated'
    Each cell with three neighbors becomes populated. 
*/
bool GameBoard::next_state(int x, int y){
    int num = num_of_alive_neighbours(x,y);
    bool current_state = this->grid[x][y]; 
    if(!current_state){
        return num == 3;
    }
    else{
        return (num == 3) || (num == 2);
    }
}

int GameBoard::num_of_alive_neighbours(int i, int j){
    int count = 0;
    for(int x = std::max(0, i-1); x <= std::min(i+1, row_limit-1); x++){
        for(int y = std::max(0, j-1); y <= std::min(j+1, column_limit-1); y++){
            if(!(x == i && y == j)){
                if(this->grid[x][y]){
                    count ++;
                }
            }
        }
    }
    return count;
}

// update all the cells in a grid. and return a new grid
void GameBoard::update(){
    // set result to be a grid of false;
    gridT result;

    for(int x = 0; x < row_limit; x++){
        result.push_back( std::vector<bool>() );
        for(int y = 0; y < column_limit; y++){
            result[x].push_back( false );
        }
    }
    
    for(int a = 0; a < row_limit; a++){
        for(int b = 0; b < column_limit; b++){
            // std::cout << next_state(x, y) << std::endl;
            result[a][b] = next_state(a, b);
        }
    }
    
    for(int x = 0; x < row_limit; x++){
        for(int y = 0; y < column_limit; y++){
            // std::cout << next_state(x, y) << std::endl;
            this->grid[x][y] = result[x][y];
        }
    }
}



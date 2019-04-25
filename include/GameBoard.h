/**
 *  \file GameBoard.h
 *  \brief An abstract data type (ADT) for representing the state of a game of "Game of Life"
 *  \author Declan Wu
 */
#ifndef A4_gameBoard
#define A4_gameBoard

#include <vector>
#include <fstream>
#include <iostream>
#include "GridTypes.h"

class GameBoard {
	private:
        gridT grid;
        
	public:
		/**
     	 *  \brief Constructs a new gameboard by default, setting all cells to be unpopulated
     	 *  \return A new GameBoard
     	 */            
    	GameBoard();

        /**
     	 *  \brief Constructs a new gameboard based on the given initial states
     	 *  \param initial_states 
     	 *  \return A new GameBoard
     	 */            
        GameBoard( gridT initial_states );

		/**
     	 *  \brief Get the state of the game board
		 *  \return the grid's state - 2 dimensional vector of boolean value
     	 */
		gridT getGrid();   

        /**
     	 *  \brief determine a cell's next state
     	 *  \param x represents the x coordinate
     	 *  \param y represents the y coordinate
     	 *  \param current_state, represents the cell's current state in boolean value 
     	 *  \return a boolean value reprsents the next state the current cell is going to be
     	 */
        bool next_state(int x, int y);

        /**
     	 *  \brief Compute the number of populated neighbour of a cell located at (x, y)
     	 *  \param x represents the x coordinate
     	 *  \param y represents the y coordinate
     	 *  \return a integer value reprsents the number of populated neighbour of a cell
     	 */
        int num_of_alive_neighbours(int i, int j);

        /**
     	 *  \brief Updates every cells in the gameboard
     	 *  \return a value of type girdT reprsents the new grid at time T+1
     	 */
        void update();
   
};

#endif
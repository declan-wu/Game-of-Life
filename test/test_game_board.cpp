#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "../include/GameBoard.h"
#include "catch.h"

TEST_CASE( "tests for GameBoard" , "[GameBoard]" ) {

    SECTION( "test for default constructor" ){
      GameBoard board = GameBoard();
      for(int x = 0; x < row_limit; x++){          
          for(int y = 0; y < column_limit; y++){
              REQUIRE( board.getGrid()[x][y] == false );
          }
      }   
    }

    SECTION( "test for constructor" ){
      gridT g2;
      for(int x = 0; x < row_limit; x++){
          g2.push_back( std::vector<bool>() );
          for(int y = 0; y < column_limit; y++){
              g2[x].push_back( false );
          }
      }
      GameBoard board = GameBoard(g2);
      for(int x = 0; x < row_limit; x++){          
          for(int y = 0; y < column_limit; y++){
              REQUIRE( board.getGrid()[x][y] == false );
          }
      }
    }

    SECTION( "test for num_of_alive_neighbours for cornor points" ){
      GameBoard board = GameBoard();
      REQUIRE( board.num_of_alive_neighbours(0,0) == 0 );
    }

    SECTION( "test for num_of_alive_neighbours for regular points, i.e. points have full 8 neighbours" ){
      GameBoard board = GameBoard();
      REQUIRE( board.num_of_alive_neighbours(5,5) == 0 );
    }

    SECTION( "test for next_state for cornor points" ){
      GameBoard board = GameBoard();
      REQUIRE( board.next_state(0,0) == false );
    }

    SECTION( "test for next_state for regular points, i.e. points have full 8 neighbours" ){
      GameBoard board = GameBoard();
      REQUIRE( board.next_state(5,5) == false );
    }

    SECTION( "test for update for still lifes - block" ){
      GameBoard board = GameBoard();
      board.update();
      for(int x = 0; x < row_limit; x++){          
          for(int y = 0; y < column_limit; y++){
              REQUIRE( board.getGrid()[x][y] == false );
          }
      }
    }

    SECTION( "test for update for oscillators - blinker" ){
      gridT g2;
      for(int x = 0; x < row_limit; x++){
          g2.push_back( std::vector<bool>() );
          for(int y = 0; y < column_limit; y++){
              g2[x].push_back( false );
          }
      }
      g2[1][0] = true;
      g2[1][1] = true;
      g2[1][2] = true;
      GameBoard board = GameBoard(g2);
      board.update();
      g2[1][0] = false;
      g2[1][1] = true;
      g2[1][2] = false;
      g2[0][1] = true;
      g2[2][1] = true;
      for(int x = 0; x < row_limit; x++){          
          for(int y = 0; y < column_limit; y++){
              REQUIRE( board.getGrid()[x][y] == g2[x][y] );
          }
      }
      REQUIRE( true );
    }
}
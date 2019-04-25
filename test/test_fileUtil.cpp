#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "../include/GameBoard.h"
#include "../include/FileUtil.h"
#include "../catch/catch.h"

TEST_CASE( "tests for FileUtil" , "[FileUtil]" ) {
    SECTION( "test for readFile" ){
        gridT g1 = readFile("data/input.txt");
        gridT g2;
        for(int x = 0; x < row_limit; x++){
            g2.push_back( std::vector<bool>() );
            for(int y = 0; y < column_limit; y++){
                g2[x].push_back( false );
            }
        }
        g2[0][0] = true;
        g2[0][1] = true;
        g2[1][0] = true;
        g2[1][1] = true;
        g2[2][2] = true;
        g2[2][3] = true;
        g2[3][2] = true;
        g2[3][3] = true;
        for(int x = 0; x < row_limit; x++){
            for(int y = 0; y < column_limit; y++){
                REQUIRE( g1[x][y] == g2[x][y] );
            }
        }       
    }

    SECTION( "test for writeToFile" ){
        gridT g2;
        for(int x = 0; x < row_limit; x++){
            g2.push_back( std::vector<bool>() );
            for(int y = 0; y < column_limit; y++){
                g2[x].push_back( false );
            }
        }
        g2[1][1] = true;    //only one cell
        GameBoard board = GameBoard(g2);
        board.update();
        writeToFile(board, "data/output.txt");
        gridT g1 = readFile("data/output.txt");
        g2[1][1] = false;
        for(int x = 0; x < row_limit; x++){
            for(int y = 0; y < column_limit; y++){
                REQUIRE( g1[x][y] == g2[x][y] );
            }
        }       
    }
}
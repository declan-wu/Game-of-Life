#include "../include/View.h"

/** means populated, and X means unpopulated */
void display(GameBoard board){
    gridT grid = board.getGrid();
    for(int a = 0; a < row_limit; a++){
        for(int b = 0; b < column_limit; b++){
            if(grid[a][b] == true){
                std::cout << " 0";
            }
            else{
                std::cout << " *";
            }
            if(b == column_limit-1){
                std::cout << std::endl;
            }
        }
    }
}
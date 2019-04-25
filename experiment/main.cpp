#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/GridTypes.h"
#include "../include/GameBoard.h"
#include "../include/FileUtil.h"
#include "../include/View.h"

int main() {
   
    gridT initial_g;
    initial_g = readFile("data/input.txt");
    
    GameBoard board = GameBoard(initial_g);
    display(board);
    std::cout << "------------------------------" << std::endl;
    
    board.update();
    display(board);
    writeToFile(board, "data/output.txt");
    std::cout << "------------------------------" << std::endl;
    board.update();
    display(board);
    writeToFile(board, "data/output.txt");
    std::cout << "------------------------------" << std::endl;
    
    return 0;
}
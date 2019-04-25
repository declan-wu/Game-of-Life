#include <fstream>
#include <iostream>
#include "../include/FileUtil.h"

gridT readFile(std::string str){
    gridT result;
    std::ifstream infile(str);

    if (infile.is_open()) { 
        std::string line;
        int x = 0; 
        while (std::getline(infile, line))
        {          
            result.push_back( std::vector<bool>() );
            std::vector<char> v(line.begin(), line.end());
            // convert the char into bool and stores it in result
            for(int y = 0; y < column_limit; y++){
                if( v[2*y] == '0' ){
                    result[x].push_back( true );
                }else{
                    result[x].push_back( false );                  
                }
            }
            x++;   
        }
    }
    else { 
        std::cout << "Unable to open file" << std::endl;
    }
    infile.close();
    return result;
}


void writeToFile(GameBoard board, std::string fileName){
    std::ofstream myfile;
    gridT grid = board.getGrid();
    myfile.open (fileName);
    for(int a = 0; a < row_limit; a++){
        for(int b = 0; b < column_limit; b++){
            if(grid[a][b] == true){
                myfile << " 0";
            }
            else{
                myfile << " *";
            }
            if(b == column_limit-1){
                myfile << std::endl;
            }
        }
    }
    myfile.close();
}
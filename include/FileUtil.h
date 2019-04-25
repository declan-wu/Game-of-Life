/**
 *  \file FileUtil.h
 *  \brief A library exporting functions to read from and write to a file
 *  \author Declan Wu
 */
#ifndef A4_fileUtil
#define A4_fileUtil

#include <fstream>
#include <iostream>
#include "GridTypes.h"
#include "GameBoard.h"

/**
 *  \brief reads a file and reture a gridT 
 *  \param fileName the name of the file to read from
 *  \return a gridT that was stored in the file
 */
gridT readFile(std::string fileName);

/**
 *  \brief write the grid to a file
 *  \param fileName the name of the file you want to write
 *  \param board represents the gameboard
 */
void writeToFile(GameBoard board, std::string fileName);

#endif

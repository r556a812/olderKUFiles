/**
*	@file : MazeReader.h
*	@author : Richard Aviles
*	@date : 2015.11.12
	Purpose:  
*/

#ifndef MAZE_READER_H
#define MAZE_READER_H 
#include "MazeCreationException.h"
#include <string>
#include <fstream>


class MazeReader
{
    
public:
    MazeReader(std::string file) throw (MazeCreationException);
    ~MazeReader();
    const char* const* getMaze() const;
    int getCols() const;
    int getRows() const;
    int getStartCol() const;
    int getStartRow() const;
    int m_rows;
    int m_cols;
    int m_startRow;
    int m_startCol;
    char** m_maze;
    std::ifstream m_in;
    std::string m_filename;
    
protected:
    void readMaze() throw (MazeCreationException);
    
};

#endif
    

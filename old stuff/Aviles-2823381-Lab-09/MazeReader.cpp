/**
*	@file : MazeReader.hpp
*	@author :  Richard Aviles
*	@date : 2015.11.12
*	Purpose:
*/


#include "MazeReader.h"
#include <string>

MazeReader::MazeReader(std::string file) throw(MazeCreationException):m_in(m_filename), m_filename(file)
{

    m_in.open(file);

    if(!(m_in.is_open()))
    {
        throw (MazeCreationException("Error"));
    }
    else
    {
        m_in >> m_rows;
        m_in >> m_cols;

        if (m_rows < 1 || m_rows > 999999 || m_cols < 1 || m_cols > 999999)
        {
            throw(MazeCreationException("Error"));
        }

        m_in >> m_startRow;
        m_in >> m_startCol;

        if (m_startRow < 0 || m_startRow > m_rows - 1 || m_startCol < 0 || m_startCol - 1 > m_cols)
        {
            throw (MazeCreationException("Error"));
        }

        m_maze = new char*[m_rows];

        for (int i = 0; i < m_rows; i++)
        {
            m_maze[i] = new char[m_cols];
        }

        readMaze();

        m_in.close();

    }

}

MazeReader::~MazeReader()
{
    for (int i = 0; i < m_rows; i++)
    {
        delete[] m_maze[i];
        m_maze[i] = nullptr;
    }

    delete[] m_maze;
    m_maze = nullptr;
}


const char* const* MazeReader::getMaze() const
{
    return (m_maze);
}

int MazeReader::getCols() const
{
    return (m_cols);
}


int MazeReader::getRows() const
{
    return (m_rows);
}

int MazeReader::getStartCol() const
{
    return (m_startCol);
}


int MazeReader::getStartRow() const
{
    return (m_startRow);
}

void MazeReader::readMaze() throw (MazeCreationException)
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_in >> m_maze[i][j];
        }
    }
}


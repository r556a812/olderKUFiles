/**
*	@file : Position.hpp
*	@author :  Richard Aviles
*	@date : 2015.11.12
*	Purpose:
*/


#include "Position.h"


Position::Position(int row, int col)
{
    m_row = row;
    m_col = col;
}

int Position::getCol() const
{
    return (m_col);
}

int Position::getRow() const
{
    return (m_row);
}


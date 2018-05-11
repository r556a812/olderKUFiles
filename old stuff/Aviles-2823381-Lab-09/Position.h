/**
*	@file : Position.h
*	@author : Richard Aviles
*	@date : 2015.11.12
	Purpose:  
*/

#ifndef POSITION_H
#define POSITION_H 


class Position
{
    
public:
    Position(int row=0, int col=0);
    int getRow() const;
    int getCol() const;
    
private:
    int m_row;
    int m_col;
    
};

#endif
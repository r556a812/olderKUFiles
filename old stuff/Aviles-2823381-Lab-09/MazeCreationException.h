/**
*	@file : MazeCreationException.h
*	@author : Richard Aviles
*	@date : 2015.11.12
	Purpose:  
*/

#ifndef MAZE_CREATION_EXCEPTION_H
#define MAZE_CREATION_EXCEPTION_H

#include <stdexcept>

class MazeCreationException:  public std::runtime_error
{
    
public:
    MazeCreationException(const char* message); //@pre Have to send a message to the method. @post Sends the message to the inherited class runtime_error. @return None
    
};

#endif

/**
*	@file : MazeCreationException.hpp
*	@author :  Richard Aviles
*	@date : 2015.11.12
*	Purpose:
*/


#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char *message):std::runtime_error(message)
{
}

/**
*	@file : PreconditionViolationException.h
*	@author : Richard Aviles
*	@date : 2015.10.01
	Purpose:  Header file for the PreconditionViolationException class.
*/

#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H

#include <stdexcept>

class PreconditionViolationException: public std::runtime_error
{
public:
    PreconditionViolationException(const char* message); //@pre Have to send a message to the method. @post Sends the message to the inherited class runtime_error. @return None
};

#endif

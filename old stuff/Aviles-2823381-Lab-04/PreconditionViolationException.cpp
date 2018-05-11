/**
*	@file : PrecondiotionViolationException.hpp
*	@author :  Richard Aviles
*	@date : 2015.10.01
*	Purpose: Creates the method for the Precondition Violation Exception class
*/

#include "PreconditionViolationException.h"
#include <stdexcept>

PreconditionViolationException::PreconditionViolationException(const char *message):std::runtime_error(message)
{
}

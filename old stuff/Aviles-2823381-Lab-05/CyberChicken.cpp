/**
*	@file : CyberChicken.cpp
*	@author :  Richard Aviles
*	@date : 2015.10.08
*	Purpose:
*/

#include "Chicken.h"
#include "CyberChicken.h"
#include "FarmAnimal.h"


CyberChicken::CyberChicken()
{
    setName("Cyber Chicken");
    setSound("Resistance is futile");
}

int CyberChicken::getCyberEggs() const
{
    return (m_eggs);
}


void CyberChicken::setCyberEggs(int eggs)
{
    m_eggs = eggs;
}

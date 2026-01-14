#include <iostream>
#include "StraightStair.h"

void StraightStair::riseAndRunCalculator() 
{
    *run = (*lengthStair) / steps;

    *rise = floorToFloorHeight / steps;

}

void StraightStair::lengthByRunCalculator() 
{
    *lengthStair = (*run) * steps;

    *rise = floorToFloorHeight / steps;
}

void StraightStair::headroomCalculator() 
{

    if(*lengthStair > openingLength) {

        headroomRise = 0;

        ceilingLength = (*lengthStair) - openingLength;

        for (double currentDist = *run; currentDist <= ceilingLength; currentDist += *run) 
        {
            headroomRise += *rise;
            
        };

        *headroom = floorToFloorHeight - ceiling - headroomRise;

        if(*headroom < 0) *headroom = 0;
        
    } else {
        *headroom = floorToFloorHeight;
    }
    
};
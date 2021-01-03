#include <assert.h>                  // For assert.
#include <algorithm>                 // For find algorithm.
#include "ThreatFinder.hpp"          // For enum KindOfThreats.
#include "ThreatsBloodRelation.hpp"  // For ThreatsBloodRelation declaration.

bool ThreatsBloodRelation::IsOnFourList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::FOUR_LIST_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::FOUR_LIST[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

bool ThreatsBloodRelation::IsOnThreeList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::THREE_LIST_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::THREE_LIST[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

bool ThreatsBloodRelation::IsOnTwoList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::TWO_LIST_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::TWO_LIST[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

bool ThreatsBloodRelation::IsOnJokerList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::JOKER_LIST_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::JOKER_LIST[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

bool ThreatsBloodRelation::IsOnAceList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::ACE_LIST_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::ACE_LIST[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

bool ThreatsBloodRelation::IsOnManyGapsList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::MANY_GAPS_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::MANY_GAPS[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

bool ThreatsBloodRelation::IsOnExtendedNeighborhoodList(const ThreatFinder::KindOfThreats kindOfThreat)
{
    bool retVal = false;

    for(uint32_t i = 0; i < ThreatsBloodRelation::EXTENDED_NEIGHBORHOOD_SIZE; ++i)
    {
        if(kindOfThreat == ThreatsBloodRelation::EXTENDED_NEIGHBORHOOD[i])
        {
            retVal = true;
            break;
        }
    }

    return retVal;
}

/***************************************************************************
 *   Copyright (C) 2018 by Zbigniew Halat                                  *
 *   zby.halat@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.           *
 ***************************************************************************/

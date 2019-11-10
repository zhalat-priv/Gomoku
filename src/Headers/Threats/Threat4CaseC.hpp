/////////////////////////////////////////////////////////////////////////////////////////
/// @file Threat4CaseC.hpp
///
/// Threat4CaseC class declaration.
///
/// @par Full Description.
/// Threat4CaseC finds pawns' which constitute one case of 'four thread' pattern.
/// See article: 'Go-Moku and Threat-Space Search' by L.V. Allis & H.J. van den Herik
///
/// @if REVISION_HISTORY_INCLUDED
/// @par Edit History
/// - zhalat 03-Mar-2016 Initial revision.
/// - zhalat 19-Oct-2016 Performance improvement.
/// 					 Pattern mask usage instead of full pattern.
/// - zhalat 27-Nov-2017 Added GetThreatUpDetails().
/// @endif
///
/// @ingroup.
///
/// @par non-Copyright (c) 2017 HalSoft
///////////////////////////////////////////////////////////////////////////////////////////

#if !defined(THREAT_FOUR_CASE_C_HPP_)
#define THREAT_FOUR_CASE_C_HPP_

// SYSTEM INCLUDES
#include <assert.h>  // For assert.

// C PROJECT INCLUDES
// <none>

// C++ PROJECT INCLUDES
#include "Board.hpp"         // PositionField, PositionXY, Board's enums.
#include "ThreatFinder.hpp"  // ThreatFinder definitions.

// FORWARD REFERENCES
// <none>

///////////////////////////////////////////////////////////////////////////////////////////
/// CLASS NAME: Threat4CaseC.
///
/// Threat4CaseC class declaration.
///
/// @par Full Description.
/// Allows to find case C of threat four pattern on a gomoku board.
///
/// O.XXXXO
/// OX.XXXO
/// OXX.XXO
/// OXXX.XO
/// OXXXX.O
///-----------------------------------symmetric--------------------------------------------
/// n/a
///////////////////////////////////////////////////////////////////////////////////////////
class Threat4CaseC : public ThreatFinder
{
   public:
    /// The size of 'Threat4CaseC' threat pattern.
    static constexpr uint32_t PATTERN_LENGHT = 7;

    /// Tells how many pawns/gaps/asterixes this thrat has.
    static const std::unordered_map<ThreatFinder::ThreatAtom, int, std::hash<int>> ATOM_NUMBER_4C;

    ///////////////////////////////////////////////////////////////////////
    // METHOD NAME: Threat4CaseC::CheckThreat
    //
    /// Check if given threat is real threat.
    ///
    /// @par Full Description
    ///	Check pretendThreat if meets all requirement to real threat.
    ///
    /// @param  pretendThreat	  Threat to be checked.
    /// @param  pointOfView       Point of view.
    /// @param  playerPerspective For which player threat is looking for.
    ///
    /// @retval True if pretendent threat is real threat, false otherwise.
    ///////////////////////////////////////////////////////////////////////
    virtual bool CheckThreat(const uint32_t pretendThreat, const uint32_t pointOfView,
                             const Board::Player playerPerspective) const;

    ///////////////////////////////////////////////////////////////////////
    // METHOD NAME: Threat4CaseC::GetThreatUpDetails
    //
    /// After threat was found, method provides threat up details.
    ///
    /// @par Full Description
    /// Provide details about threat like pawns/asterix/gaps arrangement.
    ///
    /// @param  initialPosition	  [in]Position from which threat is considered.
    /// @param  trend             [in]Threat's trend.
    /// @param  rThreatUpDetails  [out]Container where up details is being written.
    ///
    /// @retval Threat up details.
    ///////////////////////////////////////////////////////////////////////
    virtual void GetThreatUpDetails(const Board::PositionXY initialPosition, const Trend trend,
                                    ThreatUpDetails& rThreatUpDetails) const;

    ///////////////////////////////////////////////////////////////////////
    // METHOD NAME: ThreatFinder::IsBreakWhenFirstFound
    //
    /// Indicate if searching should be continue to find symmetric.
    ///
    /// @par Full Description
    /// Indicate if searching should be continue to find symmetric.
    ///
    /// @retval True if continue, false, immediate stop.
    ///////////////////////////////////////////////////////////////////////
    virtual bool IsSearchForSimmetrics() const { return false; }

    ///////////////////////////////////////////////////////////////////////
    // METHOD NAME: Threat4CaseC::PrepareSelfForNewSearch
    //
    /// Prepare class for new search.
    ///
    /// @par Full Description
    /// Prepare class for new search. Like clearing the internal flags.
    ///////////////////////////////////////////////////////////////////////
    virtual void PrepareSelfForNewSearch()
    {
        // Clear itself.
        m_ThreatDownDetails.ClearAll();
    };

    /// Constructor.
    Threat4CaseC();

   private:
    /// Private copy constructor - forbid copying.
    Threat4CaseC(const Threat4CaseC&);

    /// Private assignment operator - forbid copying.
    Threat4CaseC& operator=(const Threat4CaseC&);

    /// Threat pattern for X player.
    static const ThreatPattern m_ThreatPatternX[];

    /// Threat pattern for O player.
    static const ThreatPattern m_ThreatPatternO[];

    /// Keeps all valid points of view. Note that to speed up, points starting form '.' are removed.
    static const uint32_t m_PointsView[];

    // Keeps number of elements in pattern threat.
    static const uint32_t m_ThreatPatternElements;

    // Threat down details status.
    mutable ThreatDownDetails m_ThreatDownDetails;
};
#endif /* THREAT_FOUR_CASE_C_HPP_ */

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

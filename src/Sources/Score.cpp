#include <assert.h>           // For assert.
#include "Score.hpp"          // For Score definition.
#include "BoardScore.hpp"     // For BoardScore definition.
#include "Threat2CaseA.hpp"   // For Threat2CaseA declaration.
#include "Threat2CaseAA.hpp"  // For Threat2CaseA declaration.
#include "Threat2CaseB.hpp"   // For Threat2CaseB declaration.
#include "Threat2CaseC.hpp"   // For Threat2CaseC declaration.
#include "Threat3CaseA.hpp"   // For Threat3CaseA declaration.
#include "Threat3CaseAA.hpp"  // For Threat3CaseAA declaration.
#include "Threat3CaseB.hpp"   // For Threat3CaseB declaration.
#include "Threat3CaseC.hpp"   // For Threat3CaseC declaration.
#include "Threat4CaseA.hpp"   // For Threat4CaseA declaration.
#include "Threat4CaseAA.hpp"  // For Threat4CaseAA declaration.
#include "Threat4CaseB.hpp"   // For Threat4CaseB declaration.
#include "Threat4CaseC.hpp"   // For Threat4CaseC declaration.
#include "ThreatWinner.hpp"   // For ThreatWinner declaration.
#include "ThreatFinder.hpp"   // For ThreatFinder declaration.

static ThreatWinner threatWinner;
static Threat4CaseA threat4CaseA;
static Threat4CaseAA threat4CaseAA;
static Threat4CaseB threat4CaseB;
static Threat4CaseC threat4CaseC;
static Threat3CaseA threat3CaseA;
static Threat3CaseAA threat3CaseAA;
static Threat3CaseB threat3CaseB;
static Threat3CaseC threat3CaseC;
static Threat2CaseA threat2CaseA;
static Threat2CaseAA threat2CaseAA;
static Threat2CaseB threat2CaseB;
static Threat2CaseC threat2CaseC;

const Score::ThreatScore Score::m_ThreatScore[] = {
    /*0 */ {ThreatFinder::THREAT_WINNER, &threatWinner, THREAT_WINNER_SCORE},
    /*1 */ {ThreatFinder::THREAT_4_CASE_A, &threat4CaseA, THREAT_4_CASE_A_SCORE},
    /*2 */ {ThreatFinder::THREAT_4_CASE_AA, &threat4CaseAA, THREAT_4_CASE_AA_SCORE},
    /*3 */ {ThreatFinder::THREAT_4_CASE_B, &threat4CaseB, THREAT_4_CASE_B_SCORE},
    /*4 */ {ThreatFinder::THREAT_4_CASE_C, &threat4CaseC, THREAT_4_CASE_C_SCORE},
    /*5 */ {ThreatFinder::THREAT_3_CASE_A, &threat3CaseA, THREAT_3_CASE_A_SCORE},
    /*6 */ {ThreatFinder::THREAT_3_CASE_AA, &threat3CaseAA, THREAT_3_CASE_AA_SCORE},
    /*7 */ {ThreatFinder::THREAT_3_CASE_B, &threat3CaseB, THREAT_3_CASE_B_SCORE},
    /*8 */ {ThreatFinder::THREAT_3_CASE_C, &threat3CaseC, THREAT_3_CASE_C_SCORE},
    /*9 */ {ThreatFinder::THREAT_2_CASE_A, &threat2CaseA, THREAT_2_CASE_A_SCORE},
    /*10 */ {ThreatFinder::THREAT_2_CASE_AA, &threat2CaseAA, THREAT_2_CASE_AA_SCORE},
    /*11*/ {ThreatFinder::THREAT_2_CASE_B, &threat2CaseB, THREAT_2_CASE_B_SCORE},
    /*12*/ {ThreatFinder::THREAT_2_CASE_C, &threat2CaseC, THREAT_2_CASE_C_SCORE},
};

Score* Score::GetInstance()
{
    static Score score{};
    return &score;
}

void Score::UpdateScore(BoardScore& boardScore, const vector<Board::PositionXY>& xyList, const uint32_t multiplier)
{
    // Each threats (see content of m_ThreatScore) need to be provided with board first, such that
    // have board to analyze.
    SetBoard(boardScore.GetBoard());

    for(auto const& xy : xyList)
    {
        const bool isOpponentMove = (boardScore.GetBoard().GetMove(xy) != boardScore.GetPlayer());

        // Check if this move is a part of existing threat. If so, remove it.
        // Inform Spotter about all of removed threats, it will have to check them more precisely, because some of them
        // might be just mitigated (if opponent move), of even became more dangerous (if my move).
        boardScore.RemoveThreats(xy);

        // Execute only those threats which can have chance to exist.
        boardScore.GetSpotter().Execute(xy, isOpponentMove, multiplier);
    }
}

void Score::UpdateScore(BoardScore& boardScore, const Board::PositionXY xy, const uint32_t multiplier)
{
    assert(multiplier > 0);

    // Each threats (see content of m_ThreatScore) need to be provided with board first, to heaving board to analyze.
    SetBoard(boardScore.GetBoard());

    const bool isOpponentMove = (boardScore.GetBoard().GetMove(xy) != boardScore.GetPlayer());

    // Check if this move is a part of existing threat. If so, remove it.
    // Inform Spotter about all of removed threats, it will have to check them more precisely, because some of them
    // might be just mitigated (if opponent move), of even became more dangerous (if my move).
    boardScore.RemoveThreats(xy);

    // Execute only those threats which can have chance to exist.
    boardScore.GetSpotter().Execute(xy, isOpponentMove, multiplier);
}

void Score::SetBoard(const Board& rBoard)
{
    for(uint32_t i = 0; i < NUMELEM(m_ThreatScore); ++i)
    {
        m_ThreatScore[i].m_pThreat->SetBoard(&rBoard);
    }
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

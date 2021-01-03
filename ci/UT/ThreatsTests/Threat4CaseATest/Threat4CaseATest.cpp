#include "Board.hpp"  // for Board definitions.
#include "Threat4CaseA.hpp"
#include "GomokuBoard.hpp"
#include <assert.h>  // for assert.
//----------------------------------------------------------
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "CppUTest/TestMemoryAllocator.h"
#include "CppUTest/MemoryLeakDetector.h"

TEST_GROUP(Threat4CaseATest)
{
    void setup()
    {
        m_pGomokuBoard = new GomokuBoard(15);

        m_pThreatFinder = new Threat4CaseA();
        m_pThreatFinder->SetBoard(m_pGomokuBoard);
    }

    void teardown()
    {
        delete m_pGomokuBoard;
        delete m_pThreatFinder;
    }

   public:
    GomokuBoard* m_pGomokuBoard;
    ThreatFinder* m_pThreatFinder;
};

TEST(Threat4CaseATest, FindPatternOnHorizontalTrendTest1)
{
    // step by step build .XXXX. and verify if pattern is found.

    // a:   .X....
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 2), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_A));

    // b:   .XX...
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 3), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_A));

    // c:   .XXX..
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 4), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_A));

    // d:   .XXXX.
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 5), Board::PLAYER_A);
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 3), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 4), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 5), ThreatFinder::HORIZONTAL, Board::PLAYER_A));

    // e:   .XXXXX.
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 6), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 3), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 4), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 5), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 6), ThreatFinder::HORIZONTAL, Board::PLAYER_A));
}

TEST(Threat4CaseATest, FindPatternOnHorizontalTrendTest2)
{
    // step by step build .OOOO. and verify if pattern is found.

    // a:   .O....
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 2), Board::PLAYER_B);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_B));

    // b:   .OO...
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 3), Board::PLAYER_B);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_B));

    // c:   .OOO..
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 4), Board::PLAYER_B);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_B));

    // d:   .OOOO.
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 5), Board::PLAYER_B);
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 3), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 4), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 5), ThreatFinder::HORIZONTAL, Board::PLAYER_B));

    // e:   .OOOOO.
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 6), Board::PLAYER_B);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 3), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 4), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 5), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 6), ThreatFinder::HORIZONTAL, Board::PLAYER_B));
}

TEST(Threat4CaseATest, FindPatternAbuttedToBoardFrameTest)
{
    //	                       1 1 1 1 1
    //	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    //	0 |. . . x . x . . . . . . . . .|
    //	1 |. . x x x . . . . . x . . . .|
    //	2 |. x x x . . . . . . . x . . .|
    //	3 |x x x . . . . . . . . . x . .|
    //	4 |x . . . . . . . . . . . . x .|
    //	5 |. . . . . . . . . . . . . . .|
    //	6 |. . . . . . . . . . . . . . .|
    //	7 |. . . . . . . . . . . . . . .|
    //	8 |. . . . . . . . . . . . . . .|
    //	9 |. . . . . . . . . . . . . . .|
    //	10|. . . . . . . . . . . . . . .|
    //	11|. . . . . . . . . . . . . . .|
    //	12|. . . . . . . . . . . . . . .|
    //	13|. . . . . . . . . . . . . . .|
    //	14|. . . . . . . . . . . . . . .|
    //	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Some cases where false StraightFourPattern is abutted on the frame.
    m_pGomokuBoard->PutMove(Board::PositionXY(0, 3), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 2), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 1), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(3, 0), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 1), ThreatFinder::RISING, Board::PLAYER_A));

    m_pGomokuBoard->PutMove(Board::PositionXY(4, 0), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(3, 1), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 2), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 3), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::RISING, Board::PLAYER_A));

    m_pGomokuBoard->PutMove(Board::PositionXY(3, 2), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 3), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 4), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(0, 5), Board::PLAYER_A);
    CHECK_FALSE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(0, 5), ThreatFinder::RISING, Board::PLAYER_A));

    // A case where true StraightFourPattern is abutted on frame.
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 10), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 11), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(3, 12), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(4, 13), Board::PLAYER_A);
    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(4, 13), ThreatFinder::FALLING, Board::PLAYER_A));
}

TEST(Threat4CaseATest, GetThreatFieldsTest1)
{
    // Create threat  .XXXX.
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 2), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 3), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 4), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 5), Board::PLAYER_A);

    CHECK_TRUE(m_pThreatFinder->FindThreatPattern(Board::PositionXY(2, 2), ThreatFinder::HORIZONTAL, Board::PLAYER_A));

    // Get all fields which threat state.
    ThreatFinder::ThreatLocation threatLocation;

    m_pThreatFinder->GetThreatFields(threatLocation);

    const Board::PositionXY beginThreat = Board::PositionXY(2, 1);
    const Board::PositionXY endThreat   = Board::PositionXY(2, 6);

    CHECK(beginThreat == threatLocation.m_ThreatDetails.m_BeginningThreat);
    CHECK(endThreat == threatLocation.m_ThreatDetails.m_EndThreat);
}

TEST(Threat4CaseATest, GetThreatFieldsTest2)
{
    // Create threat  .XXXX.
    m_pGomokuBoard->PutMove(Board::PositionXY(4, 1), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(3, 2), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 3), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 4), Board::PLAYER_A);

    m_pThreatFinder->FindThreatPattern(Board::PositionXY(4, 1), ThreatFinder::RISING, Board::PLAYER_A);

    // Get all fields which threat state.
    ThreatFinder::ThreatLocation threatLocation;
    m_pThreatFinder->GetThreatFields(threatLocation);

    const Board::PositionXY beginThreat = Board::PositionXY(0, 5);
    const Board::PositionXY endThreat   = Board::PositionXY(5, 0);

    CHECK(beginThreat == threatLocation.m_ThreatDetails.m_BeginningThreat);
    CHECK(endThreat == threatLocation.m_ThreatDetails.m_EndThreat);
}

TEST(Threat4CaseATest, GetThreatFieldsTest3)
{
    // Create threat  .XXXX.
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 5), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 5), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(3, 5), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(4, 5), Board::PLAYER_A);

    m_pThreatFinder->FindThreatPattern(Board::PositionXY(1, 5), ThreatFinder::VERTICAL, Board::PLAYER_A);

    // Get all fields which threat state.
    ThreatFinder::ThreatLocation threatLocation;
    m_pThreatFinder->GetThreatFields(threatLocation);

    const Board::PositionXY beginThreat = Board::PositionXY(0, 5);
    const Board::PositionXY endThreat   = Board::PositionXY(5, 5);

    CHECK(beginThreat == threatLocation.m_ThreatDetails.m_BeginningThreat);
    CHECK(endThreat == threatLocation.m_ThreatDetails.m_EndThreat);
}

TEST(Threat4CaseATest, GetThreatFieldsTest4)
{
    // Create threat  .XXXX.
    m_pGomokuBoard->PutMove(Board::PositionXY(1, 1), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(2, 2), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(3, 3), Board::PLAYER_A);
    m_pGomokuBoard->PutMove(Board::PositionXY(4, 4), Board::PLAYER_A);

    m_pThreatFinder->FindThreatPattern(Board::PositionXY(1, 1), ThreatFinder::FALLING, Board::PLAYER_A);

    // Get all fields which threat state.
    ThreatFinder::ThreatLocation threatLocation;
    m_pThreatFinder->GetThreatFields(threatLocation);

    const Board::PositionXY beginThreat = Board::PositionXY(0, 0);
    const Board::PositionXY endThreat   = Board::PositionXY(5, 5);

    CHECK(beginThreat == threatLocation.m_ThreatDetails.m_BeginningThreat);
    CHECK(endThreat == threatLocation.m_ThreatDetails.m_EndThreat);
}

TEST(Threat4CaseATest, GetPieces1)
{
    // .xxxx.
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . x x x x . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|

    // 0. Define expectation.
    const Board::PositionXY elAsterix1   = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elAsterix2   = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap1       = Board::PositionXY(1, 3);
    const Board::PositionXY elGap2       = Board::PositionXY(1, 8);
    const Board::PositionXY elGap3       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap4       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap5       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap6       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap7       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap8       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap9       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap10      = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elX1         = Board::PositionXY(1, 4);
    const Board::PositionXY elX2         = Board::PositionXY(1, 5);
    const Board::PositionXY elX3         = Board::PositionXY(1, 6);
    const Board::PositionXY elX4         = Board::PositionXY(1, 7);
    const Board::PositionXY elX5         = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elO1         = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elO2         = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY beginning    = Board::PositionXY(1, 3);
    const Board::PositionXY end          = Board::PositionXY(1, 8);

    // 1. Create a threat.
    m_pGomokuBoard->PutMove(elX1, Board::PLAYER_A);
    m_pGomokuBoard->PutMove(elX2, Board::PLAYER_A);
    m_pGomokuBoard->PutMove(elX3, Board::PLAYER_A);
    m_pGomokuBoard->PutMove(elX4, Board::PLAYER_A);
    m_pThreatFinder->FindThreatPattern(elX1, ThreatFinder::HORIZONTAL, Board::PLAYER_A);

    // 2. Get elements.
    ThreatFinder::ThreatLocation threatLocation;
    m_pThreatFinder->GetThreatFields(threatLocation);

    // 3. Make verification.
    // a. Check '*':
    CHECK(elAsterix1 == threatLocation.m_ThreatDetails.m_Asterixes[0]);
    CHECK(elAsterix2 == threatLocation.m_ThreatDetails.m_Asterixes[1]);

    // b. Check 'x':
    CHECK(elX1 == threatLocation.m_ThreatDetails.m_MyPawns[0]);
    CHECK(elX2 == threatLocation.m_ThreatDetails.m_MyPawns[1]);
    CHECK(elX3 == threatLocation.m_ThreatDetails.m_MyPawns[2]);
    CHECK(elX4 == threatLocation.m_ThreatDetails.m_MyPawns[3]);
    CHECK(elX5 == threatLocation.m_ThreatDetails.m_MyPawns[4]);

    // c. Check '.':
    CHECK(elGap1 == threatLocation.m_ThreatDetails.m_Gaps[0]);
    CHECK(elGap2 == threatLocation.m_ThreatDetails.m_Gaps[1]);
    CHECK(elGap3 == threatLocation.m_ThreatDetails.m_Gaps[2]);
    CHECK(elGap4 == threatLocation.m_ThreatDetails.m_Gaps[3]);
    CHECK(elGap5 == threatLocation.m_ThreatDetails.m_Gaps[4]);
    CHECK(elGap6 == threatLocation.m_ThreatDetails.m_Gaps[5]);
    CHECK(elGap7 == threatLocation.m_ThreatDetails.m_Gaps[6]);
    CHECK(elGap8 == threatLocation.m_ThreatDetails.m_Gaps[7]);
    CHECK(elGap9 == threatLocation.m_ThreatDetails.m_Gaps[8]);
    CHECK(elGap10 == threatLocation.m_ThreatDetails.m_Gaps[9]);

    // d. Extend gaps:
    CHECK(elExtendGap1 == threatLocation.m_ThreatDetails.m_ExtGaps[0]);
    CHECK(elExtendGap2 == threatLocation.m_ThreatDetails.m_ExtGaps[1]);

    // d. Check 'o':
    CHECK(elO1 == threatLocation.m_ThreatDetails.m_EnemyPawns[0]);
    CHECK(elO2 == threatLocation.m_ThreatDetails.m_EnemyPawns[1]);

    // e. Check begin & end:
    CHECK(beginning == threatLocation.m_ThreatDetails.m_BeginningThreat);
    CHECK(end == threatLocation.m_ThreatDetails.m_EndThreat);
}

TEST(Threat4CaseATest, GetPieces2)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . x . . . . . . . . . .|
    // 2 |. . . x . . . . . . . . . . .|
    // 3 |. . x . . . . . . . . . . . .|
    // 4 |. x . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|

    // 0. Define expectation.
    const Board::PositionXY elAsterix1   = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elAsterix2   = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap1       = Board::PositionXY(0, 5);
    const Board::PositionXY elGap2       = Board::PositionXY(5, 0);
    const Board::PositionXY elGap3       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap4       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap5       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap6       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap7       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap8       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap9       = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elGap10      = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elX1         = Board::PositionXY(1, 4);
    const Board::PositionXY elX2         = Board::PositionXY(2, 3);
    const Board::PositionXY elX3         = Board::PositionXY(3, 2);
    const Board::PositionXY elX4         = Board::PositionXY(4, 1);
    const Board::PositionXY elX5         = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elO1         = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY elO2         = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
    const Board::PositionXY beginning    = Board::PositionXY(0, 5);
    const Board::PositionXY end          = Board::PositionXY(5, 0);

    // 1. Create a threat.
    m_pGomokuBoard->PutMove(elX1, Board::PLAYER_A);
    m_pGomokuBoard->PutMove(elX2, Board::PLAYER_A);
    m_pGomokuBoard->PutMove(elX3, Board::PLAYER_A);
    m_pGomokuBoard->PutMove(elX4, Board::PLAYER_A);
    m_pThreatFinder->FindThreatPattern(elX4, ThreatFinder::RISING, Board::PLAYER_A);

    // 2. Get elements.
    ThreatFinder::ThreatLocation threatLocation;
    m_pThreatFinder->GetThreatFields(threatLocation);

    // 3. Make verification.
    // a. Check '*':
    CHECK(elAsterix1 == threatLocation.m_ThreatDetails.m_Asterixes[0]);
    CHECK(elAsterix2 == threatLocation.m_ThreatDetails.m_Asterixes[1]);

    // b. Check 'x':
    CHECK(elX1 == threatLocation.m_ThreatDetails.m_MyPawns[0]);
    CHECK(elX2 == threatLocation.m_ThreatDetails.m_MyPawns[1]);
    CHECK(elX3 == threatLocation.m_ThreatDetails.m_MyPawns[2]);
    CHECK(elX4 == threatLocation.m_ThreatDetails.m_MyPawns[3]);
    CHECK(elX5 == threatLocation.m_ThreatDetails.m_MyPawns[4]);

    // c. Check '.':
    CHECK(elGap1 == threatLocation.m_ThreatDetails.m_Gaps[0]);
    CHECK(elGap2 == threatLocation.m_ThreatDetails.m_Gaps[1]);
    CHECK(elGap3 == threatLocation.m_ThreatDetails.m_Gaps[2]);
    CHECK(elGap4 == threatLocation.m_ThreatDetails.m_Gaps[3]);
    CHECK(elGap5 == threatLocation.m_ThreatDetails.m_Gaps[4]);
    CHECK(elGap6 == threatLocation.m_ThreatDetails.m_Gaps[5]);
    CHECK(elGap7 == threatLocation.m_ThreatDetails.m_Gaps[6]);
    CHECK(elGap8 == threatLocation.m_ThreatDetails.m_Gaps[7]);
    CHECK(elGap9 == threatLocation.m_ThreatDetails.m_Gaps[8]);
    CHECK(elGap10 == threatLocation.m_ThreatDetails.m_Gaps[9]);

    // d. Extend gaps:
    CHECK(elExtendGap1 == threatLocation.m_ThreatDetails.m_ExtGaps[0]);
    CHECK(elExtendGap2 == threatLocation.m_ThreatDetails.m_ExtGaps[1]);

    // d. Check 'o':
    CHECK(elO1 == threatLocation.m_ThreatDetails.m_EnemyPawns[0]);
    CHECK(elO2 == threatLocation.m_ThreatDetails.m_EnemyPawns[1]);

    // e. Check begin & end:
    CHECK(beginning == threatLocation.m_ThreatDetails.m_BeginningThreat);
    CHECK(end == threatLocation.m_ThreatDetails.m_EndThreat);
}

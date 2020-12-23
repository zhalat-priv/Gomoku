#include "Board.hpp"                // for Board definitions.
#include "Threat4CaseAA.hpp"
#include "GomokuBoard.hpp"
#include <assert.h>                 // for assert.
//----------------------------------------------------------
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "CppUTest/TestMemoryAllocator.h"
#include "CppUTest/MemoryLeakDetector.h"

TEST_GROUP(Threat4CaseAATest)
{
    void setup()
    {
        m_pGomokuBoard = new GomokuBoard( 15 );

		m_pThreatFinder = new Threat4CaseAA();
		m_pThreatFinder->SetBoard( m_pGomokuBoard );
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

TEST(Threat4CaseAATest,FindPatternOnHorizontalTrendTest1)
{
	// step by step build .XX.X. and verify if pattern is found.

	// a:   .X....
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// b:   .XX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   .XXX..
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   .XXX.X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 6 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 6 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat4CaseAATest,FindPatternOnHorizontalTrendTest2)
{
	// step by step build .XX.X. and verify if pattern is found.

	// a:   .X....
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// b:   .XX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   .XXX..
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   .XXXX.
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 5 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat4CaseAATest,FindPatternOnHorizontalTrendTest3)
{
	// a:   .X....
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	// b:   .XX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	// c:   .XXX..
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 4 ), Board::PLAYER_A );
	// d:   .XXX.X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 6 ), Board::PLAYER_A );
	// e:   .XXX.XO
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 6 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 6 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// a:   .X....
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 2 ), Board::PLAYER_A );
	// b:   .XX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 3 ), Board::PLAYER_A );
	// c:   .XXX..
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 4 ), Board::PLAYER_A );
	// d:   .XXX.X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 6 ), Board::PLAYER_A );
	// e:   .XXXOX.
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 5 ), Board::PLAYER_B );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 6 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat4CaseAATest,FindPatternOnHorizontalTrendTest4)
{
	//  state
	//                           1 1 1 1 1
	//       0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//       _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//    0 |. . . . . . . . . . . . . . .|
	//    1 |. . . . . . . . . . . . . . .|
	//    2 |. . . . x x x . x . . . . . .|
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 5 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 6 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 8 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 8 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat4CaseAATest,FindPatternAbbutedToFrameTest1)
{
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . o . . . . . . . . .|
	//2 |. . . . o . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |. . o . . . . . . . . . . . .|
	//5 |. o . . . . . . . . . . . . .|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|
	//8 |. . . . . . . . . . . . . . .|
	//9 |x . . . . . . . . . . . . . .|
	//10|. x . . . . . . . . . . . . .|
	//11|. . . . . . . . . . . . . . .|
	//12|. . . x . . . . . . . . . . .|
	//13|. . . . x . . . . . . . . . .|
	//14|. . . . . . . . . . . . . . .|
	//  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 5 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 4 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 2 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 5, 1 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 5 ), ThreatFinder::RISING, Board::PLAYER_B ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 4 ), ThreatFinder::RISING, Board::PLAYER_B ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 2 ), ThreatFinder::RISING, Board::PLAYER_B ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 5, 1 ), ThreatFinder::RISING, Board::PLAYER_B ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 9, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 10, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 12, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 13, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 9, 0 ), ThreatFinder::RISING, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 10, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 12, 3 ), ThreatFinder::RISING, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 13, 4 ), ThreatFinder::RISING, Board::PLAYER_A ) );
}

TEST(Threat4CaseAATest,GetPieces1)
{
	// .x.x.x.
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . . . . . . . . . . .|
	//2 |. . . x . x x x . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 2, 2 );
	const Board::PositionXY elGap2 = Board::PositionXY( 2, 4 );
	const Board::PositionXY elGap3 = Board::PositionXY( 2, 8 );
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 2, 3 );
	const Board::PositionXY elX2 = Board::PositionXY( 2, 5 );
	const Board::PositionXY elX3 = Board::PositionXY( 2, 6 );
	const Board::PositionXY elX4 = Board::PositionXY( 2, 7 );
	const Board::PositionXY elX5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 2, 2 );
	const Board::PositionXY end = Board::PositionXY( 2, 8 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX4, Board::PLAYER_A );
	m_pThreatFinder->FindThreatPattern( elX1, ThreatFinder::HORIZONTAL, Board::PLAYER_A );

	// 2. Get elements.
	ThreatFinder::ThreatLocation threatLocation;
	m_pThreatFinder->GetThreatFields( threatLocation );

	// 3. Make verification.
	// a. Check '*':
	CHECK( elAsterix1 == threatLocation.m_ThreatDetails.m_Asterixes[0] );
	CHECK( elAsterix2 == threatLocation.m_ThreatDetails.m_Asterixes[1] );

	// b. Check 'x':
	CHECK( elX1 == threatLocation.m_ThreatDetails.m_MyPawns[0] );
	CHECK( elX2 == threatLocation.m_ThreatDetails.m_MyPawns[1] );
	CHECK( elX3 == threatLocation.m_ThreatDetails.m_MyPawns[2] );
	CHECK( elX4 == threatLocation.m_ThreatDetails.m_MyPawns[3] );
	CHECK( elX5 == threatLocation.m_ThreatDetails.m_MyPawns[4] );

	// c. Check '.':
	CHECK( elGap1 == threatLocation.m_ThreatDetails.m_Gaps[0] );
	CHECK( elGap2 == threatLocation.m_ThreatDetails.m_Gaps[1] );
	CHECK( elGap3 == threatLocation.m_ThreatDetails.m_Gaps[2] );
	CHECK( elGap4 == threatLocation.m_ThreatDetails.m_Gaps[3] );
	CHECK( elGap5 == threatLocation.m_ThreatDetails.m_Gaps[4] );
	CHECK( elGap6 == threatLocation.m_ThreatDetails.m_Gaps[5] );
	CHECK( elGap7 == threatLocation.m_ThreatDetails.m_Gaps[6] );
	CHECK( elGap8 == threatLocation.m_ThreatDetails.m_Gaps[7] );
	CHECK( elGap9 == threatLocation.m_ThreatDetails.m_Gaps[8] );
	CHECK( elGap10 == threatLocation.m_ThreatDetails.m_Gaps[9] );

	// d. Extend gaps:
	CHECK( elExtendGap1 == threatLocation.m_ThreatDetails.m_ExtGaps[0] );
	CHECK( elExtendGap2 == threatLocation.m_ThreatDetails.m_ExtGaps[1] );

	// d. Check 'o':
	CHECK( elO1 == threatLocation.m_ThreatDetails.m_EnemyPawns[0] );
	CHECK( elO2 == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

TEST(Threat4CaseAATest,GetPieces2)
{
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . x . . . . . . . . .|
	//2 |. . . . x . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |. . x . . . . . . . . . . . .|
	//5 |. x . . . . . . . . . . . . .|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 0, 6 );
	const Board::PositionXY elGap2 = Board::PositionXY( 3, 3 );
	const Board::PositionXY elGap3 = Board::PositionXY( 6, 0 );
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elX2 = Board::PositionXY( 2, 4 );
	const Board::PositionXY elX3 = Board::PositionXY( 4, 2 );
	const Board::PositionXY elX4 = Board::PositionXY( 5, 1 );
	const Board::PositionXY elX5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 0, 6 );
	const Board::PositionXY end = Board::PositionXY( 6, 0 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX4, Board::PLAYER_A );
	m_pThreatFinder->FindThreatPattern( elX4, ThreatFinder::RISING, Board::PLAYER_A );

	// 2. Get elements.
	ThreatFinder::ThreatLocation threatLocation;
	m_pThreatFinder->GetThreatFields( threatLocation );

	// 3. Make verification.
	// a. Check '*':
	CHECK( elAsterix1 == threatLocation.m_ThreatDetails.m_Asterixes[0] );
	CHECK( elAsterix2 == threatLocation.m_ThreatDetails.m_Asterixes[1] );

	// b. Check 'x':
	CHECK( elX1 == threatLocation.m_ThreatDetails.m_MyPawns[0] );
	CHECK( elX2 == threatLocation.m_ThreatDetails.m_MyPawns[1] );
	CHECK( elX3 == threatLocation.m_ThreatDetails.m_MyPawns[2] );
	CHECK( elX4 == threatLocation.m_ThreatDetails.m_MyPawns[3] );
	CHECK( elX5 == threatLocation.m_ThreatDetails.m_MyPawns[4] );

	// c. Check '.':
	CHECK( elGap1 == threatLocation.m_ThreatDetails.m_Gaps[0] );
	CHECK( elGap2 == threatLocation.m_ThreatDetails.m_Gaps[1] );
	CHECK( elGap3 == threatLocation.m_ThreatDetails.m_Gaps[2] );
	CHECK( elGap4 == threatLocation.m_ThreatDetails.m_Gaps[3] );
	CHECK( elGap5 == threatLocation.m_ThreatDetails.m_Gaps[4] );
	CHECK( elGap6 == threatLocation.m_ThreatDetails.m_Gaps[5] );
	CHECK( elGap7 == threatLocation.m_ThreatDetails.m_Gaps[6] );
	CHECK( elGap8 == threatLocation.m_ThreatDetails.m_Gaps[7] );
	CHECK( elGap9 == threatLocation.m_ThreatDetails.m_Gaps[8] );
	CHECK( elGap10 == threatLocation.m_ThreatDetails.m_Gaps[9] );

	// d. Extend gaps:
	CHECK( elExtendGap1 == threatLocation.m_ThreatDetails.m_ExtGaps[0] );
	CHECK( elExtendGap2 == threatLocation.m_ThreatDetails.m_ExtGaps[1] );

	// d. Check 'o':
	CHECK( elO1 == threatLocation.m_ThreatDetails.m_EnemyPawns[0] );
	CHECK( elO2 == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

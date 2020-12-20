#include "Board.hpp"                // for Board definitions.
#include "Threat2CaseAA.hpp"
#include "GomokuBoard.hpp"
#include <assert.h>                 // for assert.
//----------------------------------------------------------
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "CppUTest/TestMemoryAllocator.h"
#include "CppUTest/MemoryLeakDetector.h"

TEST_GROUP(Threat2CaseAATest)
{
    void setup()
    {
        m_pGomokuBoard = new GomokuBoard( 15 );

		m_pThreatFinder = new Threat2CaseAA();
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

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest1)
{
	// Testing of each position: .X...X.

	//	                       1 1 1 1 1
	//	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//	0 |. . . . . . . . . . . . . . .|
	//	1 |. . . x . . . x . . . . . . .|
	//	2 |. . . . . . . . . . . . . . .|
	//	3 |. . . . . . . . . . . . . . .|

	// a:   .X.....
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// b:   .X...X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 7 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 7 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest2)
{
	// Testing of each position: .XX....

	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . x x . . . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	//    .XX....
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest3)
{
	// Testing of each position: .X.X...

	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . x . x . . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	//    .X.X...
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 5 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest4)
{
	// Testing of each position: .X..X..

	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . x . . x . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	//    .X..X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 6 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 6 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest5)
{
	// Testing of each position: .X....X.
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . x . . . . x . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	//    .X....X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 8 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 8 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest6)
{
	// Testing of each position: .OX...X.

	//	                       1 1 1 1 1
	//	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//	0 |. . . . . . . . . . . . . . .|
	//	1 |. . o x . . . x . . . . . . .|
	//	2 |. . . . . . . . . . . . . . .|
	//	3 |. . . . . . . . . . . . . . .|


	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 2 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 7 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 7 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,FindPatternOnHorizontalTrendTest7)
{
	// Testing of each position: .XO..X.

	//	                       1 1 1 1 1
	//	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//	0 |. . . . . . . . . . . . . . .|
	//	1 |. . . x o . . x . . . . . . .|
	//	2 |. . . . . . . . . . . . . . .|
	//	3 |. . . . . . . . . . . . . . .|


	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 7 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 7 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat2CaseAATest,GetPieces1)
{
	// .x...x.
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . . . . . . . . . . .|
	//2 |. . . x . . . x . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 2, 2 );
	const Board::PositionXY elGap2 = Board::PositionXY( 2, 4 );
	const Board::PositionXY elGap3 = Board::PositionXY( 2, 5 );
	const Board::PositionXY elGap4 = Board::PositionXY( 2, 6 );
	const Board::PositionXY elGap5 = Board::PositionXY( 2, 8 );
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = Board::PositionXY( 2, 5 );
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 2, 3 );
	const Board::PositionXY elX2 = Board::PositionXY( 2, 7 );
	const Board::PositionXY elX3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 2, 2 );
	const Board::PositionXY end = Board::PositionXY( 2, 8 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
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

TEST(Threat2CaseAATest,GetPieces2)
{
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . x . . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |. . . . . . . . . . . . . . .|
	//5 |. x . . . . . . . . . . . . .|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 0, 6 );
	const Board::PositionXY elGap2 = Board::PositionXY( 2, 4 );
	const Board::PositionXY elGap3 = Board::PositionXY( 3, 3 );
	const Board::PositionXY elGap4 = Board::PositionXY( 4, 2 );
	const Board::PositionXY elGap5 = Board::PositionXY( 6, 0 );
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = Board::PositionXY( 3, 3 );
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elX2 = Board::PositionXY( 5, 1 );
	const Board::PositionXY elX3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 0, 6 );
	const Board::PositionXY end = Board::PositionXY( 6, 0 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pThreatFinder->FindThreatPattern( elX2, ThreatFinder::RISING, Board::PLAYER_A );

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


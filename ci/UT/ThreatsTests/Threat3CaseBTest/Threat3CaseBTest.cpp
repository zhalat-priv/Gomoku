#include "Board.hpp"                // for Board definitions.
#include "Threat3CaseB.hpp"
#include "GomokuBoard.hpp"
#include <assert.h>                 // for assert.
//----------------------------------------------------------
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "CppUTest/TestMemoryAllocator.h"
#include "CppUTest/MemoryLeakDetector.h"

TEST_GROUP(Threat3CaseBTest)
{
    void setup()
    {
        m_pGomokuBoard = new GomokuBoard( 15 );

		m_pThreatFinder = new Threat3CaseB();
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

TEST(Threat3CaseBTest,FindPatternOnHorizontalTrendTest1)
{
	// Testing of each position: OXXX..

	// a:   O.....
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 1 ), Board::PLAYER_B );

	// b:   OX....
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   OXX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   OXXX..
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternOnHorizontalTrendTest2)
{
	// Testing of each position: OXX.X.

	// a:   O.....
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 1 ), Board::PLAYER_B );

	// b:   OX....
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   OXX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   OXX.X.
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 5 ), Board::PLAYER_A );

	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternOnHorizontalTrendTest3)
{
	// Testing of each position: OX.XX.

	// a:   O.....
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 1 ), Board::PLAYER_B );

	// b:   OX....
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   OX.X..
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   OX.XX.
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 5 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternOnHorizontalTrendTest4)
{
	// Testing of each position: ..XXXO

	// a:   .....O
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 6 ), Board::PLAYER_B );

	// b:   ....XO
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   ...XXO
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   ..XXXO
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 5 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternOnHorizontalTrendTest5)
{
	// Testing of each position: .X.XXO

	// a:   .....O
	m_pGomokuBoard->PutMove( Board::PositionXY( 5, 6 ), Board::PLAYER_B );

	// b:   ....XO
	m_pGomokuBoard->PutMove( Board::PositionXY( 5, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 5, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   ...XXO
	m_pGomokuBoard->PutMove( Board::PositionXY( 5, 4 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 5, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   .X.XXO
	m_pGomokuBoard->PutMove( Board::PositionXY( 5, 5 ), Board::PLAYER_A );

	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 5, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternOnHorizontalTrendTest6)
{
	// Testing of each position: .XX.XO

	// a:   .....O
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 6 ), Board::PLAYER_B );

	// b:   ....XO
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   ..X.XO
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 3 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 3 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   .XX.XO
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 5 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,SkipFalsePattern1)
{
//	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
//	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	0 |. . . . . . . . . . . . . . .|
//	1 |. . . . . . . . . . . . . . .|
//	2 |. . . . . . . . . . . . . . .|
//	3 |. . . . . . . . . . . . . . .|
//	4 |. o x x x o . . . . . . . . .|

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 1 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 5 ), Board::PLAYER_B );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest1)
{
	// Testing abutted to frame: OXXX..

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 0 ), ThreatFinder::RISING, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 4 ), ThreatFinder::RISING, Board::PLAYER_A) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest2)
{
	// Testing abutted to frame: OXX.X.

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 0 ), ThreatFinder::RISING, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest3)
{
	// Testing abutted to frame: OX.XX.

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 0 ), ThreatFinder::RISING, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest4)
{
	// Testing abutted to frame: ..XXXO

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 0 ), ThreatFinder::RISING, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 2 ), ThreatFinder::RISING, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest5)
{
	// Testing abutted to frame: .X.XXO

	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 4 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 3 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest6)
{
	// Testing abutted to frame: .XX.XO

	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 4 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 3, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 3, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 0, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 1 ), ThreatFinder::RISING, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternAbuttedToBoardTest7)
{
	// Testing abutted to frame: OX..XX

	// a:   O.....
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 1 ), Board::PLAYER_B );

	// b:   OX....
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 2 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// c:   OXX...
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 5 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	// d:   OXXX..
	m_pGomokuBoard->PutMove( Board::PositionXY( 1,6 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 6 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,FindPatternSixInRowTest1)
{
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |x x x . x o . . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |x x x . . x . . . . . . . . .|
	//4 |x x x . . o . . . o x . x x x|
	//5 |. . . . . . . . . . . . . . .|
	//6 |. . . . . . . . . x . . x x x|
	//7 |. . . . . . . . . o . . x x x|
	//8 |. . . . . . . . . . . . . . .|
	//9 |. . . . . . . . . . . . . . .|
	//10|. . . . . . . . . . . . . . .|
	//11|. . . . . . . . . . . . . . .|
	//12|. . . . . . . . . . . . . . .|
	//13|. . . . . . . . . . . . . . .|
	//14|. . . . . . . . . . . . . . .|
	//  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 4 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 1, 5 ), Board::PLAYER_B );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 0 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 1 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 1, 4 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 2, 5 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 0 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 1 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 2, 5 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 0 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 1 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 2 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 5 ), Board::PLAYER_B );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 0 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 1 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 2 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 10 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 12 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 13 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 14 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 4, 9 ), Board::PLAYER_B );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 10 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 12 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 13 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 4, 14 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 9 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 12 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 13 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 6, 14 ), Board::PLAYER_A );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 9 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 12 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 13 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_FALSE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 6, 14 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );

	m_pGomokuBoard->PutMove( Board::PositionXY( 7, 9 ), Board::PLAYER_B );
	m_pGomokuBoard->PutMove( Board::PositionXY( 7, 12 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 7, 13 ), Board::PLAYER_A );
	m_pGomokuBoard->PutMove( Board::PositionXY( 7, 14 ), Board::PLAYER_A );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 7, 12 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 7, 13 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
	CHECK_TRUE( m_pThreatFinder->FindThreatPattern( Board::PositionXY( 7, 14 ), ThreatFinder::HORIZONTAL, Board::PLAYER_A ) );
}

TEST(Threat3CaseBTest,GetPieces1)
{
	// oxxx..*
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . o x x x . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = Board::PositionXY( 1, 10 );
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 1, 8 );
	const Board::PositionXY elGap2 = Board::PositionXY( 1, 9 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = Board::PositionXY( 1, 9 );
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elX2 = Board::PositionXY( 1, 6 );
	const Board::PositionXY elX3 = Board::PositionXY( 1, 7 );
	const Board::PositionXY elO1 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 1, 4 );
	const Board::PositionXY end = Board::PositionXY( 1, 10 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elO1, Board::PLAYER_B );
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

TEST(Threat3CaseBTest,GetPieces2)
{
	// oxx..xo
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . o x x . . x o . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = Board::PositionXY( 1, 10 );
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 1, 7 );
	const Board::PositionXY elGap2 = Board::PositionXY( 1, 8 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
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
	const Board::PositionXY elX2 = Board::PositionXY( 1, 6 );
	const Board::PositionXY elX3 = Board::PositionXY( 1, 9 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elO2 = Board::PositionXY( 1, 10 );
	const Board::PositionXY beginning = Board::PositionXY( 1, 4 );
	const Board::PositionXY end = Board::PositionXY( 1, 10 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elO1, Board::PLAYER_B );
	m_pGomokuBoard->PutMove( elO2, Board::PLAYER_B );
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
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

TEST(Threat3CaseBTest,GetPieces3)
{
	// |x.x.x*
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |x . x . x * . . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 1, 1 );
	const Board::PositionXY elGap2 = Board::PositionXY( 1, 3 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 0 );
	const Board::PositionXY elX2 = Board::PositionXY( 1, 2 );
	const Board::PositionXY elX3 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 1, 0 );
	const Board::PositionXY end = Board::PositionXY( 1, 5 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
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

TEST(Threat3CaseBTest,GetPieces4)
{
	// |xx..xo
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |x x . . x o . . . . . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 1, 2 );
	const Board::PositionXY elGap2 = Board::PositionXY( 1, 3 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 0 );
	const Board::PositionXY elX2 = Board::PositionXY( 1, 1 );
	const Board::PositionXY elX3 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 1, 0 );
	const Board::PositionXY end = Board::PositionXY( 1, 5 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elO1, Board::PLAYER_B );
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
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[0] );
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

TEST(Threat3CaseBTest,GetPieces5)
{
	// |x.xx.|
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . x . . . . . . . . . . .|
	//2 |. . x . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |x . . . . . . . . . . . . . .|
	//5 |. . . . . . . . . . . . . . .|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|
	//8 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 0, 4 );
	const Board::PositionXY elGap2 = Board::PositionXY( 3, 1 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 3 );
	const Board::PositionXY elX2 = Board::PositionXY( 2, 2 );
	const Board::PositionXY elX3 = Board::PositionXY( 4, 0 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 0, 4 );
	const Board::PositionXY end = Board::PositionXY( 4, 0 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pThreatFinder->FindThreatPattern( elX1, ThreatFinder::RISING, Board::PLAYER_A );

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
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[0] );
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

TEST(Threat3CaseBTest,GetPieces6)
{
	// |.xx.xo
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . . . . . . x . . . .|
	//2 |. . . . . . . . . . . x . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |. . . . . . . . . . . . . x .|
	//5 |. . . . . . . . . . . . . . o|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|
	//8 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 0, 9 );
	const Board::PositionXY elGap2 = Board::PositionXY( 3, 12 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 10 );
	const Board::PositionXY elX2 = Board::PositionXY( 2, 11 );
	const Board::PositionXY elX3 = Board::PositionXY( 4, 13 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = Board::PositionXY( 5, 14 );
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 0, 9 );
	const Board::PositionXY end = Board::PositionXY( 5, 14 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elO1, Board::PLAYER_B );
	m_pThreatFinder->FindThreatPattern( elX1, ThreatFinder::FALLING, Board::PLAYER_A );

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
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

TEST(Threat3CaseBTest,GetPieces7)
{
	//  *xx..xo
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . x x . . x o . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |. . . . . . . . . . . . . . .|
	//5 |. . . . . . . . . . . . . . .|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|
	//8 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = Board::PositionXY( 1, 3 );
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 1, 6 );
	const Board::PositionXY elGap2 = Board::PositionXY( 1, 7 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elX2 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elX3 = Board::PositionXY( 1, 8 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = Board::PositionXY( 1, 9 );
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 1, 3 );
	const Board::PositionXY end = Board::PositionXY( 1, 9 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elO1, Board::PLAYER_B );
	m_pThreatFinder->FindThreatPattern( elX3, ThreatFinder::HORIZONTAL, Board::PLAYER_A );

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
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}

TEST(Threat3CaseBTest,GetPieces8)
{
	//  *xx..xo
	//                       1 1 1 1 1
	//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
	//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//0 |. . . . . . . . . . . . . . .|
	//1 |. . . . . . x x x o . . . . .|
	//2 |. . . . . . . . . . . . . . .|
	//3 |. . . . . . . . . . . . . . .|
	//4 |. . . . . . . . . . . . . . .|
	//5 |. . . . . . . . . . . . . . .|
	//6 |. . . . . . . . . . . . . . .|
	//7 |. . . . . . . . . . . . . . .|
	//8 |. . . . . . . . . . . . . . .|

	// 0. Define expectation.
	const Board::PositionXY elAsterix1 = Board::PositionXY( 1, 3 );
	const Board::PositionXY elAsterix2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap1 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elGap2 = Board::PositionXY( 1, 5 );
	const Board::PositionXY elGap3 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap5 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap6 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap7 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap8 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap9 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elGap10 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elExtendGap1 = Board::PositionXY( 1, 4 );
	const Board::PositionXY elExtendGap2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elX1 = Board::PositionXY( 1, 6 );
	const Board::PositionXY elX2 = Board::PositionXY( 1, 7 );
	const Board::PositionXY elX3 = Board::PositionXY( 1, 8 );
	const Board::PositionXY elX4 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY elO1 = Board::PositionXY( 1, 9 );
	const Board::PositionXY elO2 = ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD;
	const Board::PositionXY beginning = Board::PositionXY( 1, 3 );
	const Board::PositionXY end = Board::PositionXY( 1, 9 );

	// 1. Create a threat.
	m_pGomokuBoard->PutMove( elX1, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX2, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elX3, Board::PLAYER_A );
	m_pGomokuBoard->PutMove( elO1, Board::PLAYER_B );
	m_pThreatFinder->FindThreatPattern( elX3, ThreatFinder::HORIZONTAL, Board::PLAYER_A );

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
	CHECK( ThreatFinder::ThreatLocation::XY_OUT_OF_BOARD == threatLocation.m_ThreatDetails.m_EnemyPawns[1] );

	// e. Check begin & end:
	CHECK( beginning == threatLocation.m_ThreatDetails.m_BeginningThreat );
	CHECK( end == threatLocation.m_ThreatDetails.m_EndThreat );
}


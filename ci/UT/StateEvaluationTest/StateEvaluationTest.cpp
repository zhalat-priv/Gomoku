#include "GomokuBoard.hpp"
#include "StateEvaluation.hpp"
#include "BoardScore.hpp"
#include "Score.hpp"
//----------------------------------------------------------
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "CppUTest/TestMemoryAllocator.h"
#include "CppUTest/MemoryLeakDetector.h"

TEST_GROUP(StateEvaluationTest)
{
   public:
    void setup()
    {
        m_pGomokuBoard     = new GomokuBoard(15);
        m_pScore           = Score::GetInstance();
        m_pStateEvaluation = StateEvaluation::GetInstance();
    };

    void teardown() { delete m_pGomokuBoard; };

    GomokuBoard* m_pGomokuBoard;
    Score* m_pScore{};
    StateEvaluation* m_pStateEvaluation{};
};

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest1)
{
    // HEAD SHOT 4BC: (5,9)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . o x x x . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot4BC = Board::PositionXY(5, 9);

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest2)
{
    // HEAD SHOT 4BC: (5,9)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . o x x x . . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot4BC = Board::PositionXY(5, 9);

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest3)
{
    // HEAD SHOT 4BC: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . o x x x . . . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    // CheckWinnerMoveCondition  == true
    Board::PositionXY headShot4BCResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest4)
{
    // HEAD SHOT 4BC: (2,2)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . x . . . . . . . . . .|
    // 1 |. . . x . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . x . . . . . . . . . . .|
    // 4 |x . . . x . . . . . . . . . .|
    // 5 |. . . . . x . . . . . . . . .|
    // 6 |. . . . . . o . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(0, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot4BC = Board::PositionXY(2, 2);

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest5)
{
    // HEAD SHOT 4BC: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . x x . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none
    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest6)
{
    // HEAD SHOT 4BC: for checkWinnerMoveCondition == false:  (5,9)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. o . . . . . . . . . . . . .|
    // 1 |. o . . . . . . . . . . . . .|
    // 2 |. o . . . . . . . . . . . . .|
    // 3 |. o . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . x x . x o . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. x x x x . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(11, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(11, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(11, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(11, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY double3A = Board::PositionXY(5, 9);

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest7)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. o x x x . . x x x o . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none.

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest8)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. o x x x . . . . x x x o . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);

    // Get singletons.
    Score* m_pScore                     = Score::GetInstance();
    StateEvaluation* m_pStateEvaluation = StateEvaluation::GetInstance();
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none.

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot4BCPossibleTest9)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. o x x x . . . x x x o . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot4BC = Board::PositionXY(3, 6);

    Board::PositionXY headShot4BCResult;

    // CheckWinnerMoveCondition  == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot4BCPossible(true, headShot4BCResult, false));
    CHECK(headShot4BCResult == headShot4BC);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot4BCPossible(false, headShot4BCResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest1)
{
    // HEAD SHOT 3A: (4,9)

    //	.                      1 1 1 1 1
    //	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    //	0 |x . . . . . . . . . . . . . .|
    //	1 |x . . . . . . . . . . . . . .|
    //	2 |x . . . . . . . . . . . . . .|
    //	3 |x . . . . . . . . . . . . . .|
    //	4 |. . . . . . . x x . . . . . .|
    //	5 |. . . . . . . . . . . . . . .|
    //	6 |. . . . . . . . . x . . . . .|
    //	7 |. . . . . . . . . x . . . . .|
    //	8 |. . . . . . . . . x . . . . .|
    //	9 |. . . . . . . . . o . . . . .|
    //	10|. . . . . . . . . . . . . . .|
    //	11|. . . . . . . . . . . . . . .|
    //	12|. . . . . . . . x x x . . . .|
    //	13|. . . . . . . . . . . . . . .|
    //	14|. . . . . . . . . . . . . . .|
    //	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);

    // Get singletons.
    Score* m_pScore                     = Score::GetInstance();
    StateEvaluation* m_pStateEvaluation = StateEvaluation::GetInstance();
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(12, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(12, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(12, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(4, 9);

    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest2)
{
    // HEAD SHOT 3A: (2,2)

    //                      1 1 1 1 1
    //  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . x . . . . . . . . . .|
    // 1 |. x . x . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . x . . . . . . . . . . .|
    // 4 |x . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(0, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(2, 2);

    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest3)
{
    // HEAD SHOT 3A: none

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . x x . . . . . . .|
    // 5 |. . . . . . . . . . o o o . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest4)
{
    // HEAD SHOT 3A: (2,7)

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . x . . . . . . .|
    // 1 |. . . . . . . x . . . . . . .|
    // 2 |. . . . . x x . . . . . . . .|
    // 3 |. . . . . . . x . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(0, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(2, 7);

    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest5)
{
    // HEAD SHOT 3A: (4,9)

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . x . .|
    // 2 |. . . . . . . . . . . x . . .|
    // 3 |. . . . . . . . . . x . . . .|
    // 4 |. . . . . . x x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(4, 9);

    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest6)
{
    // HEAD SHOT 3A: none

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . x x . . . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none
    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest7)
{
    // HEAD SHOT 3A: none

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . x . x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest8)
{
    // HEAD SHOT 3A: (4,9)

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . x x . . . . . .|
    // 5 |. . . . . . . x o . o o . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(4, 9);

    Board::PositionXY headShot3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest9)
{
    // HEAD SHOT 3A: (5,9)

    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . x x . . . . . . . .|
    // 5 |. . . . . . . . . . x x . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(5, 9);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest10)
{
    // HEAD SHOT 3A: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . o . . . .|
    // 4 |. . . . . x x . . . . . . . .|
    // 5 |. . . . . . . . o . x x . . .|
    // 6 |. . . . . . . o . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // None

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest11)
{
    // HEAD SHOT 3A: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . o . .|
    // 2 |. . . . . . . . . . . o . . .|
    // 3 |. . . . . . . . . . o . . . .|
    // 4 |. . . . . x x . . . . . . . .|
    // 5 |. . . . . . . . . . x x . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // None

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest12)
{
    // HEAD SHOT 3A: (5,9)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . o . .|
    // 3 |. . . . . . . . . . . o . . .|
    // 4 |. . . . . x x . . . o . . . .|
    // 5 |. . . . . . . . . . x x . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . x . . . . .|
    // 8 |. . . . . . . . . x . . . . .|
    // 9 |. . . . . . . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(5, 9);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest13)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . x x . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . o . x . . . . .|
    // 8 |. . . . . . o . . x . . . . .|
    // 9 |. . . . . o . . . o . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3A = Board::PositionXY(4, 9);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3A);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest14)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . x . . . . . . .|
    // 4 |. . . . . . . x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . x . x . x . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest15)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . o x x x . . . x x . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3APossibleTest16)
{
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . x . x . x . x x . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3APossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest1)
{
    // HEAD SHOT 3AA: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //	 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . x . . . .|
    // 3 |. . . . . . . . . x . . . . .|
    // 4 |. . . . . . x x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . x . . . . . . . . . . .|
    // 7 |. . . x . . . . . . . . . . .|
    // 8 |. . . x . . . . . . . . . . .|
    // 9 |. . . o . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest2)
{
    // HEAD SHOT 3AA: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . x . . . .|
    // 3 |. . . . . . . . . x . . . . .|
    // 4 |. . . . . . x x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . x . . . . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . . x . . . . . . . . . .|
    // 9 |. . . . o . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest3)
{
    // HEAD SHOT 3AA: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . x x . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . o x . x . . . . . . . .|
    // 7 |. . . . x . x . . . . . . . .|
    // 8 |. . . . x . o . . . . . . . .|
    // 9 |. . . . o . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest4)
{
    // HEAD SHOT 3AA: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . x x . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . x . x . . . . . . . .|
    // 7 |. . . . x . x . . . . . . . .|
    // 8 |. . . . o . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest5)
{
    // HEAD SHOT 3AA: (4,4)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . x . . . . . . . .|
    // 3 |. . . . . . x . . . . . . . .|
    // 4 |. . . . . . . x x . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . x . . . . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . . x . . . . . . . . . .|
    // 9 |. . . . o . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . x x x . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(13, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(13, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(13, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3AA = Board::PositionXY(4, 4);

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult, true));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3AA);

    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult, true));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult, false));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest6)
{
    // HEAD SHOT 3AA: (4,4)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . x . . . . . . . .|
    // 3 |. . . . . . x . . . . . . . .|
    // 4 |. . . . . . . x x . . . . . .|
    // 5 |. . . . x . . . . . . . . . .|
    // 6 |. . . . x . . . . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . . o . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3AA = Board::PositionXY(4, 4);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3AA);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));

    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3AA);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult, false));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest7)
{
    // HEAD SHOT 3AA: (4,4)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . x . . . . . . . . . .|
    // 4 |. . . . . . x . x . . . . . .|
    // 5 |. . . . x . x . . . . . . . .|
    // 6 |. . . . x . . . . . . . . . .|
    // 7 |. . . . o . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY headShot3AA = Board::PositionXY(4, 4);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK(headShot3AResult == headShot3AA);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));

    CHECK_TRUE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult, false));
    CHECK(headShot3AResult == headShot3AA);
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult, false));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest8)
{
    // HEAD SHOT 3AA: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . x . . . . . . . .|
    // 2 |. . . . . . x . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . x x . . . . . .|
    // 6 |. . . . x . . . . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . . x . . . . . . . . . .|
    // 9 |. . . . o . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(1, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none
    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));
};

TEST(StateEvaluationTest, IsHeadShot3AAPossibleTest9)
{
    // HEAD SHOT 3AA: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . x . . . . . . . .|
    // 4 |. o o o . . x . . . . . . . .|
    // 5 |. . . . . . . x x . . . . . .|
    // 6 |. . . . x . . . . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . . x . . . . . . . . . .|
    // 9 |. . . . o . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShot3AAPossible(false, headShot3AResult, false));
};

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest1)
{
    // HEAD SHOT dragon: (5,6)/(8,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . o . . . . . . . . . .|
    // 6 |. . . . . x x o . . . . . . .|
    // 7 |. . . . . o x o . . . . . . .|
    // 8 |. . . . . x x x o . . . . . .|
    // 9 |. . . . . . o . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    const Board::PositionXY dragonSoot1 = Board::PositionXY(5, 6);
    const Board::PositionXY dragonSoot2 = Board::PositionXY(8, 3);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
};

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest2)
{
    // HEAD SHOT dragon: (5,6)/(8,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . x . . . . . . . .|
    // 5 |. . . . o . . . . . . . . . .|
    // 6 |. . . . . x . o . . . . . . .|
    // 7 |. . . . . o x o . . . . . . .|
    // 8 |. . . . . x x x o . . . . . .|
    // 9 |. . . . . . o . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    const Board::PositionXY dragonSoot1 = Board::PositionXY(5, 6);
    const Board::PositionXY dragonSoot2 = Board::PositionXY(8, 3);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest3)
{
    // HEAD SHOT dragon: (6,7)/(7,6)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . o . . . . . . . .|
    // 5 |. . . . . . x . . . . . . . .|
    // 6 |. . . . o x x . x . . . . . .|
    // 7 |. . . . o o . . . . . . . . .|
    // 8 |. . . . . x . . . . . . . . .|
    // 9 |. . . . . . x . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    const Board::PositionXY dragonSoot1 = Board::PositionXY(6, 7);
    const Board::PositionXY dragonSoot2 = Board::PositionXY(7, 6);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest4)
{
    // HEAD SHOT dragon: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . o . . . . . . .|
    // 5 |. . . . o . . . . . . . . . .|
    // 6 |. . . . . x x . . . . . . . .|
    // 7 |. . . . . o x o . . . . . . .|
    // 8 |. . . . . x x x o . . . . . .|
    // 9 |. . . . . . o . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest5)
{
    // 2. Put movies to the board.
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . o o . .|
    // 4 |. . . . . . . . . . . x . . .|
    // 5 |. . . . . . . . . . x x . . .|
    // 6 |. . . . . . o x o x o x . . .|
    // 7 |. . . . . . o x x x o x . . .|
    // 8 |. . . o x x x o x o x o . . .|
    // 9 |. . o . . o o x x o x . . . .|
    // 10|. . . . . x o o o . x . . . .|
    // 11|. . . . . . . . . . o . . . .|
    // 12|. . . . . . . . . o . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    vector<Board::PositionXY> xyListCpu{
        Board::PositionXY(7, 7),   Board::PositionXY(7, 9),  Board::PositionXY(8, 8),  Board::PositionXY(9, 7),
        Board::PositionXY(5, 11),  Board::PositionXY(6, 7),  Board::PositionXY(9, 8),  Board::PositionXY(8, 6),
        Board::PositionXY(10, 5),  Board::PositionXY(8, 10), Board::PositionXY(8, 5),  Board::PositionXY(8, 4),
        Board::PositionXY(10, 10), Board::PositionXY(9, 10), Board::PositionXY(7, 8),  Board::PositionXY(7, 11),
        Board::PositionXY(6, 11),  Board::PositionXY(4, 11), Board::PositionXY(5, 10), Board::PositionXY(6, 9)};

    vector<Board::PositionXY> xyHuman{
        Board::PositionXY(6, 8),  Board::PositionXY(7, 6),   Board::PositionXY(6, 6),  Board::PositionXY(10, 6),
        Board::PositionXY(6, 10), Board::PositionXY(8, 7),   Board::PositionXY(9, 6),  Board::PositionXY(10, 8),
        Board::PositionXY(9, 9),  Board::PositionXY(10, 7),  Board::PositionXY(9, 5),  Board::PositionXY(8, 3),
        Board::PositionXY(9, 2),  Board::PositionXY(11, 10), Board::PositionXY(8, 9),  Board::PositionXY(7, 10),
        Board::PositionXY(8, 11), Board::PositionXY(3, 11),  Board::PositionXY(12, 9), Board::PositionXY(3, 12),
    };

    for(uint32_t i = 0; i < xyListCpu.size(); ++i)
    {
        m_pGomokuBoard->PutMove(xyListCpu[i], boardScoreComputer.GetPlayer());
        m_pScore->UpdateScore(boardScoreComputer, xyListCpu[i]);
        m_pScore->UpdateScore(boardScoreHuman, xyListCpu[i]);

        m_pGomokuBoard->PutMove(xyHuman[i], boardScoreHuman.GetPlayer());
        m_pScore->UpdateScore(boardScoreComputer, xyHuman[i]);
        m_pScore->UpdateScore(boardScoreHuman, xyHuman[i]);
    }

    // Dragon shot:
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest6)
{
    // HEAD SHOT dragon: none
    //	                   1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . o . . . . . . . . . . .|
    // 3 |. . . o x x x . . . . . . . .|
    // 4 |. . o . . o o x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    // none
    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest7)
{
    // HEAD SHOT dragon: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . o . . . . . x . . . . .|
    // 3 |. . . o x x x o x o x . . . .|
    // 4 |. . o . . o o x x o x . . . .|
    // 5 |. . . . . x o o o . x . . . .|
    // 6 |. . . . . . . . x . o . . . .|
    // 7 |. . . . . . . . . o . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(2, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    // none
    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsHeadShotDragonPossibleTest8)
{
    // HEAD SHOT dragon: (5,6)/(8,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . x .|
    // 5 |. . . . o . . . . . . . . x .|
    // 6 |. . . . . x x o . . . . . x .|
    // 7 |. . . . . o x o . . . . . x .|
    // 8 |. . . . . x x x o . . . . o .|
    // 9 |. . . . . . o . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.

    newMove = Board::PositionXY(4, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Dragon shot:
    const Board::PositionXY dragonSoot1 = Board::PositionXY(5, 6);
    const Board::PositionXY dragonSoot2 = Board::PositionXY(8, 3);

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotDragonPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == dragonSoot1) || (headShot3AResult == dragonSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotDragonPossible(false, headShot3AResult, false));
};

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest1)
{
    // Lizard shot: (4,4)/(7,7)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . o x . . . . . . . . .|
    // 7 |. . . x o o o . . . . . . . .|
    // 8 |. . . . o x o . . . . . . . .|
    // 9 |. . . x x . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_B);
    BoardScore boardScoreHuman(Board::PLAYER_A);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot:
    const Board::PositionXY lizardSoot1 = Board::PositionXY(4, 4);
    const Board::PositionXY lizardSoot2 = Board::PositionXY(7, 7);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == lizardSoot1) || (headShot3AResult == lizardSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest2)
{
    // Lizard shot: (6,7)/(6,9)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . o x o . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . x o x o x . . . .|
    // 8 |. . . . . x . . . . . x . . .|
    // 9 |. . . . x . . . . . . . x . .|
    // 10|. . . o . . . . . . . . . o .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(10, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(10, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot.
    const Board::PositionXY lizardSoot1 = Board::PositionXY(6, 7);
    const Board::PositionXY lizardSoot2 = Board::PositionXY(6, 9);

    Board::PositionXY headShot3AResult;
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == lizardSoot1) || (headShot3AResult == lizardSoot2));
    CHECK_TRUE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest3)
{
    // Lizard shot: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . o o . . . . . . . . . .|
    // 3 |. . . x o . . . . . . . . . .|
    // 4 |. . . . o . . x . . . . . . .|
    // 5 |. . . . . . x . . . . . . . .|
    // 6 |. . . x o . . . . . . . . . .|
    // 7 |. . . x . . . x x x o . . . .|
    // 8 |. . . o o . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot.
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest4)
{
    // Lizard shot: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . o . . . . . . . . . .|
    // 1 |. . . . o . . . . . . . . . .|
    // 2 |. . . o o . . . . . . . . . .|
    // 3 |. . . x o . . . . . . . . . .|
    // 4 |. . . . o . . x . . . . . . .|
    // 5 |. . . . . . x . . . . . . . .|
    // 6 |. . . x o . o o o o o . . . .|
    // 7 |. . . x o . . x x x o . . . .|
    // 8 |. . . o o . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot.
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest5)
{
    // Lizard shot: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . o . . . . . . .|
    // 5 |. . . . o . . . . . . . . . .|
    // 6 |. . . . . x x . . . . . . . .|
    // 7 |. . . . . o x o . . . . . . .|
    // 8 |. . . . . x x x o . . . . . .|
    // 9 |. . . . . . o . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot.
    // none

    Board::PositionXY headShot3AResult;
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest6)
{
    // Lizard shot: (4,4)/(7,7)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . x o o o . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . o .|
    // 5 |. . . . . . . . . . . . . o .|
    // 6 |. . . . o x . . . . . . . o .|
    // 7 |. . . x o o o . . . . . . x .|
    // 8 |. . . . o x o . . . . . . . .|
    // 9 |. . . x x . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_B);
    BoardScore boardScoreHuman(Board::PLAYER_A);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 13);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot:
    const Board::PositionXY lizardSoot1 = Board::PositionXY(4, 4);
    const Board::PositionXY lizardSoot2 = Board::PositionXY(7, 7);

    Board::PositionXY headShot3AResult;

    CHECK_TRUE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK((headShot3AResult == lizardSoot1) || (headShot3AResult == lizardSoot2));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult));
}

TEST(StateEvaluationTest, IsHeadShotLizardPossibleTest7)
{
    // Lizard shot: none
    //                         1 1 1 1 1
    //	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    //	0 |. . . . . . . . . . . . . . .|
    //	1 |. . . . . . . . . . . . . . .|
    //	2 |. . . . . . . . . . . . . . .|
    //	3 |. . . . . . . . . . . . . . .|
    //	4 |. . . . . . . . . . . . . . .|
    //	5 |. . . . . . o o . . . . . . .|
    //	6 |. . . . . . . x o . . . . . .|
    //	7 |. . . . . o x x x . . . . . .|
    //	8 |. . . . . o . x . . . . . . .|
    //	9 |. . . . . . . . . . . . . . .|
    //	10|. . . . . . . . . . . . . . .|
    //	11|. . . . . . . . . . . . . . .|
    //	12|. . . . . . . . . . . . . . .|
    //	13|. . . . . . . . . . . . . . .|
    //	14|. . . . . . . . . . . . . . .|
    //	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Lizard shot:
    // none

    Board::PositionXY headShot3AResult;

    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, true));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(true, headShot3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, true));
    CHECK_FALSE(m_pStateEvaluation->IsHeadShotLizardPossible(false, headShot3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest1)
{
    // Double threat 3A: (5,5)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . x . x . . . . . . . .|
    // 7 |. . . x . . . x . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY double3A = Board::PositionXY(5, 5);

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest2)
{
    // Double threat 3A: (4,6)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . x . . . . . . . .|
    // 2 |. . . . . . x . . . . . . . .|
    // 3 |. . . . . . x . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . x . . . x . . . . . .|
    // 7 |. . . x . . . . . x . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY double3A = Board::PositionXY(4, 6);

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest3)
{
    // Double threat 3A: (3,6)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |x . . . . o o o . . . . . . .|
    // 1 |x . . . . . . . . . . . . . .|
    // 2 |x . . . . . . . . . . . . . .|
    // 3 |x . . . . . . . . . . . . . .|
    // 4 |. . . . . x . . . . . . . . .|
    // 5 |. . . . . . . . x . . . . . .|
    // 6 |. . . x . . . . . x . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY double3A = Board::PositionXY(3, 6);

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK(false == m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest4)
{
    // Double threat 3A: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . x . x . . . . . .|
    // 6 |. . . . . . . . . x . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . x . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest5)
{
    // Double threat 3A: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . o . . .|
    // 4 |. . . . . . . . . . . o . . .|
    // 5 |. . . . . . . . . . . o . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . x . . . x . . . . . . .|
    // 9 |. . . . . . . . x . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 11);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition  == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition  == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest6)
{
    // Double threat 3A: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . x . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . x . . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . x . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 10);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY double3AResult;
    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest7)
{
    // Double threat 3A: (4,5)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . x . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . x . . . . . . . .|
    // 6 |. . . x . . . . . . . . . . .|
    // 7 |. . . . . . . . x . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY double3A = Board::PositionXY(4, 5);

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest8)
{
    // Double threat 3A: (5,5)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . x . . . x . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . x . x . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(3, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    const Board::PositionXY double3A = Board::PositionXY(5, 5);

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK(double3AResult == double3A);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDouble3AOneStrokePossibleTest9)
{
    // Double threat 3A: (5,5)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . x . . x . . x . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Head shot:
    // none

    Board::PositionXY double3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(true, double3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AOneStrokePossible(false, double3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest1)
{
    // Mitigation move: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . x . . . . .|
    // 6 |. . . . . x . . . o . . . . .|
    // 7 |. . . . x . x . . o . . . . .|
    // 8 |. . . x . . . x . o . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest2a)
{
    // Mitigation move: (6,7)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . x o o o . . . . . . . .|
    // 7 |. . . . x x . x . . . . . . .|
    // 8 |. . . . . . . x . . . . . . .|
    // 9 |. . . . . . . x . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(6, 7);

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK(mitigation2x3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK(mitigation2x3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest2b)
{
    // Mitigation move: (6,7)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . x . . . . . . . . . . .|
    // 3 |. . . . x . . . . . . . . . .|
    // 4 |. . . . . x . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . x o o o . . . . . . . .|
    // 7 |. . . . x x . x . . . . . . .|
    // 8 |. . . . . . . x . . . . . . .|
    // 9 |. . . . . . . x . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(1, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Put movies into the board.
    newMove = Board::PositionXY(2, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(9, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(6, 7);

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, true));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, true));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest3)
{
    // Mitigation move: (6,6)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . x . . . . . . . . . .|
    // 6 |. . . . . o o o x . . . . . .|
    // 7 |. . . . x . . . . . . . . . .|
    // 8 |. x x . x . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest4)
{
    // Mitigation move: (6,6)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . x . x . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . x . x . . . . . . .|
    // 8 |. . . . x . . . x . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(6, 6);

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK(mitigation2x3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK(mitigation2x3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest5)
{
    // Mitigation move: none (assert)
    //						   1 1 1 1 1
    //	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    //	0 |. . . . . . . . o . . . . . .|
    //	1 |. . . . . . . . o . . . . . .|
    //	2 |. . . . . . . . o . . . . . .|
    //	3 |. . . . . . . . o . . . . . .|
    //	4 |. . . . . . . . . . . . . . .|
    //	5 |. . . . . . . . . . . . . . .|
    //	6 |. . . . . x . . . . . . . . .|
    //	7 |. . . . x . x . . . . . . . .|
    //	8 |. . . x . . . x . . . . . . .|
    //	9 |. . . . . . . . . . . . . . .|
    //	10|. . . . . . . . . . . . . . .|
    //	11|. . . . . . . . . . . . . . .|
    //	12|. . . . . . . . . . . . . . .|
    //	13|. . . . . . . . . . . . . . .|
    //	14|. . . . . . . . . . . . . . .|
    //	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(8, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none/assert

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest6)
{
    // Mitigation move: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . x . . . . . . . .|
    // 5 |. . . x o o . . o x . . . . .|
    // 6 |. . . . . . x . x . . . . . .|
    // 7 |. . . . . . x . . x . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest7)
{
    // Mitigation move: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . x . . . . . . . .|
    // 5 |. . . x o o . . o x . . . . .|
    // 6 |. . . . . . x . . . . . . . .|
    // 7 |. . . . x x x . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsDoubleThreatMitigationPossibleTest8)
{
    // Mitigation move: (5,6)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . x . . . . . . . .|
    // 5 |. . . x o o . . o x . . . . .|
    // 6 |. . . . . . x . . . . . . . .|
    // 7 |. . . . . . x x x . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 3);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 9);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(5, 6);

    Board::PositionXY mitigation2x3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult));
    CHECK(mitigation2x3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsDouble3AMitigationPossible(true, mitigation2x3AResult, false));
    CHECK(mitigation2x3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsDouble3AMitigationPossible(false, mitigation2x3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest1)
{
    // Mitigation move: (6,4)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . o . . . . . . . .|
    // 5 |. . . . . o . . . . . . . . .|
    // 6 |. . . . . x x x . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(6, 4);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest2)
{
    // Mitigation move: (6,4)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . o . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . o . . . . . . . . .|
    // 6 |. . . . . x x x . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(6, 4);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest3)
{
    // Mitigation move: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . o . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . . . . . . . . . . .|
    // 5 |. . . . . o . . . . . . . . .|
    // 6 |. . . . . x x x . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest4)
{
    // Mitigation move: (6,4)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . x . . . . . .|
    // 3 |. . . . . . . o . . . . . . .|
    // 4 |. . . . . . o . . . . . . . .|
    // 5 |. . . . . o . . . . . . . . .|
    // 6 |. . . . . x x x . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(6, 4);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest5)
{
    // Mitigation move: (1,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . o . . . . . . . . . .|
    // 1 |. . x . x x . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. o . . . . . . . . . . . . .|
    // 4 |o . . . . . . . . . . . . . .|
    // 5 |. . . . . . . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(1, 2);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(1, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(0, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 1);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 0);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(1, 3);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest6)
{
    // Mitigation move: none
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . . . . . . . .|
    // 3 |. . . . . . . . . . . . . . .|
    // 4 |. . . . . o . . . . . . . . .|
    // 5 |. . . . o . . . . . . . . . .|
    // 6 |. . . . . x x x . . . . . . .|
    // 7 |. . . . . . . . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(6, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    // none

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest7)
{
    // Mitigation move: (7,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . x . . . . . .|
    // 3 |. . . . . . . o . . . . . . .|
    // 4 |. . . . . . o . . . . . . . .|
    // 5 |. . . . . o . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . x x x . . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(7, 3);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest8)
{
    // Mitigation move: (7,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . x . . . . . .|
    // 3 |. . . . . . . o . . . . . . .|
    // 4 |. . . . . . o . . . . . . . .|
    // 5 |. . . . . o . . . . . . . . .|
    // 6 |. . . . . . . . . . . . . . .|
    // 7 |. . . . x x . x . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(7, 3);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

TEST(StateEvaluationTest, IsSingle3AThreatMitigationPossibleTest9)
{
    // Mitigation move: (7,3)
    //                       1 1 1 1 1
    //   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
    //   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 0 |. . . . . . . . . . . . . . .|
    // 1 |. . . . . . . . . . . . . . .|
    // 2 |. . . . . . . . x . . . . . .|
    // 3 |. . . . . . . o . . . . . . .|
    // 4 |. . . . . . o . . . . . x . .|
    // 5 |. . . . . o . . . . . . x . .|
    // 6 |. . . . . . . . . . . . x . .|
    // 7 |. . . . x x . x . . . . . . .|
    // 8 |. . . . . . . . . . . . . . .|
    // 9 |. . . . . . . . . . . . . . .|
    // 10|. . . . . . . . . . . . . . .|
    // 11|. . . . . . . . . . . . . . .|
    // 12|. . . . . . . . . . . . . . .|
    // 13|. . . . . . . . . . . . . . .|
    // 14|. . . . . . . . . . . . . . .|
    //  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

    // Prepare BoardScore.
    BoardScore boardScoreComputer(Board::PLAYER_A);
    BoardScore boardScoreHuman(Board::PLAYER_B);
    boardScoreComputer.SetBoard(*m_pGomokuBoard);
    boardScoreHuman.SetBoard(*m_pGomokuBoard);
    m_pStateEvaluation->SetBoards(boardScoreComputer, boardScoreHuman);

    Board::PositionXY newMove;

    // Put movies into the board.
    newMove = Board::PositionXY(2, 8);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 4);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(7, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(3, 7);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 6);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 5);
    m_pGomokuBoard->PutMove(newMove, boardScoreHuman.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(4, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(5, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    newMove = Board::PositionXY(6, 12);
    m_pGomokuBoard->PutMove(newMove, boardScoreComputer.GetPlayer());
    m_pScore->UpdateScore(boardScoreComputer, newMove);
    m_pScore->UpdateScore(boardScoreHuman, newMove);

    // Mitigation move:
    const Board::PositionXY mitigationMove = Board::PositionXY(7, 3);

    Board::PositionXY mitigation3AResult;

    // CheckWinnerMoveCondition == true
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult));

    // CheckWinnerMoveCondition == false
    CHECK_TRUE(m_pStateEvaluation->IsBlockAndAttack3APossible(true, mitigation3AResult, false));
    CHECK(mitigation3AResult == mitigationMove);
    CHECK_FALSE(m_pStateEvaluation->IsBlockAndAttack3APossible(false, mitigation3AResult, false));
}

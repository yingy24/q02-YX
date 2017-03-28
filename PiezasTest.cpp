/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <iostream>
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(PiezasTest, resetTest)
{
	Piezas piezas;
	//ASSERT_TRUE(piezas.reset());
}

TEST(PiezasTest, dropPieceTests)
{
	Piezas piezas;
	ASSERT_EQ(piezas.dropPiece(0), 'X');
	ASSERT_EQ(piezas.dropPiece(0), 'O');
	ASSERT_EQ(piezas.dropPiece(0), 'X');
	ASSERT_EQ(piezas.dropPiece(0), ' ');
	ASSERT_EQ(piezas.dropPiece(-1), '?');
}

TEST(PiezasTest, getPieceTest)
{
	Piezas piezas;
	ASSERT_EQ(piezas.pieceAt(4,4), '?');
	ASSERT_EQ(piezas.pieceAt(0,0), ' ' );
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	ASSERT_EQ(piezas.pieceAt(0,0), 'X');
	ASSERT_EQ(piezas.pieceAt(1,0), 'O');
}

TEST(PiezasTest, gameStateDrawNotOverTest)
{
	Piezas piezas;
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	ASSERT_EQ(piezas.gameState(), ' ');
	piezas.reset();
	ASSERT_EQ(piezas.gameState(), '?');
}

TEST(PiezasTest, gameStateWinnerTest)
{
	Piezas piezas;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	ASSERT_EQ(piezas.gameState(), 'X');
}

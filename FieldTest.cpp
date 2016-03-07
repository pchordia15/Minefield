/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, checkMineHidden)
{
	Field minefiled;
	
	ASSERT_FALSE(minefield.isSafe(4,5));
}

TEST(FieldTest, checkAdjacent)
{
	Field minefield;
	minefield.placeMine(4,5);
	ASSERT_EQ( EMPTY_SHOWN, minefield.revealAdjacent(4,5));
}


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

TEST(FieldTest, isSafeMineExplodes)
{
	Field oneMine;
	
	oneMine.placeMine(1,2);
	ASSERT_FALSE(oneMine.isSafe(1,2));
}

TEST(FieldTest, isSafeNoMine)
{
	Field noMine;
	
	ASSERT_TRUE(noMine.isSafe(5,7));
}

TEST(FieldTest, isSafeOutOfBounds)
{
	Field mineFiled;
	bool flag = false;
	try
	{
		bool safe = mineField.isSafe(-99,3);	
	}
	catch(...)
	{
		flag = true;	
	}
	ASSERT_TRUE(flag);
}

TEST(FieldTest, revealAdjacentOutOfBounds)
{
	Field mineFiled;
	bool flag = false;
	try
	{
		bool safe = mineField.revealAdjacent(11,12);	
	}
	catch(...)
	{
		flag = true;	
	}
	ASSERT_TRUE(flag);
}

Test(FieldTest, revealAdjacentSafe)
{
	Field mineField;
	mineField.placeMine(5,5);
	mineField.revealAdjacent(4,5);
	ASSERT_EQ(EMPTY_SHOWN, mineField.get(4,5));
	ASSERT_EQ(EMPTY_SHOWN, mineField.get(3,5));
	ASSERT_EQ(EMPTY_SHOWN, mineField.get(4,6));
	ASSERT_EQ(EMPTY_SHOWN, mineField.get(4,4));
	ASSERT_EQ(EMPTY_HIDDEN, mineField.get(4,5));	
}

TEST(FieldTest, revealAdjacentAllCells)
{
	Field empty;
	empty.revealAdjacent(0,0);
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ASSERT_EQ(EMPTY_SHOWN, empty.get(i,j));
		}
	}
}

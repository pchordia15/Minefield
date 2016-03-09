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

/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
// TEST(GuesserTest, smoke_test)
// {
//   Guesser object("Secret");
//   ASSERT_EQ( 1+1, 2 );
// }



// --------- DISTANCE --------- //

TEST(GuesserTest, dist_of_1){
	Guesser object("Secret");
	ASSERT_EQ(1, object.use_distance("Secrat"));
}

TEST(GuesserTest, dist_of_0){
	Guesser object("Secret");
	ASSERT_EQ(0, object.use_distance("Secret"));
}

TEST(GuesserTest, dist_shorter_length){
	Guesser object("Secret");
	ASSERT_EQ(3, object.use_distance("Sec"));
}

TEST(GuesserTest, dist_no_word){
	Guesser object("");
	ASSERT_EQ(0, object.use_distance("Sec"));
}

TEST(GuesserTest, dist_longer_word){
	Guesser object("Secret");
	ASSERT_EQ(1, object.use_distance("Secrets"));
}


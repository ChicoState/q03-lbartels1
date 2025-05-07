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

// --------- CONSTRUCTOR ------------//
TEST(GuesserTest, contructor_short){
	Guesser object("Secret");
	ASSERT_EQ("Secret", object.get_m_secret());
}

TEST(GuesserTest, contructor_too_long){
	Guesser object("Secretsssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
	ASSERT_EQ("Secretssssssssssssssssssssssssss", object.get_m_secret());
}

TEST(GuesserTest, contructor_just_right){
	Guesser object("Secret");
	ASSERT_EQ("Secret", object.get_m_secret());
}

// ------- match -------- //
TEST(GuesserTest, first_try){
	Guesser object("Secret");
	ASSERT_EQ(true, object.match("Secret"));
}

TEST(GuesserTest, first_try_capital){
	Guesser object("Secret");
	ASSERT_EQ(false, object.match("secret"));
}

TEST(GuesserTest, second_try){
	Guesser object("Secret");
	ASSERT_EQ(false, object.match("Secrat"));
	ASSERT_EQ(true, object.match("Secret"));
}

TEST(GuesserTest, third_try){
	Guesser object("Secret");
	ASSERT_EQ(false, object.match("Secrat"));
	ASSERT_EQ(false, object.match("secret"));
	ASSERT_EQ(true, object.match("Secret"));
}

TEST(GuesserTest, locked_by_brute){
	Guesser object("Secret");
	ASSERT_EQ(false, object.match("marbles"));
	ASSERT_EQ(false, object.match("marbles"));
	ASSERT_EQ(false, object.match("marbles"));
	ASSERT_EQ(false, object.match("Secret"));
}

TEST(GuesserTest, locked_by_no_guesses){
	Guesser object("Secret");
	ASSERT_EQ(false, object.match("secret"));
	ASSERT_EQ(false, object.match("secret"));
	ASSERT_EQ(false, object.match("secret"));
	ASSERT_EQ(false, object.match("Secret"));
}

// ------- remaining -------- //
TEST(GuesserTest, one_wrong_guess){
	Guesser object("Secret");
	object.match("secret");
	ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, two_wrong_guess){
	Guesser object("Secret");
	object.match("secret");
	object.match("secret");
	ASSERT_EQ(1, object.remaining());
}

TEST(GuesserTest, three_wrong_guess){
	Guesser object("Secret");
	object.match("secret");
	object.match("secret");
	object.match("secret");
	ASSERT_EQ(0, object.remaining());
}

TEST(GuesserTest, locked_on_first){
	Guesser object("Secret");
	ASSERT_EQ(3, object.remaining());
	object.match("marbles");
	ASSERT_EQ(2, object.remaining());
	object.match("marbles");
	ASSERT_EQ(1, object.remaining());
	object.match("marbles");
	ASSERT_EQ(0, object.remaining());
	
}







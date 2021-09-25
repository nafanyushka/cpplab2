#include "Tests.h"

AstroidTest::AstroidTest() {
	astroid = new Astroid();
}

AstroidTest::~AstroidTest() {
	delete astroid;
}

TEST_F(AstroidTest, ChangingRadiusTests)
{
	EXPECT_EQ(0, astroid->getRadius());
	astroid->setRadius(9);
	EXPECT_EQ(9, astroid->getRadius());
	astroid->setRadius(-3);
	EXPECT_EQ(0, astroid->getRadius());
}

TEST_F(AstroidTest, LengthTests)
{
	double t = 0;
	EXPECT_EQ(0, astroid->getLength());
	astroid->setRadius(9);
	EXPECT_EQ(54, astroid->getLength());
	EXPECT_EQ(0, astroid->getLength(t));
	t = 90;
	EXPECT_EQ(3.0 * 9.0 / 2.0, astroid->getLength(t));
	astroid->setRadius(3);
	EXPECT_EQ(18, astroid->getLength());
	t = 180;
	EXPECT_EQ(3.0 * 6.0 / 2.0, astroid->getLength(t));
	t = 720;
	EXPECT_EQ(-1, astroid->getLength(t));
}

TEST_F(AstroidTest, SquareTests)
{
	EXPECT_EQ(0, astroid->getSquare());
	astroid->setRadius(9);
	EXPECT_EQ(3.0 * PI * 81.0 / 8.0, astroid->getSquare());
	astroid->setRadius(3);
	EXPECT_EQ(3.0 * PI * 9.0 / 8.0, astroid->getSquare());
}

TEST_F(AstroidTest, CoordsTests)
{
	double t, x, y;
	t = 0;
	astroid->getCoords(&x, &y, t);
	EXPECT_EQ(0, x);
	EXPECT_EQ(0, y);
	astroid->setRadius(9);
	astroid->getCoords(&x, &y, t);
	EXPECT_EQ(9, x);
	EXPECT_EQ(0, y);
	t = 90;
	astroid->getCoords(&x, &y, t);
	EXPECT_EQ(0, (int)x);
	EXPECT_EQ(9, y);
	t = 45;
	astroid->getCoords(&x, &y, t);
	EXPECT_EQ(round(x), round(y));

	x = 0;
	astroid->getCoords(x, &y);
	EXPECT_EQ(9, round(y));
	x = 9;
	astroid->getCoords(x, &y);
	EXPECT_EQ(0, y);
	x = 3;
	astroid->getCoords(x, &y);
	EXPECT_EQ(3.3675, y);
}

TEST_F(AstroidTest, CurvativeRadiusTests)
{
	double t;
	t = 0;
	astroid->setRadius(9);
	EXPECT_EQ(0, astroid->getCurvativeRadius(t));
	t = 90;
	EXPECT_EQ(0, round(astroid->getCurvativeRadius(t)));
	t = 45;
	EXPECT_EQ(3.0 * 9.0 / 2.0, astroid->getCurvativeRadius(t));
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
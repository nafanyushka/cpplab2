#include <gtest/gtest.h>
#include "Astroid.h"

using namespace Batrudinov;

struct AstroidTest : testing::Test
{
	Astroid* astroid;

	AstroidTest();

	~AstroidTest();
};

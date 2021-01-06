#include "gtest/gtest.h"

#include "Singleton.cpp"


namespace
{
  class Evaluate : public testing::Test
  {
  };

  TEST_F(Evaluate, SimpleTest)
  {
    SingletonTester tester;
    ASSERT_TRUE(tester.is_singleton<SingletonTester>(
      [&]() -> SingletonTester* { return &tester; }))
      << "Expected a singleton in this case; provided lambda is yielding the same object over and over.";
    ASSERT_FALSE(tester.is_singleton<SingletonTester>([]() { return new SingletonTester{}; }));
  }
} // namespace


int main(int ac, char* av[])
{
 testing::InitGoogleTest(&ac, av);
 return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>

#include <chrono>
#include <cstdint>
#include <sstream>
#include <string>

#include "../include/point_counter.h"

// ============================================

std::string runProgramWithInput(const std::string& input) {
  std::stringstream input_stream(input);
  std::stringstream output_stream;

  auto cin_buf = std::cin.rdbuf();
  auto cout_buf = std::cout.rdbuf();

  std::cin.rdbuf(input_stream.rdbuf());
  std::cout.rdbuf(output_stream.rdbuf());

  std::uint64_t R; 
  std::cin >> R;
  std::cout << countPointsInCircle(R) << std::endl;

  std::cin.rdbuf(cin_buf);
  std::cout.rdbuf(cout_buf);

  return output_stream.str();
}

template <typename Func>
double measureTime(Func func) {
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end - start;
  return elapsed.count();
}

TEST(CorrectnessTest, Test1_Radius1) {
  std::string output = runProgramWithInput("1\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "5");
}

TEST(CorrectnessTest, Test2_Radius2) {
  std::string output = runProgramWithInput("2\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "13");
}

TEST(CorrectnessTest, Test3_Radius3) {
  std::string output = runProgramWithInput("3\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "29");
}

TEST(CorrectnessTest, Test4_Radius10) {
  std::string output = runProgramWithInput("10\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "317");
}

TEST(CorrectnessTest, Test5_Radius18) {
  std::string output = runProgramWithInput("18\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "1009");
}

TEST(CorrectnessTest, Test6_Radius99) {
  std::string output = runProgramWithInput("99\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "30757");
}

TEST(CorrectnessTest, Test7_Radius100) {
  std::string output = runProgramWithInput("100\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "31417");
}

TEST(CorrectnessTest, Test8_Radius1000) {
  std::string output = runProgramWithInput("1000\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "3141549");
}

TEST(CorrectnessTest, Test9_Radius999999) {
  std::string output = runProgramWithInput("999999\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "3141586368221");
}

TEST(CorrectnessTest, Test10_Radius1e9) {
  std::string output = runProgramWithInput("1000000000\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "3141592653589764829");
}

TEST(CorrectnessTest, Test11_Radius1999999999) {
  std::string output = runProgramWithInput("1999999999\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "12566370601792670609");
}

TEST(PerformanceTest, TimeTest_Radius1e6) {
  double elapsed = measureTime([]() { countPointsInCircle(1000000); });
  std::cout << "Radius 1,000,000 - Elapsed time: " << elapsed << " sec"
            << std::endl;
  EXPECT_LT(elapsed, 0.1) << "Time limit exceeded: " << elapsed
                          << " sec > 0.1 sec";
}

TEST(PerformanceTest, TimeTest_Radius1e9) {
  double elapsed = measureTime([]() { countPointsInCircle(1000000000); });
  std::cout << "Radius 1,000,000,000 - Elapsed time: " << elapsed << " sec"
            << std::endl;
  EXPECT_LT(elapsed, 30.0) << "Time limit exceeded for big radius";
}

TEST(EdgeCasesTest, RadiusZero) {
  std::string output = runProgramWithInput("0\n");
  output.erase(0, output.find_first_not_of(" \t\n\r"));
  output.erase(output.find_last_not_of(" \t\n\r") + 1);
  EXPECT_EQ(output, "1");
}

TEST(EdgeCasesTest, RadiusOneDirect) { EXPECT_EQ(countPointsInCircle(1), 5); }

class ParameterizedTest
    : public ::testing::TestWithParam<std::pair<std::uint64_t, std::uint64_t>> {
};

TEST_P(ParameterizedTest, CorrectnessCheck) {
  auto param = GetParam();
  std::uint64_t radius = param.first;
  std::uint64_t expected = param.second;
  EXPECT_EQ(countPointsInCircle(radius), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RadiusValues, ParameterizedTest,
    ::testing::Values(
        std::make_pair(1ULL, 5ULL), std::make_pair(2ULL, 13ULL),
        std::make_pair(3ULL, 29ULL), std::make_pair(10ULL, 317ULL),
        std::make_pair(18ULL, 1009ULL), std::make_pair(99ULL, 30757ULL),
        std::make_pair(100ULL, 31417ULL), std::make_pair(1000ULL, 3141549ULL)));
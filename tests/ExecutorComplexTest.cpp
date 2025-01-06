// 为三种列车编写更复杂的测试样例，确保功能的正确性
#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"

namespace adas
{
    INSTANTIATE_TEST_SUITE_P(
        ExecutorComplexTest,
        ExecutorDDTTest,
        ::testing::Values(
            // 普通车
            TestCase{{0, 0, 'E'}, "Normal", "BMLMFMFMBRM", {-2, 4, 'W'}, "Normal"}, // 后退2格

            // 跑车
            TestCase{{0, 0, 'E'}, "Sports", "BMLMFMFMBRM", {-5,9,'W'}, "Sports"}, // 后退4格

            // 巴士
            TestCase{{0, 0, 'E'}, "Bus", "BMLMFMFMBRM", {-3, 3, 'W'}, "Bus"} // 后退1格，再后退1格
            ));
} // namespace adas

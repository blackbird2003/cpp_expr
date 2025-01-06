// 加速状态下的指令测试，包含FM, FL, FR, FFM
#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"

namespace adas
{
    INSTANTIATE_TEST_SUITE_P(
        ExecutorFastTest,
        ExecutorDDTTest,
        ::testing::Values(
            // 普通车
            TestCase{{0, 0, 'E'}, "Normal", "FM", {2, 0, 'E'}, "Normal"},  // 前进2格
            TestCase{{0, 0, 'E'}, "Normal", "FL", {1, 0, 'N'}, "Normal"},  // 前进1格并左转
            TestCase{{0, 0, 'E'}, "Normal", "FR", {1, 0, 'S'}, "Normal"},  // 前进1格并右转
            TestCase{{0, 0, 'N'}, "Normal", "FFM", {0, 1, 'N'}, "Normal"}, // 取消加速后前进1格

            // 跑车
            TestCase{{0, 0, 'E'}, "Sports", "FM", {4, 0, 'E'}, "Sports"},  // 前进4格
            TestCase{{0, 0, 'E'}, "Sports", "FL", {1, 1, 'N'}, "Sports"},  // 前进1格，再左转，再前进1格
            TestCase{{0, 0, 'E'}, "Sports", "FR", {1, -1, 'S'}, "Sports"}, // 前进1格，再右转，再前进1格
            TestCase{{0, 0, 'N'}, "Sports", "FFM", {0, 2, 'N'}, "Sports"}, // 取消加速后前进2格

            // 巴士
            TestCase{{0, 0, 'E'}, "Bus", "FM", {2, 0, 'E'}, "Bus"}, // 前进1格，再前进1格
            TestCase{{0, 0, 'E'}, "Bus", "FL", {2, 0, 'N'}, "Bus"}, // 前进1格，再前进1格，再左转
            TestCase{{0, 0, 'E'}, "Bus", "FR", {2, 0, 'S'}, "Bus"}, // 前进1格，再前进1格，再右转
            TestCase{{0, 0, 'N'}, "Bus", "FFM", {0, 1, 'N'}, "Bus"} // 取消加速后前进1格
            ));

} // namespace adas


// 加速倒车状态下的指令测试,包含BFM,BFL,BFR
#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"

namespace adas
{
    INSTANTIATE_TEST_SUITE_P(
        ExecutorBFTest,
        ExecutorDDTTest,
        ::testing::Values(
            // 普通车
            TestCase{{0, 0, 'E'}, "Normal", "BFM", {-2, 0, 'E'}, "Normal"}, // 后退2格
            TestCase{{0, 0, 'E'}, "Normal", "BFL", {-1, 0, 'S'}, "Normal"}, // 后退1格，再左转
            TestCase{{0, 0, 'E'}, "Normal", "BFR", {-1, 0, 'N'}, "Normal"}, // 后退1格，再右转

            // 跑车
            TestCase{{0, 0, 'E'}, "Sports", "BFM", {-4, 0, 'E'}, "Sports"}, // 后退4格
            TestCase{{0, 0, 'E'}, "Sports", "BFL", {-1, 1, 'S'}, "Sports"}, // 后退1格，再右转，再后退1格
            TestCase{{0, 0, 'E'}, "Sports", "BFR", {-1, -1, 'N'}, "Sports"}, // 后退1格，再左转，再后退1格

            // 巴士
            TestCase{{0, 0, 'E'}, "Bus", "BFM", {-2, 0, 'E'}, "Bus"}, // 后退1格，再后退1格
            TestCase{{0, 0, 'E'}, "Bus", "BFL", {-2, 0, 'S'}, "Bus"}, // 后退1格，再后退1格，再右转
            TestCase{{0, 0, 'E'}, "Bus", "BFR", {-2, 0, 'N'}, "Bus"} // 后退1格，再后退1格，再左转
            ));
} // namespace adas

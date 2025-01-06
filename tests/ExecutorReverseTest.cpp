//倒车状态下的指令测试，包含BM,BL,BR,BB.
#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"

namespace adas
{
    INSTANTIATE_TEST_SUITE_P(
        ExecutorReverseTest,
        ExecutorDDTTest,
        ::testing::Values(
            // 普通车
            TestCase{{0, 0, 'E'}, "Normal", "BM", {-1, 0, 'E'}, "Normal"}, // 后退1格
            TestCase{{0, 0, 'E'}, "Normal", "BL", {0, 0, 'S'}, "Normal"},  // 右转
            TestCase{{0, 0, 'E'}, "Normal", "BR", {0, 0, 'N'}, "Normal"},  // 左转
            TestCase{{0, 0, 'E'}, "Normal", "BBM", {1, 0, 'E'}, "Normal"}, // 取消倒车后前进1格

            // 跑车
            TestCase{{0, 0, 'E'}, "Sports", "BM", {-2, 0, 'E'}, "Sports"}, // 后退2格
            TestCase{{0, 0, 'E'}, "Sports", "BL", {0, 1, 'S'}, "Sports"},  // 右转,再后退1格
            TestCase{{0, 0, 'E'}, "Sports", "BR", {0, -1, 'N'}, "Sports"}, // 左转，再后退1格
            TestCase{{0, 0, 'E'}, "Sports", "BBM", {2, 0, 'E'}, "Sports"}, // 取消倒车后前进2格

            // 巴士
            TestCase{{0, 0, 'E'}, "Bus", "BM", {-1, 0, 'E'}, "Bus"}, // 后退1格
            TestCase{{0, 0, 'E'}, "Bus", "BL", {-1, 0, 'S'}, "Bus"}, // 后退1格，再右转
            TestCase{{0, 0, 'E'}, "Bus", "BR", {-1, 0, 'N'}, "Bus"}, // 后退1格，再左转
            TestCase{{0, 0, 'E'}, "Bus", "BBM", {1, 0, 'E'}, "Bus"}  // 取消倒车后前进1格

            ));
} // namespace adas
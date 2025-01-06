// 加速状态下的指令测试，包含FM, FL, FR, FFM
#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"

namespace adas
{
    // F状态下的指令测试
    INSTANTIATE_TEST_SUITE_P(
        ExecutorFastTest, 
        ExecutorDDTTest,
        ::testing::Values(
            // 普通车
            TestCase{{0, 0, 'E'}, "Normal", "FM", {2, 0, 'E'}, "Normal"}, // 前进2格
            TestCase{{0, 0, 'E'}, "Normal", "FL", {1, 0, 'N'}, "Normal"}, // 前进一步并左转
            TestCase{{0, 0, 'E'}, "Normal", "FR", {1, 0, 'S'}, "Normal"}, // 前进一步并右转
            TestCase{{0, 0, 'N'}, "Normal", "FFM", {0, 1, 'N'}, "Normal"} // 取消加速后前进1格
            ));

} // namespace adas


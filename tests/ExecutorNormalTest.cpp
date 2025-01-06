#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"

namespace adas
{

    // Normal状态下的指令测试
    INSTANTIATE_TEST_SUITE_P(
        ExecutorNormalTest,
        ExecutorDDTTest,
        ::testing::Values(
            // 普通车
            TestCase{{0, 0, 'E'}, "Normal", "M", {1, 0, 'E'}, "Normal"},
            TestCase{{0, 0, 'W'}, "Normal", "M", {-1, 0, 'W'}, "Normal"},
            TestCase{{0, 0, 'N'}, "Normal", "M", {0, 1, 'N'}, "Normal"},
            TestCase{{0, 0, 'S'}, "Normal", "M", {0, -1, 'S'}, "Normal"},
            TestCase{{0, 0, 'E'}, "Normal", "L", {0, 0, 'N'}, "Normal"},
            TestCase{{0, 0, 'N'}, "Normal", "L", {0, 0, 'W'}, "Normal"},
            TestCase{{0, 0, 'W'}, "Normal", "L", {0, 0, 'S'}, "Normal"},
            TestCase{{0, 0, 'S'}, "Normal", "L", {0, 0, 'E'}, "Normal"},
            TestCase{{0, 0, 'E'}, "Normal", "R", {0, 0, 'S'}, "Normal"},
            TestCase{{0, 0, 'S'}, "Normal", "R", {0, 0, 'W'}, "Normal"},
            TestCase{{0, 0, 'W'}, "Normal", "R", {0, 0, 'N'}, "Normal"},
            TestCase{{0, 0, 'N'}, "Normal", "R", {0, 0, 'E'}, "Normal"},

            // 跑车
            TestCase{{0, 0, 'E'}, "Sports", "M", {2, 0, 'E'}, "Sports"},
            TestCase{{0, 0, 'W'}, "Sports", "M", {-2, 0, 'W'}, "Sports"},
            TestCase{{0, 0, 'N'}, "Sports", "M", {0, 2, 'N'}, "Sports"},
            TestCase{{0, 0, 'S'}, "Sports", "M", {0, -2, 'S'}, "Sports"},
            TestCase{{0, 0, 'E'}, "Sports", "L", {0, 1, 'N'}, "Sports"},  // 左转后前进1格
            TestCase{{0, 0, 'N'}, "Sports", "L", {-1, 0, 'W'}, "Sports"}, // 左转后前进1格
            TestCase{{0, 0, 'W'}, "Sports", "L", {0, -1, 'S'}, "Sports"}, // 左转后前进1格
            TestCase{{0, 0, 'S'}, "Sports", "L", {1, 0, 'E'}, "Sports"},  // 左转后前进1格
            TestCase{{0, 0, 'E'}, "Sports", "R", {0, -1, 'S'}, "Sports"}, // 右转后前进1格
            TestCase{{0, 0, 'S'}, "Sports", "R", {-1, 0, 'W'}, "Sports"}, // 右转后前进1格
            TestCase{{0, 0, 'W'}, "Sports", "R", {0, 1, 'N'}, "Sports"},  // 右转后前进1格
            TestCase{{0, 0, 'N'}, "Sports", "R", {1, 0, 'E'}, "Sports"},  // 右转后前进1格

            // Bus 
            TestCase{{0, 0, 'E'}, "Bus", "M", {1, 0, 'E'}, "Bus"},
            TestCase{{0, 0, 'W'}, "Bus", "M", {-1, 0, 'W'}, "Bus"},
            TestCase{{0, 0, 'N'}, "Bus", "M", {0, 1, 'N'}, "Bus"},
            TestCase{{0, 0, 'S'}, "Bus", "M", {0, -1, 'S'}, "Bus"},
            TestCase{{0, 0, 'E'}, "Bus", "L", {1, 0, 'N'}, "Bus"},  // 前进1格后左转
            TestCase{{0, 0, 'N'}, "Bus", "L", {0, 1, 'W'}, "Bus"},  // 前进1格后左转
            TestCase{{0, 0, 'W'}, "Bus", "L", {-1, 0, 'S'}, "Bus"}, // 前进1格后左转
            TestCase{{0, 0, 'S'}, "Bus", "L", {0, -1, 'E'}, "Bus"}, // 前进1格后左转
            TestCase{{0, 0, 'E'}, "Bus", "R", {1, 0, 'S'}, "Bus"},  // 前进1格后右转
            TestCase{{0, 0, 'S'}, "Bus", "R", {0, -1, 'W'}, "Bus"}, // 前进1格后右转
            TestCase{{0, 0, 'W'}, "Bus", "R", {-1, 0, 'N'}, "Bus"}, // 前进1格后右转
            TestCase{{0, 0, 'N'}, "Bus", "R", {0, 1, 'E'}, "Bus"}   // 前进1格后右转
        )
    );

} // namespace adas

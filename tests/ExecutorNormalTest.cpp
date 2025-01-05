#include "ExecutorDDTTest.hpp"

namespace adas
{
    INSTANTIATE_TEST_SUITE_P(
        ExecutorInitTests,
        ExecutorDDTTest,
        ::testing::Values(
            TestCase{{0, 0, 'N'}, "Normal", "", {0, 0, 'N'}, "Normal"},
            TestCase{{1, 2, 'W'}, "Normal", "", {1, 2, 'W'}, "Normal"},
            TestCase{{2, 3, 'S'}, "Sports", "", {2, 3, 'S'}, "Sports"},
            TestCase{{0, 0, 'E'}, "Bus", "", {0, 0, 'E'}, "Bus"}));

} // namespace adas

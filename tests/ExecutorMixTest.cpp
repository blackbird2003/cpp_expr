//加速倒车状态下的指令测试，包含BFM,BFL,BFR
#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
    // BFM: B&F 状态下，移动指令应执行倒退 2 格
    TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_BF_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BFM");

        // then
        const Pose target{-2, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // BFL: B&F 状态下，左转指令应先倒退 1 格，然后右转 90 度
    TEST(ExecutorReverseTest, should_return_x_minus_1_and_facing_south_given_status_is_BF_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BFL");

        // then
        const Pose target{-1, 0, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // BFR: B&F 状态下，右转指令应先倒退 1 格，然后左转 90 度
    TEST(ExecutorReverseTest, should_return_x_minus_1_and_facing_north_given_status_is_BF_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BFR");

        // then
        const Pose target{-1, 0, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

} // namespace adas

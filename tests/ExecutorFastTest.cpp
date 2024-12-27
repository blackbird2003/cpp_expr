#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp" // Pose 的比较运算符重载

namespace adas
{

    // 测试 F 指令使小车进入加速状态并执行移动指令 (FM)
    TEST(ExecutorFastTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
    {
        // given 初始化小车，初始位置为 (0, 0)，朝向 E
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when 执行指令 "FM"（进入加速状态并移动）
        executor->Execute("FM");

        // then 验证位置变化为 (2, 0)，方向保持为 E
        const Pose target({2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试 F 指令下的左转行为 (FL)
    TEST(ExecutorFastTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
    {
        // given 初始化小车，初始位置为 (0, 0)，朝向 E
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when 执行指令 "FL"（进入加速状态、前进一步并左转）
        executor->Execute("FL");

        // then 验证位置变化为 (1, 0)，方向变为 N
        const Pose target({1, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试 F 指令下的右转行为 (FR)
    TEST(ExecutorFastTest, should_return_S_and_x_plus_1_given_status_is_fast_command_is_R_and_facing_is_E)
    {
        // given 初始化小车，初始位置为 (0, 0)，朝向 E
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when 执行指令 "FR"（进入加速状态、前进一步并右转）
        executor->Execute("FR");

        // then 验证位置变化为 (1, 0)，方向变为 S
        const Pose target({1, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试 F 指令状态的取消(FF)
    TEST(ExecutorFastTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
    {
        // given 初始化小车，初始位置为 (0, 0)，朝向 N
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

        // when 执行指令 "FFM"（两次 F 切换状态，再移动）
        executor->Execute("FFM");

        // then 验证位置变化为 (0, 1)，方向保持为 N
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

} // namespace adas
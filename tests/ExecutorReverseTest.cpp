#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

    // 测试：B状态下执行移动指令 (BM)
    // 期望行为：倒车状态下，移动指令会让小车向反方向移动
    TEST(ExecutorReverseTest, should_move_in_reverse_given_status_is_back_command_is_M)
    {
        // given 初始化小车位置为 (0, 0)，朝向 E
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when 执行倒车指令 B 和移动指令 M
        executor->Execute("BM");

        // then 期望小车向反方向移动到 (-1, 0)
        const Pose target{-1, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试：B状态下执行左转指令 (BL)
    // 期望行为：倒车状态下，左转指令会让朝向顺时针旋转90度
    TEST(ExecutorReverseTest, should_return_facing_south_given_status_is_back_command_is_L_and_facing_is_east)
    {
        // given 初始化小车位置为 (0, 0)，朝向 E
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when 执行倒车指令 B 和左转指令 L
        executor->Execute("BL");

        // then 期望朝向从 E 变为 S
        const Pose target{0, 0, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试：B状态下执行右转指令 (BR)
    // 期望行为：倒车状态下，右转指令会让朝向逆时针旋转90度
    TEST(ExecutorReverseTest, should_return_facing_north_given_status_is_back_command_is_R_and_facing_is_east)
    {
        // given 初始化小车位置为 (0, 0)，朝向 E
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when 执行倒车指令 B 和右转指令 R

        executor->Execute("BR");
        // debug
        //  executor->Execute("B");
        //  auto st = executor->Query();
        //  std::cout << "After B command: " << st.x << " " << st.y << " " << st.heading << std::endl;

        // executor->Execute("R");
        // st = executor->Query();
        // std::cout << "After R command: " << st.x << " " << st.y << " " << st.heading << std::endl;

        // then 期望朝向从 E 变为 N
        const Pose target{0, 0, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试：B状态下再次接收B指令 (BB)
    // 期望行为：再次接收 B 指令会取消倒车状态，小车恢复正常前进
    TEST(ExecutorReverseTest, should_cancel_reverse_status_given_status_is_back_command_is_B)
    {
        // given 初始化小车位置为 (0, 0)，朝向 E，并进入倒车状态
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        executor->Execute("B");

        // when 再次执行倒车指令 B，取消倒车状态，然后执行普通移动指令 M
        executor->Execute("B"); // 取消倒车状态
        executor->Execute("M"); // 执行普通移动指令

        // then 期望小车正常向前移动到 (1, 0)
        const Pose target{1, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

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

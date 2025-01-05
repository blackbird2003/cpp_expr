// 初始化情况测试
#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp" // Pose 的比较运算符重载

namespace adas
{

    TEST(ExecutorInitTest, should_return_default_pose_and_cartype_when_without_any_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor());
        // when
        // then
        const Pose target({0, 0, 'N'});             // 默认Pose为{0,0,'N'}
        ASSERT_EQ(target, executor->Query());
        ASSERT_EQ("Normal", executor->GetCarType()); // 默认车辆类型为 "Normal"
    }

    TEST(ExecutorInitTest, should_return_default_car_type_when_initialized_with_pose_only)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({1, 2, 'W'}));
        // then
        const Pose target({1, 2, 'W'});
        ASSERT_EQ(target, executor->Query());
        ASSERT_EQ("Normal", executor->GetCarType()); // 默认车辆类型为 "Normal"
    }

    // TEST(ExecutorInitTest, should_return_default_pose_when_initialized_with_car_type_only)
    // {
    //     // given
    //     std::unique_ptr<Executor> executor(Executor::NewExecutor("Bus"));
    //     // then
    //     const Pose target({0, 0, 'N'}); // 默认Pose为{0,0,'N'}
    //     ASSERT_EQ(target, executor->Query());
    //     ASSERT_EQ("Normal", executor->GetCarType()); 
    // }

    TEST(ExecutorInitTest, should_return_specified_car_type_and_pose_when_initialized)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({2, 3, 'S'}, "Sports"));
        // then
        const Pose target({2, 3, 'S'});
        ASSERT_EQ(target, executor->Query());
        printf("executor->GetCarType()=%s\n", executor->GetCarType().c_str());
        ASSERT_EQ("Sports", executor->GetCarType()); // 初始化为 "Sports"
    }

} // namespace adas

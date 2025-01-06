#pragma once
#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

    // 测试数据结构
    struct TestCase
    {
        Pose initialPose;
        CarType carType;
        std::string command; // 指令序列
        Pose expectedPose;
        CarType expectedCarType;
    };

    // 参数化测试类
    class ExecutorDDTTest : public ::testing::TestWithParam<TestCase>
    {
    };
} // namespace adas

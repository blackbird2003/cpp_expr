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

    // 通用测试逻辑
    TEST_P(ExecutorDDTTest, ExecutesCommandsCorrectly)
    {
        // Arrange: 获取测试数据
        const TestCase &testCase = GetParam();
        std::unique_ptr<Executor> executor(Executor::NewExecutor(testCase.initialPose, testCase.carType));

        // Act: 执行指令
        executor->Execute(testCase.command);

        // Assert: 验证结果
        ASSERT_EQ(executor->Query(), testCase.expectedPose);
        ASSERT_EQ(executor->GetCarType(), testCase.expectedCarType);
    }

} // namespace adas

#include <gtest/gtest.h>
#include "ExecutorDDTTest.hpp"
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {
    // 通用测试逻辑
    TEST_P(ExecutorDDTTest, ExecutesCommandsCorrectly)
    {
        // Arrange: 获取测试数据
        const TestCase &testCase = GetParam();
        std::unique_ptr<Executor> executor(Executor::NewExecutor(testCase.initialPose, testCase.carType));

        // Act: 执行指令
        executor->Execute(testCase.command);

        // Assert: 验证结果
        printf("Expected Pose is {%d,%d,%c}, Actual Pose is {%d,%d,%c}\n", testCase.expectedPose.x, testCase.expectedPose.y, testCase.expectedPose.heading, executor->Query().x, executor->Query().y, executor->Query().heading);
        ASSERT_EQ(executor->Query(), testCase.expectedPose);
        ASSERT_EQ(executor->GetCarType(), testCase.expectedCarType);
    }
}
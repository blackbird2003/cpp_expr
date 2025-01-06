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
        ASSERT_EQ(executor->Query(), testCase.expectedPose);
        ASSERT_EQ(executor->GetCarType(), testCase.expectedCarType);
    }
}
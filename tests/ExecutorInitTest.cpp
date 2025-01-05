// 初始化情况测试 - 使用 DDT
#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp" // Pose 的比较运算符重载

namespace adas {

// 测试数据结构
struct InitTestCase {
    Pose initialPose;       // 初始位置
    CarType carType;        // 初始车辆类型
    Pose expectedPose;      // 预期位置
    CarType expectedCarType; // 预期车辆类型
};

// 定义参数化测试类
class ExecutorInitDDTTest : public ::testing::TestWithParam<InitTestCase> {};

// 使用参数化测试逻辑
TEST_P(ExecutorInitDDTTest, InitializesCorrectly) {
    // 获取测试数据
    const InitTestCase& testCase = GetParam();

    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor(testCase.initialPose, testCase.carType));

    // when(none) 
    // then
    ASSERT_EQ(testCase.expectedPose, executor->Query());
    ASSERT_EQ(testCase.expectedCarType, executor->GetCarType());
}

// 注册测试数据
INSTANTIATE_TEST_SUITE_P(
    ExecutorInitTests, // 测试组名称
    ExecutorInitDDTTest,
    ::testing::Values(
        // 测试用例
        InitTestCase{{0, 0, 'N'}, "Normal", {0, 0, 'N'}, "Normal"},    // 默认初始化
        InitTestCase{{1, 2, 'W'}, "Normal", {1, 2, 'W'}, "Normal"},    // 仅指定初始位置
        InitTestCase{{2, 3, 'S'}, "Sports", {2, 3, 'S'}, "Sports"},    // 指定位置和车辆类型
        InitTestCase{{0, 0, 'E'}, "Bus", {0, 0, 'E'}, "Bus"}           // 指定不同车辆类型
    )
);

} // namespace adas

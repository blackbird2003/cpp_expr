#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"
namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了，std::tie提高代码可读性
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
    // 格式：TEST(测试套件名，用例名) 遵循Arrange - Act - Assert(AAA) 模式
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // Arrange: 
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        const Pose target({0, 0, 'E'});
        // Assert:
        ASSERT_EQ(target, executor->Query());
    }
} // namespace adas
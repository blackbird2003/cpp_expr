#include "ExecutorImpl.hpp"
namespace adas
{
    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose)
    {
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            if (cmd == 'M') // 前进
            {
                if (pose.heading == 'E') // 朝东，x 增加
                {
                    ++pose.x;
                }
                else if (pose.heading == 'W') // 朝西，x 减少
                {
                    --pose.x;
                }
                else if (pose.heading == 'N') // 朝北，y 增加
                {
                    ++pose.y;
                }
                else if (pose.heading == 'S') // 朝南，y 减少
                {
                    --pose.y;
                }
            }
            else if (cmd == 'L') // 左转90度
            {
                if (pose.heading == 'E') // 从东转向北
                {
                    pose.heading = 'N';
                }
                else if (pose.heading == 'W') // 从西转向南
                {
                    pose.heading = 'S';
                }
                else if (pose.heading == 'N') // 从北转向西
                {
                    pose.heading = 'W';
                }
                else if (pose.heading == 'S') // 从南转向东
                {
                    pose.heading = 'E';
                }
            }
            else if (cmd == 'R') // 右转90度
            {
                if (pose.heading == 'E') // 从东转向南
                {
                    pose.heading = 'S';
                }
                else if (pose.heading == 'W') // 从西转向北
                {
                    pose.heading = 'N';
                }
                else if (pose.heading == 'N') // 从北转向东
                {
                    pose.heading = 'E';
                }
                else if (pose.heading == 'S') // 从南转向西
                {
                    pose.heading = 'W';
                }
            }
        }
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return pose;
    }

} // namespace adas
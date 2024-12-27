#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <memory>
#include <unordered_map>
namespace adas
{
    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose)
    {
    }
    void ExecutorImpl::Fast() noexcept
    {
        fast = !fast;
    }
    bool ExecutorImpl::IsFast() const noexcept
    {
        return fast;
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        // //Expr3 函数式编程，修改表驱动
        // std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap;
        // MoveCommand moveCommand;
        // cmderMap.emplace('M', moveCommand.operate);
        // TurnLeftCommand turnLeftCommand;
        // cmderMap.emplace('L', turnLeftCommand.operate);
        // TurnRightCommand turnRightCommand;
        // cmderMap.emplace('R', turnRightCommand.operate);
        // FastCommand fastCommand;
        // cmderMap.emplace('F', fastCommand.operate);

        // Expr3 函数对象实现
        // Expr3 应用初始化语义，简化表驱动代码
        const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()}};

        for (const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end())
            {
                it->second(poseHandler);
            }
        }
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

    void ExecutorImpl::Move() noexcept
    {
        if (pose.heading == 'E')
        {
            ++pose.x;
        }
        else if (pose.heading == 'W')
        {
            --pose.x;
        }
        else if (pose.heading == 'N')
        {
            ++pose.y;
        }
        else if (pose.heading == 'S')
        {
            --pose.y;
        }
    }

    void ExecutorImpl::TurnLeft() noexcept
    {
        if (pose.heading == 'E')
        {
            pose.heading = 'N';
        }
        else if (pose.heading == 'N')
        {
            pose.heading = 'W';
        }
        else if (pose.heading == 'W')
        {
            pose.heading = 'S';
        }
        else if (pose.heading == 'S')
        {
            pose.heading = 'E';
        }
    }

    void ExecutorImpl::TurnRight() noexcept
    {
        if (pose.heading == 'E')
        {
            pose.heading = 'S';
        }
        else if (pose.heading == 'S')
        {
            pose.heading = 'W';
        }
        else if (pose.heading == 'W')
        {
            pose.heading = 'N';
        }
        else if (pose.heading == 'N')
        {
            pose.heading = 'E';
        }
    }

} // namespace adas
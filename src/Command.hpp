#pragma once
#include "ExecutorImpl.hpp"

// Expr2 代码优化：指令处理的类独立到文件中

namespace adas
{

    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
    };

    // Expr2 Move/TurnLeft/TurnRight封装到类中
    // 移动
    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            // 如果处于加速状态，则移动两次
            if (executor.IsFast())
            {
                executor.Move();
            }
            executor.Move(); // 默认移动一次
        }
    };
    // 左转
    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            // 如果处于加速状态，先前进一步
            if (executor.IsFast())
            {
                executor.Move();
            }
            executor.TurnLeft(); // 执行左转
        }
    };
    // 右转
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            // 如果处于加速状态，先前进一步
            if (executor.IsFast())
            {
                executor.Move();
            }
            executor.TurnRight(); // 执行右转
        }
    };
    // Expr 2 Fast Command类
    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            executor.Fast(); // 切换加速状态
        }
    };
} // namespace adas

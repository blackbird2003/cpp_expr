#pragma once
#include "PoseHandler.hpp"

// Expr2 代码优化：指令处理的类独立到文件中

// Expr2 解耦循环依赖：executor -> poseHandler

namespace adas
{

    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    };

    // Expr2 Move/TurnLeft/TurnRight封装到类中
    // 移动
    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            // 如果处于加速状态，则移动两次
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.Move(); // 默认移动一次
        }
    };
    // 左转
    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            // 如果处于加速状态，先前进一步
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnLeft(); // 执行左转
        }
    };
    // 右转
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            // 如果处于加速状态，先前进一步
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnRight(); // 执行右转
        }
    };
    // Expr 2 Fast Command类
    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.Fast(); // 切换加速状态
        }
    };
} // namespace adas
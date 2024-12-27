#pragma once
#include "PoseHandler.hpp"

// Expr2 代码优化：指令处理的类独立到文件中

// Expr2 解耦循环依赖：executor -> poseHandler

// Expr3 改为函数式编程
#include <functional>

namespace adas
{
    // class ICommand
    // {
    // public:
    //     virtual ~ICommand() = default;
    //     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    // };

    // Expr2 Move/TurnLeft/TurnRight封装到类中
    // 移动
    class MoveCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     // 如果处于加速状态，则移动两次
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //     }
        //     poseHandler.Move(); // 默认移动一次
        // }
        const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.Move();
        };
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.Move();
        }
    };
    // 左转
    class TurnLeftCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     // 如果处于加速状态，先前进一步
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //     }
        //     poseHandler.TurnLeft(); // 执行左转
        // }
        const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        };
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        }
    };
    // 右转
    class TurnRightCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     // 如果处于加速状态，先前进一步
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //     }
        //     poseHandler.TurnRight(); // 执行右转
        // }
        const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        };
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        }
    };
    // Expr 2 Fast Command类
    class FastCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     poseHandler.Fast(); // 切换加速状态
        // }
        const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            poseHandler.Fast();
        };
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };
} // namespace adas

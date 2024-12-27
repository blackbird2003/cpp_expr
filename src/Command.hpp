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
        void operator()(PoseHandler &poseHandler) const
            noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }
            if (poseHandler.IsReverse())
            {
                poseHandler.Backward();
            }
            else
            {
                poseHandler.Forward();
            }
        }
    };
    // 左转
    class TurnLeftCommand final //: public ICommand
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            // 如果处于加速状态，先执行一次移动
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }

            // 根据是否为倒车状态决定转向逻辑
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnRight();
            }
            else
            {
                poseHandler.TurnLeft();
            }
        }
    };
    // 右转
    class TurnRightCommand final //: public ICommand
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            // 如果处于加速状态，先执行一次移动
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }

            // 根据是否为倒车状态决定转向逻辑
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnLeft();
            }
            else
            {
                poseHandler.TurnRight();
            }
        }
    };
    // Expr 2 Fast Command类
    class FastCommand final //: public ICommand
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };
    // Expr3 ReverseCommand类
    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Reverse();
        }
    };
} // namespace adas

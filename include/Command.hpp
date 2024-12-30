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
    // 移动指令类
    class MoveCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept;
    };

    // 左转指令类
    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept;
    };

    // 右转指令类
    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept;
    };

    // 加速指令类
    class FastCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept;
    };

    // 倒车指令类
    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept;
    };

} // namespace adas

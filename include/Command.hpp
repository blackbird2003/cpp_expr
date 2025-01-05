//实现指令类，管理每一条指令的执行
#pragma once
#include "PoseHandler.hpp"
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

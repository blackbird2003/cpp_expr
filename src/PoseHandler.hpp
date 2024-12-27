#pragma once
#include "Executor.hpp"
// Expr2 解耦循环依赖，封装抽离ExecutorImpl状态数据
namespace adas
{
    class PoseHandler final
    {
    public:
        PoseHandler(const Pose &pose) noexcept;
        PoseHandler(const PoseHandler &) = delete;
        PoseHandler &operator=(const PoseHandler &) = delete;

    public:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void Fast(void) noexcept;
        bool IsFast(void) const noexcept;
        Pose Query(void) const noexcept;

    private:
        Pose pose;
        bool fast{false};
    };
} // namespace ada
// 管理车辆的位置状态信息，实现原子性操作
#pragma once
#include "Executor.hpp"
#include <string>
namespace adas
{
    class PoseHandler final
    {
    public:
        PoseHandler(const Pose &pose) noexcept;
        PoseHandler(const CarType &carType) noexcept;
        PoseHandler(const Pose &pose, const CarType &carType) noexcept;
        PoseHandler(const PoseHandler &) = delete;
        PoseHandler &operator=(const PoseHandler &) = delete;

    public:
        void Forward(void) noexcept;
        void Backward(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;

        void Fast(void) noexcept;
        bool IsFast(void) const noexcept;

        void Reverse(void) noexcept;
        bool IsReverse(void) const noexcept;

        Pose Query(void) const noexcept;
        CarType GetCarType(void) const noexcept;

    private:
        Pose pose;
        CarType carType;
        bool fast{false};
        bool reverse{false};
    };
} // namespace ada
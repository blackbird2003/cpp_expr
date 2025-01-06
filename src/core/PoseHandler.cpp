#include "PoseHandler.hpp"
namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose), carType("Normal")
    {
    }
    PoseHandler::PoseHandler(const CarType &carType) noexcept : pose({0, 0, 'N'}), carType(carType)
    {
    }
    PoseHandler::PoseHandler(const Pose &pose, const CarType &carType) noexcept : pose(pose), carType(carType)
    {
    }
    void PoseHandler::Forward(int step) noexcept
    {
        if (pose.heading == 'E')
        {
            pose.x += step;
        }
        else if (pose.heading == 'W')
        {
            pose.x -= step;
        }
        else if (pose.heading == 'N')
        {
            pose.y += step;
        }
        else if (pose.heading == 'S')
        {
            pose.y -= step;;
        }
    }
    void PoseHandler::Backward(int step) noexcept
    {
        if (pose.heading == 'E')
        {
            pose.x -= step;
        }
        else if (pose.heading == 'W')
        {
            pose.x += step;
        }
        else if (pose.heading == 'N')
        {
            pose.y -= step;
        }
        else if (pose.heading == 'S')
        {
            pose.y += step;
        }
    }
    void PoseHandler::TurnLeft() noexcept
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
    void PoseHandler::TurnRight() noexcept
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
    Pose PoseHandler::Query() const noexcept
    {
        return pose;
    }
    CarType PoseHandler::GetCarType() const noexcept
    {
        return carType;
    }
    void PoseHandler::Fast() noexcept
    {
        fast = !fast;
    }
    bool PoseHandler::IsFast() const noexcept
    {
        return fast;
    }
    void PoseHandler::Reverse() noexcept
    {
        reverse = !reverse;
    }
    bool PoseHandler::IsReverse() const noexcept
    {
        return reverse;
    }
}
#include "Command.hpp"

namespace adas
{
    // 移动
    void MoveCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        if (poseHandler.GetCarType() == "Normal")
        {
            // 如果处于加速状态，执行额外的移动
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward(); // 加速倒车
                }
                else
                {
                    poseHandler.Forward(); // 加速前进
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
        else if (poseHandler.GetCarType() == "Sports")
        {
            if (poseHandler.IsFast() && poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B&F: 后退4格
                poseHandler.Backward();
                poseHandler.Backward();
                poseHandler.Backward();
            }
            else if (poseHandler.IsFast())
            {
                poseHandler.Forward(); // F: 前进4格
                poseHandler.Forward();
                poseHandler.Forward();
                poseHandler.Forward();
            }
            else if (poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B: 后退2格
                poseHandler.Backward();
            }
            else
            {
                poseHandler.Forward(); // Normal: 前进2格
                poseHandler.Forward();
            }
        }
        else if (poseHandler.GetCarType() == "Bus")
        {
            if (poseHandler.IsFast() && poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B&F: 后退2格
                poseHandler.Backward();
            }
            else if (poseHandler.IsFast())
            {
                poseHandler.Forward(); // F: 前进2格
                poseHandler.Forward();
            }
            else if (poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B: 后退1格
            }
            else
            {
                poseHandler.Forward(); // Normal: 前进1格
            }
        }
    }

    // 左转
    void TurnLeftCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        if (poseHandler.GetCarType() == "Normal")
        {
            // 如果处于加速状态，先执行移动
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

            // 根据倒车状态选择实际转向
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnRight(); // 倒车状态下左转为右转
            }
            else
            {
                poseHandler.TurnLeft();
            }
        }
    }

    // 右转
    void TurnRightCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        if (poseHandler.GetCarType() == "Normal")
        {
            // 如果处于加速状态，先执行移动
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

            // 根据倒车状态选择实际转向
            if (poseHandler.IsReverse())
            {
                poseHandler.TurnLeft(); // 倒车状态下右转为左转
            }
            else
            {
                poseHandler.TurnRight();
            }
        }
    }

    // 加速
    void FastCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        poseHandler.Fast();
    }

    // 倒车
    void ReverseCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }

} // namespace adas
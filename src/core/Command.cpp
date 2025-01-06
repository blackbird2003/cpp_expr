#include "Command.hpp"

namespace adas
{
    // 移动
    void MoveCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        if (poseHandler.GetCarType() == "Normal")
        {
            if (poseHandler.IsFast() && poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B&F: 依次后退2格
                poseHandler.Backward();
            }
            else if (poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.Forward(); // F: 依次前进2格
                poseHandler.Forward();
            }
            else if (!poseHandler.IsFast() && poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B: 后退1格
            }
            else
            {
                poseHandler.Forward(); // Normal: 前进1格
            }
        }
        else if (poseHandler.GetCarType() == "Sports")
        {
            if (poseHandler.IsFast() && poseHandler.IsReverse())
            {
                poseHandler.Backward(4); // B&F: 后退4格
            }
            else if (poseHandler.IsFast())
            {
                poseHandler.Forward(4); // F: 前进4格
            }
            else if (poseHandler.IsReverse())
            {
                poseHandler.Backward(2); // B: 后退2格
            }
            else
            {
                poseHandler.Forward(2); // Normal: 前进2格
            }
        }
        else if (poseHandler.GetCarType() == "Bus")
        {
            if (poseHandler.IsFast() && poseHandler.IsReverse())
            {
                poseHandler.Backward(); // B&F: 依次后退2格
                poseHandler.Backward();
            }
            else if (poseHandler.IsFast())
            {
                poseHandler.Forward(); // F: 依次前进2格
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
            // Normal 状态
            if (!poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.TurnLeft(); // 左转90度
            }
            // B 状态
            else if (poseHandler.IsReverse() && !poseHandler.IsFast())
            {
                poseHandler.TurnRight(); // 右转90度
            }
            // F 状态
            else if (!poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Forward();  // 前进1格
                poseHandler.TurnLeft(); // 左转90度
            }
            // B&F 状态
            else if (poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Backward();  // 后退1格
                poseHandler.TurnRight(); // 右转90度
            }
        }
        else if (poseHandler.GetCarType() == "Sports")
        {
            // Normal 状态
            if (!poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.TurnLeft(); // 左转90度
                poseHandler.Forward();  // 前进1格
            }
            // B 状态
            else if (poseHandler.IsReverse() && !poseHandler.IsFast())
            {
                poseHandler.TurnRight(); // 右转90度
                poseHandler.Backward();  // 后退1格
            }
            // F 状态
            else if (!poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Forward();  // 前进1格
                poseHandler.TurnLeft(); // 左转90度
                poseHandler.Forward();  // 再前进1格
            }
            // B&F 状态
            else if (poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Backward();  // 后退1格
                poseHandler.TurnRight(); // 右转90度
                poseHandler.Backward();  // 再后退1格
            }
        }
        else if (poseHandler.GetCarType() == "Bus")
        {
            // Normal 状态
            if (!poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.Forward();  // 前进1格
                poseHandler.TurnLeft(); // 左转90度
            }
            // B 状态
            else if (poseHandler.IsReverse() && !poseHandler.IsFast())
            {
                poseHandler.Backward();  // 后退1格
                poseHandler.TurnRight(); // 右转90度
            }
            // F 状态
            else if (!poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Forward();  // 前进1格
                poseHandler.Forward();  // 再前进1格
                poseHandler.TurnLeft(); // 左转90度
            }
            // B&F 状态
            else if (poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Backward();  // 后退1格
                poseHandler.Backward();  // 再后退1格
                poseHandler.TurnRight(); // 右转90度
            }
        }
    }

    // 右转
    void TurnRightCommand::operator()(PoseHandler &poseHandler) const noexcept
    {
        if (poseHandler.GetCarType() == "Normal")
        {
            // Normal 状态
            if (!poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.TurnRight(); // 右转90度
            }
            // B 状态
            else if (poseHandler.IsReverse() && !poseHandler.IsFast())
            {
                poseHandler.TurnLeft(); // 左转90度
            }
            // F 状态
            else if (!poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Forward();   // 前进1格
                poseHandler.TurnRight(); // 右转90度
            }
            // B&F 状态
            else if (poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Backward(); // 后退1格
                poseHandler.TurnLeft(); // 左转90度
            }
        }
        else if (poseHandler.GetCarType() == "Sports")
        {
            // Normal 状态
            if (!poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.TurnRight(); // 右转90度
                poseHandler.Forward();   // 前进1格
            }
            // B 状态
            else if (poseHandler.IsReverse() && !poseHandler.IsFast())
            {
                poseHandler.TurnLeft(); // 左转90度
                poseHandler.Backward(); // 后退1格
            }
            // F 状态
            else if (!poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Forward();   // 前进1格
                poseHandler.TurnRight(); // 右转90度
                poseHandler.Forward();   // 再前进1格
            }
            // B&F 状态
            else if (poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Backward(); // 后退1格
                poseHandler.TurnLeft(); // 左转90度
                poseHandler.Backward(); // 再后退1格
            }
        }
        else if (poseHandler.GetCarType() == "Bus")
        {
            // Normal 状态
            if (!poseHandler.IsFast() && !poseHandler.IsReverse())
            {
                poseHandler.Forward();   // 前进1格
                poseHandler.TurnRight(); // 右转90度
            }
            // B 状态
            else if (poseHandler.IsReverse() && !poseHandler.IsFast())
            {
                poseHandler.Backward(); // 后退1格
                poseHandler.TurnLeft(); // 左转90度
            }
            // F 状态
            else if (!poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Forward();   // 前进1格
                poseHandler.Forward();   // 再前进1格
                poseHandler.TurnRight(); // 右转90度
            }
            // B&F 状态
            else if (poseHandler.IsReverse() && poseHandler.IsFast())
            {
                poseHandler.Backward(); // 后退1格
                poseHandler.Backward(); // 再后退1格
                poseHandler.TurnLeft(); // 左转90度
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
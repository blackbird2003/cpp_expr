// 定义Excutor的基本操作，包括执行指令和查询。定义车辆状态Pose。
#pragma once
#include <string>
#include <iostream>
namespace adas
{
    struct Pose
    {
        int x;
        int y;
        char heading;
    };
    using CarType = std::string;
    class Executor
    {
    public:
        // Caller should delete *executor when it is no longer needed.
        static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}, const CarType &carType = "Normal") noexcept;

        

        Executor(void) = default; // 使用编译器生成的默认实现
        virtual ~Executor(void) = default;
        Executor(const Executor &) = delete; // 禁止拷贝和赋值
        Executor &operator=(const Executor &) = delete;

        // 执行指令
        virtual void Execute(const std::string &command) noexcept = 0;
        // 查询当前车辆的位置状态和类型
        virtual Pose Query(void) const noexcept = 0;
        virtual CarType GetCarType(void) const noexcept = 0;
    };
} // namespace adas
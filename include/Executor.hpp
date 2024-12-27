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
    class Executor
    {
    public:
        // Caller should delete *executor when it is no longer needed.
        static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

        Executor(void) = default; // 使用编译器生成的默认实现
        virtual ~Executor(void) = default;
        Executor(const Executor &) = delete; // 禁止拷贝和赋值
        Executor &operator=(const Executor &) = delete;

        // 执行指令
        virtual void Execute(const std::string &command) noexcept = 0;
        // 查询当前位置信息
        virtual Pose Query(void) const noexcept = 0;
    };
} // namespace adas
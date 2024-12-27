#pragma once
#include "Executor.hpp"
namespace adas
{
    class ExecutorImpl final : public Executor // 在类的定义中使用 final，会禁止该类作为基类被进一步继承。
    {
    public:
        explicit ExecutorImpl(const Pose &pose) noexcept;
        ~ExecutorImpl() noexcept = default;
        ExecutorImpl(const ExecutorImpl &) = delete;
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        void Execute(const std::string &command) noexcept override;
        Pose Query(void) const noexcept override; // override 表示该函数为虚函数的重写，如果没找到匹配的基类虚函数就会报错

    public: // Expr2 修改依赖方法访问权限(指令处理的类独立到文件中)
        // Expr2  完成Move/TurnLeft/TurnRight3个成员函数抽取
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;

        // Expr2 添加F指令接口
        void Fast(void) noexcept;
        bool IsFast(void) const noexcept;

    private:
        Pose pose;
        bool fast{false};
    };

} // namespace adas

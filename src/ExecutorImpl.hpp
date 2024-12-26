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
        Pose Query(void) const noexcept override; //override 表示该函数为虚函数的重写，如果没找到匹配的基类虚函数就会报错

    private:
        Pose pose;
    };
} // namespace adas
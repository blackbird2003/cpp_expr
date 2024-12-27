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
        bool fast{false};

        // Expr2  完成Move/TurnLeft/TurnRight3个成员函数抽取
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;

        // Expr2 添加F指令接口
        void Fast(void) noexcept;
        bool IsFast(void) const noexcept;
        
        // Expr2 Move/TurnLeft/TurnRight封装到类中
        class ICommand
        {
        public:
            virtual ~ICommand() = default;
            virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
        };
        //移动
        class MoveCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                // 如果处于加速状态，则移动两次
                if (executor.IsFast())
                {
                    executor.Move();
                }
                executor.Move(); // 默认移动一次
            }
        };
        //左转
        class TurnLeftCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                // 如果处于加速状态，先前进一步
                if (executor.IsFast())
                {
                    executor.Move();
                }
                executor.TurnLeft(); // 执行左转
            }
        };
        //右转
        class TurnRightCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                // 如果处于加速状态，先前进一步
                if (executor.IsFast())
                {
                    executor.Move();
                }
                executor.TurnRight(); // 执行右转
            }
        };
        //Expr 2 Fast Command类
        class FastCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.Fast(); // 切换加速状态
            }
        };
    };
    
} // namespace adas




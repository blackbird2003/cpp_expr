#include "ExecutorImpl.hpp"
#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
    Executor *Executor::NewExecutor(const Pose &pose, const CarType &carType) noexcept
    {
        //printf("Call 0. carType=%s\n", carType.c_str());
        return new (std::nothrow) ExecutorImpl(pose, carType);
    }
   
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose)
    {
        //printf("Call 1\n");
    }
    ExecutorImpl::ExecutorImpl(const CarType &carType) noexcept : poseHandler(carType)
    {
        // printf("Call 1\n");
    }
    ExecutorImpl::ExecutorImpl(const Pose &pose, const CarType &carType) noexcept : poseHandler(pose, carType)
    {
        //printf("Call 2. carType=%s, this->GetCarType=%s\n", carType.c_str(), this->GetCarType().c_str());
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        // Expr3 使用单体工厂类
        // const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        // std::for_each(
        //     cmders.begin(), cmders.end(),
        //     [this](const Cmder &cmder) noexcept
        //     { cmder(poseHandler); });
        // 获取 CmderFactory 单例实例
        auto &factory = Singleton<CmderFactory>::Instance();

        // 调用 GetCmders 获取命令对象列表
        auto cmders = factory.GetCmders(commands);

        // 遍历 cmders 并执行操作
        int i = 0;
        std::cout << "Command Series is: " << commands << std::endl;
        for (const auto &cmder : cmders)
        {
            const auto pose = poseHandler.Query();
            std::cout << "Current Pose: (" << pose.x << ", " << pose.y << ", " << pose.heading << ")" << std::endl;
            std::cout << "Executing command " << commands[i++] << std::endl;
            cmder(poseHandler);            
        }
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }
    CarType ExecutorImpl::GetCarType() const noexcept {
        return poseHandler.GetCarType();
    }
} // namespace adas
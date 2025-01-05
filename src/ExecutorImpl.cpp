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
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        std::for_each(
            cmders.begin(), cmders.end(),
            [this](const std::function<void(PoseHandler & poseHandler)> &cmder) noexcept
            { cmder(poseHandler); });
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }
    CarType ExecutorImpl::GetCarType() const noexcept {
        return poseHandler.GetCarType();
    }
} // namespace adas
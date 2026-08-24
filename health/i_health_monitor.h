#pragma once

#include "health/alive_supervision.h"

#include <memory>
#include <string_view>

namespace health
{

struct HealthMonitorConfig
{
};


class IHealthMonitor
{
  public:
    IHealthMonitor()                                     = default;
    IHealthMonitor(const IHealthMonitor&)                = delete;
    IHealthMonitor(IHealthMonitor&&) noexcept            = delete;
    IHealthMonitor& operator=(const IHealthMonitor&)     = delete;
    IHealthMonitor& operator=(IHealthMonitor&&) noexcept = delete;
    virtual ~IHealthMonitor()                            = default;

    [[nodiscard]] virtual std::unique_ptr<AliveSupervision> CreateAliveSupervision() = 0;
    [[nodiscard]] virtual std::string_view                  Name() const             = 0;
};

} // namespace health

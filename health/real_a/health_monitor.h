#pragma once

#include "health/i_health_monitor.h"

#include <memory>
#include <string_view>

namespace health::real_a
{

class HealthMonitor final : public IHealthMonitor
{
  public:
    explicit HealthMonitor(HealthMonitorConfig config);

    [[nodiscard]] std::unique_ptr<AliveSupervision> CreateAliveSupervision() override;
    [[nodiscard]] std::string_view                  Name() const override;

  private:
    HealthMonitorConfig config_;
    int                 magic_;
};

} // namespace health::real_a

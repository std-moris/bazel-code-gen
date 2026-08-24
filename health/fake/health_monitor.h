#pragma once

#include "health/i_health_monitor.h"

#include <memory>
#include <string_view>

namespace health::fake
{

class HealthMonitor final : public IHealthMonitor
{
  public:
    explicit HealthMonitor(HealthMonitorConfig config);

    [[nodiscard]] std::unique_ptr<AliveSupervision> CreateAliveSupervision() override;
    [[nodiscard]] std::string_view                  Name() const override;

    [[nodiscard]] int SupervisionsCreated() const;

  private:
    HealthMonitorConfig config_;
    int                 supervisions_created_ = 0;
};

} // namespace health::fake

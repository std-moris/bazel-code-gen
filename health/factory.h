#pragma once

#include "health/i_health_monitor.h"

#include <memory>

namespace health
{
[[nodiscard]] std::unique_ptr<IHealthMonitor> CreateHealthMonitor(const HealthMonitorConfig& config);

} // namespace health

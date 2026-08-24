#include "health/factory.h"
#include "health/real_a/health_monitor.h"

#include <memory>

namespace health
{

std::unique_ptr<IHealthMonitor> CreateHealthMonitor(const HealthMonitorConfig& config)
{
    return std::make_unique<real_a::HealthMonitor>(config);
}

} // namespace health

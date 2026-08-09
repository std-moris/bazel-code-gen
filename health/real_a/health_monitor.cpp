#include "health/real_a/health_monitor.h"
#include "health/real_a/generated/config.h"
#include "health/real_a/random_header.h"

#include <memory>
#include <string_view>
#include <utility>

namespace health::real_a
{

HealthMonitor::HealthMonitor(HealthMonitorConfig config) : config_(std::move(config)), magic_(kMagic) {}

std::unique_ptr<AliveSupervision> HealthMonitor::CreateAliveSupervision()
{
    return std::make_unique<AliveSupervision>();
}

std::string_view HealthMonitor::Name() const
{
    return health::real_a::kApplicationName;
}

} // namespace health::real_a

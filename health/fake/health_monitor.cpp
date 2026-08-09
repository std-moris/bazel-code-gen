#include "health/fake/health_monitor.h"

#include <memory>
#include <string_view>
#include <utility>

namespace health::fake
{

HealthMonitor::HealthMonitor(HealthMonitorConfig config)
  : config_(std::move(config))
{
}

std::unique_ptr<AliveSupervision> HealthMonitor::CreateAliveSupervision()
{
    ++supervisions_created_;
    return std::make_unique<AliveSupervision>();
}

std::string_view HealthMonitor::Name() const
{
    return "fake";
}

int HealthMonitor::SupervisionsCreated() const
{
    return supervisions_created_;
}

} // namespace health::fake

#include "health/factory.h"
#include "health/real_b/generated/config.h"

#include <memory>
#include <string_view>
#include <utility>

namespace
{
// if implementation is trivial, we can also use a single TU, no need for additional files if not needed
class RealBHealthMonitor final : public health::IHealthMonitor
{
  public:
    explicit RealBHealthMonitor(health::HealthMonitorConfig config) : config_(std::move(config)) {}

    [[nodiscard]] std::unique_ptr<health::AliveSupervision> CreateAliveSupervision() override
    {
        return std::make_unique<health::AliveSupervision>();
    }

    [[nodiscard]] std::string_view Name() const override
    {
        return health::real_b::kApplicationName;
    }

  private:
    health::HealthMonitorConfig config_;
};

} // namespace

namespace health
{

std::unique_ptr<IHealthMonitor> CreateHealthMonitor(const HealthMonitorConfig& config)
{
    return std::make_unique<RealBHealthMonitor>(config);
}

} // namespace health

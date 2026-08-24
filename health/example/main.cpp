#include "health/factory.h"

#include <iostream>
#include <memory>

int main()
{
    const health::HealthMonitorConfig config{};

    const std::unique_ptr<health::IHealthMonitor> monitor = health::CreateHealthMonitor(config);

    std::cout << "linked health monitor: " << monitor->Name() << '\n';

    return 0;
}

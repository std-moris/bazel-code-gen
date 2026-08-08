#ifndef $GUARD
#define $GUARD 

#include <cstdint>

namespace $NAMESPACE
{

constexpr auto kApplicationName = $APPLICATION_NAME;

enum class Checkpoint : std::uint8_t
{
    $CHECKPOINTS
};

} // $NAMESPACE

#endif // $GUARD
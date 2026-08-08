
#include "path/to/generated/file.h"
#include <type_traits>

int main()
{
    using generated::space::Checkpoint;

    static_assert(std::underlying_type_t<Checkpoint>(Checkpoint::Checkpoint1) == 0);
    static_assert(std::underlying_type_t<Checkpoint>(Checkpoint::Checkpoint_2) == 1);
    static_assert(std::underlying_type_t<Checkpoint>(Checkpoint::Checkpoint_3) == 2);

    return 0;
}

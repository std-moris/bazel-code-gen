
#include "path/to/generated/file.h"
#include <type_traits>

int main()
{
    static_assert(std::underlying_type_t<generated::space::Checkpoint>(generated::space::Checkpoint::Checkpoint1) == 0);
}
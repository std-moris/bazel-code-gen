# C++ header generation from single json config

## Motivation
This is to show how to use BAZEL in order to generate a header file with information from a config file. Useful for situations where you dont want a client to pass down strings but enums to avoid typos.

Further reading: https://github.com/bazelbuild/examples/blob/main/rules/generating_code/BUILD

## Example of generated code
bazel-out/k8-fastbuild/bin/path/to/generated/file.h

```cpp
#ifndef BAZEL_OUT_K8_FASTBUILD_BIN_PATH_TO_GENERATED_FILE_H_
#define BAZEL_OUT_K8_FASTBUILD_BIN_PATH_TO_GENERATED_FILE_H_ 

#include <cstdint>

namespace generated::space
{

constexpr auto kApplicationName = "Application";

enum class Checkpoint : std::uint8_t
{
    Checkpoint1 = 0,
    Checkpoint_2 = 1,
    Checkpoint_3 = 2,
};

} // generated::space

#endif // BAZEL_OUT_K8_FASTBUILD_BIN_PATH_TO_GENERATED_FILE_H_
```
load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("//conf_generator:conf_generator.bzl", "cc_generated_library")

cc_generated_library(
    name = "file",
    output_path = "path/to/generated",
    json_file = "conf.json",
    namespace = "generated::space",
)

cc_binary(
    name = "code_gen_example",
    srcs = ["main.cpp"],
    deps = [":file"],
)

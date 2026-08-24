load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("//conf_generator:conf_generator.bzl", "cc_generated_library")

cc_generated_library(
    name = "config",
    output_path = "generated",
    json_file = "config.json",
    namespace = "health::real_b",
)


cc_library(
    name = "factory",
    srcs = ["factory.cpp"],
    visibility = ["//health:__pkg__"],
    deps = [
        "//health:factory_api",
        ":config",
    ],
)

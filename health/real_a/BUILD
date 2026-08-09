load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("//conf_generator:conf_generator.bzl", "cc_generated_library")

cc_generated_library(
    name = "config",
    output_path = "generated",
    json_file = "config.json",
    namespace = "health::real_a",
)

cc_library(
    name = "monitor_impl",
    srcs = [
        "health_monitor.cpp",
    ],
    hdrs = [
        "health_monitor.h",
        "random_header.h",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "//health:interface",
        ":config"
    ],
)

cc_library(
    name = "factory",
    srcs = ["factory.cpp"],
    # important, else the client can include the headers frm the monitor_impl because of transitive dependencies
    implementation_deps = [":monitor_impl"],
    visibility = ["//health:__pkg__"],
    deps = ["//health:factory_api"],
)

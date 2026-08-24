load("@bazel_skylib//rules:common_settings.bzl", "string_flag")
load("@rules_cc//cc:cc_library.bzl", "cc_library")

string_flag(
    name = "hmon",
    build_setting_default = "real_a",
    values = [
        "real_a",
        "real_b",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "hmon_is_real_a",
    flag_values = {":hmon": "real_a"},
)

config_setting(
    name = "hmon_is_real_b",
    flag_values = {":hmon": "real_b"},
)
# ===================================================================================================

cc_library(
    name = "interface",
    hdrs = [
        "alive_supervision.h",
        "i_health_monitor.h",
        "supervised_entity.h",
    ],
    visibility = ["//visibility:public"],
)

# this is what a real_a, real_b and any other implementation will use to construct the health
cc_library(
    name = "factory_api",
    hdrs = ["factory.h"],
    visibility = ["//visibility:public"],
    deps = [":interface"],
)

# this is what clients of health will use. implementation is based on --config=hmon_real_a/b flag
alias(
    name = "health_monitor",
    actual = select({
        ":hmon_is_real_a": "//health/real_a:factory",
        ":hmon_is_real_b": "//health/real_b:factory",
    }),
    visibility = ["//visibility:public"],
)

load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "health_monitor",
    testonly = True,
    srcs = ["health_monitor.cpp"],
    hdrs = ["health_monitor.h"],
    visibility = ["//visibility:public"],
    deps = ["//health:interface"],
)


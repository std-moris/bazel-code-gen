load("@rules_python//python:defs.bzl", "py_binary")

py_binary(
    name = "conf_generator",
    srcs = ["conf_generator.py"],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "template",
    srcs = ["conf_generator_template.h"],
)

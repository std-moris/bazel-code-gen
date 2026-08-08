load("@rules_python//python:defs.bzl", "py_binary")

py_binary(
    name = "conf_generator",
    srcs = ["conf_generator.py"],
    visibility = ["//visibility:public"],
)

# Referenced by the conf_generator rule's private _template_file attr.
filegroup(
    name = "template",
    srcs = ["conf_generator_template.h"],
)

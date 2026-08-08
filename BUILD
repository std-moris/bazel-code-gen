load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("//conf_generator:conf_generator.bzl", "conf_generator")

conf_generator(
    name = "conf_generator",
    json_file = "conf.json",
    out_file="path/to/generated/file.h",
	namespace="generated::space",
)


cc_binary(
	name="code_gen_example",
	srcs = [
		"main.cpp",
		":conf_generator",
	],
)


load("@rules_cc//cc:cc_library.bzl", "cc_library")

def _conf_generator_impl(ctx):
    header = ctx.actions.declare_file(ctx.attr.header_path)

    args = ctx.actions.args()
    args.add("--json_file", ctx.file.json_file)
    args.add("--template", ctx.file._template_file)
    args.add("--out_file", header)
    args.add("--namespace", ctx.attr.namespace)

    ctx.actions.run(
        inputs = [ctx.file.json_file, ctx.file._template_file],
        outputs = [header],
        arguments = [args],
        mnemonic = "ConfGen",
        progress_message = "Generating %{output} from %{input}",
        executable = ctx.executable._gen_tool,
    )

    return [DefaultInfo(files = depset([header]))]

_conf_generator = rule(
    implementation = _conf_generator_impl,
    attrs = {
        "json_file": attr.label(
            allow_single_file = [".json"],
            mandatory = True,
        ),
        "namespace": attr.string(
            mandatory = True,
        ),
        "header_path": attr.string(
            mandatory = True,
            doc = "Path of the generated header, relative to this package.",
        ),
        "_template_file": attr.label(
            allow_single_file = True,
            default = Label(":template"),
        ),
        "_gen_tool": attr.label(
            default = Label(":conf_generator"),
            executable = True,
            cfg = "exec",
        ),
    },
)

def cc_generated_library(
        name,
        json_file,
        namespace,
        output_path,
        **kwargs):
    """Generates a config header and wraps it in a consumable cc_library.

    Args:
      name: Name of the generated cc_library.
      json_file: JSON config to read values from
      namespace: C++ namespace to emit into
      output_path: Path to the generated header path, so consumers
        write `#include "<output_path>/<name>"`
      **kwargs: Passed through to the cc_library (visibility, tags, ...).
    """
    header_path = name + ".h"
    if output_path:
        header_path = output_path + "/" + header_path
    generated = name + "_gen"

    _conf_generator(
        name = generated,
        json_file = json_file,
        namespace = namespace,
        header_path = header_path,
    )

    cc_library(
        name = name,
        hdrs = [":" + generated],
        **kwargs
    )

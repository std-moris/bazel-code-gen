def _impl(ctx):
    args = ctx.actions.args()
    args.add("--json_file", ctx.file.json_file.path)
    args.add("--out_file", ctx.outputs.out_file.path)
    args.add("--namespace", ctx.attr.namespace)
    args.add("--template", ctx.file._template_file.path)

    # Action to call the script.
    ctx.actions.run(
        inputs = [ctx.file.json_file, ctx.file._template_file],
        outputs = [ctx.outputs.out_file],
        arguments = [args],
        progress_message = "Generating config file for %s" % ctx.file.json_file.short_path,
        executable = ctx.executable.gen_tool,
    )

conf_generator = rule(
    implementation = _impl,
    attrs = {
        "json_file": attr.label(
            allow_single_file = True,
            mandatory = True,
        ),
        "out_file": attr.output(),
        "namespace": attr.string(
            mandatory = True,
        ),
        "_template_file": attr.label(
            allow_single_file = True,
            default = Label(":template"),
        ),
        "gen_tool": attr.label(
            default = Label(":conf_generator"),
            executable = True,
            allow_files = True,
            cfg = "exec",
        ),
    },
)
"""Define a transition to define FIXED_SEED downward the dependency graph.
A transition is a modification that works downward the dependency graph. See
https://bazel.build/rules/lib/builtins/transition#transition
"""

def _define_transition_impl(settings):
    # Create a new build setting dictionary to modify the C++ flags
    return {
        "//command_line_option:features": settings["//command_line_option:features"] + ["-DFIXED_SEED"],
    }

define_transition = transition(
    implementation = _define_transition_impl,
    inputs = ["//command_line_option:features"],
    outputs = ["//command_line_option:features"],
)

def _apply_transition_impl(ctx):
    return [ctx.attr.dep[DefaultInfo]]

apply_transition_rule = rule(
    implementation = _apply_transition_impl,
    attrs = {
        "dep": attr.label(),
    },
)

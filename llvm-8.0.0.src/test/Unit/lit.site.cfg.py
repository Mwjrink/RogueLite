## Autogenerated from C:/Development/C++/RogueLite/llvm-8.0.0.src/test/Unit/lit.site.cfg.py.in
## Do not edit!

import sys

config.llvm_src_root = "C:/Development/C++/RogueLite/llvm-8.0.0.src"
config.llvm_obj_root = "C:/Development/C++/RogueLite/llvm-8.0.0.src"
config.llvm_tools_dir = "C:/Development/C++/RogueLite/llvm-8.0.0.src/%(build_mode)s/bin"
config.llvm_build_mode = "%(build_mode)s"
config.enable_shared = 0
config.shlibdir = "C:/Development/C++/RogueLite/llvm-8.0.0.src/%(build_mode)s/bin"

# Support substitution of the tools_dir and build_mode with user parameters.
# This is used when we can't determine the tool dir at configuration time.
try:
    config.llvm_tools_dir = config.llvm_tools_dir % lit_config.params
    config.llvm_build_mode = config.llvm_build_mode % lit_config.params
except KeyError:
    e = sys.exc_info()[1]
    key, = e.args
    lit_config.fatal("unable to find %r parameter, use '--param=%s=VALUE'" % (key,key))

# Let the main config do the real work.
lit_config.load_config(config, "C:/Development/C++/RogueLite/llvm-8.0.0.src/test/Unit/lit.cfg.py")
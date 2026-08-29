import os

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["src/", "include/"])
sources = Glob("src/*.cpp")

library = env.SharedLibrary(
    "bin/a_few_furries_cpp_teaching",
    source=sources,
)

Default(library)

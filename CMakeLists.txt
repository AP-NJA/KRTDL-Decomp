cmake_minimum_required(VERSION 3.0.0)
project(KRTDL-DECOMP)


include_directories("src")
include_directories("include")


set (Executable
    src/Model/Model.cc
    src/State/Intangible.cc
    src/State/Candy_Invincible.cc
)

add_executable(KRTDL-DECOMP
    ${Executable}
)

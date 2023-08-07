cmake_minimum_required(VERSION 3.0.0)
project(KRTDL-DECOMP)

set (Executable
    State/Invincible/Invincible.cc
    State/Invincible/Candy_Invincible.cc
    Model/Model.cc
    State/Invincible/main.cc
)

add_executable(KRTDL-DECOMP
    ${Executable}
)
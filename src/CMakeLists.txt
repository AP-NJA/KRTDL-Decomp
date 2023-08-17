cmake_minimum_required(VERSION 3.0.0)
project(KRTDL-DECOMP)

set (Executable
    State/Invincible.c
    State/Candy_Invincible.c
    Model/Model.c
)

add_executable(KRTDL-DECOMP
    ${Executable}
)

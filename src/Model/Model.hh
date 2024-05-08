#pragma once

#include "Types.hh"

typedef struct Model
{
    u8 pad[0x67 - 0x0];
    u8 x67_displayModel;
} Model;

u8 isVisible(Model * param_1);

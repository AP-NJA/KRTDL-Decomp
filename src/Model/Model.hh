#pragma once

#include "Types.hh"

typedef struct Model
{
    u8 pad[0x67 - 0x0];
    bool x67_displayModel;
} Model;

bool isVisible(Model * param_1);

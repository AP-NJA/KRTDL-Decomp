#pragma once

#include "Types.hh"
#include "Model/Model.hh"

typedef struct Guard
{
    Model * x0_modelData;
    bool x4_enableGuardState;
    bool x5_enableGuardStateFlash;
    u8 pad[0x6 - 0x4];
    u32 x8_guardStateFlashCycle;
} Guard;

void initializeGuardFlashCycle(Guard * param_1);
void updateGuardState(Guard * param_1);
void playerGuardingCheck(Guard * param_1, bool param_2);

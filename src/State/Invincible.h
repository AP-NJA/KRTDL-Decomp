#ifndef INVINCIBLE_H_
#define INVINCIBLE_H_

#include "../../include/Types.h"
#include "../Model/Model.h"

typedef struct PlayerInvinc 
{
    u32 invincFrames;
    u32 flashCycle;
    bool wasHurt;
    bool disablePity;
} PlayerInvinc;

bool canSetInvinc(PlayerInvinc * param_1); 
u32 decrementInvincFrames(PlayerInvinc * param_1);
u32 manageFlashCycle(PlayerInvinc * param_1);

typedef struct CandyInvinc
{
    Model * modelData;
    PlayerInvinc playerInvincData;
    bool enableInvincFlash;
    bool mightyEffect;
    bool sparkleEffect;
    u32 candyTimer;
    u32 rainbowTimer;
    u32 rainbowCycle;
    u8 rgbRedValue;
    u8 rgbGreenValue;
    u8 rgbBlueValue;
} CandyInvinc;

u32 decrementCandyTimer(CandyInvinc * param_1);
bool enableSparkle(CandyInvinc * param_1);
bool disableSparkle(CandyInvinc * param_1);
void manageSparkleEffect(CandyInvinc * param_1);
u32 decrementRainbowTimer(CandyInvinc * param_1);
u32 manageRainbowCycle(CandyInvinc * param_1);
void rgbCurrentColor(CandyInvinc * param_1);
#endif

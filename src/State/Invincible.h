#ifndef INVINCIBLE_H_
#define INVINCIBLE_H_

#include "../../include/Types.h"

typedef struct PlayerInvinc 
{
    u32 invincFrames;
    u32 flashCycle;
    u8 wasHurt;
    u8 disablePity;
    u8 enableInvincFlash;
} PlayerInvinc;

u8 canSetInvinc(PlayerInvinc * param_1);
void decrementFrames(PlayerInvinc * param_1);
void manageFlashCycle(PlayerInvinc * param_1);

typedef struct CandyInvinc
{
    u32 refAddr;
    u8 mightyEffect;
    u8 sparkleEffect;
    u32 candyTimer;
    u32 rainbowTimer;
    u32 rainbowCycle;
} CandyInvinc;

void candyTimer(CandyInvinc * param_1);
void enableSparkle(CandyInvinc * param_1);
void disableSparkle(CandyInvinc * param_1);
void manageSparkleEffect(CandyInvinc * param_1);
void rainbowCycle(CandyInvinc * param_1);
void rainbowTimer(CandyInvinc * param_1);

#endif

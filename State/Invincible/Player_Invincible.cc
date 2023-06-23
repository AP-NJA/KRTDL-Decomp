#include "Player_Invincible.hh"
#include <cstdio>

namespace Invinc
{
    u8 InvincData::isInvinc(void)
    {
        if ((x0_invincFrames != 0) || (x8_wasHurt != 0) || (x9_vulnerable != 0))
        {
            return 1;
        }

        return 0;
    }

    void InvincData::decrementFrames(void)
    {
        if (x0_invincFrames < 1)
        {
            x0_invincFrames = 0;
            return;
        }

        x0_invincFrames -= 1;
    }
}

// int main(void)
// {
//     Player_Invinc::InvincData *invincData;

//     invincData->x0_invincFrames = 1000;

//     for (u32 i = 0; i < 1500; i++)
//     {
//         invincData->decrementFrames();

//         printf("Invinc Frames: %lu\n", invincData->x0_invincFrames);
//         printf("Is Invinc: %hhu\n", invincData->isInvinc());
//     }
    
//     return 0;
// }
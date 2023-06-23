#include "Candy_Invincible.hh"
#include <cstdio>
namespace Invinc
{   
    void CandyData::mightyEffect(void)
    {
        InvincData player;
        
        if (player.isInvinc() == 0)
        {
            x11_mightyEffect = 0;
            return;
        }

        x11_mightyEffect = 1;
    }
}

int main(void)
{
    Invinc::CandyData *player;
    Invinc::InvincData *invincData;

    invincData->x0_invincFrames = 9;

    for (u32 i = 0; i < 10; i++)
    {
        invincData->decrementFrames();
        player->mightyEffect();

        printf("Invinc Frames: %lu\n", invincData->x0_invincFrames);
        printf("Is Invinc: %hhu\n", invincData->isInvinc());
        printf("Mighty Effect: %hhu\n", player->x11_mightyEffect);
        printf("====================\n");
    }

    return 0;
}
#include "Invincible.hh"
#include <cstdio>

namespace State
{
    namespace Invincible
    {
        u8 InvincData::isInvinc(void)
        {
            if ((m_invincFrames != 0) || (m_wasHurt != 0) || (m_vulnerable != 0))
            {
                return 1;
            }

            return 0;
        }

        void InvincData::decrementFrames(void)
        {
            if (m_invincFrames < 1)
            {
                m_invincFrames = 0;
                return;
            }

            m_invincFrames -= 1;
            return;
        }
    }
}

int main(void)
{
    State::Invincible::InvincData *player;

    player->m_invincFrames = 10;
    player->m_wasHurt = 0;
    player->m_vulnerable = 0;

    for (u32 i = 0; i < 20; i++)
    {
        player->decrementFrames();
        player->mightyEffect();
        
        printf("====================\n");
        printf("Invinc Frames: %lu\n", player->m_invincFrames);
        printf("Is Invinc: %hhu\n", player->isInvinc());
        printf("Mighty Effect: %hhu\n", player->m_mightyEffect);
    }

    return 0;
}
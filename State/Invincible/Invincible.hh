#pragma once

#include "../../Common/Types.hh"

namespace State
{    
    namespace Invincible
    {
        class InvincData
        {
            public:
                u32 m_refAddr;
                u32 m_invincFrames;
                u32 m_flashCycles;
                u8 m_wasHurt;
                u8 m_vulnerable;
                u8 m_mightyEffect;
            
            u8 isInvinc(void);
            void decrementFrames(void);
            void mightyEffect(void);
            void manageFlashCycles(void);
        };
    }
}
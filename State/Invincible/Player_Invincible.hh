#pragma once

#include "../../Common/Types.hh"

namespace Invinc
{
    class InvincData
    {
        public:
            u32 x0_invincFrames;
            u32 x4_flashCycles;
            u8 x8_wasHurt;
            u8 x9_vulnerable;

        u8 isInvinc(void);
        void decrementFrames(void);
    };
};
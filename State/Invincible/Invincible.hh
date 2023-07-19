#pragma once

#include "../../Common/Types.hh"
#include "../../CharModel/Model.hh"

namespace State
{    
    namespace Invincible
    {
        class InvincData
        {
            public:            
                u32 m_invincFrames;
                u32 m_flashCycle;
                u8 m_wasHurt;
                u8 m_vulnerable;
                
                u8 isInvinc(void);
                void decrementFrames(void);
                void manageFlashCycles(void);
        };

        class CandyData : public InvincData, public CharModel::Model
        {   
            public:
                u32 m_candyTimer;
                u32 m_rainbowCycle;
                u8 m_mightyEffect;
                u8 m_sparkleEffect;
                u8 m_rainbowTimer;
                
                void mightyEffect(void);
                void enableSparkle(void);
                void disableSparkle(void);
                void manageSparkleEffect(void);
                void candyTimer(void);
                void rainbowCycle(void);
        };
    }
}
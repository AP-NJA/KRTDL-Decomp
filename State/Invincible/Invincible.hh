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
                static u32 m_invincFrames;
                static u32 m_flashCycle;
                static u8 m_wasHurt;
                static u8 m_vulnerable;
                
                static u8 isInvinc(void);
                static void decrementFrames(void);
                static void manageFlashCycles(void);
        };

        class CandyData
        {   
            public:
                static u32 m_candyTimer;
                static u32 m_rainbowCycle;
                static u8 m_mightyEffect;
                static u8 m_sparkleEffect;
                static u8 m_x18;

                static void mightyEffect(void);
                static void enableSparkle(void);
                static void disableSparkle(void);
                static void manageSparkleEffect(void);
                static void candyTimer(void);
                static void rainbowCycle(void); //TO-DO: Remind myself how the hell this works
        };
    }
}
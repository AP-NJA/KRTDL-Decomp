#include "Invincible.hh"
#include <cstdio>

namespace State
{
    namespace Invincible
    {          
        void CandyData::mightyEffect(void)
        {
            if (isInvinc() == 0)
            {
                m_mightyEffect = 0;
                return;
            }

            m_mightyEffect = 1;
            return;
        }
        
        void CandyData::enableSparkle(void)
        {
            if (m_sparkleEffect == 0)
            {
                m_sparkleEffect = 1;
                return;
            }
        }
        
        void CandyData::disableSparkle(void)
        {
            if (m_sparkleEffect != 0)
            {
                m_sparkleEffect = 0;
                return;
            }
        }

        void CandyData::manageSparkleEffect(void)
        {                                                                                                
            if ((m_mightyEffect == 0) || (isVisible() == 0))
            {
                disableSparkle();
                return;
            }

            enableSparkle();
            return;
        }

        void CandyData::candyTimer(void)
        {
            if (m_candyTimer < 1)
            {
                m_mightyEffect = 0;
                return;
            }

            m_candyTimer -= 1;
        }

        void CandyData::rainbowCycle(void)
        {                        
            if ((m_mightyEffect == 0) || ((m_x18 & 1) != 0)) 
            {
                m_rainbowCycle = 0;
                return;
            }

            if (m_rainbowCycle > 47)
            {
                m_rainbowCycle = 0;
            }

            m_rainbowCycle += 1;
        }
    }
}
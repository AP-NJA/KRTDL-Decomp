#include "Invincible.hh"

namespace State
{
    namespace Invincible
    {                  
        void Candy::candyTimer(void)
        {   
            if (m_candyTimer < 1)
            {
                m_candyTimer = 0;
                m_mightyEffect = 0;
                return;
            }

            m_candyTimer -= 1;
            m_mightyEffect = 1;
        }
        
        void Candy::enableSparkle(void)
        {
            if (m_sparkleEffect == 0)
            {
                m_sparkleEffect = 1;
                return;
            }            
        }
        
        void Candy::disableSparkle(void)
        {
            if (m_sparkleEffect != 0)
            {
                m_sparkleEffect = 0;
                return;
            }
        }

        void Candy::manageSparkleEffect(void)
        {                                                                                                            
            m_sparkleEffect = 0;
            
            if ((m_mightyEffect == 0) || (isVisible() == 0))
            {
                disableSparkle();
                return;
            }
            
            enableSparkle();
        }

        void Candy::rainbowCycle(void)
        {                        
            if ((m_mightyEffect == 0) && (m_rainbowTimer == 0))
            {
                m_rainbowCycle = 0;
                return;
            }
            
            if (m_rainbowTimer & 1 == 0)
            {
                m_rainbowCycle += 1;
            }

            if (m_rainbowCycle == 48)
            {
                m_rainbowCycle = 0;
            }
        }
    }
}
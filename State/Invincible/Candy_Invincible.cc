#include "Invincible.hh"

namespace State
{
    namespace Invincible
    {   
        u32 CandyData::m_candyTimer;
        u32 CandyData::m_rainbowCycle;
        u8 CandyData::m_mightyEffect;
        u8 CandyData::m_sparkleEffect;
        u8 CandyData::m_x18;
        
        void CandyData::mightyEffect(void)
        {               
            InvincData invinc;
            
            if (invinc.isInvinc() == 0)
            {
                m_mightyEffect = 0;
                return;
            }

            m_mightyEffect = 1;
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
            CharModel::Model model;
            
            if ((m_mightyEffect == 0) || (model.isVisible() == 0))
            {
                disableSparkle();
                return;
            }

            enableSparkle();
            return;
        }

        void CandyData::candyTimer(void)
        {
            if (m_mightyEffect == 0)
            {
                m_candyTimer = 0;
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
#include "Invincible.hh"

namespace State
{
    namespace Invincible
    {           
        u8 Invinc::isInvinc(void)
        {
            if ((m_invincFrames != 0) || (m_wasHurt != 0) || (m_vulnerable != 0))
            {
                return 1;
            }

            return 0;
        }

        void Invinc::decrementFrames(void)
        {
            if (m_invincFrames < 1)
            {
                m_invincFrames = 0;
                return;
            }

            m_invincFrames -= 1;
        }

        void Invinc::manageFlashCycles(void)
        {            
            if (isInvinc() == 0)
            {
                m_flashCycle = 0;
                return;
            }
            
            m_flashCycle += 1;

            if (m_flashCycle == 20)
            {
                m_flashCycle = 16;
            }
        }
    }
}
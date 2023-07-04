#include "Invincible.hh"

namespace State
{
    namespace Invincible
    {
        u32 InvincData::m_invincFrames;
        u32 InvincData::m_flashCycle;
        u8 InvincData::m_wasHurt;
        u8 InvincData::m_vulnerable;
        
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
        }

        void InvincData::manageFlashCycles(void)
        {            
            if (isInvinc() == 0)
            {
                m_flashCycle = 0;
                return;
            }
            
            if (m_flashCycle > 19)
            {
                m_flashCycle = 16;
            }

            m_flashCycle += 1;
        }
    }
}
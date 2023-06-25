#include "Invincible.hh"

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

        void InvincData::manageFlashCycles(void)
        {
            if (m_flashCycles > 19)
            {
                m_flashCycles = 16;
                return;
            }

            m_flashCycles += 1;
            return;
        }
    }
}
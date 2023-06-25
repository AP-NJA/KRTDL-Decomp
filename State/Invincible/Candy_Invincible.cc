#include "Invincible.hh"

namespace State
{
    namespace Invincible
    {
        void InvincData::mightyEffect(void)
        {
            if (isInvinc() == 0)
            {
                m_mightyEffect = 0;
                return;
            }

            m_mightyEffect = 1;
            return;
        }

        void InvincData::manageFlashCycles(void)
        {
            if (isInvinc() == 0)
            {
                return;
            }

            if (m_flashCycles > 19)
            {
                m_flashCycles = 12;
            }

            m_flashCycles += 1;

            return;
        }
    }
}
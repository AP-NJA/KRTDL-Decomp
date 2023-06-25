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
    }
}
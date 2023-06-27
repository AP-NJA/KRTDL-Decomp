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
        }

        void InvincData::manageSparkleEffect(void)
        {
            if (m_mightyEffect == 0)
            {
                m_sparkleEffect = 0;
                return;
            }

            m_sparkleEffect = 1;
        }
    }
}
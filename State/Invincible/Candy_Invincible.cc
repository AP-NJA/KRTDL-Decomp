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

        void InvincData::enableSparkle(void)
        {
            if (m_sparkleEffect == 0)
            {
                m_sparkleEffect = 1;
                return;
            }
        }
        
        void InvincData::disableSparkle(void)
        {
            if (m_sparkleEffect != 0)
            {
                m_sparkleEffect = 0;
                return;
            }
        }

        void InvincData::manageSparkleEffect(void)
        {
            CharModel::Model model;

            if (m_mightyEffect != 0)
            {
                if (model.isVisible() == 0)
                {
                    disableSparkle();
                    return;
                }

                enableSparkle();
            }  
        }
    }
}
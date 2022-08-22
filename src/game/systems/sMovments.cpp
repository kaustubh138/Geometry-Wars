#include "sMovments.hpp"
#include "../game.hpp"

namespace GeometryWars
{	

	void sMovements::configPlayerVelocity(Input direction)
	{
		switch (direction)
		{
			case (Input::LEFT):
			{
				m_PlayerVelocity.x -= GAME->m_Config->PlayerConfig->Speed;
				break;
			}

			case (Input::RIGHT):
			{
				m_PlayerVelocity.x += GAME->m_Config->PlayerConfig->Speed;
				break;
			}

			case (Input::UP):
			{
				m_PlayerVelocity.y += GAME->m_Config->PlayerConfig->Speed;
				break;
			}

			case(Input::DOWN):
			{
				m_PlayerVelocity.y -= GAME->m_Config->PlayerConfig->Speed;
				break;
			}

			default:
				break;
		}
	}
	
	void sMovements::updateEntities()
	{
		for (auto e : GAME->m_EManager.GetEntities())
		{
			if (e->GetTag() == EntityTag::Player)
			{
				GAME->m_Player->cTransform->position += m_PlayerVelocity;


			}
		}
	}
}

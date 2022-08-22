#pragma once

#include "../system.hpp"
#include "../../ecs/components/CInput.hpp"

namespace GeometryWars
{
	class sMovements
		: public Systems
	{
	public:		
		virtual void operator()(Component& c) override
		{
			CInput direction;
			CHECK_CAST(CInput, direction)
			configPlayerVelocity(direction.GetInput());
		}

	private:
		glm::vec2 m_PlayerVelocity;

	private:
		void configPlayerVelocity(Input direction);
		virtual void updateEntities() override;
	};
}
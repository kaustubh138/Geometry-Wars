#pragma once

#include "ecs/Component.hpp"
#include "glm/glm.hpp"

namespace GeometryWars
{
	class CTransform
		: public Component
	{
		polyType
	public:
		glm::vec2 position{ 0.0f, 0.0f };
		glm::vec2 velocity{ 0.0f, 0.0f };
		float angle       { 0.0f };

		CTransform(glm::vec2& pos, glm::vec2& velocity, float angle)
			: position(pos), velocity(velocity), angle(angle)
		{}
	};
}
#pragma once

#include "ecs/Component.hpp"

namespace GeometryWars
{
	class CCollision
		: public Component
	{
		polyType
	public:
		float radius = 0;
	
		CCollision(float collisionRadius)
			: radius(0)
		{}
	};
}
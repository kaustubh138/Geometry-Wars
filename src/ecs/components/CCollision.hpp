#pragma once

#include "ecs/Component.hpp"

namespace GeometryWars
{
	class CCollision
		: public Component
	{
	public:
		float radius = 0;
	
		CCollision(float collisionRadius)
			: radius(0)
		{}
	};
}
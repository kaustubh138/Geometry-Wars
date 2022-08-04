#pragma once

#include "ecs/Component.hpp"

namespace GeometryWars
{
	class CLifeSpan
		: public Component
	{
	public:
		int Remaining = 0;
		int Total = 0;

		CLifeSpan(int total)
			: Remaining(total), Total(total)
		{}
	};
}
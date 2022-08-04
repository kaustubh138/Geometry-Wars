#pragma once

#include "ecs/Component.hpp"

namespace GeometryWars
{
	class CInput
		: public Component
	{
	public:
		bool Up, Down, Left, Right, LeftMouse, RightMouse = false;
	};
}
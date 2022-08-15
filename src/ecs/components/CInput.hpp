#pragma once

#include "ecs/Component.hpp"

namespace GeometryWars
{
	enum class Input
		: unsigned int
	{
		NONE	 = 0,
		UP		 = 1,
		DOWN	 = 2,
		LEFT	 = 3,
		RIGHT	 = 4,
		LFTMOUSE = 5,
		RGTMOUSE = 6
	};

	class CInput
		: public Component
	{
		polyType
	private:
		Input activeIn = Input::NONE;

	public:
		void SetInput(Input i) { activeIn = i; }
		Input GetInput() { return activeIn; }
	};
}
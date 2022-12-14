#pragma once

namespace GeometryWars
{
#define polyType virtual void foo() override {}

	enum class ComponentType
	{
		Collison,
		Input,
		LifeSpan,
		Shape,
		Transform
	};

	// Base Class for all components
	class Component
	{
	private:
		virtual void foo() = 0; // to make all Components polymorphic type
	};
}
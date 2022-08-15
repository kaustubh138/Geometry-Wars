#pragma once

#include <SFML/Graphics.hpp>
#include "ecs/Component.hpp"

namespace GeometryWars
{
	class CShape
		: public Component
	{
		polyType
	public:
		sf::CircleShape Shape;

		CShape(float radius, unsigned int points, const sf::Color& fillColor, const sf::Color& outline, float thickness)
			: Shape(radius, points)
		{
			Shape.setOutlineColor(outline);
			Shape.setFillColor(fillColor);
			Shape.setOutlineThickness(thickness);
			Shape.setOrigin(radius, radius);
		}
	};
}
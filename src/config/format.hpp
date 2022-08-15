#pragma once

#include <string>
#include <glm/glm.hpp>

namespace GeometryWars
{
	namespace Config
	{

		struct Window
		{
			int Width, Height;
			int FrameLimit;
			int FullScreen;
		};

		struct Font
		{
			std::string File;
			int Size;
			glm::vec3 Color;
		};

		struct Player
		{
			int ShapeRadius, CollisionRadius, Speed, OutlineThickness, ShapeVertices;
			glm::vec3 FillColor, OutlineColor; // RGB
		};

		struct Enemy
		{
			int ShapeRadius, CollisionRadius;
			int OutlineThickness;
			glm::vec3 FillColor, OutlineColor; // RGB
			int SpeedMin, SpeedMax;
			int VerticesMin, VerticesMax;
			int LifeSpan;
			int SpawnInterval;
		};

		struct Bullet
		{
			int ShapeRadius, CollisionRadius;
			glm::vec3 FillColor, OutlineColor; // RGB
			int OutlineThickness;
			int ShapeVertices;
			int Speed;
			int LifeSpan;
			int SpecialBulletAmount;
		};
	}
}
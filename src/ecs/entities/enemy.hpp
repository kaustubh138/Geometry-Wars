#pragma once

#include "../Entity.hpp"
#include "../components/CCollision.hpp"
#include "../components/CShape.hpp"
#include "../components/CInput.hpp"
#include "../components/CLifeSpan.hpp"
#include "../components/CTransform.hpp"

namespace GeometryWars
{
	class Enemey
		: public Entity
	{
	public:
		std::shared_ptr<CCollision> cCollision;
		std::shared_ptr<CShape>		cShape;
		std::shared_ptr<CInput>		cInput;
		std::shared_ptr<CTransform> cTransform;
	};
}
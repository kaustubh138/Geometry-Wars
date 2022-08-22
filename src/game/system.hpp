#pragma once

#include "glm/glm.hpp"
#include "game.hpp"
#include "../ecs/Component.hpp"

namespace GeometryWars
{

#define GAME Game::GetInstance()

/*
* Usage:
*	Ex.
*		CInput direction;
*		CHECK_CAST(CInput, direction)
*/
#define CHECK_CAST(comp_type, var_cast_to) \
	try { \
		var_cast_to = dynamic_cast<comp_type&>(c);\
	} catch (std::bad_cast) { \
		std::cerr << "[ERROR] Invalid system use" << std::endl;\
		exit(-1);\
	}

	class Systems
	{
	private:
		static Game* m_Game;

	public:
		static void InitSystems(Game* g) { Systems::m_Game = g; }

		virtual void operator()(Component& c) = 0;
		virtual void updateEntities() = 0;

		~Systems() { delete m_Game; }
	};
}
#pragma once

#include "ecs/EntityManager.hpp"
#include "ecs/Entity.hpp"
#include "ecs/entities/player.hpp"
#include "sfml.hpp"

#include "game_state.hpp"
#include "config/config.hpp"

namespace GeometryWars
{
	class Game
	{
		friend class Systems;

	private:
		sf::RenderWindow m_Window;
		sf::Font m_Font;
		sf::Text m_ScoreText;

	public:
		std::unique_ptr<Config> m_Config;
		std::unique_ptr<GameState> m_State;
		std::shared_ptr<Player> m_Player;

		EntityManager m_EManager;
	
	private:
		void Configure();
		bool init();
	
	public:
		void Run();
	};
}



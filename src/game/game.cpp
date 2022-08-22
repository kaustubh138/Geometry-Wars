#include "game.hpp"

namespace GeometryWars
{
	Game* Game::m_Instance = nullptr;

	Game::Game()
	{
		init();
		Configure();
	}

	void Game::Configure()
	{
		// Initialize Game Window
		if (!m_Config->WindowConfig->FullScreen)
			m_Window.create(sf::VideoMode(m_Config->WindowConfig->Width, m_Config->WindowConfig->Height), "Geometry Wars", sf::Style::Close);
		else
		{
			auto fullScreenMode(sf::VideoMode::getFullscreenModes());
			m_Window.create(fullScreenMode[0], "Geometry Wars", sf::Style::Fullscreen);
		}
		m_Window.setFramerateLimit(m_Config->WindowConfig->FrameLimit);
		
		// Configure Font
		if (!m_Font.loadFromFile(m_Config->FontConfig->File))
			std::cerr << "[ERROR] Failed to load font" << std::endl;

		// Initialize Game State
		m_State = std::make_unique<GameState>();

		// Configure Score Text
		m_ScoreText.setFont(m_Font);
		m_ScoreText.setCharacterSize(m_Config->FontConfig->Size);
		m_ScoreText.setFillColor(sf::Color(m_Config->FontConfig->Color.x, m_Config->FontConfig->Color.y, m_Config->FontConfig->Color.z));
		m_ScoreText.setPosition(0, 0);
		m_ScoreText.setString(std::to_string(m_State->Score));
	}

	bool Game::init()
	{
		// Read Configurations
		m_Config = std::make_unique<Config::Config>();
		m_Config->Read();

		// Randomize Enemy Spawn Time
		srand(time(0));

		return false;
	}
}
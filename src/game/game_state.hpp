#pragma once

namespace GeometryWars
{
	struct GameState
	{
		int Score = 0;
		int CurrentFrame = 0;
		int LastEnemySpawnTime = 0;
		bool m_Paused = false;
		bool m_Running = true;

		GameState() = default;
	};
}
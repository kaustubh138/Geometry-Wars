#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

#include "tags.hpp"
#include "format.hpp"
#include <unordered_map>

namespace GeometryWars
{
	class Config
	{
	public:
		std::unique_ptr<Window> WindowConfig;
		std::unique_ptr<Font> FontConfig;
		std::unique_ptr<Player> PlayerConfig;
		std::unique_ptr<Enemy> EnemyConfig;
		std::unique_ptr<Bullet> BulletConfig;

	public:
		Config() = default;
		~Config() = default;
		
		void Read(const char* file_name = "config.txt");
	
	private:
		void conf(std::istringstream& stream, WindowTag);
		void conf(std::istringstream& stream, FontTag);
		void conf(std::istringstream& stream, PlayerTag);
		void conf(std::istringstream& stream, EnemyTag);
		void conf(std::istringstream& stream, BulletTag);
	};


}

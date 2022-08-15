#include "config.hpp"
#include <functional>

namespace GeometryWars
{
	namespace Config
	{
		void Config::Read(const char* file_name)
		{
			// Make mapping
			std::unordered_map<std::string, std::size_t> map;
			map.insert({ "Window", 1 });
			map.insert({ "Font", 2 });
			map.insert({ "Player", 3 });
			map.insert({ "Enemy", 4 });
			map.insert({ "Bullet", 5 });

			std::ifstream file{ file_name };
			if (!file.is_open())
			{
				std::cerr << "[ERROR] Error opening config file!" << std::endl;
				exit(-1);
			}

			std::string line, identifier;
			while (!file.eof())
			{
				std::getline(file, line, '\n');
				std::istringstream lineStream(line);
				lineStream >> identifier;

				/*
				* Mapping:
				*	Tag		: Id
				*	Window	: 1
				*	Font	: 2
				*	Player	: 3
				*	Enemy	: 4
				*	Bullet	: 5
				*/

				switch (std::get<1>(*map.find(identifier)))
				{
				case (1):
				{
					// Window
					conf(lineStream, WindowTag{});
					break;
				}

				case (2):
				{
					//Font
					conf(lineStream, FontTag{});
					break;
				}

				case (3):
				{
					// Player
					conf(lineStream, PlayerTag{});
					break;
				}

				case (4):
				{
					// Enemy
					conf(lineStream, EnemyTag{});
					break;
				}

				case(5):
				{
					// Bullet
					conf(lineStream, BulletTag{});
					break;
				}

				default:
				{
					std::cerr << "[FATAL ERROR] Invalid Config File!" << std::endl;
					exit(-1);
					break;
				}
				}
			}
		}

		void Config::conf(std::istringstream& stream, WindowTag)
		{
			WindowConfig = std::make_unique<Window>();
			stream >> WindowConfig->Width;
			stream >> WindowConfig->Height;
			stream >> WindowConfig->FrameLimit;
			stream >> WindowConfig->FullScreen;
		};

		void Config::conf(std::istringstream& stream, FontTag)
		{
			FontConfig = std::make_unique<Font>();
			stream >> FontConfig->File;
			stream >> FontConfig->Size;

			int R, G, B;
			stream >> R;
			stream >> G;
			stream >> B;

			FontConfig->Color = glm::vec3(R, G, B);
		}

		void Config::conf(std::istringstream& stream, PlayerTag)
		{
			PlayerConfig = std::make_unique<Player>();
			stream >> PlayerConfig->ShapeRadius;
			stream >> PlayerConfig->CollisionRadius;
			stream >> PlayerConfig->Speed;

			int R, G, B;

			stream >> R;
			stream >> G;
			stream >> B;
			PlayerConfig->FillColor = glm::vec3(R, G, B);

			stream >> R;
			stream >> G;
			stream >> B;
			PlayerConfig->OutlineColor = glm::vec3(R, G, B);

			stream >> PlayerConfig->OutlineThickness;
			stream >> PlayerConfig->ShapeVertices;
		}

		void Config::conf(std::istringstream& stream, EnemyTag)
		{
			EnemyConfig = std::make_unique<Enemy>();
			stream >> EnemyConfig->ShapeRadius;
			stream >> EnemyConfig->CollisionRadius;
			stream >> EnemyConfig->SpeedMin;
			stream >> EnemyConfig->SpeedMax;

			int R, G, B;

			stream >> R;
			stream >> G;
			stream >> B;
			EnemyConfig->OutlineColor = glm::vec3(R, G, B);
			stream >> EnemyConfig->OutlineThickness;

			stream >> EnemyConfig->VerticesMin;
			stream >> EnemyConfig->VerticesMax;

			stream >> EnemyConfig->LifeSpan;
			stream >> EnemyConfig->SpawnInterval;
		}

		void Config::conf(std::istringstream& stream, BulletTag)
		{
			BulletConfig = std::make_unique<Bullet>();
			stream >> BulletConfig->ShapeRadius;
			stream >> BulletConfig->CollisionRadius;
			stream >> BulletConfig->Speed;

			int R, G, B;

			stream >> R;
			stream >> G;
			stream >> B;
			BulletConfig->FillColor = glm::vec3(R, G, B);

			stream >> R;
			stream >> G;
			stream >> B;
			BulletConfig->OutlineColor = glm::vec3(R, G, B);
			stream >> BulletConfig->OutlineThickness;

			stream >> BulletConfig->ShapeVertices;
			stream >> BulletConfig->LifeSpan;
			stream >> BulletConfig->SpecialBulletAmount;
		}
	}
}

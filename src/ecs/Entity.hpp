#pragma once

#include <cstddef>
#include <string>

namespace GeometryWars
{
	class Entity
	{
		friend class EntityManager;

	public:
		// Add Components Here

		inline void Destroy() { m_Alive = false; }
		inline const std::string& GetTag() const { return m_Tag; }
		inline const std::size_t GetID() const { return m_ID; }
		inline bool IsAlive() const { return m_Alive; }
		
	private:
		std::string m_Tag = "";
		std::size_t m_ID = 0;
		bool m_Alive = true;
	
		Entity(std::size_t id, const std::string& tag) {};
	};
}
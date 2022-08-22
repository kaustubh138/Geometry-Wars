#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "Component.hpp"

namespace GeometryWars
{
	enum class EntityTag
		: unsigned int
	{
		None,
		Player,
		Enemy,
		SmallEnemy,
		Bullet
	};

	class Entity
	{
		friend class EntityManager;

	public:
		inline void Destroy() { m_Alive = false; }
		inline EntityTag GetTag() const { return m_Tag; }
		inline const std::size_t GetID() const { return m_ID; }
		inline bool IsAlive() const { return m_Alive; }
		
	public:
		Entity* AddComponent(Component* c, ComponentType t);
		void RemoveComponent(Component* c, ComponentType t);
		bool HasComponent(ComponentType t);

	private:
		std::vector<std::tuple<ComponentType, Component*>> m_Components;
		EntityTag m_Tag = EntityTag::None;
		std::size_t m_ID = 0;
		bool m_Alive = true;
	
		Entity(std::size_t id, const EntityTag& tag) {};
	};
}
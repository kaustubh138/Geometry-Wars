#pragma once

#include "Entity.hpp"
#include <vector>
#include <memory>
#include <unordered_map>

namespace GeometryWars
{
	using EntitiesVector = std::vector<std::shared_ptr<Entity>>;
	using EntitiesMap = std::unordered_map<EntityTag, EntitiesVector>;

	class EntityManager
	{
	public:
		EntityManager();
		std::shared_ptr<Entity> AddEntity(const EntityTag& tag);

		inline const EntitiesVector& GetEntities() const { return m_Entities; };
		inline EntitiesVector& GetEntities(const EntityTag& tag) { return m_EntityCache[tag]; };

		void RemoveDeadEntites();

		void Update();

	private:
		EntitiesVector m_Entities;
		EntitiesMap m_EntityCache;
		std::size_t m_TotalEntities = 0;
		EntitiesVector m_ToAdd;

	};
}


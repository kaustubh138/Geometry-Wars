#include "EntityManager.hpp"

namespace GeometryWars
{
    EntityManager::EntityManager()
    {
        
    }

    std::shared_ptr<Entity> EntityManager::AddEntity(const EntityTag& tag)
    {
		std::shared_ptr<Entity> e = std::shared_ptr<Entity>(new Entity(m_TotalEntities++, tag));
        m_ToAdd.push_back(e);
        return e;
    }

	void EntityManager::RemoveDeadEntites()
	{
		m_Entities.erase(std::remove_if(m_Entities.begin(), m_Entities.end() - 1,
			[](auto& e) { return !e->IsAlive(); }));
	}

	void EntityManager::Update()
	{
		for (std::shared_ptr<Entity>& e : m_ToAdd)
		{
			m_Entities.push_back(e);
			m_EntityCache[e->GetTag()].push_back(e);
		}
		m_ToAdd.clear();
		RemoveDeadEntites();
	}
}

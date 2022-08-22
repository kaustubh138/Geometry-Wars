#include "Entity.hpp"

namespace GeometryWars
{
	Entity* Entity::AddComponent(Component* c, ComponentType t)
	{
		m_Components.push_back(std::tie<ComponentType, Component*>(t, c));
		return this;
	}
	
	void Entity::RemoveComponent(Component* c, ComponentType t)
	{
		m_Components.erase(std::remove_if(m_Components.begin(), m_Components.end(),
			[t](auto& e)
			{
				if (std::get<0>(e) == t)
					return true;
				return false;
			}
		));
	}
	
	bool Entity::HasComponent(ComponentType t)
	{
		auto iter = std::find_if(m_Components.begin(), m_Components.end(),
			[t](auto& e)
			{
				return (std::get<0>(e) == t);
			});
		if (iter != m_Components.end())
			return true;
		return false;
	}
}
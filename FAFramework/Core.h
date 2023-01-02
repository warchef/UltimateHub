#ifndef _FAFramework_Core_h_
#define _FAFramework_Core_h_

namespace fa {

class FAComponent : public Moveable<FAComponent> {
public:
	FAComponent() {}
	virtual ~FAComponent() {}
	
	const String GetId() const { return this->id; }
	FAComponent& SetId(String id) { this->id = id; return *this; }
	
	const FAComponent* GetParent() const { return this->parent; }
	FAComponent& SetParent(FAComponent* parent) { this->parent = parent; return *this; }
	
	virtual Array<FAComponent*>& GetChilds() { return this->childs; }
	
	template<class T>
	T& CreateChildComponent() { T& child = childs.Create<T>(); child.SetParent(this); return child; }
	
	enum COMPONENT_TYPE {
		FIELD, PANEL, DATABASE
	};
	
	template<class T>
	Array<FAComponent*> findComponentsByType();
	
	template<class T>
	FAComponent* findComponentById(String id);
	
	template<class T>
	Array<FAComponent*> findComponentsByComponentType(COMPONENT_TYPE type);
	
protected:
	Array<FAComponent*> childs;
	FAComponent* parent;
	
	String id;
	COMPONENT_TYPE componentType;
};

#include <FAFramework/Core.hpp>
}

#endif

#ifndef _FAFramework_Core_h_
#define _FAFramework_Core_h_

namespace fa {

class FAState {
public:
	FAState() {}
	virtual ~FAState() {}
};

class FAComponent : public Moveable<FAComponent> {
public:
	FAComponent() {}
	virtual ~FAComponent() {}
	
	String GetId() const { return this->id; }
	FAComponent& SetId(String id) { this->id = id; return *this; }
	
	FAComponent* GetParent() { return this->parent; }
	FAComponent& SetParent(FAComponent* parent) { this->parent = parent; return *this; }
	
	Array<FAComponent*>& GetChilds() { return this->childs; }
	
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

class FAFieldCtrl : public WithFAFieldLayout<ParentCtrl>, public FAComponent {
public:
	FAFieldCtrl() { componentType = COMPONENT_TYPE::FIELD; }
	virtual ~FAFieldCtrl() {}

};

#include "Core.hpp"

}

#endif

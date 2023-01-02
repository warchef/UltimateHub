template<class T>
Array<FAComponent*> FAComponent::findComponentsByType() {
	Array<FAComponent*> result;
	
	for (FAComponent* child : this->childs) {
		if (dynamic_cast<T*>(child)) {
			result.Add(child);
		}
		
		Array<FAComponent*> childResult = child->findComponentsByType<T>();
		for (FAComponent* subChild : childResult) {
			result.Add(subChild);
		}
	}
	
	return pick(result);
}

template<class T>
FAComponent* FAComponent::findComponentById(String id) {
	FAComponent* result;
	
	for (FAComponent* child : this->childs) {
		if (child->GetId().IsEqual(id)) {
			return child;
		}
		
		for (FAComponent* subChild : child->GetChilds()) {
			if (subChild->GetId().IsEqual(id)) {
				return subChild;
			}
		}
	}
	
	return NULL;
}
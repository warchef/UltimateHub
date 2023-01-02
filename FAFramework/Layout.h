#ifndef _FAFramework_Layout_h_
#define _FAFramework_Layout_h_

namespace fa {

class FAFieldCtrl : public WithFAFieldLayout<ParentCtrl>, public FAComponent {
public:
	FAFieldCtrl() { componentType = COMPONENT_TYPE::FIELD; }
	virtual ~FAFieldCtrl() {}

};

class LayoutBuilder {
public:
	
};

}

#endif

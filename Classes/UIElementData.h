#ifndef __UI_ELEMENT_DATA_H__
#define __UI_ELEMENT_DATA_H__

#include <cocos2d.h>
#include <string>
#include "rapidxml/rapidxml.hpp"

USING_NS_CC;
using namespace std;
using namespace rapidxml;

enum class UIElementType
{
	Sprite,
	Label
};

class UIElementData
{
public:
	UIElementType type;
	string path;
	float pos_ratio_x;
	float pos_ratio_y;
	float anchor_x;
	float anchor_y;
	int opacity;	

public:	
	UIElementData(UIElementType type, xml_node<>* node);

	virtual Node* CreateElement() = 0;

	static UIElementData* GetNewElementData(xml_node<>* node);
};

#endif //__UI_ELEMENT_DATA_H__
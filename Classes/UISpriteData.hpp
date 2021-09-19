#ifndef __UI_SPRITE_DATA_HPP__
#define __UI_SPRITE_DATA_HPP__

#include <cocos2d.h>
#include "rapidxml/rapidxml.hpp"

#include "UIManager.h"
#include "UIElementData.h"

USING_NS_CC;
using namespace std;
using namespace rapidxml;

class UISpriteData : public UIElementData
{
public:
	int screen_fit;

	UISpriteData(UIElementType type, xml_node<>* node) : UIElementData(type, node)
	{
		screen_fit = stoi(node->first_attribute("screen_fit")->value());
	}

	Node* CreateElement()
	{
		return UIManager::GetInstance()->CreateSprite(this);
	}
};

#endif //__UI_SPRITE_DATA_HPP__
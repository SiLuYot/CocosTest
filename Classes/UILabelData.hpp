#ifndef __UI_LABEL_DATA_HPP__
#define __UI_LABEL_DATA_HPP__

#include <cocos2d.h>
#include "rapidxml/rapidxml.hpp"

#include "UIManager.h"
#include "UIElementData.h"

USING_NS_CC;
using namespace std;
using namespace rapidxml;

class UILabelData : public UIElementData
{
public:
	string content;
	int fontSize;
	int outlineSize;

public:
	UILabelData(UIElementType type, xml_node<>* node) : UIElementData(type, node)
	{
		content = node->first_attribute("content")->value();
		fontSize = stoi(node->first_attribute("fontSize")->value());
		outlineSize = stoi(node->first_attribute("outlineSize")->value());
	}

	Node* CreateElement()
	{
		return UIManager::GetInstance()->CreateTTF(this);
	}
};

#endif //__UI_LABEL_DATA_HPP__
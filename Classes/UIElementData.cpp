#include "UIElementData.h"

#include "UISpriteData.hpp"
#include "UILabelData.hpp"

UIElementData::UIElementData(UIElementType type, xml_node<>* node)
{
	this->type = type;
	path = node->first_attribute("path")->value();
	pos_ratio_x = stof(node->first_attribute("pos_ratio_x")->value());
	pos_ratio_y = stof(node->first_attribute("pos_ratio_y")->value());
	anchor_x = stof(node->first_attribute("anchor_x")->value());
	anchor_y = stof(node->first_attribute("anchor_y")->value());
	opacity = stoi(node->first_attribute("opacity")->value());	
}

UIElementData* UIElementData::GetNewElementData(xml_node<>* node)
{
	string elementType = node->name();

	string replaceString = "ElementType_";
	elementType.replace(elementType.find(replaceString), replaceString.size(), "");

	auto index = stoi(elementType);
	auto type = static_cast<UIElementType>(index);

	UIElementData* newData = nullptr;

	switch (type)
	{
	case UIElementType::Sprite:
		newData = new UISpriteData(type, node);
		break;
	case UIElementType::Label:
		newData = new UILabelData(type, node);
		break;
	}
	return newData;
}
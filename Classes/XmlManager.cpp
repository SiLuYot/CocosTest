#include "XmlManager.h"

#include "UIBaseData.hpp"
#include "UIElementData.h"

void XmlManager::Init()
{
	ReadXml("xml/TitleScene.xml");
}

void XmlManager::ReadXml(string path)
{
	auto str = FileUtils::getInstance()->getStringFromFile(path);

	xml_document<> doc;
	doc.parse<0>(&str[0], str.length());

	auto root = doc.first_node();

	auto uiName = root->first_attribute("name")->value();
	auto newUIData = new UIBaseData(uiName);

	auto node = root->first_node();
	while (node != nullptr)
	{
		auto newData = UIElementData::GetNewElementData(node);
		newUIData->elementArray.push_back(newData);

		node = node->next_sibling();
	}

	dataArray.push_back(newUIData);
}

vector<UIBaseData*> XmlManager::GetDataArray()
{
	return dataArray;
}
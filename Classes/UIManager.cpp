#include "UIManager.h"

#include "UIBaseData.hpp"
#include "UIElementData.h"
#include "UISpriteData.hpp"
#include "UILabelData.hpp"

void UIManager::Init(vector<UIBaseData*> dataArray)
{
	this->dataArray = dataArray;
}

void UIManager::CreateSceneUI(string name, Scene* scene)
{
	auto findDataPtr = FindSceneUIData(name);
	if (findDataPtr == nullptr)
	{
		string msg = "ShowSceneUI Error " + name;
		log(msg.c_str());
		return;
	}

	auto findData = *findDataPtr;
	for_each(findData.begin(), findData.end(), [scene](UIElementData* data)
	{
		auto newElement = data->CreateElement();
		scene->addChild(newElement);
	});
}

vector<UIElementData*>* UIManager::FindSceneUIData(string name)
{
	void* ptr = nullptr;

	for_each(dataArray.begin(), dataArray.end(), [name, &ptr](UIBaseData* v)
	{
		if (v->name == name)
			ptr = &v->elementArray;
	});

	return (vector<UIElementData*>*)ptr;
}

Sprite* UIManager::CreateSprite(UISpriteData* data)
{
	auto newSprite = Sprite::create(data->path);
	if (newSprite == nullptr)
	{
		string msg = "Create Sprite Error " + data->path;
		log(msg.c_str());

		return nullptr;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pos = Vec2(
		visibleSize.width * data->pos_ratio_x + origin.x,
		visibleSize.height * data->pos_ratio_y + origin.y);

	newSprite->setPosition(pos);
	newSprite->setAnchorPoint(Vec2(data->anchor_x, data->anchor_y));
	newSprite->setOpacity(data->opacity);

	if (data->screen_fit)
	{
		auto spriteSize = newSprite->getContentSize();

		float x = visibleSize.width / spriteSize.width;
		float y = visibleSize.height / spriteSize.height;

		newSprite->setScale(x, y);
	}

	return newSprite;
}

Label* UIManager::CreateTTF(UILabelData* data)
{
	TTFConfig fontConfig;
	fontConfig.fontFilePath = data->path;
	fontConfig.fontSize = data->fontSize;
	fontConfig.outlineSize = data->outlineSize;
	
	auto newLabel = Label::createWithTTF(fontConfig, data->content);
	if (newLabel == nullptr)
	{
		string msg = "Create TTF Error " + data->path;
		log(msg.c_str());

		return nullptr;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pos = Vec2(
		visibleSize.width * data->pos_ratio_x + origin.x,
		visibleSize.height * data->pos_ratio_y + origin.y);

	newLabel->setPosition(pos);
	newLabel->setAnchorPoint(Vec2(data->anchor_x, data->anchor_y));
	newLabel->setOpacity(data->opacity);

	return newLabel;
}
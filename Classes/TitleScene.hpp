#ifndef __TITLE_SCENE_HPP__
#define __TITLE_SCENE_HPP__

#include <string>

#include "cocos2d.h"
#include "UIManager.h"
#include "XmlManager.h"

USING_NS_CC;
using namespace std;

class TitleScene : public Scene
{
public:
	CREATE_FUNC(TitleScene);

	static Scene* createScene()
	{
		return TitleScene::create();
	}

	virtual bool init()
	{
		if (!Scene::init())
			return false;

		auto xmlManager = XmlManager::GetInstance();
		auto uiManager = UIManager::GetInstance();

		xmlManager->Init();
		uiManager->Init(xmlManager->GetDataArray());

		uiManager->ShowSceneUI(this);

		//getActionManager()->addAction(FadeTo::create(2.0f, 150), titleSprite, false);

		//auto moveAction = MoveBy::create(3.0f, Vec2(0, 50));
		//auto moveEaseAction = EaseInOut::create(moveAction, 3.0f);

		//auto fadeAction = FadeTo::create(2.0f, 255);

		//auto actionVector = new Vector<FiniteTimeAction*>();
		//actionVector->pushBack(moveEaseAction);
		//actionVector->pushBack(fadeAction);

		//auto logoAction = Spawn::create(*actionVector);
		//getActionManager()->addAction(logoAction, logoSprite, false);

		//getActionManager()->addAction(FadeTo::create(4.0f, 255), startLabel, false);

		return true;
	}

private:

};

#endif //__TITLE_SCENE_HPP__
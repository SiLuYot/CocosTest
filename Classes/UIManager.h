#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include <cocos2d.h>
#include <string>
#include <typeinfo>

#include "SingletonClass.hpp"

class UIBaseData;
class UIElementData;
class UISpriteData;
class UILabelData;

USING_NS_CC;
using namespace std;

class UIManager : public SingletonClass<UIManager>
{
private:
	vector<UIBaseData*> dataArray;

public:
	UIManager() {}
	~UIManager() {}

	void Init(vector<UIBaseData*> dataArray);
	void CreateSceneUI(string name, Scene* scene);

	vector<UIElementData*>* FindSceneUIData(string name);

	Sprite* CreateSprite(UISpriteData* data);
	Label* CreateTTF(UILabelData* data);

	template <typename T>
	void ShowSceneUI(T* scene)
	{
		string name = typeid(T).name();

		string replaceString = "class ";
		name.replace(name.find(replaceString), replaceString.size(), "");

		CreateSceneUI(name, scene);
	}
};

#endif //__UI_MANAGER_H__
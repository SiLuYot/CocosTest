#ifndef __UI_BASE_DATA_HPP__
#define __UI_BASE_DATA_HPP__

#include <string>
#include <cocos2d.h>

class UIElementData;

USING_NS_CC;
using namespace std;

class UIBaseData
{
public:
	string name;
	vector<UIElementData*> elementArray;

public:
	UIBaseData(string name) : name(name)
	{

	}
};

#endif //__UI_BASE_DATA_HPP__
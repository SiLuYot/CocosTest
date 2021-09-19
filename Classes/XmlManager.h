#ifndef __XML_MANAGER_H__
#define __XML_MANAGER_H__

#include <cocos2d.h>
#include <string>

#include "SingletonClass.hpp"
#include "rapidxml/rapidxml.hpp"

USING_NS_CC;
using namespace std;
using namespace rapidxml;

class UIBaseData;

class XmlManager : public SingletonClass<XmlManager>
{
private:
	vector<UIBaseData*> dataArray;

public:
	XmlManager() {}
	~XmlManager() {}

	void Init();
	void ReadXml(string path);

	vector<UIBaseData*> GetDataArray();
};

#endif //__XML_MANAGER_H__
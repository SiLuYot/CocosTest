#ifndef __SINGLETON_MANAGER_HPP__
#define __SINGLETON_MANAGER_HPP__

template <typename T>
class SingletonClass
{
protected:
	static T* instance;

protected:
	SingletonClass() {}
	~SingletonClass()
	{
		if (instance != nullptr)
			delete instance;

		instance = nullptr;
	}

public:
	static T* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new T();
		}

		return instance;
	}
};

template <typename T>
T* SingletonClass<T>::instance = nullptr;

#endif //__SINGLETON_MANAGER_HPP__
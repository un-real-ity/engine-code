#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
	for (auto& child : children)
		delete child;
}

void Object::AddChild(Object* obj)
{
	obj->parent = this;
	children.push_back(obj);
}

void Object::RemoveChild(Object* obj)
{
	auto iter = find(children.begin(), children.end(), obj);

	if (iter == children.end())
		return;

	obj->OnDestroy();
	delete obj;

	children.erase(iter);
}

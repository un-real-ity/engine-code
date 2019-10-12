#pragma once
#include "Object.h"
#include "Math/Vector2D.h"

class Scene : public Object
{
public:
	virtual void OnCreate();
	virtual void Update(float deltaTime);
	virtual void OnDestroy();
private:
};

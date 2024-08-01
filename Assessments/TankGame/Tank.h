#pragma once

#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Scene/SpriteObject.h"

using MathLib::SpriteObject;
using MathLib::SceneObject;

class Tank : public SceneObject
{
public:
	Tank(Texture2D* _texture, int _speed);

public:
	void SetRadius(const float _radius);

protected:
	virtual void OnTick(float _dt) override;
	
private:
	float m_radius;
	SpriteObject* m_sprite;
	int m_speed;
};


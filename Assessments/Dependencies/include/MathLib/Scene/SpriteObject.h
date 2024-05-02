#pragma once

#include <raylib/raylib.h>

#include "SceneObject.h"


namespace MathLib
{
	class SpriteObject final : public SceneObject
	{
	public:
		Vec2 size;
		Vec2 origin;
		Color tint;

	public:
		SpriteObject(Texture2D* _texture);

	public:
		Texture2D* GetTexture() const;

	protected:
		void OnRender() override;

	private:
		Texture2D* m_texture;

	};
}
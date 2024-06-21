#include "MathLib/Scene/SpriteObject.h"

#include <iso646.h>

namespace MathLib
{
	// Constructor
	SpriteObject::SpriteObject(Texture2D* _texture)
		: size{ 32.f, 32.f }, origin{ Vec2::half }, tint{ WHITE }, m_texture{ _texture }
	{
	}

	// Get Texture
	Texture2D* SpriteObject::GetTexture() const
	{
		return m_texture;
	}

	// Render object
	void SpriteObject::OnRender()
	{
		if(m_texture != nullptr)
		{
			Mat3 gt = Global();
			const Vec2 pos = gt.GetTranslation();
			const Vec2 scale = gt.GetScale() * size;
			const float rot = gt.GetRotationX() * RAD2DEG;

			const Rectangle src
			{
				0,
				0,
				static_cast<float>(m_texture->width),
				static_cast<float>(m_texture->height)
			};

			const Rectangle dst
			{
				pos.x,
				pos.y,
				scale.x,
				scale.y
			};

			DrawTexturePro(*m_texture, src, dst, origin * scale, rot, tint);

		}
	}
}

#include "stdafx.h"
#include "ResourceMgr.h"
#include"Texture.h"

ResourceMgr::ResourceMgr()
{
}


ResourceMgr::~ResourceMgr()
{
}

Texture* ResourceMgr::CreateTextureFromFile(std::wstring fileName)
{
	if (!(m_TextureMap.count(fileName)))
	{
		auto texture = new (std::nothrow) Texture();
		if (texture && texture->Init(fileName))
		{
			m_TextureMap[fileName] = texture;
		}
		else
		{
			SAFE_DELETE(texture);
			return NULL;
		}
	}

	return m_TextureMap[fileName];
}

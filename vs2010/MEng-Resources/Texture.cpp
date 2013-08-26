#include "Texture.h"

namespace MEng{
	Texture::Texture(void)
		:m_texture(0)
	{

	}


	Texture::~Texture(void){
	}

	void Texture::load(const char *filename){
		if(m_texture){
			release();
		}

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}

	void Texture::release(){
		if(m_texture)
			glDeleteTextures(1, &m_texture);
	}
}
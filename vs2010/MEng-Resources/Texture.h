#pragma once

#include <GL/glew.h>

namespace MEng{
	class Texture
	{
	public:
		Texture(void);
		~Texture(void);
		void load(const char *filename);
		void release();
	private:
		GLuint m_texture;
	};

}
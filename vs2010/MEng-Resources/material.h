#pragma once

#include "shader.h"

namespace MEng{
	class Material
	{
	public:
		Material(void);
		~Material(void);
		void setShader(Shader *shader);
		void use();
		void unbind();
	private:
		Shader *m_shader;
	};
}


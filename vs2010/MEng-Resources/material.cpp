#include <stdlib.h>
#include "material.h"
#include "assertions.h"

namespace MEng{
	Material::Material(void)
		:m_shader(NULL)
	{
	}


	Material::~Material(void)
	{
	}

	void Material::setShader(Shader *shader){
		ASSERT(shader != NULL);
		m_shader = shader;
	}

	void Material::use(){
		ASSERT(m_shader != NULL);
		m_shader->use();
	}

	void Material::unbind(){
		ASSERT(m_shader != NULL);
		m_shader->unbind();
	}
}
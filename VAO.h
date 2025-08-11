#pragma once

#include<glad/glad.h>
#include"VBO.h"
class VAO
{

public:
	GLuint ID;
	VAO();
	void LinkVBO(const VBO& VBO, GLuint layout);
	void Bind() const;
	void Unbind() const;
	void Delete() const;

};


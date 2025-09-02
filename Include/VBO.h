#pragma once

#include <cstdint>
#include <glad/glad.h>


class VBO
{
public:
	GLuint ID;
	VBO(const GLfloat* vertices, GLsizeiptr size);
	VBO(int16_t size);
	void Bind() const;
	void Unbind() const;
	void Delete() const;
	  

};




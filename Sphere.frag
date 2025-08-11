#version 430 core

in vec3 worldPos;
out vec4 color;

uniform vec3 camPos;
uniform vec3 sphereCenter;

void main() {
    color = vec4(1.0, 0.3, 0.2, 1.0); // Simple red-orange color
}
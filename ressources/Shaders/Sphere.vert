#version 430 core

layout (location = 0) in vec3 aPos;
uniform vec3 center;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 worldPos;
out vec2 textCoord;
void main() {
    vec4 wPos = model * vec4(aPos+center, 1.0);
    worldPos = vec3(wPos);
    vec3 norm = normalize(aPos); // assuming aPos is relative to the sphere center
    float u = atan(norm.z, norm.x) / (2.0 * 3.14159265359) + 0.5;
    float v = norm.y * 0.5 + 0.5;
    textCoord = vec2(u, v);
    gl_Position = projection * view * wPos;
}
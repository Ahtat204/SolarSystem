/*this shader generates a sphere by GPU procedurally based on stacks and slices.

#version 430 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int stacks;
uniform int slices;
uniform vec3 center;
uniform float radius;
out vec3 worldPos;
out vec2 textCoord;
void main() {
    int vertexID = gl_VertexID;

    int stack = vertexID / (slices + 1);
    int slice = vertexID % (slices + 1);

    float phi = float(stack) / float(stacks) * 3.14159265359; // 0 -> PI
    float theta = float(slice) / float(slices) * 2.0 * 3.14159265359; // 0 -> 2PI

    float x = radius * sin(phi) * cos(theta);
    float y = radius * cos(phi);
    float z = radius * sin(phi) * sin(theta);

    vec4 wPos = model * vec4(x+center.x, y+center.y, z+center.z, 1.0);
    worldPos = wPos.xyz;
    gl_Position = projection * view * wPos;
    textCoord= vec2(float(slice) / float(slices), float(stack) / float(stacks));
}
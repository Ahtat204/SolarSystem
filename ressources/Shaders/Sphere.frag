
#version 430 core
in vec3 worldPos;
out vec4 FragColor;
uniform sampler2D sphereTexture;
in vec2 textCoord;

void main() {
    FragColor = texture(sphereTexture, textCoord);
}
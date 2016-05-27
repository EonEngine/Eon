#version 330 core

in vec2 texCoord;
out vec4 color;

uniform sampler2D cTexture;

void main()
{
    color = texture(cTexture, texCoord);
}

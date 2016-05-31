#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 texCoord;

uniform mat4 s_modelM;
uniform mat4 s_viewM;
uniform mat4 s_projM;

void main()
{
    gl_Position = s_projM * s_viewM * s_modelM * vec4(position, 1.0f);
    texCoord = vec2(uv.x, 1.0 - uv.y);
}

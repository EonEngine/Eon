#version 330 core

layout (location = 0) in vec3 position;

float scale = 1;

void main()
{
  gl_Position = vec4(position.x * scale, position.y * scale, position.z * scale, 1.0);
  // vColor = vec4(0.0f, 0.9f, 1.0f, 1.0f) * position.x;
}

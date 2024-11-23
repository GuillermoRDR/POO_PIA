#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec2 TexCoord;
out vec3 FragPos; // Posición del fragmento en el espacio de vista

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
    FragPos = vec3(view * model * vec4(aPos, 1.0)); // Pasamos la posición en el espacio de vista
}

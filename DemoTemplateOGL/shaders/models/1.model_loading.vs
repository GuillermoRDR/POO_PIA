#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoords;
out vec3 FragPos; // Posición del fragmento en el espacio de vista

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    TexCoords = aTexCoords;
    FragPos = vec3(view * model * vec4(aPos, 1.0)); // Calculamos la posición en el espacio de vista
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}

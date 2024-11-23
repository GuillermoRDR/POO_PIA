#version 330 core

in vec3 FragPos; // posición del fragmento
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1; // textura del modelo
uniform vec3 viewPos;              // posición de la cámara
uniform vec3 fogColor;             // color de la niebla
uniform float fogDensity;          // densidad de la niebla

out vec4 FragColor;

void main() {
    // Cargar el color del fragmento desde la textura
    vec4 color = texture(texture_diffuse1, TexCoords);

    // Calcular la distancia desde la cámara al fragmento
    float distance = length(viewPos - FragPos);

    // Usar una fórmula de niebla exponencial
    float fogFactor = exp(-pow(fogDensity * distance, 2.0));
    fogFactor = clamp(fogFactor, 0.0, 1.0);

    // Mezclar el color original con el color de la niebla
    vec3 finalColor = mix(fogColor, color.rgb, fogFactor);

    FragColor = vec4(finalColor, color.a);
}

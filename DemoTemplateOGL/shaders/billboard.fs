#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 FragPos; // Posición del fragmento en el espacio de vista

// Textura del modelo
uniform sampler2D texture_diffuse1;
uniform vec4 color;

// Uniformes de niebla
uniform vec3 fogColor;             // Color de la niebla
uniform float fogDensity;          // Densidad de la niebla

void main()
{    
    vec4 texColor = texture(texture_diffuse1, TexCoord);
    if (texColor.a < 0.1)
        discard;

    // Cálculo de niebla
    float distance = length(FragPos); // Distancia al origen en el espacio de vista
    float fogFactor = exp(-pow(fogDensity * distance, 2.0)); // Fórmula exponencial
    fogFactor = clamp(fogFactor, 0.0, 1.0); // Clampeamos entre 0 y 1

    // Mezclar color del fragmento con el color de la niebla
    vec3 finalColor = mix(fogColor, texColor.rgb, fogFactor);
    FragColor = vec4(finalColor, texColor.a);
}

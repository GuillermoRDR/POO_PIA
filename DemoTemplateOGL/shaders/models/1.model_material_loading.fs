#version 330 core
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;    
    float shininess;
};
struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;  
in vec2 TexCoords;
in vec3 Normal;  
  
out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

// Nuevos uniformes para la niebla
uniform vec3 fogColor;             // Color de la niebla
uniform float fogDensity;          // Densidad de la niebla

uniform int textureSample = 1;
uniform sampler2D texture_diffuse1;
uniform vec4 color;

void main()
{    
    // Iluminación Phong
    vec3 ambient = light.ambient * material.ambient;
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);  
    vec3 result = ambient + diffuse + specular;

    vec4 texColor = texture(texture_diffuse1, TexCoords);
    if (textureSample == 1) {
        if (texColor.a < 0.1)
            discard;
        result *= texColor.rgb;
    }

    // Cálculo de niebla
    float distance = length(viewPos - FragPos);      // Distancia del fragmento a la cámara
    float fogFactor = exp(-pow(fogDensity * distance, 2.0)); // Fórmula de niebla exponencial
    fogFactor = clamp(fogFactor, 0.0, 1.0);         // Clampeamos entre 0 y 1

    // Mezcla del color final con el color de la niebla
    vec3 finalColor = mix(fogColor, result, fogFactor);
    FragColor = vec4(finalColor, texColor.a);
}

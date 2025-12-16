#version 330 compatibility

in vec3 Normal;
in vec3 FragPos;

out vec4 color;

// Uniforms (Variáveis que vamos passar da Main)
uniform vec3 lightPos; // Posição da luz (no View Space se possível, ou World)
uniform vec3 objectColor;

void main()
{
    // --- LÓGICA DE PHONG SIMPLES ---

    // 1. Ambiente
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * vec3(1.0, 1.0, 1.0);
  
    // 2. Difusa
    vec3 norm = normalize(Normal);
    // Como estamos no modo compatibility, a luz deve ser pensada em relação ao View Space
    // Para simplificar, vamos assumir lightPos fixa relativa à camera ou mundo
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(1.0, 1.0, 1.0);
    
    // 3. Especular (Simples)
    float specularStrength = 0.5;
    vec3 viewDir = normalize(-FragPos); // No ViewSpace, a camera está na origem (0,0,0)
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * vec3(1.0, 1.0, 1.0);  

    // Combina tudo
    vec3 result = (ambient + diffuse + specular) * objectColor;
    color = vec4(result, 1.0);
}
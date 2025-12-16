#version 330 compatibility

// Saídas para o Fragment Shader
out vec3 Normal;
out vec3 FragPos;

void main()
{
    // gl_NormalMatrix é calculado automaticamente pelo OpenGL baseado no seu glModelView
    // gl_Normal é o valor que você passou no glNormal3f()
    Normal = normalize(gl_NormalMatrix * gl_Normal);
    
    // Calcula a posição do vértice no espaço da Câmera (View Space)
    FragPos = vec3(gl_ModelViewMatrix * gl_Vertex);
    
    // gl_Position é obrigatório. É a posição final na tela.
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
#version 330

out vec4 finalColor;
in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

uniform vec3 ambientColor;
vec3 lightPosition = vec3(0.1, -75.0, -75.0);
float ambientStrength = 0.005;  // Reduced ambient strength
float diffuseIntensity = 0.5;   // Scales down the diffuse light

void main()
{
    // ambient
    vec3 ambient = ambientStrength * ambientColor;

    // diffuse 
    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(lightPosition - fragPosition);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * ambientColor * diffuseIntensity; // Scaled down diffuse component

    vec3 result = (ambient + diffuse) * fragColor.rgb;
    finalColor = vec4(result, fragColor.a);
}

uniform float time;
void main()
{
    // transform the vertex position
   vec3 pos = gl_Vertex.xyz;
   pos.x +=1.0 * (time);
    gl_Position = gl_ModelViewProjectionMatrix * vec4(pos,1.0); // gl_Vertex;

    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
    gl_FrontColor = gl_Color;
}

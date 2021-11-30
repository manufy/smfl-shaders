uniform float time;

// Attributes
attribute float aTheta;

// Uniforms
uniform mat4 uProjectionMatrix;
uniform float uK;

void main()
{vec3 pos = gl_Vertex.xyz;
    gl_PointSize = 162.0;
      float x = cos(uK*aTheta)*sin(aTheta);
        float y = cos(uK*aTheta)*cos(aTheta);
        
        gl_Position = gl_ModelViewProjectionMatrix * vec4(x, y, pos.z, 1.0);
        gl_PointSize = 16.0;
    // transform the vertex position
   /// vec3 pos = gl_Vertex.xyz;
   /// pos.x +=1.0 * (time);
     gl_Position = gl_ModelViewProjectionMatrix * vec4(pos,1.0); // gl_Vertex;

    // transform the texture coordinates
     gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
     gl_FrontColor = gl_Color;
    gl_PointSize = 10.0;
}

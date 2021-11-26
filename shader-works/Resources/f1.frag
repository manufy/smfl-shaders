
uniform float time;

void main() {
    gl_FragColor = vec4(abs(sin(time*4.0)),0.4,0.0,1.0);
}

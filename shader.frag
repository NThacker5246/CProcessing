#version 130

uniform int width;
uniform int height;
uniform float[7] obj;
uniform float[7] x;
uniform float[7] y;
uniform float[7] w;
uniform float[7] h;
uniform float[7] colR;
uniform float[7] colG;
uniform float[7] colB;
uniform float[7] colA;

void main() {
	vec2 uv = gl_TexCoord[0].xy;
	float pixelX = (uv.x * width);
	float pixelY = (uv.y * height);

	gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	for (int i = 0; i < 7; ++i) {
		int type = int(obj[i]);
		switch(type){
			case 0:
				if(pixelX - x[i] >= 0 && pixelX - x[i] - w[i] <= 0 && pixelY - y[i] >= 0 && pixelY - y[i] - h[i] <= 0){
					gl_FragColor = vec4(colR[i], colG[i], colB[i], colA[i]);
				}
				break;
			case 1:
				float zeroX = (pixelX - x[i]);
				float zeroY = (pixelY - y[i]);
				if(zeroX * zeroX + zeroY * zeroY <= w[i]*w[i]){
					gl_FragColor = vec4(colR[i], colG[i], colB[i], colA[i]);
				}
				break;
		}
	}
}
#include"Particle.hlsli"
struct Pixelshaderoutput {
float32_t4 color:SV_TARGET0;

};
Texture2D<float32_t4>gTexture:register(t0);
SamplerState gSampler:register(s0);
struct Material {
	float32_t4 color;
};
ConstantBuffer<Material>gMaterial:register(b0);

struct TransformationMatrix {
	float32_t4x4 WVP;
	float32_t4x4 World;
};



Pixelshaderoutput main(VertexShaderOutput input) {
	
	Pixelshaderoutput output;
	output.color = gMaterial.color; //float32_t4(1.0, 1.0, 1.0, 1.0);
	float32_t4 transformedUV=mul(float32_t4(input.texcoord,0.0f,1.0f),gMaterial.uvTransform)
	float32_t4 textureColor = gTexture.Sample(gSampler, transformedUV.xy);
	output.color = gMaterial.color * textureColor;
	
	//output.colorのa値が0の時にPixelを棄却
	if (output.color.a == 0.0) {
		discard;
	}
	
	
	
	return output;
}









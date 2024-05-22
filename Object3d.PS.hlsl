struct Pixelshaderoutput {
float32_t4 color:SV_TARGET0;
};

struct Material {
	float32_t4 color;
};
ConstantBuffer<Material>gMaterial:register(b0);




Pixelshaderoutput main() {
	Pixelshaderoutput output;
	output.color = gMaterial.color; //float32_t4(1.0, 1.0, 1.0, 1.0);
	return output;
}









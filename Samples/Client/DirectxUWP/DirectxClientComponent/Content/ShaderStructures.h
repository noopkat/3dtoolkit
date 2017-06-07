#pragma once

namespace DirectXClientComponent
{
    // Constant buffer used to send hologram position transform to the shader pipeline.
    struct ModelConstantBuffer
    {
        DirectX::XMFLOAT4X4 model;
    };

    // Assert that the constant buffer remains 16-byte aligned (best practice).
    static_assert((sizeof(ModelConstantBuffer) % (sizeof(float) * 4)) == 0,
		"Model constant buffer size must be 16-byte aligned (16 bytes is the length of four floats).");

    // Used to send per-vertex data to the vertex shader.
    struct VertexPositionTexture
    {
		DirectX::XMFLOAT3 position;		// Position
#ifdef HOLOLENS
		DirectX::XMFLOAT3 textureUV;	// Texture coordinate
#else // HOLOLENS
		DirectX::XMFLOAT2 textureUV;	// Texture coordinate
#endif // HOLOLENS
    };
}

#pragma once
#include "ofColor.h"
#include "ofShader.h"
#include "ofBaseTypes.h"

// Material concept: "Anything graphical applied to the polygons"
//
// Diederick Huijbers <diederick[at]apollomedia[dot]nl>
//
// references:
//   * Wavefront material file spec: http://people.sc.fsu.edu/~jburkardt/data/mtl/mtl.html
//   * Ogre3D: http://www.ogre3d.org/docs/manual/manual_11.html#SEC14
//   * assim material: http://assimp.sourceforge.net/lib_html/ai_material_8h.html#7dd415ff703a2cc53d1c22ddbbd7dde0

class ofMaterial: public ofBaseMaterial {
public:
	ofMaterial();
	virtual ~ofMaterial(){};
	
	/// set all material colors: reflectance type & light intensity
	void setColors(ofFloatColor oDiffuse, ofFloatColor oAmbient, ofFloatColor oSpecular, ofFloatColor emissive);
	
	/// set the diffuse reflectance
	void setDiffuseColor(ofFloatColor oDiffuse);
	
	/// set the ambient reflectance
	void setAmbientColor(ofFloatColor oAmbient);
	
	/// set the specular reflectance
	void setSpecularColor(ofFloatColor oSpecular);
	
	/// set the emitted light intensity
	void setEmissiveColor(ofFloatColor oEmmisive);
	
	/// set the specular exponent
	void setShininess(float nShininess);

	// documented in ofBaseMaterial
	ofFloatColor getDiffuseColor() const;
	ofFloatColor getAmbientColor() const;
	ofFloatColor getSpecularColor() const;
	ofFloatColor getEmissiveColor() const;
	float getShininess() const;
	
	/// data wrapper for material color properties
    struct Data{
		Data();
        ofFloatColor diffuse; ///< diffuse reflectance
        ofFloatColor ambient; //< ambient reflectance
        ofFloatColor specular; //< specular reflectance
        ofFloatColor emissive; //< emitted light intensity
        float shininess; //< specular exponent
    };
	
	/// \returns material color properties data struct
    Data getData() const;
	
	/// sets the material color properties data struct
	void setData(const ofMaterial::Data& data);
	
	// documented in ofBaseMaterial
	void begin() const;
	void end() const;

private:
	void initShaders(ofGLProgrammableRenderer & renderer) const;
	const ofShader & getShader(int textureTarget, ofGLProgrammableRenderer & renderer) const;
	void updateMaterial(const ofShader & shader,ofGLProgrammableRenderer & renderer) const;
	void updateLights(const ofShader & shader,ofGLProgrammableRenderer & renderer) const;
    
    Data data;

	static ofShader shaderNoTexture;
	static ofShader shaderTexture2D;
	static ofShader shaderTextureRect;
	static bool shadersInitialized;
	static size_t shaderLights;
	static string vertexShader;
	static string fragmentShader;
};

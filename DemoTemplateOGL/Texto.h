#ifndef _textoP_h
#define _textoP_h
#include "Base/Utilities.h"
#include "Base/Billboard.h"
#include "Base/font_atlas.h"

class Texto {

private:
    std::vector<Billboard> textBillboard;
	Model* cameraDetails = NULL;
    Shader* gpuDemo = NULL;
	bool defaultShader = false;
	float scale = 0;
	font_atlas *fontTexture = NULL;
	wstring textoActual; // Texto que se muestra actualmente
public:
	Texto(wstring texto, float escala, float rotacion, float x, float y, float z, Model* camera);

	Texto(WCHAR *texto, float escala, float rotacion, float x, float y, float z, Model* camera);

	~Texto();

    void initTexto(WCHAR *texto, float escala, float rotacion, float x, float y, float z, Model* camera);

    // Usa el shader default para poder imprimir el billboard
	void Draw();

	void Draw(Shader &shader);

	void prepShader(Shader& shader, glm::vec3 &pos);

    glm::vec2 rotate_pt(glm::vec2& rotate_about, glm::vec2 pt, float& rotation_angle);
	void setDefaultShader(bool defaultShader);

	void setTexto(wstring nuevoTexto);

	wstring getTexto() const;
};

#endif 
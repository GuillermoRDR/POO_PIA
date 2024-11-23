#ifndef ARMA_H
#define ARMA_H

#include "base/model.h"

class Arma : public Model {
private:
    std::string nombre;
    float damage;

public:
    // Constructor que recibe un modelo 3D, el nombre y el daño del arma
    Arma(std::string nombre, float damage, std::string path, Camera* camera, glm::vec3 initialPosition);

    // Getter y Setter para el nombre del arma
    std::string getNombre() const;

    void setNombre(const std::string& nombre);

    // Getter y Setter para el daño del arma
    float getDamage() const;

    void setDamage(float damage);

    // Método para dibujar el modelo del arma
    void Draw() {
        Model::Draw();  // Llama al método de la clase base para dibujar el modelo
    }
};

#endif

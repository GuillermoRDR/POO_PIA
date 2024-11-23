#include "arma.h"


Arma::Arma(std::string nombre, float damage, std::string path, Camera* camera, glm::vec3 initialPosition){}

std::string Arma::getNombre() const {
    return nombre;
}

float Arma::getDamage() const {
    return damage;
}

void Arma::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Arma::setDamage(float damage) {
    this->damage = damage;
}
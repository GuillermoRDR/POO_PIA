#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "base/model.h"

class Zombie : public Model {
private:
    // Atributos específicos del zombie
    float salud;
    bool estaVivo;
    glm::vec3 direccion;
    float velocidad;

public:
    // Constructor
    Zombie(string const& path, Camera* camera, glm::vec3 initialPosition, float salud = 100.0f, float velocidad = 0.05f);
    // Destructor
    ~Zombie();

    // Función para actualizar el comportamiento del zombie (movimiento, animación, etc.)
    void Actualizar(Model* perseguidor, Model* objetivo);

    // Función para recibir daño
    void RecibeDamage (float damage);

    // Función para comprobar si el zombie está muerto
    bool EstaMuerto() const;

    // Función de colisión personalizada para el zombie
    bool ColisionConSuperviviente(Model& player);

    // Getter y Setter para la salud
    float getSalud() const;
    void setSalud(float newsalud);
    float getVelocidad() const;
    void setVelocidad(float newVelocidad);

    // Función para hacer que el zombie se mueva hacia un objetivo
    void perseguirModelo(float velocidad, Model* perseguidor, Model* objetivo);

};

#endif

#ifndef SUPERVIVIENTE_H
#define SUPERVIVIENTE_H

#include "base/model.h"
#include "arma.h"
#include "zombie.h"

class Superviviente : public Model {
private:
    // Atributos específicos del superviviente
    float salud;
    float ataque;
    Arma* arma; // Puntero a un objeto de tipo Arma (puede ser nullptr si no tiene arma)
    bool estaVivo;

public:
    // Constructor
    Superviviente(string const& path, Camera* camera, glm::vec3 initialPosition,
        float salud = 100.0f, float ataque = 10.0f);

    Superviviente(string const& path, Camera* camera);

    // Destructor
    ~Superviviente();

    // Función para recibir daño
    void recibirDanio(float danio);

    // Función para atacar a un zombie
    void atacarZombie(Zombie& zombie);

    // Función para recoger un objeto (arma con modelo 3D)
    void recogerObjeto(Arma* nuevoArma);

    // Getter y Setter para la salud
    float getSalud() const;
    void setSalud(float nuevaSalud);

    // Getter y Setter para el ataque
    float getAtaque() const;
    void setAtaque(float nuevoAtaque);

    // Función para verificar si el superviviente está vivo
    bool estaVivof() const;

    // Función para actualizar la lógica del superviviente (si es necesario)
    void actualizar();

    // Función para dibujar el modelo del superviviente (y el arma si la tiene)
    void Draw();
};

#endif

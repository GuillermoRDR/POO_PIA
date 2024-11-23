#include "superviviente.h"
// Constructor


Superviviente::Superviviente(string const& path, Camera* camera, glm::vec3 initialPosition, float salud, float ataque){}

Superviviente::Superviviente(string const& path, Camera* camera) {}

// Destructor
Superviviente::~Superviviente() {}

// Función para recibir daño
void Superviviente::recibirDanio(float danio) {
    salud -= danio;
    if (salud <= 0) {
        estaVivo = false;
        salud = 0;
    }
}

// Función para atacar a un zombie
void Superviviente::atacarZombie(Zombie& zombie) {
    if (arma) {
        zombie.RecibeDamage(arma->getDamage());
    }
    else {
        zombie.RecibeDamage(ataque); // Si no tiene arma, ataca con el daño base
    }
}

// Función para recoger un objeto (arma con modelo 3D)
void Superviviente::recogerObjeto(Arma* nuevoArma) {
    arma = nuevoArma;
}

// Getter y Setter para la salud
float Superviviente::getSalud() const { return salud; }
void Superviviente::setSalud(float nuevaSalud) { salud = nuevaSalud; }

// Getter y Setter para el ataque
float Superviviente::getAtaque() const { return ataque; }
void Superviviente::setAtaque(float nuevoAtaque) { ataque = nuevoAtaque; }

// Función para verificar si el superviviente está vivo
bool Superviviente::estaVivof() const { return estaVivo; }

// Función para actualizar la lógica del superviviente (si es necesario)
void Superviviente::actualizar() {
    if (salud <= 0) {
        estaVivo = false;
    }
    // Aquí puedes agregar más lógica para actualizar el estado del superviviente (por ejemplo, movimiento)
}

// Función para dibujar el modelo del superviviente (y el arma si la tiene)
void Superviviente::Draw() {
    Model::Draw();  // Dibuja al superviviente
    if (arma) {
        arma->Draw();  // Dibuja el arma si la tiene
    }
}
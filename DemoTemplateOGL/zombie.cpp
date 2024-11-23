#include "Zombie.h"

Zombie::Zombie(string const& path, Camera* camera, glm::vec3 initialPosition, float salud, float velocidad)
    : Model(path, camera, false, true), salud(salud), estaVivo(true), direccion(glm::vec3(0.0f, 0.0f, 0.0f)), velocidad(velocidad) {
    setTranslate(&initialPosition);  // Colocamos al zombie en la posición inicial
}

Zombie::~Zombie() {
    // El destructor puede eliminar recursos específicos si es necesario
}

void Zombie::Actualizar(Model* perseguidor, Model* objetivo) {
    if (estaVivo) {
        perseguirModelo(velocidad, perseguidor, objetivo);
        // Actualizar comportamiento del zombie, como movimiento
        //MoverHastaJugador(cameraDetails->getPosition(), deltaTime); // Movemos al zombie hacia el jugador
    }
}

void Zombie::RecibeDamage(float damage) {
    salud -= damage;
    if (salud <= 0.0f) {
        estaVivo = false;
        // Aquí podrías iniciar una animación de muerte o hacer algo específico cuando el zombie muere
    }
}

bool Zombie::EstaMuerto() const {
    return !estaVivo;
}

bool Zombie::ColisionConSuperviviente(Model& player) {
    // Lógica para verificar la colisión con el jugador (puedes usar AABB o cualquier otro sistema de colisión)
    if (colisionaCon(player)) {
        // Si hay colisión, el zombie puede hacer algo como atacar al jugador
        return true;
    }
    return false;
}

float Zombie::getSalud() const {
    return salud;
}

void Zombie::setSalud(float newsalud) {
    salud = newsalud;
}

float Zombie::getVelocidad() const {
    return velocidad;
}

void Zombie::setVelocidad(float newVelocidad) {
    velocidad = newVelocidad;
}

void Zombie::perseguirModelo(float velocidad, Model* perseguidor, Model* objetivo) {
    // Obtén las posiciones actuales
    float xPerseguidor = perseguidor->getTranslate()->x;
    float yPerseguidor = perseguidor->getTranslate()->y;
    float zPerseguidor = perseguidor->getTranslate()->z;

    float xObjetivo = objetivo->getTranslate()->x;
    float yObjetivo = objetivo->getTranslate()->y;
    float zObjetivo = objetivo->getTranslate()->z;

    // Calcula las diferencias (dirección hacia el objetivo)
    float dx = xObjetivo - xPerseguidor;
    float dy = yObjetivo - yPerseguidor;
    float dz = zObjetivo - zPerseguidor;

    // Calcula la magnitud (distancia)
    float magnitud = sqrt(dx * dx + dy * dy + dz * dz);

    // Verifica que la magnitud no sea 0 (evita divisiones por cero)
    if (magnitud > 0.0f) {
        // Normaliza la dirección
        dx /= magnitud;
        dy /= magnitud;
        dz /= magnitud;

        // Calcula el movimiento basado en velocidad y deltaTime
        float movimientoX = dx * velocidad;
        float movimientoY = dy * velocidad;
        float movimientoZ = dz * velocidad;

        // Actualiza la posición del perseguidor
        glm::vec3 translate = glm::vec3(xPerseguidor + movimientoX, yPerseguidor + movimientoY, zPerseguidor + movimientoZ);
        perseguidor->setTranslate(&translate);
    }
}

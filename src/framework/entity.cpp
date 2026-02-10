#include "entity.h"

Entity::Entity() {
    this->mesh = nullptr;
    this->model.SetIdentity(); // Por defecto sin transformacion
}

Entity::Entity(Mesh* m, Matrix44 mat) {
    this->mesh = m;
    this->model = mat;
}

void Entity::Update(float seconds_elapsed) {
    // Aqui animaremos la matriz mas adelante (Tarea 2.4)
}

void Entity::Render(Image* framebuffer, Camera* camera, const Color& c) {
    // Aqui haremos la proyeccion 3D (Tarea 2.2)
}
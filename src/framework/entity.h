#ifndef ENTITY_H
#define ENTITY_H

#include "framework.h"
#include "mesh.h"
#include "image.h"
#include "camera.h"

class Entity {
public:
    Mesh* mesh;        // Puntero a los datos de los triangulos
    Matrix44 model;    // Matriz de transformacion (posicion, rotacion, escala)

    // Constructor vacio por si acaso
    Entity();
    // Constructor con parametros para ir mas rapido
    Entity(Mesh* m, Matrix44 mat);

    // Metodos que rellenaremos mas adelante segun los ejercicios
    void Render(Image* framebuffer, Camera* camera, const Color& c);
    void Update(float seconds_elapsed);
};

#endif
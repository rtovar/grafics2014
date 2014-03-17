#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <objecte.h>

class Obstacle : public Objecte
{
public:
    Obstacle();
    Obstacle(float, float, float);

    void make();
    void draw();
    void toGPU(QGLShaderProgram *p);
    void aplicaTGCentrat(mat4 m);

private :
    int a; // amplada
    int h; // altura
    int p; // i profunditat del cub inicial

    point4 vertices[8]; // vertexs del cub
    color4 vertex_colors[8]; // colors dels vertexs

    void quad(int,int,int,int);
    void escalatrasllada();
};

#endif // OBSTACLE_H

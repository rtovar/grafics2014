#ifndef TERRA_H
#define TERRA_H

#include <objecte.h>
using namespace std;

class Terra:public Objecte
{
public:
    Terra();
    Terra(float,float,float);

    void make();
    void draw();
    void toGPU(QGLShaderProgram *p);
    void aplicaTGCentrat(mat4 m);

private:

    float amplada;
    float profunditat;
    float y;

    point4 vertexsterra[4]; // 4 punts del terra
    color4 colorsterra[4]; // un color per cada vertex


};

#endif // TERRA_H

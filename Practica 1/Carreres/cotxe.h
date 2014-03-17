#ifndef COTXE_H
#define COTXE_H

#include <Common.h>
#include <objecte.h>
#include <roda.h>
#include <carrosseria.h>
#include <iostream>
#include <vector>

using namespace std;

class Cotxe: public Objecte
{
public:
    Cotxe(QString n);
    Cotxe(QString n, GLfloat tamanio, GLfloat x0, GLfloat y0, GLfloat z0,
          double girx, double giry, double girz,
          float xdir, float ydir, float zdir);

    void readObj(QString filename);
    void forward();
    void backward();
    void turnleft();
    void turnright();
    point4 direction;

private:

    static const int NumVerticesF = 100000;
    static const int NumCares = 300000;
    Roda roda_fr;
    Roda roda_fl;
    Roda roda_rr;
    Roda roda_rl;
    Carrosseria carrosseria;

};

#endif // COTXE_H

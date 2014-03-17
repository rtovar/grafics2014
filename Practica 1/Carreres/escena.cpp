#include <escena.h>

using namespace std;

escena::escena()

{
    // Capsa minima contenidora provisional: S'ha de fer un recorregut dels objectes de l'escenes
    capsaMinima.pmin[0] = 0; capsaMinima.pmin[1] = 0; capsaMinima.pmin[2]=0;
    capsaMinima.a = 1; capsaMinima.h = 1; capsaMinima.p = 1;

    cotxe = NULL;

}


escena::~escena()
{
    printf("DESTRUCTOR!");

}

void escena::addObjecte(Objecte *obj) {

    // Metode a modificar FET

    if (dynamic_cast<Cotxe*>(obj))
        this->cotxe = (Cotxe*)obj;

    Objectes.push_back(obj);
}

void escena::mouCotxe(int dir)
{
    switch ( dir )
    {
    case Qt::Key_Up:
        cotxe->forward();
        break;
    case Qt::Key_Down:
        cotxe->backward();
        break;
    case Qt::Key_Left:
        cotxe->turnleft();
        break;
    case Qt::Key_Right:
        cotxe->turnright();
        break;
    }
}


void escena::CapsaMinCont3DEscena()
{
    Capsa3D local;
    vec3 pmin;
    vec3 pmax;

    pmin = (9999999, 9999999, 9999999);
    pmax = (-9999999, -9999999, -9999999);

    if (Objectes.size()!=0){

        for(int i = 0; i < Objectes.size(); i++){

            local = Objectes[i]->calculCapsa3D();

            if (local.pmin.x < pmin.x){
                pmin.x = local.pmin.x;
            }
            if (local.pmin.y < pmin.y){
                pmin.y = local.pmin.y;
            }
            if (local.pmin.z < pmin.z){
                pmin.z = local.pmin.z;
            }
            if (local.pmin.x+local.a > pmax.x){
                pmax.x = local.pmin.x+local.a;
            }
            if (local.pmin[1]+local.h > pmax.y){
                pmax.y = local.pmin.y+local.h;
            }
            if (local.pmin[2]+local.p > pmin[2]){
                pmax.z = local.pmin.z+local.p;
            }

        }

        local.pmin = pmin;
        local.a = pmax[0]-pmin[0];
        local.h = pmax[1]-pmin[1];
        local.p = pmax[2]-pmin[2];
        capsaMinima = local;
    }
}

void escena::aplicaTG(mat4 m) {

    // Metode a modificar FET

    if (cotxe!=NULL)
        cotxe->aplicaTG(m);

    for ( int i = 0; i < Objectes.size() ; ++i){
        Objectes[i]->aplicaTG(m);
    }

}

void escena::aplicaTGCentrat(mat4 m) {

    // Metode a modificar FET

    if (cotxe!=NULL)
        cotxe->aplicaTGCentrat(m);

    for ( int i = 0; i < Objectes.size() ; ++i){
        Objectes[i]->aplicaTGCentrat(m);
    }

}

void escena::draw() {

    // Metode a modificar FET

    if (cotxe!=NULL)
        cotxe->draw();

    for ( int i = 0; i < Objectes.size() ; ++i){
        Objectes[i]->draw();
    }

}

void escena::reset() {

    // Metode a modificar FET

    if (cotxe!=NULL)
        cotxe->make();

    for ( int i = 0; i < Objectes.size() ; ++i){
        Objectes[i]->make();

    }

}

void escena::toGPU(QGLShaderProgram *pr){

    for ( int i = 0; i < Objectes.size() ; ++i){
        Objectes[i]->toGPU(pr);

    }


}


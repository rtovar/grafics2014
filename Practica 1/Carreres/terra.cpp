#include <terra.h>



Terra::Terra(){}

Terra::Terra(float am, float prof, float y){

    Index = 0;
    tam =1;

    xorig = 0.0;
    yorig = 0.0;
    zorig = 0.0;

    this->amplada = am;
    this->profunditat = prof;
    this->y = y;

    xRot = 0;
    yRot = 0;
    zRot = 0;

    this->vertexsterra[1] = point4(xorig-am/2.0,y,zorig-prof/2.0,1.0);
    this->vertexsterra[0] = point4(xorig+this->amplada/2.0,y,zorig-prof/2.0,1.0);
    this->vertexsterra[2] = point4(xorig-am/2.0,y,zorig+this->profunditat/2.0,1.0);
    this->vertexsterra[3] = point4(xorig+am/2.0,y,zorig+this->profunditat/2.0,1.0);

    this->colorsterra[0] =    color4( 1.0, 0.0, 0.0, 1.0 );  // red
    this->colorsterra[1] =    color4( 1.0, 1.0, 0.0, 1.0 );  // yellow
    this->colorsterra[2] =    color4( 0.0, 1.0, 0.0, 1.0 );  // green
    this->colorsterra[3] =    color4( 0.0, 0.0, 1.0, 1.0 );  // blue

    numPoints = 12;

    this->make();

}

void Terra::make(){

    points = new point4[numPoints];
    colors = new color4[numPoints];

    // part superior del terra
    colors[0] = colorsterra[0]; points[0] = vertexsterra[0];Index++;
    colors[1] = colorsterra[1]; points[1] = vertexsterra[1];Index++;
    colors[2] = colorsterra[2]; points[2] = vertexsterra[3];Index++;
    colors[3] = colorsterra[3]; points[3] = vertexsterra[3];Index++;
    colors[4] = colorsterra[1]; points[4] = vertexsterra[1];Index++;
    colors[5] = colorsterra[2]; points[5] = vertexsterra[2];Index++;

    // part inferior del terra
    colors[6] = colorsterra[0]; points[6] = vertexsterra[3];Index++;
    colors[7] = colorsterra[1]; points[7] = vertexsterra[1];Index++;
    colors[8] = colorsterra[2]; points[8] = vertexsterra[0];Index++;
    colors[9] = colorsterra[3]; points[9] = vertexsterra[2];Index++;
    colors[10] = colorsterra[1]; points[10] = vertexsterra[1];Index++;
    colors[11] = colorsterra[2]; points[11] = vertexsterra[3];Index++;

}

void Terra::draw(){
    Objecte::draw();
}

void Terra::toGPU(QGLShaderProgram *program){
 Objecte::toGPU(program);

}

void Terra::aplicaTGCentrat(mat4 m)
{
   Objecte::aplicaTGCentrat(m);

}



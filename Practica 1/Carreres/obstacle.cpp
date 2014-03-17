#include "obstacle.h"
#include <vector>
Obstacle::Obstacle()
{
    std::cout<<"Estic en el constructor del Obstacle \n";

    // Cub centrat al 0,0,0 amb dimensió 1 a totes les seves arestes
    xorig = -0.5; yorig = -0.50; zorig = -0.5;
    a = 1.0;
    h = 1.0;
    p = 1.0;


    // Vertices of a unit cube centered at origin, sides aligned with axes
    vertices[0] = point4( -0.5, -0.5,  0.5, 1.0 );
    vertices[1] = point4( -0.5,  0.5,  0.5, 1.0 );
    vertices[2] = point4(  0.5,  0.5,  0.5, 1.0 );
    vertices[3] = point4(  0.5, -0.5,  0.5, 1.0 );
    vertices[4] = point4( -0.5, -0.5, -0.5, 1.0 );
    vertices[5] = point4( -0.5,  0.5, -0.5, 1.0 );
    vertices[6] = point4(  0.5,  0.5, -0.5, 1.0 );
    vertices[7] = point4(  0.5, -0.5, -0.5, 1.0 );

    // RGBA colors
    vertex_colors[0] =    color4( 0.0, 0.0, 0.0, 1.0 );  // black
    vertex_colors[1] =    color4( 1.0, 0.0, 0.0, 1.0 );  // red
    vertex_colors[2] =    color4( 1.0, 1.0, 0.0, 1.0 );  // yellow
    vertex_colors[3] =    color4( 0.0, 1.0, 0.0, 1.0 );  // green
    vertex_colors[4] =    color4( 0.0, 0.0, 1.0, 1.0 );  // blue
    vertex_colors[5] =    color4( 1.0, 0.0, 1.0, 1.0 );  // magenta
    vertex_colors[6] =    color4( 1.0, 1.0, 1.0, 1.0 );  // white
    vertex_colors[7] =    color4( 0.0, 1.0, 1.0, 1.0 );  // cyan

    numPoints = 36;

   // this->make();
    this->escalatrasllada();
}

Obstacle::Obstacle(float x, float y, float z){

}

void Obstacle::escalatrasllada(){

    // ACABAR DE MUNTAR

    int numpunts = 8;

   /* float tx = rand()%10+0.5; // tamany aresta x cub -> random entre 0.5-10
    float ty = rand()%10+0.5;
    float tz = rand()%10+0.5;*/

     float tx = rand()%2+0.5; // tamany aresta x cub -> random entre 0.5-2
     float ty = rand()%2+0.5;
     float tz = rand()%2+0.5;

    cout <<" tamany : "<<tx<<ty<<tz<<endl;

    mat4 escalar = Scale(tx,ty,tz);
   // mat4 escalar = Scale(0.5,0.5,0.5);

/*    float x = rand()%(25-int(tx))+0.5 ; // random entre 0.5 i 10
    float y = 0.0;          // la y es el terra = 0.0
    float z = rand()%(25-int(tz))+0.5;// random entre 0.5 i 10
  */
    float x = rand()%1+0.5 ; // random entre 0.5 i 10
    float y = 0.0;          // la y es el terra = 0.0
    float z = rand()%1+0.5;// random entre 0.5 i 10

    if ( rand() > 0.5) x = -1.0*x;
    if ( rand() > 0.5) z = -1.0*z;
    cout <<"trasllat punt   "<<x<<y<<z<<endl;

    mat4 trasllada = Translate(x,y,z);

    mat4 matriu = trasllada*escalar;

    point4 *trans = new point4[numpunts];

    for ( int i = 0; i < numpunts; ++i){
        trans[i] = matriu * vertices[i];
    }
    trans = &trans[0];

    for( int i = 0; i < numpunts; ++i){
        vertices[i] = trans[i];
    }

    delete trans;

    this->make();


}


void Obstacle::make(){

    points = new point4[numPoints];
    colors = new color4[numPoints];

    Index = 0;
    quad( 1, 0, 3, 2 );
    quad( 2, 3, 7, 6 );
    quad( 3, 0, 4, 7 );
    quad( 6, 5, 1, 2 );
    quad( 4, 5, 6, 7 );
    quad( 5, 4, 0, 1 );

}

void Obstacle::quad( int a, int b, int c, int d )
{
    colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
    colors[Index] = vertex_colors[b]; points[Index] = vertices[b]; Index++;
    colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
    colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
    colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
    colors[Index] = vertex_colors[d]; points[Index] = vertices[d]; Index++;
}


void Obstacle::draw(){ Objecte::draw();}

void Obstacle::toGPU(QGLShaderProgram *p){
    Objecte::toGPU(p);
}


void Obstacle::aplicaTGCentrat(mat4 m){
    Objecte::aplicaTGCentrat(m);
}





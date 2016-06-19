#include "Cylinder.h"
//#include <math>

Cylinder::Cylinder(int texture, float radius, float height, const Ponto_3D& center) : Objeto_3D ( texture)
{

}

Intersection Cylinder::Intercepta(const Raio &r_vis, IntersectionMode mode, float threshold)
{}
Vetor_3D Cylinder::normal(const Ponto_3D &ponto) const
{}
TexturePoint Cylinder::pontoTextura(const Ponto_3D &ponto) const
{}

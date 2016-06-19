#include "Cylinder.h"
//#include <math>

Cylinder::Cylinder(int texture, float radius, float height, const Ponto_3D& center) : Objeto_3D ( texture)
{
    raio = radius;
    centro = center;
    altura = height;
}

Intersection Cylinder::Intercepta(const Raio &r_vis, Objeto_3D::IntersectionMode mode, float threshold)
{
    float a, b, c, delta, t0, t1, y0, y1;
    Intersection intersection;

    // valores intermediários
    Vetor_3D K = Vetor_3D(r_vis.X0() - centro.X(),
                          r_vis.Y0() - centro.Y(),
                          r_vis.Z0() - centro.Z());

    a = r_vis.Dx() * r_vis.Dx() + r_vis.Dz() * r_vis.Dz();
    b = 2 * K.X() * r_vis.Dx() + 2 * K.Z() * r_vis.Dz();
    c = K.X() * K.X() + K.Z() * K.Z() - raio * raio;

    delta = b * b - 4 * a * c;
    if (delta >= 0)
    {
        t0 = (-b + sqrt(delta)) / (2 * a);
        t1 = (-b - sqrt(delta)) / (2 * a);

        y0 = K.Y() + t0 * r_vis.Dy();
        y1 = K.Y() + t1 * r_vis.Dy();

        if ((centro.Y() - altura / 2 < y0 && y0 < centro.Y() + altura / 2) || (centro.Y() - altura / 2 < y1 && y1 < centro.Y() + altura / 2))
        {
            intersection = Intersection::nearest(Intersection(this, t0), Intersection(this, t1), threshold);
        }
    }

    return intersection;
}

Vetor_3D Cylinder::normal(const Ponto_3D &ponto) const
{
    Vetor_3D tmp;

    tmp = ponto - centro;
    tmp.normaliza();
    tmp.setY(0);

    return tmp;
}

TexturePoint Cylinder::pontoTextura(const Ponto_3D &ponto) const
{
    float s, t;
    Vetor_3D tmp;

    tmp = ponto - centro;
    tmp.normaliza();

    s = (atan2(tmp.X(), tmp.Z()) + M_PI) / (2 * M_PI);
    t = tmp.Y();

    return TexturePoint(s, t);
}

/*Intersection Cylinder::Intercepta(const Raio &r_vis, IntersectionMode mode, float threshold)
{}
Vetor_3D Cylinder::normal(const Ponto_3D &ponto) const
{}
TexturePoint Cylinder::pontoTextura(const Ponto_3D &ponto) const
{}*/

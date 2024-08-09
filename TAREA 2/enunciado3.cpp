#include <iostream>
#include <cmath>
using namespace std;

class FiguraGeometrica{
    private:
        float area = 0;
        float perimetro = 0;

    public:
        FiguraGeometrica() : area(0), perimetro(0) {}
        virtual float getArea() = 0;
        virtual float getPerimetro() = 0;
        void setArea(float area) { this->area = area; }
        void setPerimetro(float perimetro) { this->perimetro = perimetro; }
};

//Clase Triangulo Rectangulo
class Triangulo : public FiguraGeometrica{
    private:
        float base;
        float altura;

    public:
        Triangulo() : FiguraGeometrica(), base(0), altura(0) {}
        Triangulo(float base, float altura) : FiguraGeometrica(), base(base), altura(altura) {}
        float getArea() { setArea((base * altura) / 2); }
        float getPerimetro() { setPerimetro(base + altura + sqrt(pow(base, 2) + pow(altura, 2))); }

};

class Rectangulo : public FiguraGeometrica{
    private:
        float base;
        float altura;

    public:
        Rectangulo() : FiguraGeometrica(), base(0), altura(0) {}
        Rectangulo(float base, float altura) : FiguraGeometrica(), base(base), altura(altura) {}
        float getArea() { setArea(base * altura); }
        float getPerimetro() { setPerimetro(2 * base + 2 * altura); }
};

class Circulo : public FiguraGeometrica{
    private:
        float radio;

    public:
        Circulo() : FiguraGeometrica(), radio(0) {}
        Circulo(float radio) : FiguraGeometrica(), radio(radio) {}
        float getArea() { setArea(3.1416 * pow(radio, 2)); }
        float getPerimetro() { setPerimetro(2 * 3.1416 * radio); }
};

int main(){
    Triangulo T1(3, 4);
    Rectangulo R1(3, 4);
    Circulo C1(3);

    T1.getArea();
    T1.getPerimetro();
    cout << "Area del Triangulo: " << T1.getArea() << endl;
    cout << "Perimetro del Triangulo: " << T1.getPerimetro() << endl;

    R1.getArea();
    R1.getPerimetro();
    cout << "Area del Rectangulo: " << R1.getArea() << endl;
    cout << "Perimetro del Rectangulo: " << R1.getPerimetro() << endl;

    C1.getArea();
    C1.getPerimetro();
    cout << "Area del Circulo: " << C1.getArea() << endl;
    cout << "Perimetro del Circulo: " << C1.getPerimetro() << endl;

    return 0;
}
#include<iostream>
#include<cmath>

namespace assignment{
  class Complex{	
        float real, img;
	static Complex origin;
    public:
	Complex(float, float);
	//void display();
	Complex operator+(const &Complex other)const;
	Complex operator-(const &Complex other)const;
	Complex operator*(const &Complex other)const;
	float magnitude()const{return(std::sqrt(real*real+img*img));}
	Complex operator/(const &Complex other)const;
	
  };
  Complex::Complex(float r, float i){real = r;img = i;}
  Complex Complex::origin = Complex(0.0,0.0);
  Complex Complex::operator+(const &Complex other)const{
        float real_part = this->real+other.real;
	float img_part = this->img+other.img;
	return Complex(real_part, img_part);}
  Complex Complex::operator-(const &Complex other)const{
	float real_part = this->real-other.real;
	float img_part = this->img-other.img;
        return Complex(real_part,img_part);}
  Complex Complex::operator*(const &Complex other)const{
        float real_prod1 = (this->real*other.real);
	float real_prod2 = this->img*other.img;
	float img_prod1 = this->real*other.img;
	float img_prod2 = this->img*other.real;
	return Complex(real_prod1-real_prod2,img_prod1+img_prod2);}
  Complex Complex::operator/(const &Complex other)const{
	float real_prod1 = (this->real*other.real);
	float real_prod2 = this->img*other.img;
	float img_prod1 = (this->real*other.img);
	float img prod2 = this->img*other.real;
	float magn = other.magnitude;
        return Complex((real_prod1+real_prod2)/magn,(-img_prod1+img+prod2)/magn;}
};

int main(){
	assignment::Complex a(1.0, 2.0);
}


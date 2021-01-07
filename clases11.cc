#include<iostream>
#include<math.h>
#include<limits>
#include<stdexcept>

using namespace std; 

class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int arg1, int arg2, int arg3){
        dia=arg1;
        mes=arg2;
        anio=arg3;
    }
    void Dia(int n){
        dia=n;
    }
    void Mes(int n){
        mes=n;
    }
    void Anio(int n){
        anio=n;
    }
    void funcionfecha(){
        cout<<dia<<'/'<<mes<<'/'<<anio<<endl;
    }
    void funcionbiciesto(){
        if(anio % 4 == 0){
            cout<<"Es año biciesto"<<endl;
        }
        else{
            cout<<"No es año biciesto"<<endl;
        }
    }
};
class Complejo{
private:
    double real, imaginaria;
public:
    Complejo(int arg1 = 0, int arg2 = 0){   
        real = arg1;
        imaginaria = arg2;
    }
    void suma(Complejo num1, Complejo num2){
        real = num1.real + num2.real;
        imaginaria = num1.imaginaria + num2.imaginaria;
        cout<<real<<" + "<<imaginaria<<endl;
    }
    void resta(Complejo num1, Complejo num2){
        real = num1.real - num2.real;
        imaginaria = num1.imaginaria - num2.imaginaria;
        cout<<real<<" + "<<imaginaria<<endl;
    }
    void multiplicacion(Complejo num1, Complejo num2){
        real = num1.real * num2.real + -1 * (num1.imaginaria * num2.imaginaria);
        imaginaria = num1.imaginaria * num2.real + num1.real * num2.imaginaria;
        cout<<real<<" + "<<imaginaria<<endl;
    }
    void division(Complejo num1, Complejo num2){
        Complejo numerocon(num2.real, -1*num2.imaginaria); 
        double denominador = pow(num1.real, 2) + pow(num2.imaginaria, 2);
        real = (num1.real * numerocon.real + -1 * (num1.imaginaria * numerocon.imaginaria)) / denominador;
        imaginaria = (num1.imaginaria * numerocon.real + num1.real * numerocon.imaginaria) / denominador;
        cout<<real<<" + "<<imaginaria<<endl;
    }
};

class Racional{
private:
    double numerador, denominador;
public:
    Racional(double arg1 = 0, double arg2 = 0){  
        numerador = arg1;
        denominador = arg2;
    }
    void simplificar (){
        for (double i = denominador * numerador; i > 1; i--) {
            if ((fmod(denominador, i) == 0) && (fmod(numerador, i) == 0)) {  
                numerador /= i;  
                denominador /= i;  
            }        
        }
        while(fmod(numerador, 10) == 0 && fmod(denominador, 10) == 0){
            numerador /= 10;
            denominador /= 10;
        }

    }
    void suma(Racional r1, Racional r2){
        double numerador1=r1.numerador;
        double denominador1=r1.denominador;
        double numerador2=r2.numerador;
        double denominador2=r2.denominador;
        numerador = denominador2 * numerador1 + denominador1 * numerador2;
        denominador = denominador1 * denominador2;
        cout<<numerador<<"/"<<denominador<<endl;
        simplificar();
    }
    void resta(Racional r1, Racional r2){
        double numerador1=r1.numerador;
        double denominador1=r1.denominador;
        double numerador2=r2.numerador;
        double denominador2=r2.denominador;
        numerador=denominador2 * numerador1 - denominador1 * numerador2;
        denominador=denominador1 * denominador2;
        cout<<numerador<<"/"<<denominador<<endl;
        simplificar();
    }
    void multiplicacion(Racional r1, Racional r2){
        double numerador1=r1.numerador;
        double denominador1=r1.denominador;
        double numerador2=r2.numerador;
        double denominador2=r2.denominador;
        numerador=numerador1 * numerador2;
        denominador=denominador1 * denominador2;
        cout<<numerador<<"/"<<denominador<<endl;
        simplificar();
    }
    void dividir(Racional r1, Racional r2){
        double numerador1=r1.numerador;
        double denominador1=r1.denominador;
        double numerador2=r2.numerador;
        double denominador2=r2.denominador;
        numerador=numerador1 * denominador2;
        denominador=numerador2 * denominador1;
        cout<<numerador<<"/"<<denominador<<endl;
        simplificar();
    }
};

int main(){
    //Fecha
    Fecha hoy (7,1,2021);
    hoy.Dia(dia,mes,anio);
    hoy.Mes(dia,mes,anio);
    hoy.Anio(dia,mes,anio);
    hoy.funcionfecha(dia,mes,anio);
    hoy.funcionbiciesto(dia,mes,anio);
    //Complejo
    Complejo num1(3,5), num2(4,9);
    Complejo complex;
    complex.resta(num1,num2);
    complex.suma(num1,num2);
    complex.division(num1,num2);
    complex.multiplicacion(num1,num2);
    //Racional
    Racional r1(5,7), r2 (9,4);
    Racional total;
    total.suma(numerador,denominador);
    total.resta(numerador,denominador);
    total.multiplicacion(numerador,denominador);
    total.division(numerador,denominador);
    return 0;
}

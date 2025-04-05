#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

//metricas
double DistanciaTaxi(double x1, double x2, double y1, double y2) {
   return abs(x2-x1) + abs(y2-y1);
}

double DistanciaEuclidea(double x1, double x2, double y1, double y2) {
    return sqrt( pow(x2-x1, 2) + pow(y2 - y1, 2));
}

double DistanciaMaximo(double x1, double x2, double y1, double y2) {
    return max(abs(x2-x1), abs(y2-y1));

}

//Unidades
double ConvertiraMetro(char unidades, double distancia) {

switch(unidades) {

case 'k': case 'K':
return distancia * 1000;

case 'a': case 'A':
return distancia * 1609.344;

case 'm':case 'M':
return distancia;

default: system("pause");
    return 0;
}
}

int main() {

char unidades, metricas;
double x1, x2, y1, y2;
double distancia;

cout << "Calculadora de distancias.";

cout << "\nDame las unidades: ";
cin >> unidades;

if(unidades != 'k' && unidades != 'K' && unidades != 'A' && unidades != 'a' && unidades != 'm'&& unidades != 'M') {
    cout << "Opcion no valida.\n" ;
    system("pause");
    return 0;
}


cout << "\nDame la metrica: ";
cin >> metricas;
cout << endl;

if(metricas != 't' && metricas != 'm' && metricas != 'e') {
    cout << "Opcion no valida.\n";
    system("pause");
    return 0;
}

cout << "Dame el primer punto: ";
cout << "\nx1:";
cin >> x1;

cout << "y1: ";
cin >> y1;

cout << "Dame el segundo punto:";
cout << "\nx2: ";
cin >> x2;

cout << "y2: ";
cin >> y2;


if(metricas == 't') {
    distancia = DistanciaTaxi(x1, x2, y1, y2);
}
else if(metricas == 'e') {
    distancia = DistanciaEuclidea(x1, x2, y1, y2);
}
else if(metricas == 'm') {
    distancia = DistanciaMaximo(x1, x2, y1, y2);
}


double distanciaenMetros = ConvertiraMetro(unidades, distancia);
 

if(distanciaenMetros < 0){
    cout << "Distancia no valida(tiene valor negativo).\n";
    system("pause");
    return 0;
}

cout << "\nLa distancia entre el punto1(x1,y1) y el punto2(x2,y2) es: " << distanciaenMetros << "m." << endl;


getch();
    return 0;
}
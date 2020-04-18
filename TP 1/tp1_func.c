#include <stdio.h>
#include <stdlib.h>
#include "tp1_func.h"

int sumar (int a,int b)
{
    int suma;
    suma = a+b;
    return suma;
}
int restar(int a,int b)
{
    int resta;
    resta = a-b;
    return resta;
}
int multiplicar (int a,int b)
{
    int producto;
    producto = a*b;
    return producto;
}
float dividir(int a,int b)
{
    float resultado;
    resultado = (float)a/b;
    return resultado;
}
long long int sacarFactorial (int a)
{
    long long int factorial = 1;
    if (a>0){
    for (; a>1; a--)
    {
        factorial = factorial * a;
    }
    } else if (a==0){
        factorial = 0;
    } else {
    factorial = -1;
    }
    return factorial;
}

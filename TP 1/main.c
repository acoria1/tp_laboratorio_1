#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1_func.h"

//TP1: Calculadora de 2 operandos. Toma 2 numeros enteros y calcula su suma,resta,division,multiplicacion, y factorial de cada uno

int main()
{
    char respuesta;
    int num1;
    int num2;
    int suma;
    int resta;
    int producto;
    float division;
    long long int factorialNum1;
    long long int factorialNum2;
    int contOp1 = 0;
    char continuar1;
    int contOp2 = 0;
    char continuar2;
    int contCalculo = 0;

    do
    {
        printf("***CALCULADORA BASICA*** \n\n");
        if (contOp1 == 0){
        printf("a- Ingresar 1er operando A = x\n");
        } else {
        printf("a- Ingresar 1er operando A = %d\n",num1);
        }
        if (contOp2 == 0){
        printf("b- Ingresar 2do operando B = y\n");
        } else {
        printf("b- Ingresar 2do operando B = %d\n",num2);
        }

        printf("c- Calcular todas las operaciones \n");
        printf("d- Ver resultados \n");
        printf("e- Salir \n");

        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta = tolower(respuesta);

        switch(respuesta)
        {
        case 'a':
            if (contOp1 == 0)
            {
                printf("\nIngrese primer operando: ");
                fflush(stdin);
                scanf("%d",&num1);
                contOp1++;
            }
            else
            {
                do
                {
                    printf("Ya ingreso primer operando, desea continuar de todos modos? (los datos se sobrescribiran)...\n(y/n)\n");
                    fflush(stdin);
                    scanf("%c",&continuar1);
                    continuar1 = tolower(continuar1);
                }
                while (continuar1 != 'n'&&continuar1!='y');
                if (continuar1 == 'y')
                {
                    printf("Ingrese primer operando: ");
                    scanf("%d",&num1);
                    contOp1++;
                }
            }
            break;
        case 'b':
            if (contOp2 == 0)
            {
                printf("\nIngrese segundo operando: ");
                fflush(stdin);
                scanf("%d",&num2);
                contOp2++;
            }
            else
            {
                do
                {
                    printf("Ya ingreso segundo operando, desea continuar de todos modos? (los datos se sobrescribiran)\n(y/n)\n");
                    fflush(stdin);
                    scanf("%c",&continuar2);
                }
                while (continuar2 != 'n'&&continuar2!='y');
                if (continuar2 == 'y')
                {
                    printf("Ingrese segundo operando: ");
                    scanf("%d",&num2);
                    contOp2++;
                }
            }
            break;
        case 'c':
            if (contOp1 != 0 && contOp2 != 0)
            {
                suma = sumar(num1,num2);
                resta = restar(num1,num2);
                division = dividir(num1,num2);
                producto = multiplicar(num1,num2);

                if (num1>=0&&num1 <=20)
                {
                    factorialNum1 = sacarFactorial(num1);
                }
                if (num2>=0 && num2<=20)
                {
                    factorialNum2 = sacarFactorial(num2);
                }
                contCalculo++;
                printf("Calculos finalizados \n");

            }
            else
            {
                printf("\nError. Debe ingresar 2 operandos para realizar los calculos");
                if (contOp1 == 0)
                {
                    printf("\n1er operando no tiene valor");
                }
                if (contOp2 == 0)
                {
                    printf("\n2do operando no tiene valor");
                }
                printf("\n\n");
            }
            system("pause");
            break;
        case 'd':
            if (contCalculo>0)
            {
                system("cls");
                printf("**RESULTADOS**\n");
                printf("El resultado de %d + %d es: %d \n",num1,num2,suma);
                printf("El resultado de %d - %d es: %d \n",num1,num2,resta);
                if (num2 != 0)
                {
                    printf("El resultado de %d / %d es: %.2f \n",num1,num2,division);
                }
                else
                {
                    printf("El resultado de %d / %d es: -Error, no se puede dividir por 0.- \n",num1,num2);
                }
                printf("El resultado de %d * %d es: %d \n",num1,num2,producto);
                if (num1<0)
                {
                    printf("El factorial de %d es: -Error, no se puede calcular el factorial de numeros negativos.- \n",num1);
                }
                else if (num1>20)
                {
                    printf("El factorial de %d es: -Error, el factorial es muy grande como para ser mostrado por este programa.- \n",num1);
                }
                else
                {
                    printf("El factorial de %d es: %lli \n",num1,factorialNum1);
                }
                if (num2<0)
                {
                    printf("El factorial de %d es: -Error, no se puede calcular el factorial de numeros negativos.- \n",num2);
                }
                else if (num2>20)
                {
                    printf("El factorial de %d es: -Error, el factorial es muy grande como para ser mostrado por este programa.- \n",num2);
                }
                else
                {
                    printf("El factorial de %d es: %lli \n",num2,factorialNum2);
                }
                system("pause");
            }
            else
            {
                printf("Debe realizar los calculos antes de mostrar los resultados.\n");
                system("pause");
            }
            break;
        case 'e':
            break;
        default:
            printf("opcion no encontrada en el menu...");
            system("pause");
        }
        system("cls");
    }
    while (respuesta != 'e');

    return 0;
}


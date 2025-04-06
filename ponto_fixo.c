/*
AUTOR       -   GABRIEL FERREIRA DOS SANTOS ESTEVES
NUSP        -   15453240
EXERCÍCIO   -   EXERCÍCIO-PROGRAMA 1: Equações não lineares em uma variável
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double e = M_E;    // definição do número de euler

double h(int x){
    /*
    ENTRADA:
        double x:   abcissa em que será calculada h(x)
    
    SAÍDA:
        double x:   resultado de h(x)

    função que retorna a função h(x) = x
    */

    return x;
}

double g(double x){
    /*
    ENTRADA:
        double x:      abcissa inicial onde será calculada g(x)

    SAÍDA:
        log(2x^2),      se x > 2
        sqrt((e^x)/2),  se 0 <= x <= 2
        -sqrt((e^x)/2), se x < 0

    função que retorna a função auxiliar g(x),
    para aproximar f(x) = 0.
    */
    
    if (x > 2){
        return log(pow(2*x, 2));
    }

    else if (x < 0){
        return -sqrt((pow(e,x))/2);
    }

    else{
        return sqrt((pow(e,x))/2);
        }
    }

void ponto_fixo(double x0, double epsilon){
    /*
    ENTRADA:
        double x0:       ponto inicial onde será calculado g(x)
        double epsilon:  erro tolerado para aproximar f(x) = 0

    SAÍDA:
        double xk1:      primeiro ponto em que xk+1 - xk  <= epsilon

    função que calcula iterativamente o método de ponto fixo
    para encontrar uma raíz de f(x) usando as funções auxiliares
    g(x) e h(x)
    */

    double alpha = g(x0);        // valor de g na abcissa x0 dada
    double xk1 = h(x0);          // ponto x_{k+1} da iteração atual
    double xk;                   // ponto x_{k} da iteração anterior

    double beta;                 // valor auxiliar da iteração


    ///// loop principal do método /////
    while (1){
        if (abs(xk1-xk) <= epsilon){
            printf("\nA raiz aproximada é: %lf \nCom epsilon == %lf\n", xk1, epsilon);
            return;
        }

        xk = xk1;

        beta = g(alpha);
        xk1 = h(beta);
        alpha = g(xk1);
    }
}


int main(){
    
    double x0;           // abcissa inicial x_{0}
    double epsilon;      // erro tolerável para aproximar f(x) = 0

    printf("Insira uma abcissa x0 onde deseja que o algoritmo comece: ");
    scanf("%lf", &x0);
    printf("Insira um valor de erro tolerável para aproximar f(x) = 0: ");
    scanf("%lf", &epsilon);

    ponto_fixo(x0, epsilon);

    return 0;
}
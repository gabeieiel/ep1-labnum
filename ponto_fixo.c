/*
AUTOR       -   GABRIEL FERREIRA DOS SANTOS ESTEVES
NUSP        -   15453240
EXERCÍCIO   -   EXERCÍCIO-PROGRAMA 1: Equações não lineares em uma variável
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double e = M_E;    // definição do número de euler


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
        return log(2*pow(x, 2));
    }

    else if (x < 0){
        return -sqrt(pow(e,x)/2);
    }

    else{
        return sqrt(pow(e,x)/2);
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

    double xk1;         // ponto x_{k} da iteração atual
    double xk = x0;     // ponto x_{k} da iteração anterior

    ///// loop principal do método /////
    while (1){
        
        xk1 = g(xk);
        
        if (fabs(xk1-xk) <= epsilon){
            printf("\nUma raiz aproximada é: x == %lf \nCom epsilon == %lf e x0 == %lf \n", xk1, epsilon, x0);

            return;
        }

        xk = xk1;        
    }
}


int main(){
    
    double x0;           // abcissa inicial x_{0}
    double epsilon = 1e-6;      // erro tolerável para aproximar f(x) = 0

    /// x0's para aproximar as três raízes de f(x) ///
    ponto_fixo(-1.5, epsilon);
    ponto_fixo(1.0, epsilon);
    ponto_fixo(3.0, epsilon);


    printf("\nInsira uma abcissa x0 onde deseja que o algoritmo comece: ");
    scanf("%lf", &x0);
    printf("\nInsira um valor de erro tolerável para aproximar f(x) = 0: ");
    scanf("%lf", &epsilon);

    ponto_fixo(x0, epsilon);

    return 0;
}
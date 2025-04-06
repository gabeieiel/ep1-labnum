/*
AUTOR       -   GABRIEL FERREIRA DOS SANTOS ESTEVES
NUSP        -   15453240
EXERCÍCIO   -   EXERCÍCIO-PROGRAMA 1: Equações não lineares em uma variável
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>

double complex evalf(double complex z){
    /*
    método para retornar a função
    f(z) = z⁵ + 1
    */

    return cpow(z,5) + 1;
}

double complex evalDf(double complex z){
	/*
    método para retornar a derivada
    f'(z) = 5z⁴
    */

    return 5*cpow(z,4);
}

double complex metodo_newton_raphson(double complex z0, double epsilon){
    /*
    ENTRADA:
        double complex  z0:         ponto inicial z0, um complexo
        double          epsilon:    erro tolerado para a aproximação

    SAÍDA:
        double complex  zk1:        ponto de maior aproximação da função

    função para aproximar as raízes de f(z) = z⁵ + 1
    usando o método de newton-raphson
    */

    /// ABCISSAS DA ITERAÇÃO ///
    double complex zk1;     // ponto da iteração atual
    double complex zk = z0; // ponto da iteração anterior 
    
    
    /// LOOP PRINCIPAL DO MÉTODO ///
    while (1){
        zk1 = zk - (evalf(zk)/evalDf(zk));
            
        // CONDIÇÃO DE PARADA //
        if (cabs(zk1 - zk) <= epsilon){
            return zk1;
        }

        zk = zk1;
    }
}


int associa_raiz(double complex z, double complex *raizes, int n, double epsilon){
    /*
    ENTRADA:
        double complex  z:          aproximação da raiz
        double complex  *raizes:    ponteiro para o array de raízes reais
        int             n:          quantidade de raizes de f(x)
        double          epsilon:    erro tolerado para associação entre z e sua raiz real

    SAÍDA:
        int             indice:     indice da raiz real associada a z dentro de seu array


    função que associa a aproximação z da raiz com as raízes reais e retorna
    um número (índice da raiz real em seu array) de acordo com a raiz associada
    */

    /// LOOP PARA PERCORRER O ARRAY DE RAIZES ///
    for (int indice = 0; indice < n; indice++) {
        if (cabs(z - raizes[indice]) < epsilon) {
            return indice;
        }
    }
    return -1;   // não convergiu para nenhuma raiz conhecida
}



void newton_basins(double l[2], double u[2], double p[2], double epsilon){
    /*
    ENTRADA:
        double  l:  array com os valores limitantes das abcissas 
                    do intervalo em que será calculada a bacia de convergência
                    
        double  u:  array com os valores limitantes das ordenadas 
                    do intervalo em que será calculada a bacia de convergência

    SAÍDA:
        double complex  z:   resultado de h(z)

    função calcula o método de newton em todos os pontos de [l_{1},u_{1}]x[l_{2},u_{2}]
    e gera o gráfico das bacias usando gnuplot.
    */

    /// RAIZES CONHECIDAS DA FUNÇÃO ///
    double complex raizes[5];
    for (int k = 0; k < 5; k++) {
        
        // cálculo analítico das raízes de f(z) //
        double theta = M_PI * (2*k + 1) / 5;
        raizes[k] = ccos(theta) + csin(theta)*I;
    }

    /// ARQUIVO ///
    FILE *fp = fopen("output.txt", "w");    // cria o arquivo output.txt em modo de escrita

    if (fp == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }


    /// PASSOS DE CADA ITERAÇÃO ///
    double passo_x = fabs(l[0] - l[1])/p[0];
    double passo_y = fabs(u[0] - u[1])/p[1]; 

    /// LOOP PARA PERCORRER CADA PIXEL DA IMAGEM ///
    for (double i = 0; i < p[0]; i++){
        for(double j = 0; j < p[1]; j++){
            
            double x = l[0] + i*passo_x;        // parte real do pixel
            double y = l[1] + j*passo_y;        // parte complexa do pixel
            
            double complex pixel = x + y*I;

            double complex raiz_aprox = metodo_newton_raphson(pixel, epsilon);
            
            int indice = associa_raiz(raiz_aprox, raizes, 5, epsilon);


            fprintf(fp, "%d", indice);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}


int main(){

    double epsilon = 1e-6;
    
    /*
    /// APROXIMAÇÃO DAS 5 RAIZES ///
    metodo_newton_raphson(1.0 + 0.0*I, epsilon);
    metodo_newton_raphson(0.0 + 1.0*I, epsilon);
    metodo_newton_raphson(1.0 - 1.0*I, epsilon);
    metodo_newton_raphson(0.0 - 1.0*I, epsilon);
    metodo_newton_raphson(0.5 + 0.5*I, epsilon);
    */

    /// PLANO [l1,u1]x[l2,u2]
    double l[2] = {-2.0,2.0};       // intervalo [l1,u1]
    double u[2] = {-2.0,2.0};       // intervalo [l2,u2]
        
    double p[2] = {1000.0,1000.0};  // tamanho da imagem

    newton_basins(l,u,p,epsilon);

    return 0;
}
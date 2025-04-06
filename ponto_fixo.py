import math
e = math.exp(1)

def h(x):
    '''
    método para retornar a função h(x) = x
    '''

    return x

def g(x):
    '''
    método para retornar a função auxiliar g(x),
    para aproximar f(x):
    - se x > 2, g(x) = ln(2x²)
    - caso contrário, g(x) = sqrt(e^x / 2)
    '''

    if x > 2:
        return math.log(2*(x**2))
    
    elif x < 0:
        return -math.sqrt((e**x)/2)
    
    else:
        return math.sqrt((e**x)/2)

def f(x):
    '''
    função f(x) = e^{x} - 2x^{2}, dada pelo enunciado
    do exercício.
    '''

    return e**x - 2*x**2

def ponto_fixo(x0, epsilon):
    '''
    método iterativo de ponto fixo, que aproxima
    a função f(x) = e**x - 2x**2 usando as funções
    auxiliares g(x) e h(x) = x
    '''
    
    alpha = g(x0)
    xk1 = h(x0)      # ponto x_{k+1} da iteração atual
    xk = 0           # ponto x_{k} da última iteração

    while True:
        ##### critério de parada #####
        if abs(xk1 - xk) < epsilon:
            print(f"\nA raiz aproximada é: {xk1} \nCom epsilon == {epsilon}")
            return
            

        xk = xk1

        beta = g(alpha)
        xk1 = h(beta)
        alpha = g(xk1)

def main():
    x0 = float(input("Insira uma abcissa x0 para iniciar o algoritmo: "))
    epsilon = float(input("Insira o valor desejado de epsilon: "))

    ponto_fixo(x0, epsilon)


if __name__=="__main__":
    main()


    


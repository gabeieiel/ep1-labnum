import matplotlib.pyplot as plt
import numpy as np
import math
import os

e = math.exp(1)

fig, ax = plt.subplots(figsize=(7,5))

DOMINIO = np.linspace(-3, 4, 3000)


def h(x):
    '''
    método para retornar a função h(x) = x
    '''

    return x



def g(DOMINIO):
    '''
    ENTRADA:
        int[] DOMINIO:  
    
    SAÍDA:

    método para retornar a função auxiliar g(x),
    para aproximar f(x):
    - se x > 2, g(x) = 2ln(2x)
    - caso contrário, g(x) = sqrt(e^x / 2)
    '''

    g1 = np.log(2 * np.abs(DOMINIO**2))
    g2 = np.where(DOMINIO >= 0, np.sqrt(e**DOMINIO / 2), -1*np.sqrt(e**DOMINIO / 2))

    g_x = np.where(DOMINIO > 2, g1, g2)
    
    # Verifica os pontos onde g(x) está próximo de h(x)
    epsilon = 1e-3  # Reduzindo epsilon para maior precisão
    indices_proximos = np.where(np.abs(g_x - h(DOMINIO)) < epsilon)[0]

    # Remover duplicatas nos índices encontrados
    indices_unicos = np.unique(indices_proximos)

    if indices_unicos.size > 0:
        print(f"g(x) ≈ h(x) nos pontos: {DOMINIO[indices_unicos]}")
        print(f"Valores correspondentes de f(x): {f(DOMINIO[indices_unicos])}")

    return g_x


def f(x):
    '''
    função f(x) = e^{x} - 2x^{2}, dada pelo enunciado
    do exercício.
    '''

    return e**x - 2*x**2

g(DOMINIO)

ax.plot(DOMINIO, h(DOMINIO), label='Função h(x) = x', color='orange')
ax.plot(DOMINIO, g(DOMINIO), label='Função g1(x) = ln(2x²) caso x>2 \nou g2(x) = sqrt((e^x)/2) caso x<=2', color='r')
ax.plot(DOMINIO, f(DOMINIO), label='Função f(x) = e^x - 2x^2', color='g')

ax.set_title("Implementação do Método de Ponto Fixo\n com precisão de 3000 pontos em [-3,4]")
ax.legend()
ax.grid()

##### DOWNLOAD DO GRÁFICO #####
diretorio = "teste de plotagem do ponto fixo ep1"

    ### verifica se o diretorio existe ou cria-lhe, caso não exista
if not os.path.exists(diretorio):
    os.makedirs(diretorio)

caminho_arquivo = os.path.join(diretorio, "ponto_fixo.png")
plt.savefig(caminho_arquivo, format='png')

plt.show()


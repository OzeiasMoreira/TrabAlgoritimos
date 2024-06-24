import os
import matplotlib.pyplot as plt

def ler_arquivo(nome_arquivo):
    dados = {'Sequencial': [], 'Sequencial ordenado': [], 'Binaria': []}
    if not os.path.isfile(nome_arquivo):
        print(f"Arquivo {nome_arquivo} não encontrado no diretório: {os.getcwd()}")
        return dados
    with open(nome_arquivo, 'r') as arquivo:
        for linha in arquivo:
            partes = linha.strip().split(': ')
            if len(partes) != 2:
                continue
            tipo, resto = partes
            tam, iteracoes = resto.split(',')
            tam = int(tam)
            iteracoes = int(iteracoes)
            if tipo in dados:
                dados[tipo].append((tam, iteracoes))
            else:
                dados[tipo] = [(tam, iteracoes)]
    return dados

def plotar_grafico(dados, titulo):
    plt.figure(figsize=(10, 6))
    for tipo, valores in dados.items():
        tamanhos = [x[0] for x in valores]
        iteracoes = [x[1] for x in valores]
        plt.plot(tamanhos, iteracoes, label=tipo)
    plt.xlabel('Tamanho do Array')
    plt.ylabel('Número de Iterações')
    plt.title(titulo)
    plt.legend()
    plt.grid(True)
    plt.show()

# Adicione o caminho completo para os arquivos, se necessário
caminho_pior_caso = 'C:\\Users\\Ozeias\\Desktop\\TrabAlgoritimos\\output\\iteracoesPiorCaso.txt'
caminho_caso_medio = 'C:\\Users\\Ozeias\\Desktop\\TrabAlgoritimos\\output\\iteracoesCasoMedio.txt'

# Debugging: imprimir o diretório atual e verificar se os arquivos existem
print(f"Diretório atual: {os.getcwd()}")
print(f"Arquivo {caminho_pior_caso} existe? {os.path.isfile(caminho_pior_caso)}")
print(f"Arquivo {caminho_caso_medio} existe? {os.path.isfile(caminho_caso_medio)}")

dados_pior_caso = ler_arquivo(caminho_pior_caso)
dados_caso_medio = ler_arquivo(caminho_caso_medio)

if dados_pior_caso:
    plotar_grafico(dados_pior_caso, 'Número de Iterações no Pior Caso')
else:
    print("Dados do pior caso não foram carregados.")

if dados_caso_medio:
    plotar_grafico(dados_caso_medio, 'Número de Iterações no Caso Médio')
else:
    print("Dados do caso médio não foram carregados.")

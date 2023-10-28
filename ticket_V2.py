from colorama import Fore, Style, init

# Inicializa o Colorama
init(autoreset=True)

print(Fore.BLUE + "Bem-vindo ao Museu Multitemático!" + Style.RESET_ALL)

exposicoes_selecionadas = []

while len(exposicoes_selecionadas) < 4:
    print("Escolha a exposição desejada:")
    print("1. 100 anos da semana de arte moderna")
    print("2. 150 anos de Santos Dumont")
    print("3. Jogos olímpicos de Paris 2024")
    print("4. Tema a ser definido")

    exposicao = int(input("Digite o número da exposição desejada (ou 0 para sair): "))

    if exposicao == 0:
        break
    elif exposicao < 1 or exposicao > 4:
        print(Fore.RED + "Opção inválida. Por favor, escolha uma exposição de 1 a 4." + Style.RESET_ALL)
    else:
        exposicoes_selecionadas.append(exposicao)

for exposicao in exposicoes_selecionadas:
    categoria = input(f"Exposição {exposicao} - Escolha a categoria de ingresso:\n"
                     "a. Inteira\n"
                     "b. Meia entrada\n"
                     "c. Gratuito (para idosos)\n"
                     "Digite a categoria de ingresso (a, b ou c) para a Exposição {exposicao}: ")

    quantidade = int(input(f"Digite a quantidade de ingressos desejada para a Exposição {exposicao}: "))

    valor_total = 0.0

    if categoria == 'a':
        valor_total = quantidade * 20.0
    elif categoria == 'b':
        valor_total = quantidade * 10.0
    elif categoria == 'c':
        valor_total = 0.0
    else:
        print(Fore.RED + "Categoria de ingresso inválida." + Style.RESET_ALL)

    print(Fore.GREEN + f"Valor total para a Exposição {exposicao}: R$ {valor_total:.2f}" + Style.RESET_ALL)

confirmacao = input("Confirmar a compra (S para sim, N para não): ")

if confirmacao == 'S' or confirmacao == 's':
    # Código para registrar a compra e exibir mensagem de agradecimento
    print(Fore.BLUE + "Compra confirmada. Obrigado por comprar os ingressos!" + Style.RESET_ALL)
else:
    print(Fore.RED + "Compra cancelada." + Style.RESET_ALL)

nova_compra = input("Deseja fazer outra compra (S para sim, N para não): ")

if nova_compra == 'S' or nova_compra == 's':
    pass

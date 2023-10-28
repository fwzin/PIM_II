print("Bem-vindo ao Museu Multitemático!")

exposicoes_selecionadas = []  # Uma lista para armazenar as exposições selecionadas

while len(exposicoes_selecionadas) < 4:  # Permite selecionar até 4 exposições
    print("Escolha a exposição desejada:")
    print("1. 100 anos da semana de arte moderna")
    print("2. 150 anos de Santos Dumont")
    print("3. Jogos olímpicos de Paris 2024")
    print("4. Tema a ser definido")

    # Solicitar exposição (1 a 4)
    exposicao = int(input("\n \n Digite o número da exposição desejada (ou 0 para sair): "))

    if exposicao == 0:
        break  # Sai do loop se o cliente escolher 0
    elif exposicao < 1 or exposicao > 4:
        print("Opção inválida. Por favor, escolha uma exposição de 1 a 4.")
    else:
        # Armazena a exposição selecionada na lista
        exposicoes_selecionadas.append(exposicao)

# Agora, incluímos o código para a compra de ingressos para cada exposição selecionada
for exposicao in exposicoes_selecionadas:
    categoria = input(f"\n \n Exposição {exposicao} - Escolha a categoria de ingresso:\n"
                     "a. Inteira\n"
                     "b. Meia entrada\n"
                     "c. Gratuito (para idosos)\n"
                     "Digite a categoria de ingresso (a, b ou c) para a Exposição {exposicao}: ")

    quantidade = int(input(f"\n \n Digite a quantidade de ingressos desejada para a Exposição {exposicao}: "))

    valor_total = 0.0  # Inicializamos com zero

    # Calcular valor total com base na categoria e quantidade de ingressos
    if categoria == 'a':  # Inteira
        valor_total = quantidade * 20.0  # Preço fictício de R$20 por ingresso inteira
    elif categoria == 'b':  # Meia entrada
        valor_total = quantidade * 10.0  # Preço fictício de R$10 por ingresso meia entrada
    elif categoria == 'c':  # Gratuito (idosos)
        valor_total = 0.0  # Ingressos para idosos são gratuitos
    else:
        print("Categoria de ingresso inválida.")

    print(f"\n \nValor total para a Exposição {exposicao}: R$ {valor_total:.2f}")

confirmacao = input("Confirmar a compra (S para sim, N para não): ")

if confirmacao == 'S' or confirmacao == 's':
    # Inserir aqui o código para registrar a compra e exibir mensagem de agradecimento
    pass
else:
    print("Compra cancelada.")

nova_compra = input("Deseja fazer outra compra (S para sim, N para não): ")

if nova_compra == 'S' or nova_compra == 's':
    pass

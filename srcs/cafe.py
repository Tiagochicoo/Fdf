#loja de café

coffee = {
    1 : "Café",
    2 : "Descafeínado",
    3 : "Café Duplo",
    4 : "Abatanado",
    5 : "Galão",
    6 : "Meia de Leite",
    7 : "Carioca",
}
price = {
    1 : 1,
    2 : 1.60,
    3 : 1.10,
    4 : 1.50,
    5 : 0.80,
}
# class cafes:                     #definir um tipo de variável para os cafés
#     nome_c: str
#     preco_c: float

# cafe = cafes                   #declaração das variáveis com a variável criada
# descafeinado = cafes
# duplo = cafes
# abatanado = cafes
# galao = cafes
# meia_de_leite = cafes
# carioca = cafes

# cafe.nome_c = "Café"                                  #definir nome e preço dos cafés
# cafe.preco_c = 1
# descafeinado.nome_c = "Descafeínado"
# descafeinado.preco_c = 1
# duplo.nome_c = "Duplo"
# duplo.preco_c = 1.60
# abatanado.nome_c = "Abatanado"
# abatanado.preco_c = 1.10
# galao.nome_c = "Galão"
# galao.preco_c = 1.60
# meia_de_leite.nome_c = "Meia de Leite"
# meia_de_leite.preco_c = 1.50
# carioca.nome_c = "Carioca"
# carioca.preco_c = 0.80

print('Olá, Bem-vindo à cafetaria do Paulo!')        #Introdução

nome = input('Como se chama?\n')

print('Olá '+ nome +', obrigado por ter escolhido a nossa cafetaria hoje!\n')

# menu = ["Café", "Descafeínado", "Duplo", "Abatanado", "Galão", "Meia de Leite", "Carioca"]
preco = 0
def pedido():
    x = 0
    if preco != 0:
        return preco
    for i in coffee:          #mostrar o menu
        print(i,"-", coffee[i])
    print()
    item = input("Aqui está o nosso menu. Introduza o número deseja\n")                         #anotar o pedido
    if item == "1" or item == "2":      #valor dos cafés
        preco = price[1]
    elif item == "3" or item == "4":
        preco = price[2]
    elif item == "5":
        preco = price[3]
    elif item == "6":
        preco = price[4]
    elif item == "7":
        preco = round(price[5], 2)
    else:
        print("\nProduto não reconhecido!\nPor favor selecione um número da lista.\n")
        pedido()    #recursão -> se não selecionar um item válido, volta a mostrar a lista na função pedido()
        # exit

preco = pedido()
if preco == None:
    preco = pedido()
else:
    total1 = preco

total1 = preco

print("Obrigado. O seu total é: " + str(total1), '€')

dinheiro_receb = float(input("Insira aqui o dinheiro para pagar: "))

def verificar_dinheiro(total):           #procedimento para verificar se o utilizador tem dinheiro necessário

    if dinheiro_receb < total:
        total = round(total - dinheiro_receb, 1)
        dinheiro_falta = round(float(input("Falta(m) " + str(round(total, 1)) + "€, por favor insira o restante valor ou chamaremos a polícia. ")), 1)
        if dinheiro_falta < total:
            total = round(total - float(dinheiro_falta), 1)
            print("Ainda falta(m)",round(total, 1),"€")
            resp = input("Tem o montante suficiente para pagar o resto? ")
            if resp == "Sim":
                dinheiro_falta = round(float(input("Introduza o dinheiro restante: ")), 1)
                if dinheiro_falta < total:
                    print("Demos-lhe uma última chance, agora chamaremos a polícia!\n")
                    print("Foste preso por um mero café. Tem vergonha.")
                elif dinheiro_falta == total:
                    print("Obrigado e volte sempre! :))")
                elif (dinheiro_falta) > total:
                    total = dinheiro_falta - total
                    print("Aqui tem o seu troco. (",round(total, 1),")")
            elif resp == "Não":
                print("Peço desculpa mas não pode sair sem pagar, teremos que chamar a polícia.\n")
                print("Foste preso por um mero café. Tem vergonha.")
        elif float(dinheiro_falta) == total:
            print("Obrigado e volte sempre! :))")
        elif float(dinheiro_falta) > total:
            print("Aqui tem o seu troco, obrigado e volte sempre! :)")
    elif dinheiro_receb > total:
        total = dinheiro_receb - total
        print("Aqui tem o seu troco. (",round(total, 1),")")
        print("Obrigado e volte sempre! :))")
    elif dinheiro_receb == total:
        print("Obrigado e volte sempre! :))")

verificar_dinheiro(total1)
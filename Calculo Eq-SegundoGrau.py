print("Programa para a resolução de equações de segundo grau!")
print()

try:
    a = float(input("Digite o coeficiente a: "))
    b = float(input("Digite o coeficiente b: "))
    c = float(input("Digite o coeficiente c: "))

    if a == 0:
        print("A equação não é de segundo grau!")
    else:
        delta = b ** 2 - 4 * a * c

        if delta < 0:
            print("Não há raízes reais!")
        elif delta == 0:
            raiz = -b / (2 * a)
            print(f'Só tem uma raiz e ela vale: {raiz}')
        else:
            raiz1 = (-b - delta ** 0.5) / (2 * a)
            raiz2 = (-b + delta ** 0.5) / (2 * a)
            print(f'Existem duas raízes, e elas valem: {raiz1} e {raiz2}')
except ValueError:
    print("Devem-se utilizar números!")

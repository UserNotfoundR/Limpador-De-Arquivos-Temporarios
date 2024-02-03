import shutil
import os as sistema
import os
import time
while True:
    print("\x1b[2J\x1b[1;1H") 
    dir = f"C:/users/{sistema.getlogin()}/AppData/Local/Temp/"
    dir1 = f"C:/Windows/Temp"
    dir2 = f"C:/Users/{sistema.getlogin()}/AppData/Local/Microsoft/Windows/INetCache/IE"
    dir3 = f"C:/$Recycle.bin/S-1-5-21-2053619040-3475313007-3058449245-1004"

    def paste():
        size = 0
        Folderpath = dir
        for path, dirs, files in os.walk(Folderpath):
            for f in files:
                fp = os.path.join(path, f)
                size += os.path.getsize(fp)
        size = size / 1024
        size = size / 1024
        print("%TEMP%(MB): " + str(size))

        size = 0
        Folderpath = dir1
        for path, dirs, files in os.walk(Folderpath):
            for f in files:
                fp = os.path.join(path, f)
                size += os.path.getsize(fp)
        size = size / 1024
        size = size / 1024
        print("TEMP(MB): " + str(size))

        size = 0
        Folderpath = dir2
        for path, dirs, files in os.walk(Folderpath):
            for f in files:
                fp = os.path.join(path, f)
                size += os.path.getsize(fp)
        size = size / 1024
        size = size / 1024
        print("ARQUIVOS DE INTERNET(MB): " + str(size))

        size = 0
        Folderpath = dir3
        for path, dirs, files in os.walk(Folderpath):
            for f in files:
                fp = os.path.join(path, f)
                size += os.path.getsize(fp)
        size = size / 1024
        size = size / 1024
        print("LIXEIRA(MB): " + str(size))

    def rapido():
        shutil.rmtree(dir, ignore_errors = True)
        shutil.rmtree(dir1, ignore_errors=True)
        print("Tamanho depois da limpeza.")
        print("===================")
        paste()
        print("===================")


    def avancado():
        shutil.rmtree(dir, ignore_errors = True)
        shutil.rmtree(dir1, ignore_errors=True)
        shutil.rmtree(dir2, ignore_errors=True)
        shutil.rmtree(dir3, ignore_errors=True)
        print("Tamanho depois da limpeza.")
        print("===================")
        paste()
        print("===================")
        # Aqui não acho nesseraio colocar mais que isso de exemplo.
        
    print("tamanho da pastas temporarias(MB):")
    paste()

    print()
    
    print("===================")
    
    print("1: Limpeza rapida")
    print("2: Limpeza avançada")
    print("3: Sair")
    
    print("===================")

    op = input("Digite a opção: ")
    print("\x1b[2J\x1b[1;1H") 

    if op == "1":
        rapido()
        input("Precione enter para voltar ao menu.")

    elif op == "2":
        avancado()
        input("Precione enter para voltar ao menu.")

    elif op == "3":
        break
        exit
        
    else:
        print("Selecione uma opção valida")
        input("Precione enter para voltar ao menu.")




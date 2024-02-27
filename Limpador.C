#include <stdio.h>
#include <windows.h>

void deletarArquivosNaPasta(const char* caminhoPasta) {
    char caminhoCompleto[MAX_PATH];
    sprintf(caminhoCompleto, "%s\\*.*", caminhoPasta);

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(caminhoCompleto, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Erro ao abrir o diretório.\n");
        return;
    }

    do {
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
            sprintf(caminhoCompleto, "%s\\%s", caminhoPasta, findFileData.cFileName);

            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                // Se for uma pasta, chama a função recursivamente
                deletarArquivosNaPasta(caminhoCompleto);
                // Após excluir os arquivos na pasta, tenta remover a pasta
                if (!RemoveDirectory(caminhoCompleto)) {
                    printf("Erro ao excluir a pasta: %s\n", findFileData.cFileName);
                }
            } else {
                // Se for um arquivo, tenta excluí-lo
                if (!DeleteFile(caminhoCompleto)) {
                    printf("Erro ao excluir o arquivo: %s\n", findFileData.cFileName);
                }
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

int main() {
    char username[256];
    DWORD size = sizeof(username);

    if (GetUserName(username, &size)) {

        char caminhoTemp[MAX_PATH];
        sprintf(caminhoTemp, "C:\\Users\\%s\\AppData\\Local\\Temp", username);

        const char* tmp = "c:\\Windows\\Temp";

        int opc;

        printf("\nBem-vindo ao limpador:\n");
        printf("=============================\n");
        printf(" 1: Limpeza rápida\n");
        printf(" 2: Limpeza avançada\n");
        printf(" 3: Sair\n");
        printf("=============================\n");

        printf("Digite um número: ");
        scanf("%d", &opc);

        if (opc == 1) {
            deletarArquivosNaPasta(tmp);
            deletarArquivosNaPasta(caminhoTemp);
            printf("Os arquivos temporários e subpastas foram deletados.\n");
        } else if (opc == 2) {
            deletarArquivosNaPasta(tmp);
            deletarArquivosNaPasta(caminhoTemp);
            printf("Limpeza avançada realizada.\n");
        } else if (opc == 3) {
            printf("Saindo do programa.\n");
        } else {
            printf("Escolha a opção correta.\n");
        }
    } else {
        printf("Erro ao obter o nome de usuário. Código de erro: %d\n", GetLastError());
    }

    return 0;
}

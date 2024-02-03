#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <windows.h> 

using namespace std;
namespace fs = std::filesystem;

void removerConteudo(const fs::path& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        try {
            if (fs::is_directory(entry.path())) {
                // Se for um diretório, chama a função recursivamente
                removerConteudo(entry.path());
            }
            // Remove o arquivo ou subdiretório
            fs::remove_all(entry.path());
        }
        catch (const std::exception& e) {
            cerr << "Erro ao remover: " << e.what() << endl;
        }
    }
}

int main() {
    WCHAR userName[256];
    DWORD size = sizeof(userName) / sizeof(userName[0]);
    if (GetUserName(userName, &size)) {
        wprintf(L"Nome do usuário: %s\n", userName);
    }

    printf("Escolha uma opção:");
    printf("\n=================");
    printf("\n1: Limpeza rápida");
    printf("\n2: Limpeza complexa");
    printf("\n=================");

    int x;
    cout << "\nDigite um número: ";
    cin >> x;

    wstring userFolder = L"C:/Users/" + wstring(userName) + L"/AppData/Local/Temp";
    fs::path pasta_a_excluir = userFolder.c_str();
    fs::path dir1 = "C:/Windows/Temp";
    fs::path dir2 = "C:/$Recycle.bin/S-1-5-21-2053619040-3475313007-3058449245-1004";
    wstring userCacheFolder = L"C:/Users/" + wstring(userName) + L"/AppData/Local/Microsoft/Windows/INetCache/IE";
    fs::path dir3 = userCacheFolder.c_str();

    try {
        if (x == 1) {
            printf("\nLimpeza começando...");
            removerConteudo(pasta_a_excluir);
            removerConteudo(dir1);
            printf("\nLimpeza terminada.");
        }
        else if (x == 2) {
            printf("\nLimpeza começando...");
            removerConteudo(pasta_a_excluir);
            removerConteudo(dir1);
            removerConteudo(dir2);
            removerConteudo(dir3);
            printf("\nLimpeza terminada.");
        }
        else {
            printf("Selecione uma opção válida.");
        }
    }
    catch (const std::exception& e) {
        cerr << "Erro durante a limpeza: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Erro desconhecido durante a limpeza." << endl;
    }

    return 0;
}

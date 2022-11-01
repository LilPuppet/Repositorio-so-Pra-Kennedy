#include "Hash.cpp"
#include "lerArquivos.cpp"


int main (){
    char *arquivo1 = (char *)"bancoDeDados/legenda.txt";
    cidade *todasCidades = getCidades(arquivo1);
    char *arquivo2 = (char *)"bancoDeDados/coordenadas.csv";
    gps *locais = getGps(arquivo2);
    dataItem *d = getItens(todasCidades, locais);
    hash H;
    init(H);
    int j;
    for (int i = 0; i < SIZE; i++) {
        j = inserirNovo(H, d+i, divisao);
        if (i == -1) {
            printf("erro\n");
        }
    }
    escrever(H);
    //printDataItens(d);   
}
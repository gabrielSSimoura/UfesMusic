#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "midia.h"
typedef struct playlist Playlist;

/*Aloca uma Playlist vazia
*Input: nenhum;
*Output: uma Playlist Alocada;
*/
Playlist* AlocaPlaylist();

/*Recebe uma Playlist ja alocada, e seus dados, nome, colaboradores, quantidade de midias atuais, etc;
*Input: Playlist *p e caracteres;
*Output: nenhum;
*/
void CriaPlaylist(Playlist *p, char* nomep, char* colab1, char* colab2, int qtdColab, int qtdMidia, int tipo);

/*Recebe uma Playlist ja alocada, e seus dados, nome, colaboradores, quantidade de midias atuais, etc;
*Input: Playlist *p e caracteres;
*Output: nenhum;
*/
void AdicionaMidiaPlaylist(Playlist *p, Midia *m);

/*Recebe uma Playlist ja alocada;
*Input: Playlist *p;
*Output: inteiro com a quantidade de Midias;
*/
int RetornaQtdMidias(Playlist *p);

/*Recebe uma Playlist ja alocada,e a posicao da midia que deseja apagar;
*Input: Playlist *p e inteiro;
*Output: nenhum;
*/
void ApagaMidiaPlaylist(Playlist *p, int posicao);

/*Recebe uma Playlist ja alocada, e as posiçoes das midias;
*Input: Playlist *p e inteiros;
*Output: nenhum;
*/
void TrocaMidia(Playlist *p, int posicao1, int posicao2);

/*Recebe uma Playlist ja alocada e Imprime os dados da playlist;
*Input: Playlist *p;
*Output: nenhum;
*/
void ImprimePlaylist(Playlist *p);

/*Recebe uma Playlist ja alocada e Imprime o nome da playlist;
*Input: Playlist *p;
*Output: nenhum;
*/
void ImprimeNomePlaylist(Playlist *p);   

/*Recebe uma Playlist ja alocada e Imprime o nome dos colaboradores da playlist;
*Input: Playlist *p;
*Output: nenhum;
*/
void ImprimeColaboradoresPlaylist(Playlist *p);

/*Recebe uma Playlist ja alocada e Imprime as Midias da playlist;
*Input: Playlist *p;
*Output: nenhum;
*/
void ImprimeMidiasPlaylist(Playlist *p);

/*Recebe uma Playlist ja alocada e um nome e altera o nome anterior;
*Input: Playlist *p e caracter;
*Output: nenhum;
*/
void AtribuiNomePlaylist(Playlist *p, char *nomep);

/*Recebe uma Playlist ja alocada e Imprime-a;
*Input: Playlist *playfav;
*Output: nenhum;
*/
void ImprimePlaylistFavorita(Playlist *playfav);

/*Recebe uma Playlist ja alocada e Imprime o tipo;
*Input: Playlist *p;
*Output: inteiro;
*/
int RetornaTipo(Playlist *p);


/*Realiza a Leitura do arquivo, lendo os dados da playlist no arquivo
*inputs: Arquivo;
*outputs: Playlist;
*/
Playlist *LerPlaylistArquivo(FILE *arquivo);

/*Realiza a escrita do arquivo, escrevendo os dados  da playlist no arquivo
*inputs:Playlist e Arquivo;
*outputs: nenhum;
*/
void SalvaPlaylist(Playlist *p, FILE *arquivo);

/*Retorna a Quantidade de colaboradores;
*inputs:Playlist *p;
*outputs: int;
*/
int RetornaQtdColaborador(Playlist *p);

/*Retorna o nome do colaboradores;
*inputs:Playlist *p;
*outputs: char*;
*/
char* RetornaColaborador(Playlist *p);

/*Retorna o nome da Playlist;
*inputs:Playlist *p;
*outputs: char*;
*/
char* RetornaNomePlaylist(Playlist *p);

/*Troca a Posição dos colaboradores, "apagando-os";
*inputs:Playlist *p, posiçao atual e posterior;
*outputs: nenhum;
*/
void TrocaColaborador(Playlist *p, int posicao1, int posicao2);
#endif
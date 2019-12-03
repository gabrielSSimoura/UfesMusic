#ifndef ALBUM_H
#define ALBUM_H
#include "midia.h"
#include "album.h"

typedef struct album Album;

/*Aloca um Album vazio
*inputs: vazio;
*outputs: retorna um Album vazio, alocado
 */
Album* AlocaAlbum();

/*Cria um Album, com suas informaçoes;
*inputs: Um album previamente Alocado, dados do album (nome, genero, produtor...);
*Cria um album com seus dados ja atribuidos, porém o album está vazio;
*/
void CriaAlbum(Album *a,char* nomeAlb, char* nArtista,char* gen, char* produtor,int ano,int qtd);

/*Adiciona uma midia pre existente em um album;
*inputs: um album e uma midia;
* Atribui uma midia a uma posicao da quantidade de midias atuais no album;
*/
void AdicionaMidiaAlbum(Album* a,Midia* m);

/*Atribui um nome ao album;
*inputs: um album e uma string com o nome digitado;
*/
void AtribuiNomeAlbum(Album *a, char* nome);

/*Atribui um nome de Artista ao album;
*inputs: um album e uma string com o nome digitado;
*/
void AtribuiArtistaAlbum(Album *a, char* nomeArtista);

/*Atribui um Ano ao album;
*inputs: um album e um inteiro com o ano digitado;
*/
void AtribuiAnoAlbum(Album *a, int ano);

/*Atribui uma quantidade de midias ao album;
*inputs: um album e um inteiro com a quantidade digitada;
*/
void AtribuiqtdMidias(Album *a, int qtd);

/*Atribui um Genero ao album;
*inputs: um album e uma string com o nome digitado;
*/
void AtribuiGenero(Album *a, char* genero);

/*Atribui uma Produtora ao album;
*inputs: um album e uma string com o nome digitado;
*/
void AtribuiProdutoraAlbum(Album *a, char* produtora);

/*Imprime os dados basicos do album, sem imprimir suas midias;
*inputs: um album ;
*/
void ImprimeDadosBasicosAlbum(Album *a);

/*Imprime os dados completos do album, assim como imprime suas midias;
*inputs: um album;
*/
void ImprimeAlbum(Album *a);

/*Imprime o nome do album;
*inputs: um album ;
*/
void ImprimeNomeAlbum(Album *a);    

/*Imprime o nome do Artista do album;
*inputs: um album ;
*/
void ImprimeArtistaAlbum(Album *a);

/*Imprime o Genero do album;
*inputs: um album ;
*/
void ImprimeGeneroAlbum(Album *a);

/*Imprime o nome da Produtora do album;
*inputs: um album ;
*/
void ImprimeProdutoraAlbum(Album *a);

/*Imprime a quantidade de midias do album;
*inputs: um album ;
*/
void ImprimeqtdMidias(Album *a);

/*Imprime o ano do album;
*inputs: um album ;
*/
void ImprimeAnoAlbum(Album *a);

/*Pesquisa e Imprime os albuns que possuem um nome igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
*/
void PesquisaAlbum(Album *a, char *nome);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
*/
void PesquisaMidiaAlbum(Album *a, char* nomeM);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome de Artista igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
*/
void PesquisaArtistaMidiaAlbum(Album *a, char* nomeA);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome de Compositor igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
*/
void PesquisarNomeCompositorAlbum(Album *a, char* nomeC);

/*Pesquisa dentro do Album e Imprime as midias que possuem um Genero  gual ao gemero digitado pelo usuario;
*inputs: um album e um nome;
*/
void PesquisarGeneroAlbum(Album *a, char* nomeG);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome de Produtora igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
*/
void PesquisarProdutoraAlbum(Album *a, char* nomeP);

/*Retorna Midia de um Album;
*inputs: um album e a posição em que essa midia se encontra;
*/
Midia* RetornaMidiaAlbum(Album *a, int posicao);


#endif
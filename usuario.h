#ifndef USUARIO_H
#define USUARIO_H
#include "playlist.h"

typedef struct usuario Usuario;

/*Retorna uma struct usuario Alocada
*inputs: nenhum;
*outputs: Usuario *u;
*/
Usuario* AlocaUsuario();

/*Preenche os dados a um Usuario ja Alocado
*inputs: Usuario *u e os dados do mesmo;
*outputs: nenhum;
*/
void CriaUsuario(Usuario* u,char* login,char* senha,int id);

/*Apaga Playlist de um  Usuario ja Alocado
*inputs: Usuario *u e a posição da playlist;
*outputs: nenhum;
*/
void ApagaPlaylistUsuario(Usuario *u, int posicao);

/*Adiciona uma Playlist a um  Usuario ja Alocado
*inputs: Usuario *u e Playlist *p;
*outputs: nenhum;
*/
void AdicionaPlaylistUsuario(Usuario *u, Playlist *p);

/*Troca a posição da Playlist  de um  Usuario ja Alocado
*inputs: Usuario *u e posições selecionadas;
*outputs: nenhum;
*/
void TrocaPlaylist(Usuario *u, int posicao1, int posicao2);


void ImprimeUsuario(Usuario *u);            //| --> Imput: Usuario *u; Output: nennhum;
void ImprimeLogin(Usuario *u);              //| --> Imprime dados do usuario, login. usuario e senha;
void ImprimeSenha(Usuario *u);              //|

/*Imprime a senha de um usuario encriptada
*inputs: Usuario *u;
*outputs: nenhum;
*/
void ImprimeSenhaEncriptada(Usuario *u);

/*Retorna Login de um  Usuario ja Alocado
*inputs: Usuario *u ;
*outputs: char;
*/
char* RetornaLogin(Usuario *u);

/*Retorna Senha de um  Usuario ja Alocado
*inputs: Usuario *u ;
*outputs: char;
*/
char* RetornaSenha(Usuario *u);

/*Retorna Playlist de um  Usuario ja Alocado
*inputs: Usuario *u e a posição da playlits ;
*outputs:  Playlist * p;
*/
Playlist* RetornaPlaylistUsuario(Usuario *u, int idplay);


/*Adiciona uma Playlist favorita a um  Usuario ja Alocado
*inputs: Usuario *u e Playlist *p;
*outputs: nenhum;
*/
void AdicionaPlaylistFavoritaUsuario(Usuario *u,Playlist *p);

/*Recebe o Usuario por parametro e um inteiro do id do Usuarios, atribui esse id ao Usuario;
*Input: Usuario *u e inteiro;
*Output nenhum;
*/
void AtribuiIdUsuario(Usuario *u, int id);

/*Recebe o Usuario por parametro e retorna um inteiro de id do Usuarios;
*Input: Usuario *u ;
*Output inteiro;
*/
int RetornaIdUsuario(Usuario *u);

/*Recebe o Usuario por parametro, imprime as informaçoes basicas;
*Input: Usuario *u ;
*Output nenhum;
*/
void ImprimeUsuarioDadosBasicos(Usuario *u);

/*Recebe o Usuario por parametro e uma playlist seguindo;
*Input: Usuario *u e Playlist *p;
*Output nenhum;
*/
void AtribuiPlaylistSeguindo(Usuario *u, Playlist *p);

/*Recebe o Usuario por parametro e Imprime as playlist que sao publicas;
*Input: Usuario *u;
*Output nenhum;
*/
void ImprimeUsuarioPlayPublicoPrivado(Usuario *u);

/*Realiza a leitura do arquivo, lendo os dados do usuario no arquivo
*inputs:Usuario;
*outputs: Usuario;
*/
Usuario *LerUsuarioArquivo(FILE *arquivo);

/*Realiza a escrita do arquivo, escrevendo os dados do usuario no arquivo
*inputs:Usuario e Arquivo;
*outputs: nenhum;
*/
void SalvaUsuario(Usuario *u, FILE *arquivo);
#endif 

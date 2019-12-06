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

void AtribuiIdUsuario(Usuario *u, int id);
int RetornaIdUsuario(Usuario *u);
void ImprimeUsuarioDadosBasicos(Usuario *u);
void AtribuiPlaylistSeguindo(Usuario *u, Playlist *p);
void ImprimeUsuarioPlayPublicoPrivado(Usuario *u);
Usuario *LerUsuarioArquivo(FILE *arquivo);
#endif 

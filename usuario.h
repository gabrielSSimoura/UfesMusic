#ifndef USUARIO_H
#define USUARIO_H
#include "playlist.h"

typedef struct usuario Usuario;

Usuario* AlocaUsuario();
void CriaUsuario(Usuario* u,char* login,char* senha);
void ApagaPlaylistUsuario(Usuario *u, int posicao);
void AdicionaPlaylistUsuario(Usuario *u, Playlist *p);
void TrocaPlaylist(Usuario *u, int posicao1, int posicao2);
void ImprimeUsuario(Usuario *u);
void ImprimeLogin(Usuario *u);
void ImprimeSenha(Usuario *u);
void ImprimeSenhaEncriptada(Usuario *u);

char* RetornaLogin(Usuario *u);
char* RetornaSenha(Usuario *u);
Playlist* RetornaPlaylistUsuario(Usuario *u, int idplay);


#endif 

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "midia.h"
typedef struct playlist Playlist;

Playlist* AlocaPlaylist();
void CriaPlaylist(Playlist *p, char* nomep, char* colab1, char* colab2, int qtdColab, int qtdMidia);

void AdicionaMidiaPlaylist(Playlist *p, Midia *m);
int RetornaQtdMidias(Playlist *p);
void ApagaMidiaPlaylist(Playlist *p, int posicao);
void TrocaMidia(Playlist *p, int posicao1, int posicao2);

void ImprimePlaylist(Playlist *p);
void ImprimeNomePlaylist(Playlist *p);   
void ImprimeColaboradoresPlaylist(Playlist *p);
void ImprimeMidiasPlaylist(Playlist *p);
void AtribuiNomePlaylist(Playlist *p, char *nomep);


#endif
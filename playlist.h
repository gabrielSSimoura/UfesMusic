#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

Playlist* AlocaPlaylist();
void CriaPlaylist(Playlist *p, char* nomep, char* colab1, char* colab2, int qtdColab, int qtdMidia);
void ApagaPlaylist(Playlist *p);
void AdicionaMidiaPlaylist(Playlist *p, Midia *m);
void ImprimePlaylist(Playlist *p);
int RetornaQtdMidias(Playlist *p);


void ImprimeNomePlaylist(Playlist *p);   
void ImprimeColaboradoresPlaylist(Playlist *p);
void ImprimeMidiasPlaylist(Playlist *p);


#endif
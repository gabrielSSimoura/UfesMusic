#ifndef SISTEMA_H
#define SISTEMA_H
#include "album.h"
#include "midia.h"
#include "usuario.h"
typedef struct sistema Sistema;

Sistema* AlocaSistema();
int RetornaQtdAlbum(Sistema *s);
void AdicionaAlbumSistema(Sistema *s, Album *a);
void AdicionaUsuarioSistema(Sistema *s, Usuario *u);
void ImprimeAlbunsSistema(Sistema *s);
void ImprimeUsuarioSistema(Sistema *s);
int VerificaSenhaDev(Sistema *s,int senha);
Usuario* VerificaUsuarioSistema(Sistema *s,char *login, char *senha);
Album* RetornaAlbumEscolhido(Sistema *s, int identificador);
Midia* RetornaMidia(Sistema *s, int idAlbum, int idMidia);
void PequisarNomeAlbum(Sistema *s, char* nomeAlb);
void PesquisarNomeMidia(Sistema *s, char* nomeMid);
void PesquisarNomeArtista(Sistema *s, char* nomeArt);
void PesquisarNomeCompositor(Sistema *s, char* nomeC);
void PesquisarGenero(Sistema *s, char* nomeG);
void PesquisarProdutora(Sistema *s, char* nomeP);

#endif 
#ifndef SISTEMA_H
#define SISTEMA_H
#include "album.h"
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


#endif 
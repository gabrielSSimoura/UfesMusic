#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

struct sistema{
    Album *albuns[11];
    Usuario *usuarios[5];
    int qtdUsuario;
    int qtdAlbuns;
    int senhaDev;
};

Sistema* AlocaSistema(){
    Sistema* s=(Sistema*)malloc(sizeof(Sistema));
    for(int i=0;i<11;i++){
        s->albuns[i]=AlocaAlbum();
    }
    for(int i=0;i<5;i++){
        s->usuarios[i]=AlocaUsuario();
    }
    s->qtdAlbuns=0;
    s->qtdUsuario=0;
    s->senhaDev=130511;
}

int RetornaQtdAlbum(Sistema *s){
    return s->qtdAlbuns;
}
int RetornaQtdUsuario(Sistema *s){
    return s->qtdUsuario;
}
void AdicionaAlbumSistema(Sistema *s, Album *a){
    s->albuns[s->qtdAlbuns]=a;
    s->qtdAlbuns++;
}
void AdicionaUsuarioSistema(Sistema *s, Usuario *u){
    s->usuarios[s->qtdUsuario]=u;
    s->qtdUsuario++;
}

void ImprimeAlbunsSistema(Sistema *s){
    for(int i=0;i<s->qtdAlbuns;i++){
        printf("\t\tAlbum [%02d]: ",i);
        ImprimeDadosBasicosAlbum(s->albuns[i]);
    }
}
void ImprimeUsuarioSistema(Sistema *s){
    for(int i=0;i<s->qtdUsuario;i++){
        printf("\t\tUsuario [%02d]\n",i);
        ImprimeUsuario(s->usuarios[i]);
    }
}

Usuario* VerificaUsuarioSistema(Sistema *s,char *login, char *senha){
  
}

int VerificaSenhaDev(Sistema *s,int senha){
    if(s->senhaDev==senha){return 1;}
    return 0;
}

Album* RetornaAlbumEscolhido(Sistema *s, int identificador){
    return s->albuns[identificador];
}
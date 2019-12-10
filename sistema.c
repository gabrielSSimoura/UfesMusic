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
    Usuario *usuarios[11];
    int qtdUsuario;
    int qtdAlbuns;
    int senhaDev;
};

Sistema* AlocaSistema(){
    Sistema* s=(Sistema*)malloc(sizeof(Sistema));
    for(int i=0;i<11;i++){
        s->albuns[i]=AlocaAlbum();
    }
    for(int i=0;i<11;i++){
        s->usuarios[i]=AlocaUsuario();
    }
    s->qtdAlbuns=0;
    s->qtdUsuario=0;
    s->senhaDev=130511;
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
        printf("\n\t\tAlbum [%02d]: ",i);
        ImprimeDadosBasicosAlbum(s->albuns[i]);
    }
}
void ImprimeUsuarioSistema(Sistema *s,int id, int verifica){
   if(verifica==1)ImprimeUsuario(s->usuarios[id]);
   else if(verifica==0){
       ImprimeUsuarioPlayPublicoPrivado(s->usuarios[id]);
   }
}

int VerificaUsuarioSistema(Sistema *s,char *login, char *senha){
    char* log=(char*)malloc(50);
    char* snha=(char*)malloc(50);
  for(int i=0;i<=s->qtdUsuario;i++){
      log=RetornaLogin(s->usuarios[i]);      
      if(!(strcmp(login,log))){
          snha=RetornaSenha(s->usuarios[i]);          
          if(!(strcmp(senha,snha))){
              printf("\n\t\tLogin bem sucedido!");
              return i;
          }
      }
  }
  printf("\n\t\tUsuario nao encontrado");
  return -1;
}
Usuario* RetornaUsuarioSistema(Sistema *s, int posicao){    
    return s->usuarios[posicao];
}

int VerificaSenhaDev(Sistema *s,int senha){
    if(s->senhaDev==senha){return 1;}
    return 0;
}

Album* RetornaAlbumEscolhido(Sistema *s, int identificador){
    return s->albuns[identificador];
}

Midia* RetornaMidia(Sistema *s, int idAlbum, int idMidia){
    return RetornaMidiaAlbum(s->albuns[idAlbum], idMidia);
}

void PequisarNomeAlbum(Sistema *s, char* nomeAlb){
    for(int i=0;i<s->qtdAlbuns;i++){
        PesquisaAlbum(s->albuns[i], nomeAlb);
    }
}
void PesquisarNomeMidia(Sistema *s, char* nomeMid){
    for(int j=0;j<s->qtdAlbuns;j++){
        PesquisaMidiaAlbum(s->albuns[j],nomeMid);
    }
}
void PesquisarNomeArtista(Sistema *s, char* nomeArt){
    for(int j=0;j<s->qtdAlbuns;j++){
        PesquisaArtistaMidiaAlbum(s->albuns[j],nomeArt);
    }
}

void PesquisarNomeCompositor(Sistema *s, char* nomeC){
    for(int j=0;j<s->qtdAlbuns;j++){
        PesquisarNomeCompositorAlbum(s->albuns[j],nomeC);
    }

}
void PesquisarGenero(Sistema *s, char* nomeG){
    for(int j=0;j<s->qtdAlbuns;j++){
        PesquisarGeneroAlbum(s->albuns[j],nomeG);
    }
}
void PesquisarProdutora(Sistema *s, char* nomeP){
    for(int j=0;j<s->qtdAlbuns;j++){
        PesquisarProdutoraAlbum(s->albuns[j],nomeP);
    }
}

void AtribuiQtdAlbunsSistema(Sistema *s,int qtd){
    s->qtdAlbuns=qtd;
}

int RetornaQtdAlbumSistema(Sistema *s){
    return s->qtdAlbuns;
}

void AtribuiQtdUsuariosSistema(Sistema *s, int qtdU){
    s->qtdUsuario=qtdU;
}
int RetornaQtdUsuariosSistema(Sistema *s){
    return s->qtdUsuario;
}
void OpcaoPesquisarUsuario(Sistema *s, int idusuario_atual){
    
    for(int i=0,j=0;i<s->qtdUsuario;i++,j++){
        if(i==idusuario_atual){continue;}
        printf("\n\t\tUsuario [%02d]: ",j);
        ImprimeUsuarioDadosBasicos(s->usuarios[i]);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

struct usuario{   
    char *login;
    char *senha;
    int qtdplay;    
    Playlist *play[51];
    Playlist *favoritos;
    int favorito;
    int qtdTotalPlaylist;
    
};

Usuario* AlocaUsuario(){
    Usuario* u=(Usuario*)malloc(sizeof(Usuario));
    u->login=(char*)malloc(50);
    u->senha=(char*)malloc(50);
    u->qtdTotalPlaylist=50;
    u->favoritos=AlocaPlaylist();
    for(int i=0;i<51;i++){
        u->play[i]=AlocaPlaylist();
    }    
    return u;
}
void AdicionaPlaylistUsuario(Usuario *u, Playlist *p){
    if(u->qtdplay<u->qtdTotalPlaylist){
        u->play[u->qtdplay]=p;
        u->qtdplay++;
    }
    else printf("\n\t\tPlaylist cheia!");
}

void AdicionaPlaylistFavoritaUsuario(Usuario *u,Playlist *p){
    if(u->favorito==0){
       u->favoritos=p;
        u->favorito=1;
    }
    else if(u->favorito==1){
    printf("\n\t\tPlaylist Favorita ja Criada!");

    }
}

void CriaUsuario(Usuario* u,char* login,char* senha){  
    strcpy(u->login,login);
    strcpy(u->senha,senha);
    u->qtdplay=0;   
    u->favorito=0;  
    u->qtdTotalPlaylist=50;
      
}

void ApagaPlaylistUsuario(Usuario *u, int posicao){
    for(int i=posicao;i<u->qtdplay;i++){
        TrocaPlaylist(u,i,(i+1));
    }
    u->qtdplay--;
}

void TrocaPlaylist(Usuario *u, int posicao1, int posicao2){
    Playlist *auxiliar=AlocaPlaylist();
    auxiliar=u->play[posicao1];
    u->play[posicao1]=u->play[posicao2];
    u->play[posicao2]=auxiliar;
}

void ImprimeUsuario(Usuario *u){
    ImprimeLogin(u);
    ImprimeSenhaEncriptada(u);
    for(int i=0;i<u->qtdplay;i++){
        printf("\n\t\t[%02d] ",i);
        ImprimePlaylist(u->play[i]);
    }
    printf("\n\t\tFavorita: ");
    ImprimePlaylist(u->favoritos);
}
void ImprimeLogin(Usuario *u){
    printf("\t\tLogin: %s\n",u->login);
}
void ImprimeSenha(Usuario *u){
    printf("\t\t%s\n",u->senha);
}
void ImprimeSenhaEncriptada(Usuario *u){
    int snha;
    snha=strlen(u->senha);
    printf("\t\tSenha: ");
    for(int i=0;i<snha;i++){
        printf("*");
    }
}

char* RetornaLogin(Usuario *u){
    return u->login;
}

char* RetornaSenha(Usuario *u){
    return u->senha;
}

Playlist* RetornaPlaylistUsuario(Usuario *u, int idplay){
    return u->play[idplay];
}
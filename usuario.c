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
    int idusuario; 
    char *login;
    char *senha;
    int qtdplay;    
    Playlist *play[51];
    Playlist *favoritos;
    Playlist *seguindo[5];
    int favorito;
    int qtdTotalPlaylist;
    int qtdPseguindo;
    
};

Usuario* AlocaUsuario(){
    Usuario* u=(Usuario*)malloc(sizeof(Usuario));
    u->login=(char*)malloc(50);
    u->senha=(char*)malloc(50);
    u->qtdTotalPlaylist=50;
    u->qtdPseguindo=0;
    u->favoritos=AlocaPlaylist();
    for(int i=0;i<51;i++){
        u->play[i]=AlocaPlaylist();
    }   
    for(int i=0;i<5;i++){
        u->seguindo[i]=AlocaPlaylist();
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

void CriaUsuario(Usuario* u,char* login,char* senha,int id){  
    strcpy(u->login,login);
    strcpy(u->senha,senha);
    u->qtdplay=0;   
    u->favorito=0;  
    u->qtdTotalPlaylist=50;
    u->idusuario=id; 
       
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
    if(u->favorito==1){
        printf("\n\t\tFavorita: ");
        ImprimePlaylist(u->favoritos);
    }
    if(u->qtdPseguindo>0){
        for(int i=0;i<u->qtdPseguindo;i++){
        printf("\n\t\tSeguiundo [%02d] ",i);
        ImprimePlaylist(u->seguindo[i]);
    }

    }
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
void AtribuiIdUsuario(Usuario *u, int id){
    u->idusuario=id;
}
int RetornaIdUsuario(Usuario *u){    
    return u->idusuario;
}
void ImprimeUsuarioDadosBasicos(Usuario *u){
    printf("\n");
    ImprimeLogin(u);
    ImprimeSenhaEncriptada(u);
    printf("\n");
}
void AtribuiPlaylistSeguindo(Usuario *u, Playlist *p){
    if(u->qtdPseguindo<=5){
        u->seguindo[u->qtdPseguindo]=p;
        u->qtdPseguindo++;
        printf("\n\t\t Essa playlist esta sendo seguida! :)");
    }
    else printf("\n\t\tMaximo de playlist seguindo atingido!");
}
void ImprimeUsuarioPlayPublicoPrivado(Usuario *u){
    int tipo=0;
    ImprimeUsuarioDadosBasicos(u);

    for(int i=0,j=0;i<u->qtdplay;i++,j++){
        tipo=RetornaTipo(u->play[i]);
        if(tipo==1){continue;}
        else { 
            printf("\n\t\t Playlist [%02d]: ",j);
            ImprimePlaylist(u->play[i]);
        }
    }    
}
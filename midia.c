#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"

struct midia{
    int  tipo;                      //1.musica,2.video,3.podcast;    
    char *nomeMidia; 
    char *nomeArtista;
    char *nomeCompositor;   
    char *genero;
    char *produzidoPor;
    float duracao;
};

void ImprimeMidia(Midia *m){
    ImprimeTipo(m);
    ImprimeNomeMidia(m);
    ImprimeNomeArtista(m);
    ImprimeNomeCompositor(m);
    ImprimeProdutora(m);
    ImprimeGenero(m);
    ImprimeDuracao(m);
}
  
void CriaMidia(Midia* m, char* nome, char* nomeArtista, char* nomeCompositor,char* genero, char* produtora,  int tipo, float duracao){
    m->nomeMidia=nome;
    m->nomeArtista=nomeArtista;
    m->nomeCompositor=nomeCompositor;
    m->genero=genero;
    m->produzidoPor=produtora;
    m->tipo=tipo;
    m->duracao=duracao;
}

void DeletaMidiaPrograma(Midia *m){
    if(m){
        if(m->nomeMidia)free(m->nomeMidia);
        if(m->nomeArtista)free(m->nomeArtista);
        if(m->genero)free(m->genero);
        if(m->produzidoPor)free(m->produzidoPor);
        if(m->nomeCompositor)free(m->nomeCompositor);
        printf("\t\tMusica Apagada com sucesso");
        free(m);
    }    
}

Midia* AlocaMidia(){
    Midia* m=(Midia*)malloc(sizeof(Midia));
    m->nomeMidia=(char*)malloc(50);
    m->nomeArtista= (char*)malloc(50);
    m->genero= (char*)malloc(50);        
    m->produzidoPor =(char*)malloc(50);   
    m->nomeCompositor= (char*)malloc(50); 
    return m;    
}

void AtribuiNomeMidia(Midia *m, char* nome){m->nomeMidia=nome;}
void AtribuiNomeArtista(Midia *m, char* nomeArtista){m->nomeArtista=nomeArtista;}
void AtribuiNomeCompositor(Midia *m, char* nomeCompositor){m->nomeCompositor=nomeCompositor;}
void AtribuiNomeGenero(Midia *m, char* genero){m->genero=genero;}
void AtribuiTipo(Midia *m, int tipo){m->tipo=tipo;}
void AtribuiDuracao(Midia *m, float duracao){m->duracao=duracao;}
void AtribuiNomeProdutora(Midia *m, char* produtora){m->produzidoPor=produtora;}

void ImprimeNomeMidia(Midia *m){printf("\t\t%s\n",m->nomeMidia);}    
void ImprimeNomeArtista(Midia *m){printf("\t\t%s\n",m->nomeArtista);}
void ImprimeNomeCompositor(Midia *m){printf("\t\t%s\n",m->nomeCompositor);}   
void ImprimeGenero(Midia *m){printf("\t\t%s\n",m->genero);}
void ImprimeDuracao(Midia *m){printf("\t\t%.2f\n",m->duracao);}
void ImprimeTipo(Midia *m){printf(" %d\n",m->tipo);}
void ImprimeProdutora(Midia *m){printf("\t\t%s\n",m->produzidoPor);}

    

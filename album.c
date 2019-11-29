#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"


struct album{
    char *nomeAlbum;
    char *nomeArtista;       
    char *genero;
    char *produzidoPor;        
    Midia *midia[21];
    int qtdMidias;
    int ano;
};

void CriaAlbum(Album *a,char* nomeAlb, char* nArtista,char* gen, char* produtor,int ano,int qtd){
    strcpy(a->nomeAlbum,nomeAlb);
    strcpy(a->nomeArtista,nArtista);
    strcpy(a->genero,gen);
    strcpy(a->produzidoPor,produtor);
    a->ano=ano;
    a->qtdMidias=qtd;
}

Album* AlocaAlbum(){
    Album* a=(Album*)malloc(sizeof(Album));
    a->nomeAlbum=(char*)malloc(50);
    a->nomeArtista= (char*)malloc(50);
    a->genero= (char*)malloc(50);        
    a->produzidoPor =(char*)malloc(50);

    for(int i=0;i<21;i++){
        a->midia[i]=AlocaMidia();
    }
    return a;
}
void ImprimeAlbum(Album *a){
    ImprimeNomeAlbum(a);
    ImprimeArtistaAlbum(a);
    ImprimeGeneroAlbum(a);
    ImprimeProdutoraAlbum(a);
    ImprimeqtdMidias(a);
    ImprimeAnoAlbum(a);
    for(int i=0;i<a->qtdMidias;i++){
        printf("\n\t\t[%02d]",i);
        ImprimeMidia(a->midia[i]);
    }   
}

void AdicionaMidiaAlbum(Album* a,Midia* m, int posicao){
    a->midia[posicao]=m;
}


void AtribuiNomeAlbum(Album *a, char* nome){a->nomeAlbum=nome;}
void AtribuiArtistaAlbum(Album *a, char* nomeArtista){a->nomeArtista=nomeArtista;}
void AtribuiGenero(Album *a, char* genero){a->genero=genero;}
void AtribuiProdutoraAlbum(Album *a, char* produtora){a->produzidoPor=produtora;}
void AtribuiAnoAlbum(Album *a, int ano){a->ano=ano;}
void AtribuiqtdMidias(Album *a, int qtd){a->qtdMidias=qtd;}

void ImprimeNomeAlbum(Album *a){printf("\t\t%s\n",a->nomeAlbum);}    
void ImprimeArtistaAlbum(Album *a){printf("\t\t%s\n",a->nomeArtista);}  
void ImprimeGeneroAlbum(Album *a){printf("\t\t%s\n",a->genero);}  
void ImprimeProdutoraAlbum(Album *a){printf("\t\t%s\n",a->produzidoPor);}  
void ImprimeqtdMidias(Album *a){printf("\t\t%d\n",a->qtdMidias);}  
void ImprimeAnoAlbum(Album *a){printf("\t\t%d\n",a->ano);}  

Midia* RetornaMidiaAlbum(Album *a, int posicao){
    return a->midia[posicao];
}
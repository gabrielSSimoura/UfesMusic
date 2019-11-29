#ifndef ALBUM_H
#define ALBUM_H

typedef struct album Album;

Album* AlocaAlbum();
void CriaAlbum(Album *a,char* nomeAlb, char* nArtista,char* gen, char* produtor,int ano,int qtd);
void AdicionaMidiaAlbum(Album* a,Midia* m, int posicao);

void AtribuiNomeAlbum(Album *a, char* nome);
void AtribuiArtistaAlbum(Album *a, char* nomeArtista);
void AtribuiAnoAlbum(Album *a, int ano);
void AtribuiqtdMidias(Album *a, int qtd);
void AtribuiGenero(Album *a, char* genero);
void AtribuiProdutoraAlbum(Album *a, char* produtora);

void ImprimeAlbum(Album *a);
void ImprimeNomeAlbum(Album *a);    
void ImprimeArtistaAlbum(Album *a);
void ImprimeGeneroAlbum(Album *a);
void ImprimeProdutoraAlbum(Album *a);
void ImprimeqtdMidias(Album *a);
void ImprimeAnoAlbum(Album *a);

Midia* RetornaMidiaAlbum(Album *a, int posicao);


#endif
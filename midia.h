#ifndef MIDIA_
#define MIDIA_

typedef struct midia Midia;

Midia* AlocaMidia();
void ImprimeMidia(Midia* m);
void CriaMidia(Midia* m, char* nome, char* nomeArtista, char* nomeCompositor,char* genero, char* produtora,  int tipo, float duracao);


void AtribuiNomeMidia(Midia *m, char* nome);
void AtribuiNomeArtista(Midia *m, char* nomeArtista);
void AtribuiNomeCompositor(Midia *m, char* nomeCompositor);
void AtribuiNomeGenero(Midia *m, char* genero);
void AtribuiTipo(Midia *m, int tipo);
void AtribuiDuracao(Midia *m, float duracao);
void AtribuiNomeProdutora(Midia *m, char* produtora);

void ImprimeNomeMidia(Midia *m);    
void ImprimeNomeArtista(Midia *m);
void ImprimeNomeCompositor(Midia *m);
void ImprimeGenero(Midia *m);
void ImprimeDuracao(Midia *m);
void ImprimeTipo(Midia *m);
void ImprimeProdutora(Midia *m);

void DeletaMidiaPrograma(Midia *m);


#endif
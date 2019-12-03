#ifndef MIDIA_
#define MIDIA_

typedef struct midia Midia;

Midia* AlocaMidia();
void ImprimeMidia(Midia* m);
void CriaMidia(Midia* m, char* nome, char* nomeArtista,char* nomeArtista2, char* nomeCompositor,char* nomeCompositor2,char* genero, char* produtora,  int tipo, float duracao, int qtdA, int qtdC);


void AtribuiNomeMidia(Midia *m, char* nome);
void AtribuiNomeArtista1(Midia *m, char* nomeArtista);
void AtribuiNomeCompositor1(Midia *m, char* nomeCompositor);
void AtribuiNomeArtista2(Midia *m, char* nomeArtista);
void AtribuiNomeCompositor2(Midia *m, char* nomeCompositor);
void AtribuiNomeGenero(Midia *m, char* genero);
void AtribuiTipo(Midia *m, int tipo);
void AtribuiDuracao(Midia *m, float duracao);
void AtribuiNomeProdutora(Midia *m, char* produtora);

void ImprimeNomeMidia(Midia *m);    
void ImprimeNomeArtista1(Midia *m);
void ImprimeNomeCompositor1(Midia *m);
void ImprimeNomeArtista2(Midia *m);
void ImprimeNomeCompositor2(Midia *m);
void ImprimeGenero(Midia *m);
void ImprimeDuracao(Midia *m);
void ImprimeTipo(Midia *m);
void ImprimeProdutora(Midia *m);

void DeletaMidiaPrograma(Midia *m);
void PesquisaMidia(Midia *m, char* nome);
void PesquisaArtistaMidia(Midia *m, char* nomeA);
void PesquisarNomeCompositorMidia(Midia *m, char* nomeC);
void PesquisarGeneroMidia(Midia *m, char* nomeG);
void PesquisarProdutoraMidia(Midia *m, char* nomeP);

int RetornaQtdArtista(Midia *m);
int RetornaQtdCompositor(Midia *m);
#endif
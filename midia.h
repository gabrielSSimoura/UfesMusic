#ifndef MIDIA_
#define MIDIA_

typedef struct midia Midia;

/*Aloca uma Midia vazia
*inputs: vazio;
*outputs: retorna uma Midia vazia, alocada
 */
Midia* AlocaMidia();

/*Imprime dados da Midia
*inputs: Midia *a;
*outputs: Uma midia alocada;
*/
void ImprimeMidia(Midia* m);

/*Cria uma midia com os dados obtidos previamente
*inputs: Midia *a, caracteres com nomes e inteiros e floats com tipo e duração, respectivamente;
*outputs: nenhum
*/
void CriaMidia(Midia* m, char* nome, char* nomeArtista,char* nomeArtista2, char* nomeCompositor,char* nomeCompositor2,char* genero, char* produtora,  int tipo, float duracao, int qtdA, int qtdC);

/*Altera Nome midia
*inputs: Midia *a e caracter;
*outputs: nenhum;
*/
void AtribuiNomeMidia(Midia *m, char* nome);

/*Altera Nome artista da midia
*inputs: Midia *a e caracter;
*outputs: nenhum;
*/
void AtribuiNomeArtista1(Midia *m, char* nomeArtista);

/*Altera Nome artista 2 midia
*inputs: Midia *a e caracter;
*outputs: nenhum;
*/
void AtribuiNomeArtista2(Midia *m, char* nomeArtista);

/*Altera Nome Compositor midia
*inputs: Midia *a e caracter;
*outputs: nenhum;
*/
void AtribuiNomeCompositor1(Midia *m, char* nomeCompositor);

/*Altera Nome Compositor 2 midia
*inputs: Midia *a e caracter;
*outputs: nenhum;
*/
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


void PesquisaMidia(Midia *m, char* nome);
void PesquisaArtistaMidia(Midia *m, char* nomeA);
void PesquisarNomeCompositorMidia(Midia *m, char* nomeC);
void PesquisarGeneroMidia(Midia *m, char* nomeG);
void PesquisarProdutoraMidia(Midia *m, char* nomeP);

void DeletaMidiaPrograma(Midia *m);
int RetornaQtdArtista(Midia *m);
int RetornaQtdCompositor(Midia *m);
#endif
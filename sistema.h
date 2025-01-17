#ifndef SISTEMA_H
#define SISTEMA_H
#include "album.h"
#include "midia.h"
#include "usuario.h"
typedef struct sistema Sistema;

/* Aloca a struct sistema;
* Realiza o malloc de todos os ponteiros existents na struct sistema
*output: Uma Struct Sistema Alocada;
*/
Sistema* AlocaSistema();


/*Recebe o Sistema por parametro e adiciona um album ao sistema;
*Input: Sistema *s e Album *a;
*Output: nenhum;
*/
void AdicionaAlbumSistema(Sistema *s, Album *a);

/*Recebe o Sistema por parametro e adiciona um Usuario ao sistema;
*Input: Sistema *s e Usuario *u;
*Output: nenhum;
*/
void AdicionaUsuarioSistema(Sistema *s, Usuario *u);

/*Recebe o Sistema por parametro e Imprime os albuns existentes no sistema;
*Input: Sistema *s;
*Output: nenhum;
*/
void ImprimeAlbunsSistema(Sistema *s);

/*Recebe o Sistema por parametro e Imprime o usuario atual do sistema;
*Input: Sistema *s;
*Output: nenhum;
*/
void ImprimeUsuarioSistema(Sistema *s,int id, int verifica);

/*Recebe o Sistema por parametro e uma senha;
*Input: Sistema *s e um inteiro;
*Output: Verdadeiro(Senha Correta) ou Falso(Senha Incorreta);
*/
int VerificaSenhaDev(Sistema *s,int senha);

/*Recebe o Sistema por parametro e os caracteres de login e senha do usuario;
*Input: Sistema *s e caracteres;
*Output: posição usuario;
*/
int VerificaUsuarioSistema(Sistema *s,char *login, char *senha);

/*Recebe o Sistema por parametro e um idenificador da posição do Album escolhido;
*Input: Sistema *s e inteiro;
*Output: um Album;
*/
Album* RetornaAlbumEscolhido(Sistema *s, int identificador);

/*Recebe o Sistema por parametro e um identificador da posição da Midia escolhida;
*Input: Sistema *s e inteiro;
*Output: Midia;
*/
Midia* RetornaMidia(Sistema *s, int idAlbum, int idMidia);

/*Recebe o Sistema por parametro, um caracter com o nome do album;
*Input: Sistema *s e caracter;
*Output: nenhum;
*/
void PequisarNomeAlbum(Sistema *s, char* nomeAlb);

/*Recebe o Sistema por parametro,um caracter com o nome da Midia e Imprime a Midia com o nome digitado;
*Input: Sistema *s e caracter;
*Output: nenhum;
*/
void PesquisarNomeMidia(Sistema *s, char* nomeMid);

/*Recebe o Sistema por parametro,um caracter com o nome do Artista e Imprime a Midia com o nome do artista digitado;
*Input: Sistema *s e caracter;
*Output: nenhum;
*/
void PesquisarNomeArtista(Sistema *s, char* nomeArt);
/*Recebe o Sistema por parametro,um caracter com o nome do Compositor e Imprime a Midia com o nome do compositor digitado;
*Input: Sistema *s e caracter;
*Output: nenhum;
*/
void PesquisarNomeCompositor(Sistema *s, char* nomeC);

/*Recebe o Sistema por parametro,um caracter com o nome do Compositor e Imprime a Midia com o nome do Genero digitado;
*Input: Sistema *s e caracter;
*Output: nenhum;
*/
void PesquisarGenero(Sistema *s, char* nomeG);

/*Recebe o Sistema por parametro,um caracter com o nome do Compositor e Imprime a Midia com o nome da Produtora digitado;
*Input: Sistema *s e caracter;
*Output: nenhum;
*/
void PesquisarProdutora(Sistema *s, char* nomeP);

/*Recebe o Sistema por parametro e um identificador da posição do Usuario escolhida;
*Input: Sistema *s e inteiro;
*Output Usuario;
*/
Usuario* RetornaUsuarioSistema(Sistema *s, int posicao);

/*Recebe o Sistema por parametro e um inteiro da qtd de albuns;
*Input: Sistema *s e inteiro;
*Output nenhum;
*/
void AtribuiQtdAlbunsSistema(Sistema *s,int qtd);

/*Recebe o Sistema por parametro;
*Input: Sistema *s;
*Output inteiro;
*/
int RetornaQtdAlbumSistema(Sistema *s);

/*Recebe o Sistema por parametro e um inteiro da qtd de Usuarios;
*Input: Sistema *s e inteiro;
*Output nenhum;
*/
void AtribuiQtdUsuariosSistema(Sistema *s, int qtdU);

/*Recebe o Sistema por parametro;
*Input: Sistema *s;
*Output inteiro;
*/
int RetornaQtdUsuariosSistema(Sistema *s);

/*Recebe o Sistema por parametro e um inteiro da identificaçao do Usuario atual;
*Input: Sistema *s e inteiro;
*Output imprime todos os usuarios existentes exceto o que esta pesquisando;
*/
void OpcaoPesquisarUsuario(Sistema *s, int idusuario_atual);

/*Identifica se o colaborador possui a mesma playlist que 
    esta sendo apagada pelo Usuario atual e a apaga;
*inputs:Sistema *s, char com o login do Usuario e char com o nome da playlist;
*outputs: nenhum;
*/
void ApagaPlayColaborador(Sistema *s, char *login, char *nomeplay);

/*Identifica se outro Usuario segue a mesma playlist que 
    esta sendo apagada pelo Usuario atual e a apaga;
*inputs:Sistema *s e char com o nome da playlist;
*outputs: nenhum;
*/
void ApagaPlaySeguindoUsuariosSistema(Sistema *s,char *nomeplay);

#endif 
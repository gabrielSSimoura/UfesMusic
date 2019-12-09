#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "sistema.h"

/*Realiza a Leitura do arquivo, lendo os dados de tudo do programa;
*inputs: nenhum;
*outputs: Sistema;
*/
Sistema* LerPrograma();


/*Realiza a Escrita do arquivo, escrevendo os dados de tudo do programa;
*inputs: Sistema;
*outputs: nenhum;
*/
void SalvaPrograma(Sistema *s);


/*Realiza a Leitura dos dados das Midias;
*inputs: Midia *m;
*outputs: nenhum;
*/
void DadosMidia(Midia *m);

/*Realiza a Leitura dos dados dos Albuns;
*inputs: Album;
*outputs: nenhum;
*/
void DadosAlbum(Album *alb);

/*Realiza a Leitura dos dados da Playlist;
*inputs: Playlist;
*outputs: nenhum;
*/
void DadosPlaylist(Playlist *play,Sistema *s,int id);

/*Realiza a Leitura dos dados do Usuario;
*inputs: Usuario;
*outputs: nenhum;
*/
void DadosUsuario(Usuario * usu, Sistema *s);

/*Cria uma Playlist para o usuario;
*inputs: Sistema, Usuario e um inteiro para saber se é uma playlist favorita ou nao;
*outputs: nenhum;
*/
void OpcaoCriarPlaylist(Sistema *s,Usuario *usu, int opcao);

/*Edita uma Playlist para o usuario;
*inputs: Sistema e Usuario;
*outputs: nenhum;
*/
void EditaPlaylist(Sistema *s,Usuario *usu);

/*Pesquisa Informaçoes no Sistema;
*inputs: Sistema;
*outputs: nenhum;
*/
void OpcaoPesquisar(Sistema *s);

/*Opçao de Desenvolvedor;
*inputs: Sistema;
*outputs: nenhum;
*/
void OpcaoDev(Sistema *s);

/*Pesquisa Usuarios no Sistema;
*inputs: Sistema e Usuario atual;
*outputs: nenhum;
*/
void PequisaUsuario(Sistema *s, Usuario *u);

/*Edita informaçoes da Midia;
*inputs: Midia e a opçao escolhida;
*outputs: nenhum;
*/
void AlteraMidia(Midia *m,int escolha);

/*Edita informaçoes do Album;
*inputs: Album e a opçao escolhida;
*outputs: nenhum;
*/
void AlteraAlbum(Album *a,int escolha);

/*Edita informaçoes da Playlist;
*inputs: Playlist e a opçao escolhida;
*outputs: nenhum;
*/
void AlteraPlaylist(Playlist *p, int escolha);

/*Adiciona  um Album ao Sitema;
*inputs: Sistema;
*outputs: nenhum;
*/
void PreencheSistemaComAlbum(Sistema *s);

/*Adiciona Usuario ao Sitema;
*inputs: Sistema, Usuario;
*outputs: nenhum;
*/
void PreencheSistemaComUsuario(Sistema *s,Usuario *usu);

/*Adiciona informaçoes ao Album;
*inputs: Album e a qtd de Midias;
*outputs: nenhum;
*/
void PreencheAlbum(Album *a, int qtd);

/*Adiciona informaçoes a Playlist;
*inputs: Album e Playlist;
*outputs: nenhum;
*/
void PreenchePlaylst(Playlist* p,Album *a);

/*Le caracteres do terminal;
*inputs: nenhum;
*outputs: ponteiro de Char;
*/
char* LeDados();

/*Le inteiros do terminal;
*inputs: nenhum;
*outputs: inteiro;
*/
int LerInteiros();

/*Le floats do terminal;
*inputs: nenhum;
*outputs: float;
*/
float LerFloat();

Sistema* LerPrograma(){
   Sistema *s=AlocaSistema();
   Album *a;
   Usuario *u;
   int qtdAlb=0, qtdUsu=0;
  
   FILE *arquivo;
   arquivo=fopen("programa.txt", "r");
    if(!arquivo){
        printf("falha na abertura");
        exit (1);
    }    
    fscanf(arquivo, "%d", &qtdAlb);
    fscanf(arquivo, "\n");    
    fscanf(arquivo, "%d", &qtdUsu);     
    fscanf(arquivo, "\n");   
    
    for(int i= 0;i<qtdAlb; i++){        
        a=AlocaAlbum();
        a=LerAlbunsArquivo(arquivo);             
        AdicionaAlbumSistema(s,a);
    }
    for(int i=0;i<qtdUsu;i++){
        u=AlocaUsuario();
        u=LerUsuarioArquivo(arquivo);        
        AdicionaUsuarioSistema(s,u);
    }  
    fclose(arquivo);
    return s;
}
void SalvaPrograma(Sistema *s){
    int qtdAlb, qtdUsu;
    FILE *arquivo;
    Album *a;
    Usuario *u;
   arquivo=fopen("programa.txt", "w");
    if(!arquivo){
        printf("falha na abertura");
        exit (1);
    }
    qtdAlb=RetornaQtdAlbumSistema(s);
    qtdUsu=RetornaQtdUsuariosSistema(s);
    fprintf(arquivo, "%d", qtdAlb);
    fprintf(arquivo, "\n");    
    fprintf(arquivo, "%d", qtdUsu);     
    fprintf(arquivo, "\n");

    for(int i= 0;i<qtdAlb; i++){
        a=AlocaAlbum();
        a=RetornaAlbumEscolhido(s,i);
        SalvaAlbum(a,arquivo); 
    }
    for(int i=0;i<qtdUsu;i++){
        u=AlocaUsuario();
        u=RetornaUsuarioSistema(s,i);      
        SalvaUsuario(u,arquivo);
    }  
    fclose(arquivo);
}
char* LeDados(){
    char *dados=(char*)malloc(50);      
    setbuf(stdin, NULL); 
    scanf("%[^\n]s",dados);
    setbuf(stdin, NULL);    
    return dados;
}
int LerInteiros(){
    int num;
    setbuf(stdin, NULL); 
    scanf("%d",&num);
    setbuf(stdin, NULL); 
    return num;
}
float LerFloat(){
    float fnum;    
    setbuf(stdin, NULL); 
    scanf("%f",&fnum);
    setbuf(stdin, NULL);  
    return fnum;
}
void PreencheAlbum(Album *alb, int qtd){
    Midia* m;
    for(int i=0;i<qtd;i++){
        m=AlocaMidia();
        DadosMidia(m);        
        AdicionaMidiaAlbum(alb,m);
    }
}
 void DadosUsuario(Usuario *usu, Sistema *s){    
    char* lgin=(char*)malloc(50);
    char* snha=(char*)malloc(50);
    int id=0;
    printf("\n\t\tLogin : ");
    lgin=LeDados();
    printf("\t\tSenha: ");
    snha=LeDados();
    id=RetornaQtdUsuariosSistema(s);    
    CriaUsuario(usu,lgin,snha,id);    
}
void DadosAlbum(Album *alb){    
    char* nomeAlb=(char*)malloc(50);
    char* nArtista=(char*)malloc(50);    
    char* gen=(char*)malloc(50);
    char* produtor=(char*)malloc(50);
    int ano,qtd; 

    printf("\n\t\tAno de Lancamento do Album: ");
    ano=LerInteiros();
    printf("\t\tQuantidade de midias: ");
    qtd=LerInteiros();
    printf("\t\tNome do Album: ");
    nomeAlb=LeDados();
    printf("\t\tNome do artista: ");
    nArtista=LeDados();
    printf("\t\tNome produtora: ");
    produtor=LeDados();
    printf("\t\tGenero: ");
    gen=LeDados();
    CriaAlbum(alb,nomeAlb,nArtista,gen,produtor,ano,qtd); 
    PreencheAlbum(alb,qtd);
}
void DadosMidia(Midia *m){
    
    char* nome=(char*)malloc(50);
    char* nomeArtista=(char*)malloc(50);
    char* nomeArtista2=(char*)malloc(50);
    char* nomeCompositor=(char*)malloc(50);
    char* nomeCompositor2=(char*)malloc(50);
    char* genero=(char*)malloc(50);
    char* produtora=(char*)malloc(50);
    int tipo,qtdA, qtdC;
    float duracao;

    printf("\n\t\tTipo da midia [01]Musica, [02]Video, [03]Podcast: ");
    tipo=LerInteiros();
    printf("\t\tNome da midia: ");
    nome=LeDados();
    printf("\t\tQuantidade de artistas (MAX 2): ");
    qtdA=LerInteiros();
    if(qtdA==1){
        printf("\t\tArtista [00]: ");
        nomeArtista=LeDados();
    }
    else if(qtdA==2){
         printf("\t\tArtista [00]: ");
        nomeArtista=LeDados();
         printf("\t\tArtista [01]: ");
        nomeArtista2=LeDados();
    }
    printf("\t\tQuantidade de Compositores (MAX 2): ");
    qtdC=LerInteiros();
    if(qtdC==1){
        printf("\t\tCompositor [00]: ");
        nomeCompositor=LeDados();
    }
    else if(qtdC==2){
         printf("\t\tCompositor [00]: ");
        nomeCompositor=LeDados();
         printf("\t\tCompositor [01]: ");
        nomeCompositor2=LeDados();
    }    
    printf("\t\tNome produtora: ");
    produtora=LeDados();
    printf("\t\tGenero: ");
    genero=LeDados();
    printf("\t\tDuracao: ");
    duracao=LerFloat();
    CriaMidia(m, nome, nomeArtista, nomeArtista2, nomeCompositor, nomeCompositor2,genero, produtora, tipo,duracao, qtdA,qtdC);
}
void DadosPlaylist(Playlist *play,Sistema *s,int id){
    Usuario *u=AlocaUsuario();
    Usuario *u2=AlocaUsuario();
    char *nomep=(char*)malloc(50);
    char *nomeColab1=(char*)malloc(50);
    char *nomeColab2=(char*)malloc(50);
    int qtdColab=0, qtdMidia=0, tipo=0, colab1=0, colab2=0;

    printf("\n\t\tNome da Playlist: ");
    nomep=LeDados();
    printf("\t\tQuantidade de colaboradores (MAX 2), (Nenhum==-1): ");
    qtdColab=LerInteiros();
    OpcaoPesquisarUsuario(s,id);    
    if(qtdColab==1){
        printf("\n\t\tId do Colaborador [00]: ");
        colab1=LerInteiros();
        u=RetornaUsuarioSistema(s,colab1);
        nomeColab1=RetornaLogin(u);
    }
    else if(qtdColab==2){
         printf("\t\tId do Colaborador [00]: ");
        colab1=LerInteiros();
        u=RetornaUsuarioSistema(s,colab1);
        nomeColab1=RetornaLogin(u);
         printf("\t\tId do Colaborador [01]: ");        
         u2=RetornaUsuarioSistema(s,colab2);
         nomeColab2=RetornaLogin(u2);
        colab2=LerInteiros();
    }
    printf("\t\tSera :Publica(0) ou Privada(1): ");
    tipo=LerInteiros();
    CriaPlaylist(play,nomep,nomeColab1, nomeColab2, qtdColab, qtdMidia, tipo);
    if(qtdColab==1){
        AdicionaPlaylistUsuario(u,play);
    }else if(qtdColab==2){
        AdicionaPlaylistUsuario(u,play);
        AdicionaPlaylistUsuario(u2,play);
    }
}
void AlteraMidia(Midia *m,int escolha){
    char *nome=(char*)malloc(50);
    int num,op,qtdA,qtdC;
    float fnum;
    if(escolha==1){
        printf("\n\t\tNome da midia: ");
        nome=LeDados();
        AtribuiNomeMidia(m,nome);
    }
    else if(escolha==2){   
            qtdA=RetornaQtdArtista(m);
            if(qtdA==1){     
                printf("\n\t\tNome do artista: ");
                nome=LeDados();
                AtribuiNomeArtista1(m,nome);
            }
            else if(qtdA==2){
                printf("\n\t\tQual dos Artistas deseja alterar (0 ou 1): ");
                op=LerInteiros();
                if(op==1){
                    printf("\n\t\tNome do artista: ");
                    nome=LeDados();
                    AtribuiNomeArtista1(m,nome);
                }
                else if(op==2){
                    printf("\n\t\tNome do artista: ");
                    nome=LeDados();
                    AtribuiNomeArtista2(m,nome);
                }
            }
        }
    else if(escolha==3){
        qtdC=RetornaQtdCompositor(m);
        if(qtdC==1){
            printf("\n\t\tNome Compositor: ");
            nome=LeDados();
            AtribuiNomeCompositor1(m,nome);
        }
        else if(qtdC==2){
            printf("\n\t\tQual dos Compositores deseja alterar (0 ou 1): ");
            op=LerInteiros();        
            if(op==1){
                printf("\n\t\tNome Compositor: ");
                nome=LeDados();
                AtribuiNomeCompositor1(m,nome);
            }
            else if(op==2){
                printf("\n\t\tNome Compositor: ");
                nome=LeDados();
                AtribuiNomeCompositor2(m,nome);
            }        
        }
    }
        
    else if(escolha==4){
        printf("\n\t\tGenero: ");
        nome=LeDados();
        AtribuiNomeGenero(m,nome);
    }
    else if(escolha==5){
        printf("\n\t\tTipo, [01]Musica [02]Video [03]Podcast:  ");
        num=LerInteiros();
        AtribuiTipo(m,num);
    }
    else if(escolha==6){
        printf("\n\t\tDuracao: ");
        fnum=LerFloat();
        AtribuiDuracao(m,fnum);
    }
    else if(escolha==7){
       printf("\n\t\tNome produtora: ");
       nome=LeDados();
       AtribuiNomeProdutora(m,nome);
    }
}
void AlteraAlbum(Album *a,int escolha){
    char *nome=(char*)malloc(50);
    int num;    
    if(escolha==1){
        printf("\n\t\tNome do Album: ");
        nome=LeDados();
        AtribuiNomeAlbum(a,nome);
    }
    else if(escolha==2){
        printf("\n\t\tNome do artista: ");
        nome=LeDados();
        AtribuiArtistaAlbum(a,nome);
    }
    else if(escolha==3){
        printf("\n\t\tGenero: ");
        nome=LeDados();
        AtribuiGenero(a,nome);
    }
    else if(escolha==4){
       printf("\n\t\tNome produtora: ");
       nome=LeDados();
       AtribuiProdutoraAlbum(a,nome); 
    }
    else if(escolha==5){
        printf("\n\t\tAno do Album: ");
        num=LerInteiros();
        AtribuiAnoAlbum(a,num);
    }
}
void AlteraPlaylist(Playlist *p, int escolha){
    char *nome=(char*)malloc(50);
    int num;
    if(escolha==1){
        printf("\n\t\tNome da Playlist: ");
        nome=LeDados();
        AtribuiNomePlaylist(p,nome);        
    }    
}
void PreenchePlaylist(Playlist* p, Album *a){
    Midia *m=AlocaMidia();
    int num;
    ImprimeAlbum(a);
    printf("\t\tNumero da midia que deseja adicionar na Playlist: ");
    num=LerInteiros();
    m=RetornaMidiaAlbum(a,num);
    AdicionaMidiaPlaylist(p,m);
}
void PreencheUsuario(Usuario *u,Album *a, int favorita,Sistema *s){
    int qtd,id;
    Playlist *play=AlocaPlaylist();
    id=RetornaIdUsuario(u);
    DadosPlaylist(play,s,id);
    printf("\n\t\tQuantas midias deseja adicionar em sua Playlist? (MAX 50): ");
    qtd=LerInteiros();    

    for(int i=0;i<qtd;i++){
        PreenchePlaylist(play,a);
    }
        if(favorita==0){AdicionaPlaylistUsuario(u,play);}
        else if(favorita==1){AdicionaPlaylistFavoritaUsuario(u,play);}        
}
void PreencheSistemaComAlbum(Sistema *s){
    Album *alb=AlocaAlbum();
    DadosAlbum(alb);
    AdicionaAlbumSistema(s,alb);  
    printf("\n\n");    
}
void PreencheSistemaComUsuario(Sistema *s,Usuario *usu){
    AdicionaUsuarioSistema(s,usu);  
}
void OpcaoCriarPlaylist(Sistema *s,Usuario *usu, int opcao){
    int favorita=0,id=0,idusu=0;
    if(opcao==3){
        favorita=1;
    }
    ImprimeAlbunsSistema(s);
    printf("\n\t\tDidite o Id do Album que deseja visualizar as Midias: ");
    id=LerInteiros();
    Album *albm=AlocaAlbum();
    albm=RetornaAlbumEscolhido(s,id);
    PreencheUsuario(usu,albm,favorita,s);
    idusu=RetornaIdUsuario(usu);    
    ImprimeUsuarioSistema(s,idusu,1);
}
void EditaPlaylist(Sistema *s,Usuario *usu){

 while(1){
        int op1=0,id1=0,opMenuAltera=0,midia=0;
         MenuPlaylist();
        op1=LerInteiros();
        if(op1==1){//Apagar Playlist
            ImprimeUsuario(usu);
            printf("\n\t\tDigite o id da Playlist que deseja apagar: ");
            id1=LerInteiros();
            ApagaPlaylistUsuario(usu,id1);
            ImprimeUsuario(usu);
             break;
        }
        else if(op1==2){//Editar Playlist
            Playlist* play=AlocaPlaylist();
            ImprimeUsuario(usu);
            printf("\n\t\tDigite o id da Playlist que deseja editar: ");
            id1=LerInteiros();
            play=RetornaPlaylistUsuario(usu,id1);
            while(1){
                opMenuAltera=0;
                midia=0;
                MenuAlteraPlaylist();
                opMenuAltera=LerInteiros();
                if(opMenuAltera<1 || opMenuAltera>5){continue;}
                else if(opMenuAltera==5){opMenuAltera=0;break;}
                else if(opMenuAltera==1){AlteraPlaylist(play,opMenuAltera);break;}
                else if(opMenuAltera==2){
                    ImprimePlaylist(play);
                    printf("\n\t\tEscolha a midia que deseja apagar: ");
                    midia=LerInteiros();
                    ApagaMidiaPlaylist(play,midia);
                    continue;
                }
                else if(opMenuAltera==3){//Altera Ordem Das Midias
                    int p1,p2;
                    ImprimePlaylist(play);
                    printf("\n\t\tEscolha a posicao das midias que deseja aterar: ");
                    p1=LerInteiros();
                    p2=LerInteiros();
                    TrocaMidia(play,p1,p2);
                    ImprimePlaylist(play);
                    continue;
                }
                else if(opMenuAltera==4){//Adicionar Midia a playlist
                int idp;
                        ImprimeAlbunsSistema(s);
                        printf("\n\t\tDidite o Id do Album que deseja visualizar as Midias: ");
                        idp=LerInteiros();
                        Album *albm=AlocaAlbum();
                        Midia *m=AlocaMidia();
                        albm=RetornaAlbumEscolhido(s,idp);
                        ImprimeAlbum(albm);
                        printf("\n\t\tDidite o Id da Midia que deseja adicionar à Playlist: ");
                        idp=LerInteiros();
                        m=RetornaMidiaAlbum(albm,idp);
                        AdicionaMidiaPlaylist(play,m);
                        continue;
                }
            }
        }
        else if(op1==3){break;}//Sair Menu
        else {printf("\n\t\tOpcao Invalida, tente novamente!"); continue;}
    } 
}
void OpcaoPesquisar(Sistema *s){
     while(1){
        int op=0;
        char *nomes;
        MenuPesquisar();
        op=LerInteiros();
        if(op==1){//Nome Album
            printf("\n\t\tDigite o nome do Album que deseja pesquisar: ");
            nomes=LeDados();
            PequisarNomeAlbum(s,nomes);
            continue;
        }
        else if(op==2){//Nome Midia
            printf("\n\t\tDigite o nome da Midia que deseja pesquisar: ");
            nomes=LeDados();
            PesquisarNomeMidia(s,nomes);
            continue;
            }
        else if(op==3){//Nome Artista
             printf("\n\t\tDigite o nome do Artista que deseja pesquisar: ");
            nomes=LeDados();
            PesquisarNomeArtista(s,nomes);
            continue;
            }
        else if(op==4){
            printf("\n\t\tDigite o nome do Compositor que deseja pesquisar: ");
            nomes=LeDados();
            PesquisarNomeCompositor(s,nomes);
            }
        else if(op==5){
            printf("\n\t\tDigite o nome da Produtora que deseja pesquisar: ");
            nomes=LeDados();
            PesquisarProdutora(s,nomes);                        
            }
        else if(op==6){
            printf("\n\t\tDigite o Genero que deseja pesquisar: ");
            nomes=LeDados();
            PesquisarGenero(s,nomes);
            }
        else if(op==7){break;}
        else continue;
    }
}
void OpcaoDev(Sistema *s){
 printf("\n\t\tDigite a senha: ");
       int senha;
       senha=LerInteiros();
       if(!(VerificaSenhaDev(s,senha))){printf("\n\t\tSenha Incorreta!\n");}   
       else {
         while(1){
            int id1=0,opcao1=0;  
            MenuDesenvolvedor();
            opcao1=LerInteiros();
            if(opcao1==1){              
               PreencheSistemaComAlbum(s);
            }
            else if(opcao1==3){//Editar Album;
                int alb=0;
                 int opA=0;
                Album *alterar=AlocaAlbum();
                ImprimeAlbunsSistema(s);
                printf("Escolha o Album que deseja editar: ");
                alb=LerInteiros();
                alterar=RetornaAlbumEscolhido(s,alb);
                while(1){
                    opA=0;
                    MenuAlteraAlbum();
                    opA=LerInteiros();
                    if(opA<1 ||opA>6){continue;}
                    else if(opA==6){opA=0;break;}
                    else{AlteraAlbum(alterar,opA); opA=0; break;}
                }                
            }
            else if(opcao1==2){//EditarMidia
                int mid=0,alb=0, opM=0;
                Album *alterar=AlocaAlbum();
                Midia *midiaAltera=AlocaMidia();
                ImprimeAlbunsSistema(s);
                printf("\n\t\tSelecione o Album: ");
                alb=LerInteiros();
                alterar=RetornaAlbumEscolhido(s,alb);
                ImprimeAlbum(alterar);
                printf("Escolha a Midia que deseja editar: ");
                mid=LerInteiros();
                midiaAltera=RetornaMidia(s,alb,mid);
                while(1){
                    opM=0;
                    MenuAlteraMidia();
                    opM=LerInteiros();
                    if(opM<1 || opM>8){continue;}
                    else if(opM==8){opM=0;break;}
                    else{AlteraMidia(midiaAltera,opM);opM=0; break;}
                }                
            }
         if(opcao1==4){break;}   
        }        
    }
}
void PequisaUsuario(Sistema *s, Usuario *u){
    
    while(1){
        Playlist *p=AlocaPlaylist();
        Usuario *u2=AlocaUsuario();
        int id_opcao=0,s_n=0,idplay=0;
        OpcaoPesquisarUsuario(s,RetornaIdUsuario(u));
        printf("\n\t\tDigite o id do Usuario para ver suas Playlists: ");
        id_opcao=LerInteiros();
        ImprimeUsuarioSistema(s,id_opcao,0);
        printf("\n\t\tDeseja Seguir alguma playlist desse usuario, [1]SIM, [0]NAO: ");
        s_n=LerInteiros();
        if(s_n==0){
            printf("\t\tDeseja Sair do menu pesquisar usuario,[1]SIM, [0]NAO: ");
            s_n=LerInteiros();
            if(s_n==1){break;}            
        }
        else if(s_n==1){
            printf("\n\t\tDigite o id da Playlists que deseja seguir: ");
            idplay=LerInteiros();
            u2=RetornaUsuarioSistema(s,id_opcao);
            p=RetornaPlaylistUsuario(u2,idplay);
            AtribuiPlaylistSeguindo(u,p);
            continue;
        }
    }
}
int main(){    
   Sistema *s=AlocaSistema();
   s=LerPrograma();
   
    while(1){
        int escolha=0,ij;
        MenuInicial();
        escolha=LerInteiros(); 
        if(escolha==1){//Cria Usuario
            Usuario *usu=AlocaUsuario();
            DadosUsuario(usu,s);               
            PreencheSistemaComUsuario(s,usu);         
            continue;
        }
        else if(escolha==2){ //OPçao Desenvolvedor   
            OpcaoDev(s);
            continue;      
        }
        if(escolha==3){//Login
            int posi=0;
            char *login=(char*)malloc(50);
            char *senha=(char*)malloc(50);
            Usuario *u=AlocaUsuario();
            printf("\n\t\tLogin: ");
            login=LeDados();
            printf("\t\tSenha: ");
            senha=LeDados();
            posi=VerificaUsuarioSistema(s,login,senha);
            if(posi==-1){continue;}
            else {
                u=RetornaUsuarioSistema(s,posi);  
            while(1){            
                int id=0,opcao=0; 
                MenuUsuario();            
                opcao=LerInteiros();
                if(opcao==1 || opcao==3){
                    OpcaoCriarPlaylist(s,u,opcao);
                    continue;                
                }
                else if(opcao==2){//Pesquisar Usuarios
                    PequisaUsuario(s,u);
                    continue;                
                }           
                else if(opcao==4){//Imprime conta do Usuario
                    ImprimeUsuario(u);
                }
                else if(opcao==5){//Editar Playlists
                    EditaPlaylist(s,u);
                    continue;
                }
                else if (opcao==6){break;}//Sai do Menu
                else {printf("\n\t\tOpcao Invalida, tente novamente!"); continue;}
            }
            continue;    
            }
        }    
        else if(escolha==4){//Pesquisar
            OpcaoPesquisar(s);
            continue;
        }
        else if(escolha==5){break;}//Sai do Programa
        else {printf("\n\t\tOpcao Invalida! Tente Novamente.");continue;}
        }     
    SalvaPrograma(s);       
    return 0;
}
#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#include <stdlib.h>

int confirmacao();
void confirmandovoto(int c);

typedef struct //obrigatorio usar o type para definir
{
    char nome[9];
    int  votos;
} aranha;

main()
{
        aranha c [3]= {"Tobey",0,
                   "Tom", 0,
                   "Andrew",0
                  };
    int i, encerrarvotacao, eleito, eleito2, eleito3;

    // Inicializa uma janela com a largura e altura da tela máxima
    initwindow(getmaxwidth(),getmaxheight(),"Qual o melhor Homem-Aranha?",0,0);
   voltar:
    while(1)
    {
        // Insere as imagens e define as coordenadas de exibicao na janela
        readimagefile("inicio.jpg", 0,0,getmaxwidth(), getmaxheight());
        readimagefile("tobeyon.jpg",155,314,325,482);
        readimagefile("tomon.jpg",386,312,558,482);
        readimagefile("andrewon.jpg",614,314,787,480);
        readimagefile("encerrabtn.jpg",319, 698,560,780);
        //readimagefile("quit.jpg",1407, 708, 1508, 824);
        while (1)
        {
            /*snprintf(buffer, 100, "Mouse X: %d\nMouse Y: %d", mousex(),mousey());
            outtextxy(0,0, buffer);*/ //CASO QUEIRA VER AS COORDENADAS

            // Area da primeira imagem (Tobey)
            if (ismouseclick(WM_LBUTTONDOWN) &&
                    mousex() > 200 && mousex() < 350 &&
                    mousey() > 350 && mousey() < 500)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                readimagefile("tobeyselected.jpg",155,314,325,482);
                delay (1000);

                confirmandovoto(0);

                if(confirmacao()==0) //SE APERTAR EM RETORNAR, VALE 0 QUE FAZ VOLTAR A TELA INICIAL
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("retornarselected.jpg",1146, 410,1420, 504);
                    Sleep(1000);
                    break;
                }

                if(confirmacao()==1)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("votarselected.jpg",1147, 259, 1412, 350);
                    c[0].votos++;
                    delay(1000);
                    break;
                }

            }

            // Area da segunda imagem (Tom)
            if (ismouseclick(WM_LBUTTONDOWN) &&
                    mousex() > 386 && mousex() < 558 &&
                    mousey() > 312 && mousey() < 482)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                readimagefile("tomselected.jpg",386,312,558,482);
                delay (1000);

                confirmandovoto(1);
                if(confirmacao()==0)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("retornarselected.jpg",1146, 410,1420, 504);
                    Sleep(1000);
                    break;
                }

                if(confirmacao()==1)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("votarselected.jpg",1147, 259, 1412, 350);
                    c[1].votos++;
                    delay(1000);
                    break;
                }

            }

            // Area da terceira imagem (Andrew)
            if (ismouseclick(WM_LBUTTONDOWN) &&
                    mousex() > 618 && mousex() < 787 &&
                    mousey() > 314 && mousey() < 480)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                readimagefile("andrewselected.jpg",614,314,787,480);
                delay (1000);

                confirmandovoto(2);
                if(confirmacao()==0)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("retornarselected.jpg",1146, 410,1420, 504);
                    Sleep(1000);
                    break;
                }

                if(confirmacao()==1)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("votarselected.jpg",1147, 259, 1412, 350);
                    c[2].votos++;
                    delay(1000);
                    break;
                }

            }
            if (ismouseclick(WM_LBUTTONDOWN) &&              //BOTÃO ENCERRAR VOTAÇÃO
                    mousex() > 319 && mousex() < 560 &&
                    mousey() > 698 && mousey() < 780)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                readimagefile("encerrarselected.jpg",319, 698,560,780);
                encerrarvotacao = 1;
                break;
            }
        }
        if(encerrarvotacao == 1)
            break;
    }

    eleito = c[0].votos;
    for(i = 0; i < 3; i++)
    {
        if(c[i].votos > eleito)
        {
            eleito = i;
        }
       else eleito3 = i;
        if (eleito2 > eleito3)
        {
            eleito2 = i;
        }
    }

    if (c[eleito].votos == 0){
        readimagefile("carregando.jpg", 0,0,getmaxwidth(), getmaxheight());
        Sleep(3000);
        goto voltar;
    }



    printf("\t===================================== TABELA DOS VALORES =====================================");
    printf("\n\nO vencedor, %s ,esta na posicao = %d", c[eleito].nome, eleito);
    printf("\n\n****************************** Votos Tobey (0) = %d", c[0].votos);
    printf("\n\n****************************** Votos Tom (1) = %d", c[1].votos);
    printf("\n\n****************************** Votos Andrew (2) = %d\n", c[2].votos);
    printf("\n\n\t\t\t||  ||\n\t\t\t\\\\()//\n                       //(__)\\\\\n                       ||    || \n\n\t\t By: Gabriel Sasuke, Luiz Felipe T.S, Vittoria\n \t\t\tAte breve!!\n\n\n");
    switch(eleito)
    {
    case 0:
        readimagefile("tobeyeleito.jpg", 0,0,getmaxwidth(), getmaxheight());
        break;
    case 1:
        readimagefile("tomeleito.jpg",0,0,getmaxwidth(), getmaxheight());
        break;
    case 2:
        readimagefile("andreweleito.jpg",0,0,getmaxwidth(), getmaxheight());
        break;
    }
    setfillstyle(1,0);
    setbkcolor(15);
    setcolor(0);
    outtextxy(165,368,c[eleito].nome); //1ª POSIÇÃO

    outtextxy(169,438,c[eleito2].nome); //2ª POSIÇÃO


    outtextxy(169,510,c[eleito3].nome); //3ª POSIÇÃO

    Sleep (5000);
}

int confirmacao()
{
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousex() > 1147 && mousex() < 1412 &&
               mousey() > 259 && mousey() < 340)
            {
                return 1;
            }
            if(mousex() > 1146 && mousex() < 1420 &&
               mousey() > 417 && mousey() < 504)
            {
                return 0;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void confirmandovoto(int c)
{
    switch(c)
    {
    case 0:
        readimagefile("confirmar0.jpg",0,0,getmaxwidth(), getmaxheight()); //Tobey
        break;
    case 1:
        readimagefile("confirmar1.jpg",0,0,getmaxwidth(), getmaxheight()); //Tom
        break;
    case 2:
        readimagefile("confirmar2.jpg",0,0,getmaxwidth(), getmaxheight()); //Andrew
        break;
    }
}

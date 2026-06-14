/* Leonardo_Kac_Szmajser 2410775 3WB */

#include <stdio.h>
#include "cria_func.h"

void cria_func(void *f, DescParam params[], int n, unsigned char codigo[])
{
    unsigned char *p = codigo;

    //Prólogo

    //push %rbp
    *p++ = 0x55;
   
    //mov %rsp, %rbp
    *p++ = 0x48;
    *p++ = 0x89;
    *p++ = 0xe5;

    //salvar os argumentos originais recebidos em registradores temporários

    //%rdi -> %r8
    *p++ = 0x49;
    *p++ = 0x89;
    *p++ = 0xf8;


    //%rsi -> %r9
    *p++ = 0x49;
    *p++ = 0x89;
    *p++ = 0xf1;


    //%rdx -> %r10
    *p++ = 0x49;
    *p++ = 0x89;
    *p++ = 0xd2;

    //contador de quais parâmetros originais já processamos
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (params[i].orig_val == PARAM)
        {
            //traz o argumento do registrador temporário para o alvo
            if (params[i].tipo_val == INT_PAR)
            {
                if (k == 0)
                {
                    if (i == 0)
                    {
                        *p++ = 0x44; *p++ = 0x89; *p++ = 0xc7;
                    }
                    else if (i == 1)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xc6;
                    }
                    else if (i == 2)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xc2;
                    }
                }
                else if (k == 1)
                {
                    if (i == 0)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xcf;
                    }
                    else if (i == 1)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xce;
                    }
                    else if (i == 2)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xca;
                    }
                }
                else if (k == 2)
                {
                    if (i == 0)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xd7;
                    }
                    else if (i == 1)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xd6;
                    }
                    else if (i == 2)
                    {
                        *p++ = 0x44;
                        *p++ = 0x89;
                        *p++ = 0xd2;
                    }
                }
            }
            else
            {
                if (k == 0)
                {
                    if (i == 0)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xc7;
                    }
                    else if (i == 1)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xc6;
                    }
                    else if (i == 2)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xc2;
                    }
                }
                else if (k == 1)
                {
                    if (i == 0)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xcf;
                    }
                    else if (i == 1)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xce;
                    }
                    else if (i == 2)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xca;
                    }
                }
                else if (k == 2)
                {
                    if (i == 0)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xd7;
                    }
                    else if (i == 1)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xd6;
                    }
                    else if (i == 2)
                    {
                        *p++ = 0x4c;
                        *p++ = 0x89;
                        *p++ = 0xd2;
                    }
                }
            }

            k++;

        }
        else if (params[i].orig_val == FIX)
        {
            if (params[i].tipo_val == INT_PAR)
            {
                if (i == 0)
                {
                    *p++ = 0xbf;
                }
                else if (i == 1)
                {
                    *p++ = 0xbe;
                }
                else if (i == 2)
                {
                    *p++ = 0xba;
                }
                *((int *)p) = params[i].valor.v_int; p += 4;
            }
            else
            {
                if (i == 0)
                {
                    *p++ = 0x48;
                    *p++ = 0xbf;
                }
                else if (i == 1)
                {
                    *p++ = 0x48;
                    *p++ = 0xbe;
                }
                else if (i == 2)
                {
                    *p++ = 0x48;
                    *p++ = 0xba;
                }
                *((void **)p) = params[i].valor.v_ptr; p += 8;
            }
        }
        else if (params[i].orig_val == IND)
        {
            //movabs $ptr, %r11
            *p++ = 0x49; *p++ = 0xbb;
            *((void **)p) = params[i].valor.v_ptr; p += 8;

            if (params[i].tipo_val == INT_PAR)
            {
                //mov (%r11), %edi
                if (i == 0)
                {
                    *p++ = 0x41;
                    *p++ = 0x8b;
                    *p++ = 0x3b;
                }
                //mov (%r11), %esi
                else if (i == 1)
                {
                    *p++ = 0x41;
                    *p++ = 0x8b;
                    *p++ = 0x33;
                }
                //mov (%r11), %edx
                else if (i == 2)
                {
                    *p++ = 0x41;
                    *p++ = 0x8b;
                    *p++ = 0x13;
                }
            }
            else
            {
                //mov (%r11), %rdi
                if (i == 0)
                {
                    *p++ = 0x49;
                    *p++ = 0x8b;
                    *p++ = 0x3b;
                }
                //mov (%r11), %rsi
                else if (i == 1)
                {
                    *p++ = 0x49;
                    *p++ = 0x8b;
                    *p++ = 0x33;
                }
                //mov (%r11), %rdx
                else if (i == 2)
                {
                    *p++ = 0x49;
                    *p++ = 0x8b;
                    *p++ = 0x13;
                }
            }
        }
    }

    //chamada da função original f

    //movabs $f, %rax
    *p++ = 0x48;
    *p++ = 0xb8;

    *((void **)p) = f;
    p += 8;

    //call *%rax
    *p++ = 0xff;
    *p++ = 0xd0;

    //Epílogo
    *p++ = 0xc9; //leave
    *p++ = 0xc3; //ret
}
#include <stdio.h>
#include "tokens.h"

Token newToken(int type, double value)
{
    Token token;
    token.type = type;
    if (value != TOKEN_NULL) {
        token.has_value = true;
        token.value = value;
    } else
        token.has_value = false;
    return token;
}

void print_tokens(Token tokens[], size_t len)
{

    printf("[");

    for (int i = 0; i < len; i++) {
        
        if (i != 0)
            printf(", ");

        switch (tokens[i].type)
        {
            case TT_NUMBER:
                printf("NUMBER");
                break;
            case TT_PLUS:
                printf("PLUS");
                break;
            case TT_MINUS:
                printf("MINUS");
                break;
            case TT_MULTIPLY:
                printf("MULTIPLY");
                break;
            case TT_DIVIDE:
                printf("DIVIDE");
                break;
            case TT_LPAREN:
                printf("LPAREN");
                break;
            case TT_RPAREN:
                printf("RPAREN");
                break;
        }

        if (tokens[i].has_value)
           printf(":%lf", tokens[i].value);

    }

    printf("]\n");

}


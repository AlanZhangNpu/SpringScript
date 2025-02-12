%{
/*The codes in this file are from 
http://blog.csdn.net/opendba/article/details/5949762*/
#include "stdio.h"
#include "stdlib.h"
int num_num=0,num_id=0;
%}

INTEGER [-+]?[1-9][0-9]*
ID [a-zA-Z][a-zA-Z_0-9]*
SPACE [ /n/t]

%%

{INTEGER} { num_num++;
  printf("(num=%d)/n",atoi(yytext));/*打印数字值*/
    /*数字数加一*/
}

{ID} { num_id++;
    printf("(id=%s)/n",yytext);
    }

{SPACE} |
. {
   /*什么也不做,滤掉白字符和其它字符*/
   }

%%

int main()
{
   yylex();
   printf("num=%d,id=%d/n",num_num,num_id);
   return 0;
}

int yywrap()//此函数必须由用户提供
{
    return 1;
}
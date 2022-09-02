#include<stdio.h>
#include <string.h>

int MAXSIZE = 10000;       
char stack[10000];     
int top = -1;            

char *reverse(char *str)
{
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

char peek() {
   return stack[top];
}

char pop() {
   int data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(char data) {
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
  char str[10000];
    puts("Input");
    scanf("%[^\n]%*c", str);
    char answer[10000];
  char temp[10000];
  
  for (int i = 0; str[i] !='\0' ; i++) {
    push(str[i]);
  }
  
  while(!isempty()) {
      if(peek() == ' '){
          pop();
          char vr = ' ';
          
          reverse(temp);  
          strncat( temp,&vr, 1);
          strcat(answer, temp);
          for(int i=0;i<strlen(temp);i++)
            {
                temp[i] = 0;
            }
      }else{
        char vr = pop();
        strncat(temp,&vr, 1);
          
      }
  }
        reverse(temp); 
        strcat(answer, temp);
    puts("\n\nReverse String");
  puts(answer);
    puts("\nActual String");
  puts(str);
  return 0;
}

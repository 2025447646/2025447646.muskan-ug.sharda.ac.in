#include <stdio.h>
#include<string.h>
int countfrequency(char str[], char ch)
{
  int i,count = 0;
  for(i=0; str[i] !='\0'; i++)
  {
    if (str[i]== ch)
  count++;
  }
  return count;
}

  int main()
{
  char str[100],ch;
  int words;
   printf ("enter string: ");
  gets(str);
  printf("enter character: ");
  scanf("%c", &ch);

  printf( "%c", &ch);
  printf("frequency of %c = %d\n",ch, frequency (str,ch));
  words = frequency (str, ' ') + 1;
  printf (" Number of words=%d\n",words);
  printf("\nfrequency of each alphabet:\n");
  for (char c='a';c<= 'z'; c++)
  {
    int f = frequency(str,c);
    if(f>0)
    printf("%c=%d\n",c,f);
  }
  return 0;
}
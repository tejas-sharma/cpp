int main(int argc, char ** argv) 
{
  char c = 'a';
  char * pChar = &c;

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *pArr = arr;

  char text[] = "hello world";
  char * pStr = text;

  const int cInt = 10;
  int const * pCInt = &cInt;
  int i = 20;
  int * const cPInt = &i;

  return 0;
}

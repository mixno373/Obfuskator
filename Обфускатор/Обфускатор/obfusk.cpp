#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 

int i = 0, slkol = 0; //slkol - ���������� ������, ������ ������
char cArray[10000], c = 'n', lc = 'n', s[10000], cc = 'n', ccc = 'n';
int len = strlen(cArray);
int kav1 = 0, kav2 = 0; // �������. 1 - '_', 2 - "_"; 

int word = 0, countOfWords = 0, whereWord = 0;
char words[10000][100], chang[10000][100];
//��������� ������ �� �������������� � ����������� �������� 
int isWord(char qwertyuiop) {
  if (((qwertyuiop > 64) && (qwertyuiop < 91)) || ((qwertyuiop > 96) && (qwertyuiop < 123)))
    return 1;
  return 0;
}


char *changeWord() {
  int e = 0, save = 0;
  for (int tyoh = 0; tyoh < countOfWords; tyoh++) {
    e = 0;
    while (words[tyoh][e] || words[countOfWords][e]) {
      save = tyoh; if (words[tyoh][e] != words[countOfWords][e]) goto met; e++;
    }
    countOfWords--;
    return chang[save];
  met:;
  }
  return chang[countOfWords];
}

void take(char s[100]) {
  int n = 0;
  while (s[n]) {
    words[countOfWords][n] = s[n];
    chang[countOfWords][n] = s[n];
    n++;
    words[countOfWords][n] = s[n];
    chang[countOfWords][n] = s[n];
    n++;
  }
  words[countOfWords][n] = '\0';
  chang[countOfWords][n] = '\0';
  countOfWords++;
}

void launch() {
  take("int");
  take("char");
  take("long");
  take("short");
  take("for");
  take("while");
  take("do");
  take("void");
  take("printf");
  take("scanf");
  take("getch");
  take("getchar");
  take("return");
  take("fgetc");
  take("fputc");
  take("getc");
  take("putc");
  take("fgets");
  take("fputs");
  take("FILE");
  take("scanf");
  take("else");
  take("switch");
  take("case");
  take("elseif");
  take("continue");
  take("break");
  take("goto");
  take("if");
  take("fopen");
  take("fclose");;
  take("strlen");
  take("strcpy");
  take("strncpy");
  take("strcmp");
  take("strncmp");
  take("strcat");
  take("strncat");
  take("feof");
  take("EOF");
  take("unsigned");
  take("isdigit");
  take("main");
  take("double");
  take("sin");
  take("cos");
  take("pow");
  take("powl");
  take("pi");
}

int main()
{
  int def = 0;
  int zx;
  int ku;
  for (int rt = 0; rt < 10000;rt++)
  {
    chang[rt][0] = 'f';
    chang[rt][1] = 'u';
    chang[rt][2] = 'n';
    ku = rt;
    zx = 3;
    while (ku)
    {
      chang[rt][zx++] = (ku % 10) + 48; ku /= 10;
    }
    chang[rt][zx] = '\0';
    rt++;
    chang[rt][0] = 'f';
    chang[rt][1] = 'u';
    chang[rt][2] = 'n';
    ku = rt;
    zx = 3;
    while (ku)
    {
      chang[rt][zx++] = (ku % 10) + 48; ku /= 10;
    }
    chang[rt][zx] = '\0';
  }
  launch();

  char inFile[100] = "in2.c", c = 'n';
  //printf("Input file name:");
  //scanf("%s", &inFile);


  FILE *fin = fopen(inFile, "r");
  FILE *fout = fopen("Output.c", "w");

  char last = 'n';
  while (!feof(fin)) {
  xyz1:
    last = c;
    c = fgetc(fin);
    if (feof(fin)) { break; }
  eto:
    //������� ���� "_" 
    if (c == '\"') {
      fputc('\"', fout);
      i = 0;
      slkol = 0;
      lc = 'n';
      c = '#';
      while ((c != '\"') || (slkol % 2 != 0)) {
      repa1:lc = c;
        c = fgetc(fin);
        if (feof(fin)) { goto tuda1; }
        if (((c == '\n') && (lc == '\\') && (slkol % 2 == 1))) { fputc('\n', fout); slkol = 0; goto repa1; }
        else { if (c == '\n') { fputc('\n', fout); goto xyz1; } }
        if (c == '\\') {
          if (lc == '\"') { slkol = 1; }
          else { slkol++; }
        }
        else { if (c != '\"') { slkol = 0; } }
        fputc(c, fout);
      }
      //fputc('#', fout); 
      goto xyz1;
    }
    else {
      //TODO ���� � ���������� 
      //������� ���� '_' 
      if (c == '\'') {
        fputc('\'', fout);
        i = 0;
        slkol = 0;
        lc = 'n';
        c = '#';
        while ((c != '\'') || (slkol % 2 != 0)) {
          lc = c;
          c = fgetc(fin);
          if (feof(fin)) { goto tuda1; }
          if (c == '\n') { fputc('\n', fout); goto xyz1; }
          if (c == '\\') {
            if (lc == '\'') { slkol = 1; }
            else { slkol++; }
          }
          else { if (c != '\'') { slkol = 0; } }
          fputc(c, fout);
        }
        goto xyz1;
      }
      else {
        //. 

        //����������� 
        if (c == '/') {
          c = fgetc(fin); if (feof(fin)) { fputc('/', fout); goto tuda1; }
          if (c == '/') {
            fputc('\n', fout); 
            while (1) {
              lc = c;
              c = fgetc(fin);
              if (feof(fin)) { goto tuda1; }
              if (c == '\n') {
                if (lc == '\\') {
                  continue;
                }
                else { break; }
              }
            }
            goto xyz1;
          }
          else {
            if (c == '*') {
              cc = 'i'; ccc = 'i'; while ((cc != '*') || (ccc != '/')) { cc = ccc; ccc = fgetc(fin); if (feof(fin)) { goto tuda1; } } goto xyz1;
            }
            else {
              fputc('/', fout);  
              goto eto;
            }
          }
          goto xyz1;
        }
        else {

          if (def == 0) {
            if (c == '#') { char ss[1000]; fgets(ss, 1000, fin); fputc('#', fout); fputs(ss, fout); continue; }
          }
          if (c == '{') def = 1;
          if ((last == ' ') && (c == ' ')) { continue; }
          if (isWord(c)) { if (word == 0) countOfWords++; word = 1; words[countOfWords][whereWord++] = c; }
          else {
            if (word == 1) {
              words[countOfWords][whereWord] = '\0';  whereWord = 0; if (countOfWords == 8) {

              }
              fputs(changeWord(), fout);
            }
            word = 0;
            fputc(c, fout);
          }
        }
      }
    }
  }
tuda1:;
  fclose(fin);
  fclose(fout);
  return 0;
}
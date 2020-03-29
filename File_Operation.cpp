// 12 C语言文件操作文件
/*1、定义文件类型指针，FILE *文件指针变量*；
  2、打开文件，调用fopen函数；
  3、文件读写，调用读写函数；
  4、关闭文件，调用fclose函数*/

//文件的打开
/*1、FILE *fopen(char *fname,char *mode) 按照mode的方式，打开fname指定的文件；
  2、" r w a + b t "六种模式选择符号；
  3、FILE *fp;
     char fname[18];
     cout<<"Input filename:\n";
     cin>>fname;
     fp=fopen(fname,"r"); or fp=fopen("D:\\Max\\baby.txt","a");
  4、fopen函数的返回值进行检验，判断文件是否成功打开，必须带stdlib.h头文件；
      if((fp=fopen(fname,mode))==NULL)
      {
        cout<<"Can't open file!\n";
        exit(1);
       }*/

//文件的关闭
/*1、int fclose(FILE *fp);关闭有fp所指的文件，释放由fp所指的文件类型结构体变量
  2、返回值，正常返回0,异常返回EOF(-1)*/

//文件的读写（C语言提供四种顺序读写函数）
/*1、fputc fgetc ; 写入读取字符； 
  2、fwrite fread ; 写入读取数据块；
  3、fputs fgets ; 写入读取字符串；
  4、fprintf fscanf; 格式化写入读取数据*/
/*1、int fgetc(FILE *fp);返回类型说明！！！！！！！char与int；
  2、int feof(FILE *fp); 文件结束测试函数
     while (!feof(fp)
     {
       ch=fgetc(fp);
       putchar(ch);
      }
   3、int fputc(int ch, FILE *fp); 把ch中的字符写入fp所指的文件当前位置处，并使文件指针后移一个字符位置*/

#define N 5
#include <iostream>
#include <stdlib.h>
using namespace std;

//将文件file1.txt的内容显示在屏幕上，同时还将文件中的数字字符复制到文件file2.txt中。
FILE *fp, *fp1, *fp2;
struct student
{
    char name[20];
    char num[8];
    double score;
};

int main()
{
    char ch;
    errno_t err;// Open for read (will fail if file "D:\\ProgramS\\file1.txt" does not exist)
    err = fopen_s(&fp1, "D:\\ProgramS\\file1.txt", "r");
    if (err == 0)
    {
        printf("The file 'file1.txt' was opened! \n");
    }
    else
    {
        printf("The file 'file1.txt' was not opened! \n");
    }

    // Open for write
    err = fopen_s(&fp2, "D:\\ProgramS\\file2.txt", "w+");
    if (err == 0)
    {
        printf("The file 'file2.txt' was opened\n");
    }
    else
    {
        printf("The file 'file2.txt' was not opened\n");
    }

    while (!feof(fp1))
    {
        ch = fgetc(fp1);
        putchar(ch); //文件中的内容读到内存后显示在屏幕上
        if (ch >= '0' && ch < '9')
            fputc(ch, fp2);
    }

    // Close fp1 if it is not NULL
    if (fp1)
    {
        err = fclose(fp1);
        if (err == 0)
        {
            printf("The file 'file1.txt' was closed\n");
        }
        else
        {
            printf("The file 'file1.txt' was not closed\n");
        }
    }
    fclose(fp2);

    // All other files are closed:
    /*int numclosed = _fcloseall();
    printf("Number of files closed by _fcloseall: %u\n", numclosed);*/

    struct student s[N], t[N];
    int i;
    err = fopen_s(&fp, "D:\\ProgramS\\student.dat", "wb");
    if (err == 0)
    {
        printf("The file 'student.dat' was opened! \n");
        exit(1);
    }
    else
    {
        printf("The file 'student.dat' was not opened! \n");
    }
    for (i = 0; i < N; i++)
    {
        cin >> s[i].name >> s[i].num >> s[i].score;
        fwrite(&s[i],sizeof(student),1,fp);  //逐元素向文件写数据
    }
    fclose(fp);

    err = fopen_s(&fp, "D:\\ProgramS\\student.dat", "rb");
    if (err == 0)
    {
        printf("The file 'student.dat' was not opened! \n");
        exit(1);
    }
    fread(t, sizeof(t), 1, fp); //一次从文件读出整个数组
    for (i = 0; i < N; i++)
        cout << t[i].name << t[i].num << ' ' << t[i].score << endl;
    fclose(fp);
    system("pause");
    return 0;
}

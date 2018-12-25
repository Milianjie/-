
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct      ///账号密码结构体
{
    char user[20];
    char password[20];
    char email[30];
}UserPassword;

typedef struct     ///账号密码线性表构建
{
    UserPassword str[100];
    int len;  //len表示线性表长度，即线性表中有多少元素！第一个元素为str[0];
}ListUser;



void ListUserInit(ListUser *U) ///账号密码线性表  初始化
{
    U->len=0;
}

void ListUserInsert(ListUser *U,int loc,UserPassword e)  ///账号密码线性表  插入
{
    if(U->len>=100)
    {
        printf("可申请账号已达限制！！！"); //账号密码结构体已满
        return;
    }

    if(loc<0||loc>U->len+1)
    {
        printf("出现错误！");//插入账号密码结构体的位置错误
        return;
    }

    int i;
    for(i=U->len;i>loc;i--)
    {
        U->str[i]=U->str[i-1];
    }
    U->str[loc]=e;
    U->len++;
}

void ListUserCreat(ListUser *U)  ///  创建 从文件中读入数据到账号密码线性表
{
    FILE *fp;
    fp=fopen("UserPassword.txt","r+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }
    int i=1;//从第一个开始读入
    char c;
    UserPassword e;
    do
    {
        fscanf(fp,"%s",e.user);
        fseek(fp,1,1);
        fscanf(fp,"%s",e.password);
        fseek(fp,1,1);
        fscanf(fp,"%s",e.email);
        fseek(fp,1,1);


        ListUserInsert(U,i,e);
        i++;
        c=fgetc(fp);
        if(c!=EOF)
            fseek(fp,-1,1);
    }while(!feof(fp));
    fclose(fp);
}

void ApplyUser(ListUser *U)  ///帐号申请
{
    system("cls");
    title();
    printf("\t***账号申请***\n\n请输入帐号：");
    scanf("%s",U->str[U->len].user);
    printf("请输入密码：");
    scanf("%s",U->str[U->len].password);
    printf("请输入邮箱用以密码找回：");
    scanf("%s",U->str[U->len].email);
    U->len++;

}

int WriteinfileUser(ListUser *U)  ///账号写入文件
{
    FILE *fp;
    fp=fopen("UserPassword.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }

    void write(FILE *fp,UserPassword *e)  ///账号写入函数
    {
        fprintf(fp,"%s\t",e->user);
        fprintf(fp,"%s\t",e->password);
        fprintf(fp,"%s\t",e->email);
        fprintf(fp,"\n");
    }

    int i;
    for(i=1;i<U->len;i++)
    {
        write(fp,&U->str[i]);
    }
    fclose(fp);
    return 1;   //账号写入成功
}




void title()///界面表头
{
    printf("\n");
    printf("================================\n");
    printf("   欢迎进入学生成绩管理系统\n"     );
    printf("================================\n");
    printf("\n");
}



int Loginjudge(ListUser *U)  ///登陆及判断
{
    char user[20];
    char password[20];
    system("cls");
    title();
    printf("请输入登陆账号：\n");
    printf("               ");
    scanf("%s",user);
    printf("请输入登陆密码：\n");
    printf("               ");
    scanf("%s",password);
    char m; m=getchar();//消除回车干扰

   int i,j;
   for(i=0;i<U->len;i++)
   {
       if(strcmp(user,U->str[i].user)==0)
       {
           if(strcmp(password,U->str[i].password)==0)
                return 0;  //0登陆成功
            else return
                1;//密码错误
       }
   }
   return 2;//系统无此用户


}

int loginstate(int a)   ///登陆状态
{
    system("cls");
    title();
   if(a==0)
   {
       printf("登陆成功！\n");
       return 1;

   }
    else if(a==2)
    {
         printf("系统无此用户！\n");
         return 0;
    }


    else if(a==1)
    {
        printf("密码错误！\n");
        return 0;
    }

}

typedef struct   ///学生信息结构体
{
    char SN[15];    //学号
    char NAME[20];  //姓名
    char SEX[2];    //性别
    int scor[6];    //各科成绩
    int total;
}student;



typedef struct   ///学生信息线性表构建
{
    student stu[100];
    int len;
}List;

void ListInit(List *L)  ///线性表初始长度
{
    L->len=0;
}
/*
//第一种直接写入文件
void frecord(FILE *fp,student *rpt)
{
    fprintf(fp,"%s\t",rpt->SN);
    fprintf(fp,"%s\t",rpt->NAME);
    fprintf(fp,"%s\t",rpt->SEX);
    fprintf(fp,"%d\t",rpt->scor[0]);

    fprintf(fp,"%d\t",rpt->scor[1]);
    fprintf(fp,"%d\t",rpt->scor[2]);
    fprintf(fp,"%d\t",rpt->scor[3]);
    fprintf(fp,"%d\t",rpt->scor[4]);
    fprintf(fp,"%d",rpt->scor[5]);
    fprintf(fp,"\n");
}
*/




void ListInsert(List *L,int loc,student e) ///将元素插入线性表
{
    if(L->len>=99)
    {
        puts("List has been full.\n");
        return;
    }
    if(loc<0 || loc>L->len+1)
    {
        puts("error location.\n");
        return;
    }
    int i;
    for(i=L->len+1;i>loc;i--)
    {
        L->stu[i]=L->stu[i-1];
    }
    L->stu[loc]=e;
    L->len++;
}

void ListCreat(List *L)  ///（创建）从文件中读入数据到线性表
{
    FILE *fp;
    fp=fopen("stuf.txt","r+");    ///打开方式为r或r+!!!不可为w+
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    char c;
    int i,j;
    student e;
    i=1;//第一次的插入位置
    do
    {
        fgets(e.SN,12,fp);
        fseek(fp,1,1);
       // fscanf(fp,"%s",&e.NAME);

        fgets(e.NAME,7,fp);
        fseek(fp,1,1);
        fgets(e.SEX,3,fp);
        fseek(fp,1,1);

        e.total=0;
        for(j=0;j<6;j++)
        {
            fscanf(fp,"%d",&e.scor[j]);
            e.total+=e.scor[j];

        }

        ListInsert(L,i,e);
        i++;
        c=fgetc(fp);

        c=fgetc(fp);///防止文件结束前有\n
        if(c!=EOF)
            fseek(fp,-1,1);

    }while(!feof(fp));
    fclose(fp);
}

void ListDisplay(List *L)///遍历
{
   // system("cls");
    int i,j;
    for(i=1;i<L->len+1;i++)
    {
        printf("%d\t%s\t%s\t%s\t",i,L->stu[i].SN,L->stu[i].NAME,L->stu[i].SEX);
        for(j=0;j<6;j++)
        {
            printf("%d\t",L->stu[i].scor[j]);
        }
        printf("%d",L->stu[i].total);
        printf("\n");
    }

}

void writeinfile(List *L)  ///把线性表写入文件中
{
    FILE *fp;
    fp=fopen("stuf.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    void write(FILE *fp,student *rpt) //写入函数
    {
        fprintf(fp,"%s\t",rpt->SN);
        fprintf(fp,"%s\t",rpt->NAME);
        fprintf(fp,"%s\t",rpt->SEX);
        fprintf(fp,"%d\t",rpt->scor[0]);

        fprintf(fp,"%d\t",rpt->scor[1]);
        fprintf(fp,"%d\t",rpt->scor[2]);
        fprintf(fp,"%d\t",rpt->scor[3]);
        fprintf(fp,"%d\t",rpt->scor[4]);
        fprintf(fp,"%d",rpt->scor[5]);
        fprintf(fp,"\n");
    }

    int i;
    for(i=1;i<L->len+1;i++)//从第一个开始写入
    {
        write(fp,&L->stu[i]);
    }
    fclose(fp);
}

void addrecord(List *L)  ///增添数据
{
    //system("cls");
    //title();
	int i,n;
	printf("输入数据个数为：");
	scanf("%d",&n);
	/*动态学生结构数组*/
	student *a;
	a=(student *)malloc(sizeof(student)*n);
	if(a==0)
    {
        puts("动态学生结构数组定义出错！！！");
        exit(0);
    }

    for(i=0;i<n;i++)
	{
	    printf("请输入第%d个数据\n",i+1);
	    printf("学号（11）位：：");
            scanf("%s",a[i].SN);
	    printf("姓名：");
            scanf("%s",a[i].NAME);
	    printf("性别：");
            scanf("%s",a[i].SEX);
	    printf("高数分数：");
            scanf("%d",&a[i].scor[0]);
        printf("英语分数：");
            scanf("%d",&a[i].scor[1]);
        printf("C语言分数：");
            scanf("%d",&a[i].scor[2]);
        printf("电路分数：");
            scanf("%d",&a[i].scor[3]);
        printf("思修分数：");
            scanf("%d",&a[i].scor[4]);
        printf("体育分数：");
            scanf("%d",&a[i].scor[5]);
        printf("\n");

        ListInsert(L,1+L->len,a[i]);///此时L为形参指针类型！！！
	}
	/* for(i=1;i<n+1;i++)
    {
       ListInsert(L,i+L->len,a[i]);///此时L为形参指针类型！！！
    }*/
   // writeinfile(L);

}
 void Search(List *L)  ///信息查询，按学号
 {
     printf("1.按学号查找\n2.按姓名查找\n");

     char m; m=getchar();  ///消除回车干扰

     int c,change=0;   ///change作为判断是否查找成功
     scanf("%d",&c);

     if(c==1)
     {
         char sn[15];
         printf("请输入查找学号：");
         scanf("%s",sn);
         int i,j;
         for(i=0;i<L->len;i++)
         {
             if(strcmp(L->stu[i].SN,sn)==0)
             {
                printf("%d\t%s\t%s\t%s\t",i+1,L->stu[i].SN,L->stu[i].NAME,L->stu[i].SEX);
                for(j=0;j<6;j++)
                {
                    printf("%d\t",L->stu[i].scor[j]);
                }
                printf("%d",L->stu[i].total);
                printf("\n");
                change=1;
             }
         }
         if(change==0)
            printf("系统无此学号！");
     }
     else if(c==2)
     {
        int i,j;
        char name[20];
         printf("请输入查找姓名：");
         scanf("%s",name);
         for(i=0;i<L->len;i++)
         {
             if(strcmp(L->stu[i].NAME,name)==0)
             {
                printf("%d\t%s\t%s\t%s\t",i+1,L->stu[i].SN,L->stu[i].NAME,L->stu[i].SEX);
                for(j=0;j<6;j++)
                {
                    printf("%d\t",L->stu[i].scor[j]);
                }
                printf("%d",L->stu[i].total);
                printf("\n");
                change=1;
             }
         }
         if(change==0)
            printf("系统无此姓名！");
     }
 }

void dateinsert(List *L)  ///插入数据
{
	    student a;
	    printf("请输入所插入的数据\n");
	    printf("学号（11）位：");
            scanf("%s",a.SN);
        char m; m=getchar();//消除回车干扰
	    printf("姓名：");
	     gets(a.NAME);
            //scanf("%s",a.NAME);
	    printf("性别：");
            scanf("%s",a.SEX);
	    printf("高数分数：");
            scanf("%d",&a.scor[0]);
        printf("英语分数：");
            scanf("%d",&a.scor[1]);
        printf("C语言分数：");
            scanf("%d",&a.scor[2]);
        printf("电路分数：");
            scanf("%d",&a.scor[3]);
        printf("思修分数：");
            scanf("%d",&a.scor[4]);
        printf("体育分数：");
            scanf("%d",&a.scor[5]);
        printf("\n");
	printf("请输入所插入的位置：\n");
	char c;
	c=getchar();
	int i,n;
	scanf("%d",&i);
       ListInsert(L,i,a);//此时L为形参指针类型！！！

       //ListInsert(&L,i+L.len,a[i]);
}

void datedelete(List *L) //数据删除
{

    int n,i;
    printf("请输入删除序号：");
    scanf("%d",&n);
    for(i=n;i<L->len+1;i++)
    {
        L->stu[i]=L->stu[i+1];
    }
    L->len-=1;
    //writeinfile(L);
}

void changedate(List *L)    //数据修改
{
    int n,i;
    printf("请输入所修改数据序号：");
    scanf("%d",&n);
   student a;
	    printf("请输入修改后数据\n");
	    printf("学号：");
            scanf("%s",a.SN);
        char m; m=getchar();//消除回车干扰
	    printf("姓名：");
	     gets(a.NAME);
            //scanf("%s",a.NAME);
	    printf("性别：");
            scanf("%s",a.SEX);
	    printf("高数分数：");
            scanf("%d",&a.scor[0]);
        printf("英语分数：");
            scanf("%d",&a.scor[1]);
        printf("C语言分数：");
            scanf("%d",&a.scor[2]);
        printf("电路分数：");
            scanf("%d",&a.scor[3]);
        printf("思修分数：");
            scanf("%d",&a.scor[4]);
        printf("体育分数：");
            scanf("%d",&a.scor[5]);
        printf("\n");
        L->stu[n]=a;
}


#endif // HEAD_H_INCLUDED

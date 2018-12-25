
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct      ///�˺�����ṹ��
{
    char user[20];
    char password[20];
    char email[30];
}UserPassword;

typedef struct     ///�˺��������Ա���
{
    UserPassword str[100];
    int len;  //len��ʾ���Ա��ȣ������Ա����ж���Ԫ�أ���һ��Ԫ��Ϊstr[0];
}ListUser;



void ListUserInit(ListUser *U) ///�˺��������Ա�  ��ʼ��
{
    U->len=0;
}

void ListUserInsert(ListUser *U,int loc,UserPassword e)  ///�˺��������Ա�  ����
{
    if(U->len>=100)
    {
        printf("�������˺��Ѵ����ƣ�����"); //�˺�����ṹ������
        return;
    }

    if(loc<0||loc>U->len+1)
    {
        printf("���ִ���");//�����˺�����ṹ���λ�ô���
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

void ListUserCreat(ListUser *U)  ///  ���� ���ļ��ж������ݵ��˺��������Ա�
{
    FILE *fp;
    fp=fopen("UserPassword.txt","r+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }
    int i=1;//�ӵ�һ����ʼ����
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

void ApplyUser(ListUser *U)  ///�ʺ�����
{
    system("cls");
    title();
    printf("\t***�˺�����***\n\n�������ʺţ�");
    scanf("%s",U->str[U->len].user);
    printf("���������룺");
    scanf("%s",U->str[U->len].password);
    printf("�������������������һأ�");
    scanf("%s",U->str[U->len].email);
    U->len++;

}

int WriteinfileUser(ListUser *U)  ///�˺�д���ļ�
{
    FILE *fp;
    fp=fopen("UserPassword.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }

    void write(FILE *fp,UserPassword *e)  ///�˺�д�뺯��
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
    return 1;   //�˺�д��ɹ�
}




void title()///�����ͷ
{
    printf("\n");
    printf("================================\n");
    printf("   ��ӭ����ѧ���ɼ�����ϵͳ\n"     );
    printf("================================\n");
    printf("\n");
}



int Loginjudge(ListUser *U)  ///��½���ж�
{
    char user[20];
    char password[20];
    system("cls");
    title();
    printf("�������½�˺ţ�\n");
    printf("               ");
    scanf("%s",user);
    printf("�������½���룺\n");
    printf("               ");
    scanf("%s",password);
    char m; m=getchar();//�����س�����

   int i,j;
   for(i=0;i<U->len;i++)
   {
       if(strcmp(user,U->str[i].user)==0)
       {
           if(strcmp(password,U->str[i].password)==0)
                return 0;  //0��½�ɹ�
            else return
                1;//�������
       }
   }
   return 2;//ϵͳ�޴��û�


}

int loginstate(int a)   ///��½״̬
{
    system("cls");
    title();
   if(a==0)
   {
       printf("��½�ɹ���\n");
       return 1;

   }
    else if(a==2)
    {
         printf("ϵͳ�޴��û���\n");
         return 0;
    }


    else if(a==1)
    {
        printf("�������\n");
        return 0;
    }

}

typedef struct   ///ѧ����Ϣ�ṹ��
{
    char SN[15];    //ѧ��
    char NAME[20];  //����
    char SEX[2];    //�Ա�
    int scor[6];    //���Ƴɼ�
    int total;
}student;



typedef struct   ///ѧ����Ϣ���Ա���
{
    student stu[100];
    int len;
}List;

void ListInit(List *L)  ///���Ա��ʼ����
{
    L->len=0;
}
/*
//��һ��ֱ��д���ļ�
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




void ListInsert(List *L,int loc,student e) ///��Ԫ�ز������Ա�
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

void ListCreat(List *L)  ///�����������ļ��ж������ݵ����Ա�
{
    FILE *fp;
    fp=fopen("stuf.txt","r+");    ///�򿪷�ʽΪr��r+!!!����Ϊw+
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    char c;
    int i,j;
    student e;
    i=1;//��һ�εĲ���λ��
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

        c=fgetc(fp);///��ֹ�ļ�����ǰ��\n
        if(c!=EOF)
            fseek(fp,-1,1);

    }while(!feof(fp));
    fclose(fp);
}

void ListDisplay(List *L)///����
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

void writeinfile(List *L)  ///�����Ա�д���ļ���
{
    FILE *fp;
    fp=fopen("stuf.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    void write(FILE *fp,student *rpt) //д�뺯��
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
    for(i=1;i<L->len+1;i++)//�ӵ�һ����ʼд��
    {
        write(fp,&L->stu[i]);
    }
    fclose(fp);
}

void addrecord(List *L)  ///��������
{
    //system("cls");
    //title();
	int i,n;
	printf("�������ݸ���Ϊ��");
	scanf("%d",&n);
	/*��̬ѧ���ṹ����*/
	student *a;
	a=(student *)malloc(sizeof(student)*n);
	if(a==0)
    {
        puts("��̬ѧ���ṹ���鶨���������");
        exit(0);
    }

    for(i=0;i<n;i++)
	{
	    printf("�������%d������\n",i+1);
	    printf("ѧ�ţ�11��λ����");
            scanf("%s",a[i].SN);
	    printf("������");
            scanf("%s",a[i].NAME);
	    printf("�Ա�");
            scanf("%s",a[i].SEX);
	    printf("����������");
            scanf("%d",&a[i].scor[0]);
        printf("Ӣ�������");
            scanf("%d",&a[i].scor[1]);
        printf("C���Է�����");
            scanf("%d",&a[i].scor[2]);
        printf("��·������");
            scanf("%d",&a[i].scor[3]);
        printf("˼�޷�����");
            scanf("%d",&a[i].scor[4]);
        printf("����������");
            scanf("%d",&a[i].scor[5]);
        printf("\n");

        ListInsert(L,1+L->len,a[i]);///��ʱLΪ�β�ָ�����ͣ�����
	}
	/* for(i=1;i<n+1;i++)
    {
       ListInsert(L,i+L->len,a[i]);///��ʱLΪ�β�ָ�����ͣ�����
    }*/
   // writeinfile(L);

}
 void Search(List *L)  ///��Ϣ��ѯ����ѧ��
 {
     printf("1.��ѧ�Ų���\n2.����������\n");

     char m; m=getchar();  ///�����س�����

     int c,change=0;   ///change��Ϊ�ж��Ƿ���ҳɹ�
     scanf("%d",&c);

     if(c==1)
     {
         char sn[15];
         printf("���������ѧ�ţ�");
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
            printf("ϵͳ�޴�ѧ�ţ�");
     }
     else if(c==2)
     {
        int i,j;
        char name[20];
         printf("���������������");
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
            printf("ϵͳ�޴�������");
     }
 }

void dateinsert(List *L)  ///��������
{
	    student a;
	    printf("�����������������\n");
	    printf("ѧ�ţ�11��λ��");
            scanf("%s",a.SN);
        char m; m=getchar();//�����س�����
	    printf("������");
	     gets(a.NAME);
            //scanf("%s",a.NAME);
	    printf("�Ա�");
            scanf("%s",a.SEX);
	    printf("����������");
            scanf("%d",&a.scor[0]);
        printf("Ӣ�������");
            scanf("%d",&a.scor[1]);
        printf("C���Է�����");
            scanf("%d",&a.scor[2]);
        printf("��·������");
            scanf("%d",&a.scor[3]);
        printf("˼�޷�����");
            scanf("%d",&a.scor[4]);
        printf("����������");
            scanf("%d",&a.scor[5]);
        printf("\n");
	printf("�������������λ�ã�\n");
	char c;
	c=getchar();
	int i,n;
	scanf("%d",&i);
       ListInsert(L,i,a);//��ʱLΪ�β�ָ�����ͣ�����

       //ListInsert(&L,i+L.len,a[i]);
}

void datedelete(List *L) //����ɾ��
{

    int n,i;
    printf("������ɾ����ţ�");
    scanf("%d",&n);
    for(i=n;i<L->len+1;i++)
    {
        L->stu[i]=L->stu[i+1];
    }
    L->len-=1;
    //writeinfile(L);
}

void changedate(List *L)    //�����޸�
{
    int n,i;
    printf("���������޸�������ţ�");
    scanf("%d",&n);
   student a;
	    printf("�������޸ĺ�����\n");
	    printf("ѧ�ţ�");
            scanf("%s",a.SN);
        char m; m=getchar();//�����س�����
	    printf("������");
	     gets(a.NAME);
            //scanf("%s",a.NAME);
	    printf("�Ա�");
            scanf("%s",a.SEX);
	    printf("����������");
            scanf("%d",&a.scor[0]);
        printf("Ӣ�������");
            scanf("%d",&a.scor[1]);
        printf("C���Է�����");
            scanf("%d",&a.scor[2]);
        printf("��·������");
            scanf("%d",&a.scor[3]);
        printf("˼�޷�����");
            scanf("%d",&a.scor[4]);
        printf("����������");
            scanf("%d",&a.scor[5]);
        printf("\n");
        L->stu[n]=a;
}


#endif // HEAD_H_INCLUDED

# README
该存储库用于存储C语言编写的简单学生成绩管理系统
****
### Author:e云竹
### E-mail：eyunzhu@foxmail.com
### 个人博客：http://blog.csdn.net/eyunzhu
### 个人网站：www.eyunzhu.com
### QQ:1036795373

#### 主要功能
* 系统登陆
	* 操作
		* 数据输入 
		* 数据输出
		* 信息查询
		* 数据查入
		* 数据删除
		* 数据修改
		* 退出系统
	
#### 实现
* 登陆
	* 账号结构体
	*  账号线性表
	
```C
typedef struct      ///账号密码结构体
{
    char user[20];
    char password[20];
    char email[30];
}UserPassword;

typedef struct     ///账号密码线性表构建
{
    UserPassword str[100];
    int len;  //len表示线性表长度，即线性表中有多少元素！
}ListUser;
```
* 学生信息
	* 学生信息结构体
```C
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
```
操作实现（主要函数）
```C
void ListUserCreat(ListUser *U)  ///创建 从文件中读入数据到账号密码线性表
void ApplyUser(ListUser *U)      ///帐号申请
int Loginjudge(ListUser *U)      ///登陆及判断
void ListCreat(List *L)         ///(创建）从文件中读入数据到线性表
void ListDisplay(List *L)       ///遍历
void addrecord(List *L)         ///增添数据
void Search(List *L)           ///信息查询
```
	 

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

typedef struct {
  char key[15];
  char name[20];
  int age;
} DATA;

typedef struct // 定义顺序表结构
{
  DATA ListData[MAXSIZE + 1]; // 保存顺序的数值
  int ListLen;
} SeqListType;

/*  定义顺序表的操作 */
void SeqListInit(SeqListType *SL);
int SeqListLength(SeqListType *SL);         // 返回顺序表的元素数量
int SeqListAdd(SeqListType *SL, DATA data); // 向顺序表中添加元素
int SeqListInsert(SeqListType *SL, int n, DATA data); // 向顺序表中插入元素
int SeqListDelete(SeqListType *SL, int n); // 删除顺序表中的数据元素
DATA *SeqListFindByNum(SeqListType *SL, int n); // 根据序号返回元素
int SeqListFindByContent(SeqListType *SL, char *key); // 按关键字查找

void SeqListAll(SeqListType *SL); // 遍历顺序表中的内容

void SeqListInit(SeqListType *SL) // 初始化顺序表
{
  SL->ListLen = 0; // 初始化时，设置顺序表长度为 0
}

int SeqListLength(SeqListType *SL) {
  return (SL->ListLen); // 返回顺序表的长度
}
int SeqListAdd(SeqListType *SL, DATA data) // 增加节点到顺序表尾部
{
  if (SL->ListLen >= MAXSIZE) {
    printf("顺序表已满, 不能添加结点了\n");
    return 1; // 返回1 插入失败
  }
  SL->ListData[++SL->ListLen] = data;
  return 0;
}

int SeqListInsert(SeqListType *SL, int n, DATA data) // 向顺序表中插入元素
{
  int i;
  if (SL->ListLen >= MAXSIZE) {
    printf("顺序表表已满，不能插入节点！\n");
    return 1;
  }
  if (n < 1 || n > SL->ListLen - 1) // 序号不正确
  {
    printf("插入节点序号错误，不能插入元素！\n");
    return 2;
  }
  for (i = SL->ListLen; i >= n; i--) // 将顺序表中的数据向后移动
    SL->ListData[i + 1] = SL->ListData[i];
  SL->ListData[n] = data; // 插入节点
  SL->ListLen++;          // 顺序表节点数量增加1
  return 0;               // 返回1，表示成功插入
}

int SeqListDelete(SeqListType *SL, int n) {
  int i;
  if (n < 1 || n > SL->ListLen + 1) {
    printf("删除节点序号错误，不能删除节点！\n");
    return 1; //  返值为0 表示删除不成功
  }
  for (i = n; i < SL->ListLen; i++) {
    SL->ListData[i] = SL->ListData[i];
  }
  SL->ListLen--;
  return 0;
}

DATA *SeqListFindByNum(SeqListType *SL, int n) // 根据序号返回数据元素
{
  if (n < 1 || n > SL->ListLen + 1) {
    printf("节点序号错误，不能返回节点！\n");
    return NULL;
  }
  return &(SL->ListData[n]);
}

int SeqListFindByContent(SeqListType *SL, char *key) {
  int i;
  for (i = 1; i <= SL->ListLen; i++)
    if (strcmp(SL->ListData[i].key, key) == 0)
      return i;
  return -1; // 遍历后未找到，返回0
}
void SeqListAll(SeqListType *SL) {
  int i;
  for (i = 1; i < SL->ListLen; i++) {
    printf("(%s,%s,%d)\n", SL->ListData[i].key, SL->ListData[i].name,
           SL->ListData[i].age);
  }
}

int main() {

  int i;
  SeqListType SL; // 定义顺序表变量
  DATA data, *data1;
  char key[15];

  SeqListInit(&SL); // 初始化顺序表

  // do {
  //   printf("输入添加节点: ");
  //   fflush(stdin); // 清空输入缓冲区
  //   scanf("%s %s %d", data.key, data.name, &data.age);
  //   if (data.age) {                   // 年龄不为 0
  //     if (SeqListAdd(&SL, data) != 0) // 添加失败
  //       break;
  //   } else {
  //     break;
  //   }
  // } while (1);

  data.key = "1";
  data.name = 'aaa';
  &data.age = 15;

  SeqListAdd(&SL, data);
  //   data.key ="2";
  // data.name ='bbb';
  // data.age =17;
  //   SeqListAdd(&SL,data);
  // SeqListAdd(&SL, '3','ccc',19);

  printf("\n顺序表中的节点顺序是: \n");
  SeqListAll(&SL); // 显示所有节点数据

  fflush(stdin);

  printf("\n 输入要取出节点的序号");

  scanf("%d", &i);

  data1 = SeqListFindByNum(&SL, i);

  if (data1) {
    printf("第%d个元素是:(%s,%s,%d)", i, data1->key, data1->name, data1->age);
  }

  fflush(stdin);
  printf("\n 输入要取出关键字：");

  scanf("%s", key);
  i = SeqListFindByContent(&SL, key);

  data1 = SeqListFindByNum(&SL, i);
  if (data1) {

    printf("第%d个元素是:(%s,%s,%d)", i, data1->name, data1->key, data1->age);
  }

  // getch();

  return 0;
}
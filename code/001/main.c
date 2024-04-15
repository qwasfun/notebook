#include <stdio.h>
#include <string.h>

void convto(char *s, int n, int b) { // 函数声明
  char bit[] = {"0123456789ABCDEF"};
  int len; // 声明变量
  if (n == 0) {
    strcpy(s, ""); // 字符串复制
    return;
  }
  convto(s, n / b, b); // 递归
  len = strlen(s);     // 获取字符串长度
  printf("%s\n", s);
  s[len] = bit[n % b];
  s[len + 1] = '\0';
}

void main(void) { // 主函数
  char s[80];
  int i, base, old;
  printf("请输入十进制数：");
  scanf("%d", &old);
  printf("请输入转换的进制：");
  scanf("%d", &base);
  convto(s, old, base); // 对数制转换
  printf("%s\n", s);
  getchar();
  return;
}

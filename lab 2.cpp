#include <stdio.h>
#include<malloc.h>

typedef struct STUDENT
{
	long long num;//学号
	char name[50];//名字
	char sex[10];//性别
	int english;//英语
	int pc;//计算机
	int math;//高数
	int sum;//总分
	double avg;//平均分
}student;

typedef struct LinkNode {
	student Data;
	struct LinkNode* next;
}LNode;//建立单链表

void Main_menu() {
	printf("\n\t\t\t\t学生信息管理系统\n");
	printf("\t1.显示学生信息\n");
	printf("\t2.查找学生信息\n");
	printf("\t3.修改学生信息\n");
	printf("\t4.添加学生信息\n");
	printf("\t请选择（1-4）：");
}//输出主菜单

void Show_Header(int f) {
	if (f) {
		printf("\n序号\t学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");//输出带序号的表头
	}
	else {
		printf("\n学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");//输出不带序号的表头
	}
}

void Update_Menu() {
	printf("\n\t1.姓名\n");
	printf("\t2.性别\n");
	printf("\t3.英语\n");
	printf("\t4.计算机\n");
	printf("\t5.高数\n");
}//输出修改列表

void InputStu_wwl(LNode *&L) {
	student stu;
	scanf_s("%lld", &stu.num);
	getchar();
	scanf_s("%s", stu.name, 20);
	getchar();
	scanf_s("%s", stu.sex, 10);
	scanf_s("%d", &stu.english);
	scanf_s("%d", &stu.pc);
	scanf_s("%d", &stu.math);
	stu.sum = stu.english + stu.pc + stu.math;
	stu.avg = (double)stu.sum / 3.0;
	L->Data = stu;
}//录入学生的信息

void OutputStu_wwl(LNode* L) {
	if (L != NULL) {
		printf("%lld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", L->Data.num, L->Data.name, L->Data.sex, L->Data.english, L->Data.pc, L->Data.math, L->Data.sum, L->Data.avg);
	}
}//输出信息

LNode* SearchStu_wwl(LNode* head, long long num) {
	LNode* p = head->next;
	do {
		if (p->Data.num == num)
			return p;
		p = p->next;
	} while (p != NULL);
	printf("\n该学生的信息不存在，查找失败\n");
	return NULL;
}//查询信息

void UpdataStu_wwl(LNode* head,long long num) {
	int a = 0, F = 1, f = 1;
	for (LNode* p = head; p != NULL; p = p->next) {
		if (p->Data.num == num) {
			Show_Header(0);
			OutputStu_wwl(p);
			while (F) {
				Update_Menu();
				scanf_s("%d", &a);
				switch (a) {
				case 1:printf("请输入修改后的信息:");
					F = 0; char str1[50];//创建备份防止原信息被破坏
					while (f) {
						if (!scanf_s("%s", str1, 50)) {
							while (getchar() != '\n');//清空输入缓存区
							printf("\n请勿输入过长的名字\n");
						}
						else {
							for (int j = 0; j < 50; j++) {
								p->Data.name[j] = str1[j];
							}
							f = 0;
						}
					}
					break;
				case 2:printf("请输入修改后的信息:");
					F = 0; char str2[10];//创建备份防止原信息被破坏
					while (f) {
						if (!scanf_s("%s", str2, 10)) {
							while (getchar() != '\n');//清空输入缓存区
							printf("\n请输入人类有的性别\n");
						}
						else {
							for (int j = 0; j < 10; j++) {
								p->Data.name[j] = str2[j];
							}
							f = 0;
						}
					}
					break;
				case 3:printf("请输入修改后的信息:");
					scanf_s("%d", &p->Data.english);
					p->Data.sum = p->Data.english + p->Data.pc + p->Data.math;
					p->Data.avg = (double)p->Data.sum / 3.0;
					f = 0;
					break;
				case 4:printf("请输入修改后的信息:");
					scanf_s("%d", &p->Data.pc);
					p->Data.sum = p->Data.english + p->Data.pc + p->Data.math;
					p->Data.avg = (double)p->Data.sum / 3.0;
					f = 0;
					break;
				case 5:printf("请输入修改后的信息:");
					scanf_s("%d", &p->Data.math);
					p->Data.sum = p->Data.english + p->Data.pc + p->Data.math;
					p->Data.avg = (double)p->Data.sum / 3.0;
					f = 0;
					break;
				default:
					printf("\n请选择有的功能哦\n");
				}
			}
			Show_Header(0);
			OutputStu_wwl(p);
			return;
		}
	}
	printf("\n该生的信息不存在，修改失败\n");
}//通过学号，修改学生指定信息

	void AppendStu_wwl(LNode * &L) {
		InputStu_wwl(L);
	}//增加新学生

	int main() {
		int n = 0, N, f = 0;
		long long x = 0;
		LNode* L = nullptr;
		L = (LNode*)malloc(sizeof(LNode));
		LNode* s = nullptr, * r = L;
		do {
			printf("请输入学生记录个数n=");
			scanf_s("%d", &n);
			if (0 < n && n <= 100) {
				f = 0;
				printf("\n请输入学生信息：\n");
				for (int i = 0;i < n;i++) {
					s = (LNode*)malloc(sizeof(LNode));
					InputStu_wwl(s);
					r->next = s;
					r = s;
					while (getchar() != '\n');
				}
				r->next = NULL;
			}
			else {
				while (getchar() != '\n');
				printf("\n请正确输入学生总数以启动系统（至少1人，最多100人）\n");
				f = 1;
			}
		} while (f);

		while (1) {
			Main_menu();
			int i = 0;
			scanf_s("%d", &N);
			switch (N)
			{
			case 1://显示学生信息
				i = 0;
				Show_Header(1);
				for (LNode* pi = L->next; pi != NULL; pi = pi->next) {
					printf("%d\t", ++i);
					OutputStu_wwl(pi);
				}
				break;
			case 2://查找学生
				while (getchar() != '\n');//清空输入缓存区
				printf("请输入待查找的学号：");
				long long x;
				scanf_s("%lld", &x);
				OutputStu_wwl(SearchStu_wwl(L, x));
				break;
				
			case 3://修改学生信息
				while (getchar() != '\n');
				printf("请输入要修改记录的学号：");
				scanf_s("%lld", &x);
				UpdataStu_wwl(L, x);
				break;
			case 4://添加学生信息
				while (getchar() != '\n');
				if (n < 100) {
					printf("请输入学生信息：");
					s = (LNode*)malloc(sizeof(LNode));
					AppendStu_wwl(s);
					r->next = s;
					r = s;
					r->next = NULL;
				}
				else printf("已达学生人数上限");
				break;
			default:printf("\n请选择（1-4）");
				while (getchar() != '\n');
				break;
			}
		}
		return 0;
	}
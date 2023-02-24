#include <stdio.h>
#include<malloc.h>

typedef struct STUDENT
{
	long long num;//ѧ��
	char name[50];//����
	char sex[10];//�Ա�
	int english;//Ӣ��
	int pc;//�����
	int math;//����
	int sum;//�ܷ�
	double avg;//ƽ����
}student;

typedef struct LinkNode {
	student Data;
	struct LinkNode* next;
}LNode;//����������

void Main_menu() {
	printf("\n\t\t\t\tѧ����Ϣ����ϵͳ\n");
	printf("\t1.��ʾѧ����Ϣ\n");
	printf("\t2.����ѧ����Ϣ\n");
	printf("\t3.�޸�ѧ����Ϣ\n");
	printf("\t4.���ѧ����Ϣ\n");
	printf("\t��ѡ��1-4����");
}//������˵�

void Show_Header(int f) {
	if (f) {
		printf("\n���\tѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");//�������ŵı�ͷ
	}
	else {
		printf("\nѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");//���������ŵı�ͷ
	}
}

void Update_Menu() {
	printf("\n\t1.����\n");
	printf("\t2.�Ա�\n");
	printf("\t3.Ӣ��\n");
	printf("\t4.�����\n");
	printf("\t5.����\n");
}//����޸��б�

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
}//¼��ѧ������Ϣ

void OutputStu_wwl(LNode* L) {
	if (L != NULL) {
		printf("%lld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", L->Data.num, L->Data.name, L->Data.sex, L->Data.english, L->Data.pc, L->Data.math, L->Data.sum, L->Data.avg);
	}
}//�����Ϣ

LNode* SearchStu_wwl(LNode* head, long long num) {
	LNode* p = head->next;
	do {
		if (p->Data.num == num)
			return p;
		p = p->next;
	} while (p != NULL);
	printf("\n��ѧ������Ϣ�����ڣ�����ʧ��\n");
	return NULL;
}//��ѯ��Ϣ

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
				case 1:printf("�������޸ĺ����Ϣ:");
					F = 0; char str1[50];//�������ݷ�ֹԭ��Ϣ���ƻ�
					while (f) {
						if (!scanf_s("%s", str1, 50)) {
							while (getchar() != '\n');//������뻺����
							printf("\n�����������������\n");
						}
						else {
							for (int j = 0; j < 50; j++) {
								p->Data.name[j] = str1[j];
							}
							f = 0;
						}
					}
					break;
				case 2:printf("�������޸ĺ����Ϣ:");
					F = 0; char str2[10];//�������ݷ�ֹԭ��Ϣ���ƻ�
					while (f) {
						if (!scanf_s("%s", str2, 10)) {
							while (getchar() != '\n');//������뻺����
							printf("\n�����������е��Ա�\n");
						}
						else {
							for (int j = 0; j < 10; j++) {
								p->Data.name[j] = str2[j];
							}
							f = 0;
						}
					}
					break;
				case 3:printf("�������޸ĺ����Ϣ:");
					scanf_s("%d", &p->Data.english);
					p->Data.sum = p->Data.english + p->Data.pc + p->Data.math;
					p->Data.avg = (double)p->Data.sum / 3.0;
					f = 0;
					break;
				case 4:printf("�������޸ĺ����Ϣ:");
					scanf_s("%d", &p->Data.pc);
					p->Data.sum = p->Data.english + p->Data.pc + p->Data.math;
					p->Data.avg = (double)p->Data.sum / 3.0;
					f = 0;
					break;
				case 5:printf("�������޸ĺ����Ϣ:");
					scanf_s("%d", &p->Data.math);
					p->Data.sum = p->Data.english + p->Data.pc + p->Data.math;
					p->Data.avg = (double)p->Data.sum / 3.0;
					f = 0;
					break;
				default:
					printf("\n��ѡ���еĹ���Ŷ\n");
				}
			}
			Show_Header(0);
			OutputStu_wwl(p);
			return;
		}
	}
	printf("\n��������Ϣ�����ڣ��޸�ʧ��\n");
}//ͨ��ѧ�ţ��޸�ѧ��ָ����Ϣ

	void AppendStu_wwl(LNode * &L) {
		InputStu_wwl(L);
	}//������ѧ��

	int main() {
		int n = 0, N, f = 0;
		long long x = 0;
		LNode* L = nullptr;
		L = (LNode*)malloc(sizeof(LNode));
		LNode* s = nullptr, * r = L;
		do {
			printf("������ѧ����¼����n=");
			scanf_s("%d", &n);
			if (0 < n && n <= 100) {
				f = 0;
				printf("\n������ѧ����Ϣ��\n");
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
				printf("\n����ȷ����ѧ������������ϵͳ������1�ˣ����100�ˣ�\n");
				f = 1;
			}
		} while (f);

		while (1) {
			Main_menu();
			int i = 0;
			scanf_s("%d", &N);
			switch (N)
			{
			case 1://��ʾѧ����Ϣ
				i = 0;
				Show_Header(1);
				for (LNode* pi = L->next; pi != NULL; pi = pi->next) {
					printf("%d\t", ++i);
					OutputStu_wwl(pi);
				}
				break;
			case 2://����ѧ��
				while (getchar() != '\n');//������뻺����
				printf("����������ҵ�ѧ�ţ�");
				long long x;
				scanf_s("%lld", &x);
				OutputStu_wwl(SearchStu_wwl(L, x));
				break;
				
			case 3://�޸�ѧ����Ϣ
				while (getchar() != '\n');
				printf("������Ҫ�޸ļ�¼��ѧ�ţ�");
				scanf_s("%lld", &x);
				UpdataStu_wwl(L, x);
				break;
			case 4://���ѧ����Ϣ
				while (getchar() != '\n');
				if (n < 100) {
					printf("������ѧ����Ϣ��");
					s = (LNode*)malloc(sizeof(LNode));
					AppendStu_wwl(s);
					r->next = s;
					r = s;
					r->next = NULL;
				}
				else printf("�Ѵ�ѧ����������");
				break;
			default:printf("\n��ѡ��1-4��");
				while (getchar() != '\n');
				break;
			}
		}
		return 0;
	}
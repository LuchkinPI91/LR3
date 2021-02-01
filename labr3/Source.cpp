#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <clocale>
#include <malloc.h>
#include <string>
#include <algorithm>
#define M 20
#define N 30
size_t remove_ch(char* s, char ch)           //������� �������� ������������ ��������
{
	size_t i, j;

	j = 0;

	for (i = 0; s[i]; ++i)
		if (s[i] != ch)
			s[j++] = s[i];

	s[j] = '\0';

	return j;
}
class students {
public:
	void input(char student_last_name[N][M],int grn[N],float avg1[N],float avg2[N],int n) {
	
		for (int i = 0;i < n;i++) {
			remove_ch(student_last_name[i], '\n');
			strcpy(last_name[i], student_last_name[i]);
			group[i] = grn[i];
			avg_ball1[i] = avg1[i];
			avg_ball2[i] = avg2[i];
		
		
		}
	
	}

	void output(int n) {
		for (int i = 0;i < n;i++) {
		
			printf(" %s | %d | %0.2f | %0.2f \n", last_name[i],group[i],avg_ball1[i],avg_ball2[i]);
		
		}
	
	
	
	}
	void sort(int n) {
		char ln[M];
		int* g = new int();
		float* a1 = new float();
		float* a2 = new float();
		for (int i = 0;i < n-1;i++) {
			for(int j=n-1;j>i;j--)
			if (group[j-1] < group[j]) {
				strcpy(ln, last_name[j - 1]);
				last_name[j - 1][0] = '\0';
				strcpy(last_name[j - 1], last_name[j]);
				last_name[j][0] = '\0';
				strcpy(last_name[j], ln);
				ln[0] = '\0';


				*g = group[j - 1];
				group[j - 1] = group[j];
				group[j] = *g;

				*a1 = avg_ball1[j - 1];
				avg_ball1[j - 1] = avg_ball1[j];
				avg_ball1[j] = *a1;

				*a2 = avg_ball2[j - 1];
				avg_ball2[j - 1] = avg_ball2[j];
				avg_ball2[j] = *a2;



			}


		}
		
		delete g;
		delete a1;
		delete a2;
	
	}

	void zadanie(int n) {
		printf("��������, � ������� ������ �� 2 ������� ����, ��� �� ������\n");
		for (int i = 0;i < n;i++) {
			if (avg_ball2[i] < avg_ball1[i]) {

				printf("%s\n", last_name[i]);

			}

		}
	}

	void sumofballs(int n) {
	
		float sum1=0;
		float sum2=0;

		for (int i = 0;i < n;i++) {
		
			sum1 += avg_ball1[i];
		
			sum2 += avg_ball2[i];
		}
	
		printf("����� ������ �� 1 �������:%f", sum1);
		printf("����� ������ �� 2 �������:%f", sum2);

	}

private:
	char last_name[N][M];// ������� ��������
	int group[N];//����� ������ ��������
	float avg_ball1[N];//������� ���� �� 1 �������
	float avg_ball2[N];//������� ���� �� 2 �������
};



int _tmain() {
	char Ln[N][M];
	int n;
	float* avgb1=new float[N];
	
	setlocale(LC_ALL, "russian");
	printf("������� ���-�� ����������:");
	do {
		scanf("%d", &n);
		
		if ( n<0 || n>30)
		{
			printf("���-�� ���������� ������ ���� ������ 30, �� �������� 1!\n");
		}
	
	} while (n<0 || n>30);
	float* avgb2 = (float*)calloc(n, sizeof(float));
	int* groupn = (int*)malloc(n * sizeof(int));
	for (int i=0;i < n;i++) {
		while (getchar() != '\n');
		printf("������� �������:");
		fgets(Ln[i],19,stdin);
		printf("������� ����� ������:");
		scanf("%d", &groupn[i]);
		while (getchar() != '\n');
		printf("������� ������� ���� �� 1 �������:");
		scanf("%f", &avgb1[i]);
		while (getchar() != '\n');
		printf("������� ������� ���� �� 2 �������:");
		scanf("%f", &avgb2[i]);
	
	}
	students* student=new students();
	student->input(Ln, groupn,avgb1, avgb2, n);
	printf("�� ����������:\n");
	student->output(n);
	student->sort(n);
	printf("����� ����������:\n");
	student->output(n);
	student->zadanie(n);
	student->sumofballs(n);
	delete[] avgb1;
	free(groupn);
	free(avgb2);
	return 0;
}
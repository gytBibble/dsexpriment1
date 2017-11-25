/* Linear Table On Sequence Structure */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/*--------------------page 10 on textbook ----------------------------------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

/*--------------------page 22 on textbook ----------------------------------*/
#define LIST_INIT_SIZE 100   //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10    //���Ա�洢�ռ�ķ�������
typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType * elem;     //�洢�ռ��ַ
	int length;          //��ǰ����
	int listsize;        //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;
/*--------------------page 19 on textbook ----------------------------------*/
status IntiaList(SqList & L);
status DestroyList(SqList & L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e); //�򻯹�
status PriorElem(SqList L,ElemType cur_e,ElemType & pre_e);
status NextElem(SqList L,ElemType cur_e,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);
status ListDelete(SqList & L, int i, ElemType & e);
status ListTrabverse(SqList L);  //�򻯹�
status Load_data(SqList &L);
status Save_data(SqList L);
/*------------------------------------------------------*/


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
typedef int ElemType; //数据元素类型定义

/*--------------------page 22 on textbook ----------------------------------*/
#define LIST_INIT_SIZE 100   //线性表存储空间的初始分配量
#define LISTINCREMENT  10    //线性表存储空间的分配增量
typedef struct {  //顺序表（顺序结构）的定义
	ElemType * elem;     //存储空间基址
	int length;          //当前长度
	int listsize;        //当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;
/*--------------------page 19 on textbook ----------------------------------*/
status IntiaList(SqList & L);
status DestroyList(SqList & L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e); //简化过
status PriorElem(SqList L,ElemType cur_e,ElemType & pre_e);
status NextElem(SqList L,ElemType cur_e,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);
status ListDelete(SqList & L, int i, ElemType & e);
status ListTrabverse(SqList L);  //简化过
status Load_data(SqList &L);
status Save_data(SqList L);
/*------------------------------------------------------*/


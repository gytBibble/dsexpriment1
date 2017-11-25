#include"slist.h"
void main(void) {
	SqList L;
	IntiaList(L);
	int op = 1;
	while (op) {
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty      10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem        12. ListTrabverse\n");
		printf("    	 13. Load_data      14. Save_data\n");
		printf("    	  0. Exit\n");
		printf("------------------------------------------------------\n");
		printf("    请选择你的操作[0~14]:");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			if (IntiaList(L) == OK) printf("线性表创建成功！\n");
			else printf("线性表创建失败！\n");
			getchar(); getchar();
			break;
		case 2:
			if (L.elem != NULL)
			{
				if (DestroyList(L) == OK) printf("线性表销毁成功！\n");
				else printf("线性表销毁失败！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 3:
			if (L.elem != NULL)
			{
				if (ClearList(L) == OK) printf("线性表清空成功！\n");
				else printf("线性表清空失败！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 4:
			if (L.elem != NULL)
			{
				if (ListEmpty(L) == TRUE) printf("该表为空表！\n");
				else printf("该表不为空！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 5:
			if (L.elem != NULL)
			{
				int i = 0;
				i = ListLength(L);
				printf("该表的长度为 %d\n",i);
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 6:
			if (L.elem != NULL)
			{
				int i = 0;
				ElemType e = 0;
				printf("请输入你想知道第几个元素的值：\n");
				scanf_s("%d", &i);
				if (GetElem(L, i, e) == OK) printf("该表中第%d个元素为%d!\n", i, e);
				else printf("输入错误，该表没有第%d个元素！\n",i);
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 7:
			if (L.elem != NULL)
			{
				ElemType x = 0;
				printf("请输入你想查找的元素：\n");
				scanf_s("%d", &x);
				int i = LocateElem(L, x);
				if (i!=0) printf("该元素存在，且在该表中为第%d位！\n",i);
				else printf("该元素在此表中不存在！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 8:
			if (L.elem != NULL)
			{
				ElemType pre_e = 0, cur_e = 0;
				printf("请输入你想要获得前驱的元素：\n");
				scanf_s("%d", &cur_e);
				if (PriorElem(L, cur_e, pre_e) == OK) printf("前驱元素为%d\n", pre_e);
				else printf("请重新输入！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 9:
			if (L.elem != NULL)
			{
				ElemType cur_e = 0, next_e = 0;
				printf("请输入你想要获得后继的元素：\n");
				scanf_s("%d", &cur_e);
				if (NextElem(L, cur_e, next_e) == OK) printf("后继元素为%d\n", next_e);
				else printf("请重新输入！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 10:
			if (L.elem != NULL)
			{
				int i = 0;
				ElemType e = 0;
				printf("请输入你想要插入元素的位置：\n");
				scanf_s("%d", &i);
				printf("请输入你想要插入的元素：\n");
				scanf_s("%d", &e);
				if (ListInsert(L, i, e) == OK) printf("插入成功！\n");
				else printf("插入失败！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 11:
			if (L.elem != NULL)
			{
				if (L.length != 0) {
					int i = 0;
					ElemType e = 0;
					printf("请输入你想要删除的元素的位置：\n");
					scanf_s("%d", &i);
					if (ListDelete(L, i, e) == OK) printf("删除成功，且删除的元素为%d！\n", e);
					else printf("删除失败！\n");
				}
				else printf("该表为空表！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 12:
			if (L.elem != NULL)
			{
				if (!ListTrabverse(L)) printf("线性表是空表！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 13:
			if (Load_data(L) == OK)printf("文件数据加载成功！\n");
			else printf("文件数据加载失败！\n");
			getchar(); getchar();
			break;
		case 14:
			if (Save_data(L) == OK)printf("文件数据保存成功！\n");
			else printf("文件数据保存失败！\n");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()
status IntiaList(SqList & L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
status DestroyList(SqList & L)
{
	free(L.elem);
	return OK;
}
status ClearList(SqList &L)
{
	L.length = 0;
	return OK;
}
status ListEmpty(SqList L)
{
	if (L.length == 0) return TRUE;
	return FALSE;
}
int ListLength(SqList L)
{
	return L.length;
}
status GetElem(SqList L, int i, ElemType & e)
{
	if ((i < 1) || (i > L.length)) return ERROR;
	e = L.elem[i-1];
	return OK;
}
status LocateElem(SqList L, ElemType e)
{
	int i=0;
	while ( i < L.length)
		if (L.elem[i++]== e)return i;
	return 0;
}
status PriorElem(SqList L, ElemType cur_e, ElemType & pre_e)
{
	int i;
	i = LocateElem(L,cur_e);
	if (i == 0 || i == 1)return ERROR;
	pre_e = L.elem[i - 2];
	return OK;
}
status NextElem(SqList L, ElemType cur_e, ElemType & next_e)
{
	int i;
	i = LocateElem(L, cur_e);
	if (i == 0 || i == L.length)return ERROR;
	next_e = L.elem[i];
	return OK;
}
status ListInsert(SqList & L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length+1)) return ERROR;
	ElemType *newbase,*q,*p;
	int j;
	if (L.length >= L.listsize)
	{//当前存储空间已满，增加分配
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}
status ListDelete(SqList & L, int i, ElemType & e)
{
	ElemType *newbase, *q, *p;
	if ((i < 1) || (i > L.length)) return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)*(p - 1) = *p;
	--L.length;
	return OK;
}
status ListTrabverse(SqList L) {
	int i;
	printf("\n-------------------- all elements ------------------------------\n");
	for (i = 0; i<L.length; i++) printf("%d ", L.elem[i]);
	printf("\n------------------------- end ----------------------------------\n");
	return L.length;
}
status Load_data(SqList &L)
{
	FILE *fp;	
	char fname[30];
	L.length = 0;
	strcpy(fname, "buffer.txt");
	if ((fp = fopen(fname, "r")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	while (fread(&L.elem[L.length], sizeof(ElemType), 1, fp))
		L.length++;
	fclose(fp);
	return TRUE;
}
status Save_data(SqList L)
{
	FILE *fp;
	char fname[30];
	strcpy(fname, "buffer.txt");
	if ((fp = fopen(fname, "w")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	fwrite(L.elem, sizeof(ElemType), L.length, fp);
	fclose(fp);
	return OK;
}


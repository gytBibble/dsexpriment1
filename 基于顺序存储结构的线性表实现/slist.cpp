#include"slist.h"
void main(void) {
	SqList L;
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
		printf("    	  0. Exit\n");
		printf("------------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~12]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiaList���ܴ�ʵ�֣�\n");
			if (IntiaList(L) == OK) printf("���Ա����ɹ���\n");
			else printf("���Ա���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2:
			printf("\n----DestroyList���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 3:
			printf("\n----ClearList���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 4:
			printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 5:
			printf("\n----ListLength���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 6:
			printf("\n----GetElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 7:
			printf("\n----LocateElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 8:
			printf("\n----PriorElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 9:
			printf("\n----NextElem���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 10:
			printf("\n----ListInsert���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 11:
			printf("\n----ListDelete���ܴ�ʵ�֣�\n");
			getchar(); getchar();
			break;
		case 12:
			//printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");     
			if (!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
	if (L.length == 0) return OK;
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
	int i;
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
	{//��ǰ�洢�ռ����������ӷ���
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


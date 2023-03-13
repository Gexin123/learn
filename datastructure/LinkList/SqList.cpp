//���Ա��˳��洢�ṹ
//������洢˳���
#define MAXSIZE 20
typedef int ElemType;
//����˳��洢�Ľṹ
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
//��ȡԪ�صĲ���
ElemType GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return 0;
	*e = L.data[i - 1];
	return 1;
}
// ����
int ListInsert(SqList &L, int i, ElemType e)
{
	int k;
	if (L.length == MAXSIZE)
		return 0;
	if (i<1 || i>L.length + 1)
		return 0;
	if (i <= L.length) {
		for (k = L.length - 1; k >= i - 1; k--)
			L.data[k + 1] = L.data[k];
	}
	L.data[i - 1] = e;
	L.length++;
	return 1;
}
//ɾ��
int ListDelete(SqList& L, int i, ElemType *e)
{
	
	if (i<1 || i>L.length)
		return 0;
	*e = L.data[i - 1];
	if (i < L.length)
	{
		for (int k = i; k < L.length; k++) {
			L.data[k - 1] = L.data[k];
		}
	}
	L.length--;
	return 1;
}
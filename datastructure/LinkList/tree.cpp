//����˫�ױ�ʾ�����ṹ����
#define MAX_TREE_SIZE 100
typedef int ElemType;
typedef struct PtNode
{
	ElemType data;
	int parent;
}PtNode;
typedef struct
{
	PtNode nodes[MAX_TREE_SIZE];
	int r, n;//����λ�úͽ����
}PTree;

//���ӱ�ʾ��
//���ӽ��
typedef struct CTNode
{
	int child;
	struct CTNode* next;
}ChilePtr;
//��ͷ�ṹ
typedef struct
{
	ElemType data;
	ChilePtr firstchild;
}CTbox;
//���ṹ
typedef struct
{
	CTbox nodes[MAX_TREE_SIZE];
	int r, n;//����λ�úͽ����
}CTree;
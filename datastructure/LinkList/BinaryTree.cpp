#include <queue>
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T>* leftChild, * rightChild;
	BinTreeNode() : leftChild(NULL), rightChild(NULL) {}                                                           //�޲ι��캯��
	BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL) : data(x), leftChild(l), rightChild(r) {} //�вι��캯��
};

//��������������
template <typename T>
class BinaryTree
{
public:
    //���캯��
    BinaryTree() : root(NULL) {}
    //ָ��������־�Ĺ��캯��
    BinaryTree(T value) : root(NULL), RefValue(value) {}
    //��������
    ~BinaryTree();
    //�������캯��������������(ǰ�������Ӧ��)
    BinaryTree(BinaryTree<T>& s);
    //ʹ�ù����������������'#'�ַ��������
    void CreateBinTree();
    //ǰ���������������(ǰ�������Ӧ��)����#��ʾ�ս��
    void CreateBinTree_PreOrder(BinTreeNode<T>*& subTree);
    //ʹ����������������������������
    void CreateBinTreeBy_Pre_In(const char* pre, const char* in);
    //ʹ�ú�������������������������
    void CreateBinTreeBy_Post_In(const char* post, const char* in);

    //����������ݹ飩
    void PreOrder(BinTreeNode<T>*& subTree);
    //�������(�ݹ�)
    void InOrder(BinTreeNode<T>*& subTree);
    //����������ݹ飩
    void PostOrder(BinTreeNode<T>*& subTree);
    //�������(�ǵݹ�1)
    void PreOrder_NoRecurve1(BinTreeNode<T>* p);
    //�������(�ǵݹ�2)
    void PreOrder_NoRecurve2();
    //�������(�ǵݹ�)
    void InOrder_NoRecurve();
    //�������(�ǵݹ�)
    void PostOrder_NoRecurve();
    //��α���(�ǵݹ�)
    void LevelOrder(BinTreeNode<T> *p);

    //��ȡ�������ĸ��ڵ�
    BinTreeNode<T>* getRoot();
    //��ȡcurrent���ĸ��ڵ�
    BinTreeNode<T>* Parent(BinTreeNode<T>* current);
    //��ȡcurrent��������
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* current);
    //��ȡcurrent�����ҽ��
    BinTreeNode<T>* RightChild(BinTreeNode<T>* current);

    //���ٺ���
    void Destroy();
    //�ж����Ŷ������Ƿ����(ǰ�������Ӧ��)
    bool operator==(BinaryTree<T>& s);
    //����������Ľ��ĸ���(���������Ӧ��)
    int Size();
    //����������ĸ߶ȣ����������Ӧ�ã�
    int Height();
    //�ж϶������Ƿ�Ϊ��
    bool Empty();
    //�Թ�������ʽ���������(ǰ�������Ӧ��)
    void PrintBinTree();
    //��ת������
    void InvertTree();

private:
    BinTreeNode<T>* root; //���ڵ�
    T RefValue;           //��������ֹͣ�ı�־����Ҫһ�����캯��
};

/*
ǰ���������������
ÿ����һ��ֵ����Ϊ��������㡣�ý����Ϊ����㣬
���ַͨ�������������Ͳ��� subTree ֱ�����ӵ���Ϊʵ�ʲ�����ָ���С�
Ȼ�󣬷ֱ�Ը������������ݹ�ؽ���������ֱ�������������
*/
template<typename T>
void BinaryTree<T>::CreateBinTree_PreOrder(BinTreeNode<T> *&subTree)
{
    T item;
    if (cin >> item) {
        if (item != RefValue) {
            subTree = new BinTreeNode<T>(item);
            CreateBinTree_PreOrder(subTree->leftChild);  //�ݹ鴴��������
            CreateBinTree_PreOrder(subTree->rightChild); //�ݹ鴴��������
        }
        else {
            subTree = NULL;
        }
    }
}


//���������������˳��Ϊ������� -> ���ӽ�� -> �Һ��ӽ��
template<typename T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>*& subTree)
{
    if (subTree != NULL)
    {
        cout << subTree->data << " ";
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}


//���������������˳��Ϊ�����ӽ�� -> ����� -> �Һ��ӽ��
template<typename T>
void BinaryTree<T>::InOrder(BinTreeNode<T>*& subTree)
{
    if (subTree != NULL)
    {
        InOrder(subTree->leftChild);
        cout << subTree->data << " ";
        InOrder(subTree->rightChild);
    }
}

//�������ĺ������˳��Ϊ�����ӽ�� -> �Һ��ӽ�� -> ���ڵ�
template<typename T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>*& subTree)
{
    if (subTree != NULL) {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data << " ";
    }
}

//�ǵݹ��α���
template<typename T>
void BinaryTree<T>::LevelOrder(BinTreeNode<T>* p)
{
    queue<BinTreeNode<T>*>Q;
    Q.push(p);
    BinTreeNode<T>* front;
    while (!Q.empty()) {
        front = Q.front();
        Q.pop();
        cout << front->data << " ";

        if (front->leftChild != NULL) {
            Q.push(front->leftChild);
        }
        if (front->rightChild != NULL) {
            Q.push(front->rightChild);
        }
    }

}


//ǰ������ķǵݹ�ʵ��
template<typename T>
void BinaryTree<T>::PreOrder_NoRecurve1(BinTreeNode<T>* p)
{
    stack<BinTreeNode<T>*>s;

}

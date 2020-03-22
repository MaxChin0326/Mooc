//11  链表
//一、由若干结点（元素）组成，这些结点可在运行时动态生成
/*1、第一个结点：申请存放空间，为其数据域赋值； p=new node;p->date=10;
  2、第二个结点：申请存放空间，为其数据域赋值，将指针域置空； q=new node;q->data=20;q->next=null;
  3、将第二个结点连接到第一个结点之后，即让第一个结点的指针域指向第二个结点；p->next=q;*/

//二、链表常见操作
/*1、创建链表；
  2、遍历链表（输出链表）
  3、确定链表的长度，即统计链表中结点的个数；
  4、查找链表中的某个结点；
  5、在链表中插入一个新的结点；
  6、删除链表中的某个结点。*/

//三、动态创建一个含有n个结点的单链表。该链表只有一个数据域，且其类型为整形。
/*1、定义三个指针
     head--表头指针，指向第一个结点；
     newnode--指向当前动态创建的结点；
     tail--表尾指针，指向当前链表的最后一个结点；
   2、创建步骤
     置空表，即 head=NULL
     动态创建新结点，使newnode指向该结点，并向其数据域输入数据；
     newnode=new node；
     cin>>newnode->data;
   3、把newnode所指向的结点插入到链表中
   若当前链表为空，newnode所指向的结点成为该链表中的首结点，让head指向该结点。
     tail->next=newnode;
   4、newnode所指向的结点成为新的表尾结点，移动表尾指针指向该结点。
     tail=newnode;
   5、重复执行2-4步n次；
   6、将最后一个结点的指针域置空
      tail->next=NULL;*/

#include <iostream>
using namespace std;

struct node
{
	char num[6];
	float score;
	struct node* next;
};

//创建结点
struct node* create(int n)
{
    struct node* head = NULL;  //初始置空表
    struct node* tail, * newnode;
    for (int i = 0; i < n; i++)
    {
        newnode = new node;
        cin >> newnode->data;
        if (head == NULL)      //如果表头是空的；
            head = newnode;   //成为第一个（首）结点
        else
            tail->next = newnode;  //非空时新结点加到表尾后
        tail = newnode;   //新结点成为新的表尾结点，表空和非空共用该语句
    }
    tail->next = NULL;
    return(head);
}

//工作指针的移动
struct print(struct node* head)
{
    struct node* p = head;
    while (p != NULL)
    {
        cout << p->data << '\t';
        p = p->next;  //不能用p++
    } 
}

//查找结点
void search(struct node* head, int i)
{
    int j = 1;
    struct node* p = head;
    if (i < 1)
        cout << "illegal index\n";
    else
    {
        while (j != i && p != NULL)
        {
            j++;
            p = p->next;
        }
        if (j == i && p != NULL)
            cout << p->data;
        else
            cout << "illegal index \n";
    }
}

//插入结点
/*在一个数据域按递增顺序组织的链表中，插入一个新的数据x，
使得插入后该链表中的数据仍然有序*/
struct node* insert(node* head, int x)
{
    struct node* behind, * front, * newnode;  
    newnode = new node;
    newnode->data = x;   //将待插入数据存入新创建结点newnode
    behind = head;
    if (head == NULL)  //若为空表，新结点成为首结点
    {
        head = newnode;
        newnode->nect = NULL;
    }
    else     //不为空表
    {
        while (behid != NULL && x > behind->data)  //找插入位置
        {
            fornt = behind;
            behind = behind->next;
        }
        if (behind == head)  //往表头前插
        {
            newnode->next = head;
            head = newnode;
        }
        else if (head == NULL)  //往表尾后插
        {
            front->next = newnode;
            newnode->next = NULL;
        }
        else                      //往表中间插
        {
            front->next = newnode;
            newnode->next = behind;
        }
        return head;
    }
}

//删除结点
struct node* delnode(node* head, int x)
{
    struct node* p, * q;
    p = head;
    if (head == NULL)
        cout << " This list is null!\n";
    else
    {
        while(p!=NULL&&p->data!=x) //找到删除结点位置
        {
            q = p;
            p = p->next;
        }
        if (p == head)  //p==head,删除第一个结点
        {
            head = p->next;
            delet p;
        }
        else if (p != NULL)  //删除中间结点
        {
            q->next = p->next;
            delete p;
        }
        else
            cout<<x<<"dose not exist in the list!"
    }
    return head;
}

int main()
{

}
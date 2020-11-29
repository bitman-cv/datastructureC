#### 数据结构：

##### 二叉树：

遍历一棵二叉树常用的有四种方法，前序（PreOrder）、中序（InOrder）、后序（PastOrder）还有层序（LevelOrder）。前中后序三种遍历方式都是以根节点相对于它的左右孩子的访问顺序定义的。例如根->左->右便是前序遍历，左->根->右便是中序遍历，左->右->根便是后序遍历。
而层序遍历是一层一层来遍历的。

```c++
typedef char DataType;

typedef struct TreeNode{
    DataType data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
```

###### 前序遍历：

```c++
//递归：
void preOrderLoop(const TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    printf("%c",root->data);
    preOrderLoop(root->left);
    preOrderLoop(root->right);
}
//非递归：
void PreOrderLoop(const TreeNode *root)
{
    std::stack<TreeNode*> nodeStack;
    TreeNode *cur *top;
    cur = root;
    while(cur!=nullptr || !nodeStack.empty())
    {
        while(cur!=nullptr)
        {
            printf("%c",cur.data);
            nodeStack.push(cur);
            cur = cur.left;
        }
        top = nodeStack.top;
        nodeStack.pop();
        cur = top.right;
    }
}
```

###### 中序遍历：

```c++
//递归：
void InOrderLoop(const TreeNode *root)
{
	if(root == nullptr)
	{
		return;
	}
	InOrderLoop(root->left);
	printf("%c",root->data);
	InorderLoop(root->right);
}
//非递归：
void InOrderLoop(const TreeNode *root)
{
	if(root == nullptr)
	{
		return;
	}
	TreeNode *cur, *top;
	std::stack<TreeNode*> nodeStack;
    cur = root;
	while(cur!=0 || !nodeStack.empty())
    {
        while(cur!=nullptr)
        {
           	nodeStack.push(cur);
        	cur = cur.left; 
        } 
        cur = nodeStack.top();
    	nodeStack.pop;
    	printf("%c", cur->data);
    	cur = cur->right;
    }
}
```

###### 后序遍历：

```c++
//递归
void backOrderLoop(TreeNode *root)
{
    if(root==nullptr)
    {
        return;
    }
    backOrderLoop(root->left);
    backOrderLoop(root->right);
    printf("%c",root->data);
    
}
//非递归
void backOrderLoop(TreeNode *root)
{
    if(root==nullptr)
    {
        return;
    }
    TreeNode *cur,*top,*last;
    std::stack<TreeNode*> nodeStack;
    cur = root;
    while(cur!=nullptr || !nodeStack.empty())
    {
    	while(cur!=nullptr)
        {
            nodeStack.push(cur);
            cur = cur->left;
        }

        top = nodeStack.top();
        if(top->right==nullptr || top->right == last)
        {
            nodeStack.pop();
            printf("%c",top->data);
            last = top;
        }else{
            cur = top->right;
        } 
    }  
}

```

###### 层序遍历：

```c++
void leverlOrderLoop(TreeNode *root)
{
	if(root==nullptr)
	{
		return;
	}
	std::queue<TreeNode*> nodeQueue;
	TreeNode *front;
	nodeQueue.push(root);
	
	while(!nodeQueue.empty())
    {
        front = nodeQueue.front();
        nodeQueue.pop();
        
        if(front->left)
        {
            nodeQueue.push(front->left);
        }
        if(front->right)
        {
            nodeQueue.push(front->right);
        }
        printf("%c",front->data);
    }
}
```

##### 栈：

```c
#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef struct
{
	elemtype   * base;
	elemtype  *  top;
	int  stacksize;
}SqStack;

int Inistack(SqStack &s)
{
	s.base = (elemtype *)malloc(STACK_INIT_SIZE * sizeof(elemtype));
	if (!s.base)
		exit(0);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return 1;
}

int push(SqStack &s, elemtype e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (elemtype *)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(elemtype));
		if (!s.base)
			exit(0);
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*(s.top++) = e;
	return 1;
}

int pop(SqStack &s)
{
	elemtype e;
	if (s.top == s.base)
		exit(0);
	e = *(--s.top);
	return e;
}

int main()
{
	SqStack s;
	Inistack(s);
	int num;
	int a[6] = { 12,43,34,16,19,20 };	//12，43，34，16，19，20
	printf("将入栈12，43，34，16，19，20这6个元素\n");
	for (int i = 0; i < 6; i++)
	{
		push(s, a[i]);
	}
	printf("请输入要出栈的个数:");
	scanf("%d", &num);
	printf("出栈的元素为：\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", pop(s));
	}
	printf("\n");
	system("pause");
	int str[100];
	scanf("%s", &str);

}
```

#### 算法：

##### 排序：

| 类别     | 排序方法  | 时复(aver) | 时复(best) | 时复(worst) | 空间复杂度 | 稳定性 |
| -------- | --------- | ---------- | ---------- | ----------- | ---------- | ------ |
| 插入排序 | 插入排序  | O(N^2^)    | O(N)       | O(N^2^)     | O(1)       | 稳定   |
|          | shell排序 | O(N^1.3^)  | O(N)       | O(N^2^)     | O(1)       | 不稳定 |
| 选择排序 | 选择排序  | O(N^2^)    | O(N^2^)    | O(N^2^)     | O(1)       | 不稳定 |
|          | 堆排序    | O(N*lgN)   | O(N*lgN)   | O(N*lgN)    | O(1)       | 不稳定 |
| 交换排序 | 冒泡排序  | O(N^2^)    | O(N)       | O(N^2^)     | O(1)       | 稳定   |
|          | 快速排序  | O(N*lgN)   | O(N*lgN)   | O(N^2^)     | O(lgN)     | 不稳定 |
| 归并排序 | 归并排序  | O(N*lgN)   | O(N*lgN)   | O(N*lgN)    | O(N)       | 稳定   |

###### 冒泡排序：

（Bubble Sort）：比较两个相邻的元素,如果升序的话,前面的比后面的大,就交换,这样一轮下来,就会找到这组数据中最大的元素,然后抛开这个元素继续重复上述步骤.知道排完为止;

###### 快速排序（Quick Sort):

任取待排序中的某一元素作为基准值,按照该排序码,将待排序集合分割成两个子序列,左边的序列比基准值小,右边的比基准值大.然后对左右子序列重复上述步骤.直到排完为止;

###### 直接插入排序(Insertion sort):

从第一个元素开始,该元素已经排好序,继续取元素与排好序的元素依次进行比较,升序的话插入到比前一个大比后一个小的位置,然后重复上述步骤,直到插完元素为止;

###### 希尔排序(Shell sort):

对整个待排序序列进行分组,然后对每一组进行直接插入排序;

###### 直接选择排序(Straight Select Sorting):

在未排序的序列中找到最小的元素,存放到序列的首位置,找到最大的元素存放到序列的末尾.然后抛开首位和末尾,继续重复该步骤,直到排完为止;

###### 堆排序(Heap sort):

若升序的话,就将堆调成一个大堆,若降序的话,就将堆调成一个小堆.从倒数第一个非叶子节点开始往根遍历,若当前节点的值都大于左右孩子,则不用动,若是小于,就将左右孩子当中最大的节点与当前节点交换,交换后就需要进行向下调整(因为交换会影响大堆结构).重复上述步骤,直到根节点为止;

###### 归并排序(Merge Sort):

将待排序的元素序列分为两个长度相等的子序列,对每个子序列进行排序,然后将他们合并成一个序列,合并两个子序列的过程称为二路归并;

```c++
#include <cstdio>
#include <cstdlib>
#include <cstring>

void myprint(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void swap(int& b1, int& b2)
{
	int ntmp = b1;
	b1 = b2;
	b2 = ntmp;
}

// 冒泡排序（Bubble Sort）
void myBubbleSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		int k = -1;
		for (int i = 0; i < length-1; i++)
		{
			k = -1;
			for (int j = 0; j < length-i-1; j++)
			{
				if (b[j] > b[j+1])
				{
					swap(b[j], b[j + 1]);
					k = j;
				}
			}
			if (k == -1)
			{
				break;
			}
		}

		printf("sort by myBubbleSort Sort:");
		myprint(b, length);
		free(b);
	}
}
//快速排序（Quick Sort)
int oneQuickSort(int* b, int low, int high)
{
	int nKey = b[low];
	while (low < high)
	{
		while (low<high && b[high]>nKey)
		{
			high--;
		}
		if (low < high)
		{
			b[low++] = b[high];
		}
		while (low < high && b[low] < nKey)
		{
			low++;
		}
		if (low < high)
		{
			b[high--] = b[low];
		}
	}
	b[low] = nKey;
	return low;
}

void quickSort(int* b, int low, int high)
{
	if (low < high)
	{
		int keyIndex = oneQuickSort(b, low, high);

		quickSort(b, low, keyIndex - 1);
		quickSort(b, keyIndex + 1, high);
	}
}

void myQuickSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		quickSort(b, 0, length-1);
		printf("sort by myQuickSort Sort:");
		myprint(b, length);
		free(b);
	}
}

//直接插入排序(Insertion sort)
void myInsertSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		for(int i = 1; i < length; i++)
		{
			int nKey = b[i];
			int end = i - 1;
			while (end>=0 && nKey<b[end])
			{
				b[end + 1] = b[end--];
			}
			b[end+1] = nKey;
		}
		printf("sort by myInsertSort Sort:");
		myprint(b, length);
		free(b);
	}
}

void myBinarySearchInsertSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		for (int i = 1; i < length; i++)
		{
			int nKey = b[i];
			int low = 0;
			int high = i-1;
			while (low <= high)
			{
				int nmid = (low + high) >> 1;
				if (b[i] < b[nmid])
				{
					high = nmid-1;
				}
				else {
					low = nmid+1;
				}
			}

			high = i - 1;
			while (low <= high)
			{
				b[high + 1] = b[high];
				high--;
			}
			b[++high] = nKey;

		}
		printf("sort by myBinarySearchInsertSort Sort:");
		myprint(b, length);
		free(b);
	}
}

//希尔排序(Shell sort)
void myShellSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		int step = 3;
		while (step > 0)
		{
			for (int i = step; i < length; i++)
			{
				int nKey = b[i];
				int end = i - step;
				while (end >= 0 && nKey < b[end])
				{
					b[end + step] = b[end];
					end = end - step;
				}
				b[end + step] = nKey;
			}
			step--;
		}
		printf("sort by myShellSort Sort:");
		myprint(b, length);
		free(b);
	}
}

//直接选择排序(Straight Select Sort):
void myStraightSelectSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		int left = 0;
		int right = length-1;

		while (left < right)
		{
			int minIndex = left;
			int maxIndex = left;
			for (int i = left; i <= right; i++)
			{
				if (b[i] < b[minIndex])
				{
					minIndex = i;
				}
				if (b[i] > b[maxIndex])
				{
					maxIndex = i;
				}
			}
			swap(b[minIndex], b[left]);
			swap(b[maxIndex], b[right]);

			left++;
			right--;
		}

		printf("sort by myStraightSelectSort Sort:");
		myprint(b, length);
		free(b);
	}
}

//堆排序(Heap sort)
void heapAdjust(int b[], int length, int parent)
{
	int child = parent * 2 + 1;
	while (child < length)
	{
		if ((child + 1) < length && b[child + 1] > b[child])
		{
			child += 1;
		}
		if (b[parent] < b[child])
		{
			swap(b[parent], b[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}
void myHeapSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		//建堆
		int root = ((length - 2) >> 1);
		int end = length - 1;
		for (; root >= 0; --root)
		{
			heapAdjust(b, length, root);
		}
		//调整
		while (end)
		{
			swap(b[end], b[0]);
			heapAdjust(b, end, 0);
			--end;
		}

		myprint(b, length);
		
		printf("sort by myHeapSort Sort:");
		myprint(b, length);
		free(b);
	}
}

//归并排序(Merge Sort)
void myMergeSort(int a[], int length)
{
	int* b = (int*)malloc(length * sizeof(int));
	if (b)
	{
		memcpy(b, a, length * sizeof(int));
		
		printf("sort by myShellSort Sort:");
		myprint(b, length);
		free(b);
	}
}
int main()
{
	int arr[] = { 2,0,3,10,3,6,6,7,1,5 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("original array:");
	myprint(arr, length);
	myBubbleSort(arr, length);
	myQuickSort(arr, length);
	myInsertSort(arr, length);
	myBinarySearchInsertSort(arr, length);
	myShellSort(arr, length);
	myStraightSelectSort(arr, length);
	myHeapSort(arr, length);
}
```



###### 红黑树：

红黑树能够以O(log2(N))的时间复杂度进行搜索、插入、删除操作。此外,任何不平衡都会在3次旋转之内解决。这一点是AVL所不具备的。



###### 数据库事务特性：

## ⑴ 原子性（Atomicity）

　　原子性是指事务包含的所有操作要么全部成功，要么全部失败回滚，这和前面两篇博客介绍事务的功能是一样的概念，因此事务的操作如果成功就必须要完全应用到数据库，如果操作失败则不能对数据库有任何影响。

## ⑵ 一致性（Consistency）

　　一致性是指事务必须使数据库从一个一致性状态变换到另一个一致性状态，也就是说一个事务执行之前和执行之后都必须处于一致性状态。

　　拿转账来说，假设用户A和用户B两者的钱加起来一共是5000，那么不管A和B之间如何转账，转几次账，事务结束后两个用户的钱相加起来应该还得是5000，这就是事务的一致性。

## ⑶ 隔离性（Isolation）

　　隔离性是当多个用户并发访问数据库时，比如操作同一张表时，数据库为每一个用户开启的事务，不能被其他事务的操作所干扰，多个并发事务之间要相互隔离。

　　即要达到这么一种效果：对于任意两个并发的事务T1和T2，在事务T1看来，T2要么在T1开始之前就已经结束，要么在T1结束之后才开始，这样每个事务都感觉不到有其他事务在并发地执行。

　　关于事务的隔离性数据库提供了多种隔离级别，稍后会介绍到。

## ⑷ 持久性（Durability）

　　持久性是指一个事务一旦被提交了，那么对数据库中的数据的改变就是永久性的，即便是在数据库系统遇到故障的情况下也不会丢失提交事务的操作。

　　例如我们在使用JDBC操作数据库时，在提交事务方法后，提示用户事务操作完成，当我们程序执行完成直到看到提示后，就可以认定事务以及正确提交，即使这时候数据库出现了问题，也必须要将我们的事务完全执行完成，否则就会造成我们看到提示事务处理完毕，但是数据库因为故障而没有执行事务的重大错误。



## 1，脏读

　　脏读是指在一个事务处理过程里读取了另一个未提交的事务中的数据。

　　当一个事务正在多次修改某个数据，而在这个事务中这多次的修改都还未提交，这时一个并发的事务来访问该数据，就会造成两个事务得到的数据不一致。例如：用户A向用户B转账100元，对应SQL命令如下

```
    update account set money=money+100 where name=’B’;  (此时A通知B)

    update account set money=money - 100 where name=’A’;
```

　　当只执行第一条SQL时，A通知B查看账户，B发现确实钱已到账（此时即发生了脏读），而之后无论第二条SQL是否执行，只要该事务不提交，则所有操作都将回滚，那么当B以后再次查看账户时就会发现钱其实并没有转。

## 2，不可重复读

　　不可重复读是指在对于数据库中的某个数据，一个事务范围内多次查询却返回了不同的数据值，这是由于在查询间隔，被另一个事务修改并提交了。

　　例如事务T1在读取某一数据，而事务T2立马修改了这个数据并且提交事务给数据库，事务T1再次读取该数据就得到了不同的结果，发送了不可重复读。

　　不可重复读和脏读的区别是，脏读是某一事务读取了另一个事务未提交的脏数据，而不可重复读则是读取了前一事务提交的数据。

　　在某些情况下，不可重复读并不是问题，比如我们多次查询某个数据当然以最后查询得到的结果为主。但在另一些情况下就有可能发生问题，例如对于同一个数据A和B依次查询就可能不同，A和B就可能打起来了……

## 3，虚读(幻读)

　　幻读是事务非独立执行时发生的一种现象。例如事务T1对一个表中所有的行的某个数据项做了从“1”修改为“2”的操作，这时事务T2又对这个表中插入了一行数据项，而这个数据项的数值还是为“1”并且提交给数据库。而操作事务T1的用户如果再查看刚刚修改的数据，会发现还有一行没有修改，其实这行是从事务T2中添加的，就好像产生幻觉一样，这就是发生了幻读。

　　幻读和不可重复读都是读取了另一条已经提交的事务（这点就脏读不同），所不同的是不可重复读查询的都是同一个数据项，而幻读针对的是一批数据整体（比如数据的个数）。

 

　　现在来看看MySQL数据库为我们提供的四种隔离级别：

　　① Serializable (串行化)：可避免脏读、不可重复读、幻读的发生。

　　② Repeatable read (可重复读)：可避免脏读、不可重复读的发生。

　　③ Read committed (读已提交)：可避免脏读的发生。

　　④ Read uncommitted (读未提交)：最低级别，任何情况都无法保证。
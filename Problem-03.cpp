//#include<iostream>
//using namespace std;
//class node
//{
//public:
//	int data;
//	node* left;
//	node* right;
//	int height;
//	node()
//	{
//		data = 0;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//};
//class AVL_Trees
//{
//	const int s = 5;
//	int* arr;
//	int count;
//public:
//	node* root;
//	AVL_Trees()
//	{
//		root = NULL;
//		count = 0;
//	}
//	node* get_root()
//	{
//		return root;
//	}
//	void make_array(int size)
//	{
//		arr = new int[size];
//	}
//	int height(node* N)
//	{
//		if (N == NULL)
//		{
//			return 0;
//		}
//		return N->height;
//	}
//	int max(int a, int b)
//	{
//		if (a > b)
//		{
//			return a;
//		}
//		else
//		{
//			return b;
//		}
//	}
//	node* newNode(int d)
//	{
//		node* ptr = new node;
//		ptr->data = d;
//		ptr->left = NULL;
//		ptr->right = NULL;
//		ptr->height = 1;
//		return ptr;
//	}
//	node* rightRotate(node* y)
//	{
//		node* x = y->left;
//		node* T2 = x->right;
//		x->right = y;
//		y->left = T2;
//		y->height = max(height(y->left), height(y->right)) + 1;
//		x->height = max(height(x->left), height(x->right)) + 1;
//		return x;
//	}
//	node* leftRotate(node* x)
//	{
//		node* y = x->right;
//		node* T2 = y->left;
//		y->left = x;
//		x->right = T2;
//		x->height = max(height(x->left), height(x->right)) + 1;
//		y->height = max(height(y->left), height(y->right)) + 1;
//		return y;
//	}
//	int getBalance(node* N)
//	{
//		if (N == NULL)
//		{
//			return 0;
//		}
//		return height(N->left) - height(N->right);
//	}
//	node* insert_AVL(node* r, int d)
//	{
//		if (r == NULL)
//		{
//			return newNode(d);
//		}
//
//		if (d < r->data)
//		{
//			r->left = insert_AVL(r->left, d);
//		}
//		else if (d > r->data)
//		{
//			r->right = insert_AVL(r->right, d);
//		}
//		else
//		{
//			return r;
//		}
//		r->height = 1 + max(height(r->left), height(r->right));
//		int balance = getBalance(r);
//		if (balance > 1 && d < r->left->data)
//		{
//			return rightRotate(r);
//		}
//
//		if (balance < -1 && d > r->right->data)
//		{
//			return leftRotate(r);
//		}
//		if (balance > 1 && d > r->left->data)
//		{
//			r->left = leftRotate(r->left);
//			return rightRotate(r);
//		}
//		if (balance < -1 && d < r->right->data)
//		{
//			r->right = rightRotate(r->right);
//			return leftRotate(r);
//		}
//		return r;
//	}
//	void insert_BST(int val)
//	{
//		node* ptr = new node;
//		ptr->data = val;
//		if (root == NULL)
//		{
//			root = ptr;
//			cout << " Node Inserted on Root " << endl;
//			return;
//		}
//		else
//		{
//			node* temp = root;
//			while (temp != NULL)
//			{
//				if (temp->data == ptr->data)
//				{
//					cout << " This Data already Exists! " << endl;
//					return;
//				}
//				else if (ptr->data < temp->data && temp->left == NULL)
//				{
//					temp->left = ptr;
//					cout << " Node inserted to the Left! " << endl;
//					return;
//				}
//				else if (ptr->data < temp->data)
//				{
//					temp = temp->left;
//				}
//				else if (ptr->data > temp->data && temp->right == NULL)
//				{
//					temp->right = ptr;
//					cout << " Node inserted to the Right! " << endl;
//					return;
//				}
//				else if (ptr->data > temp->data)
//				{
//					temp = temp->right;
//				}
//			}
//		}
//	}
//	void convert()
//	{
//		int size = count_nodes(get_root());
//		root = NULL;
//		for (int i = 0; i < size; i++)
//		{
//			root = insert_AVL(get_root(), arr[i]);
//		}
//	}
//	void Display(node* r, int space)
//	{
//		if (r == NULL)
//		{
//			return;
//		}
//		space = space + s;
//		Display(r->right, space);
//		cout << endl;
//		for (int i = s; i < space; i++)
//		{
//			cout << " ";
//		}
//		cout << r->data << endl;
//		Display(r->left, space);
//	}
//	int count_nodes(node* r)
//	{
//		if (r == NULL)
//		{
//			return 0;
//		}
//		int l_tree = count_nodes(r->left);
//		int r_tree = count_nodes(r->right);
//		return 1 + l_tree + r_tree;
//	}
//	void Filling_arr(node* r)
//	{
//		if (r == NULL)
//		{
//			return;
//		}
//		Filling_arr(r->left);
//		arr[count] = r->data;
//		count++;
//		Filling_arr(r->right);
//	}
//};
//int main()
//{
//	const int spaces = 5;
//	AVL_Trees t1;
//	int a = 0, val;
//	while (a != -1)
//	{
//		cout << " Enter the Data: ";
//		cin >> val;
//	    t1.insert_BST(val);
//		cout << " Enter -1 when You Finish Entering Data: ";
//		cin >> a;
//	}
//	cout << endl << " Your BST is " << endl << endl;
//	t1.Display(t1.get_root(), spaces);
//	cout <<endl<< "----------- Now Converting to AVL ------------ " << endl<<endl;
//	int size = t1.count_nodes(t1.get_root());
//	t1.make_array(size);
//	t1.Filling_arr(t1.get_root());
//	t1.convert();
//	cout << endl << endl << " ---- Your AVL Tree is -----" << endl<<endl;
//	t1.Display(t1.get_root(), spaces);
//}
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
//	node* ptr;
//public:
//	node* root;
//	AVL_Trees()
//	{
//		ptr = NULL;
//		root = NULL;
//	}
//	AVL_Trees(AVL_Trees& obj)
//	{
//		root = obj.root;
//		ptr = obj.ptr;
//	}
//	node* get_root()
//	{
//		return root;
//	}
//	node* get_node()
//	{
//		return ptr;
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
//	node* insert(node* r, int d)
//	{
//		if (r == NULL)
//		{
//			return newNode(d);
//		}
//
//		if (d < r->data)
//		{
//			r->left = insert(r->left, d);
//		}
//		else if (d > r->data)
//		{
//			r->right = insert(r->right, d);
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
//	node* nodeOnRight(node* r)
//	{
//		node* temp = r;
//		while (temp->left != NULL)
//		{
//			temp = temp->left;
//		}
//		return temp;
//	}
//	node* Delete_node(node* r, int val)
//	{
//		if (r == NULL)
//		{
//			return r;
//		}
//		else if (val < r->data)
//		{
//			r->left = Delete_node(r->left, val);
//		}
//		else if (val > r->data)
//		{
//			r->right = Delete_node(r->right, val);
//		}
//		else
//		{
//			if (r->left == NULL)
//			{
//				node* temp = r->right;
//				delete r;
//				return temp;
//			}
//			else if (r->right == NULL)
//			{
//				node* temp = r->left;
//				delete r;
//				return temp;
//			}
//			else
//			{
//				node* ptr = nodeOnRight(r->right);
//				r->data = ptr->data;
//				r->right = Delete_node(r->right, ptr->data);
//			}
//		}
//		r->height = 1 + max(height(r->left), height(r->right));
//		int balance = getBalance(r);
//		if (balance > 1 && val < r->left->data)
//		{
//			return rightRotate(r);
//		}
//
//		if (balance < -1 && val > r->right->data)
//		{
//			return leftRotate(r);
//		}
//		if (balance > 1 && val > r->left->data)
//		{
//			r->left = leftRotate(r->left);
//			return rightRotate(r);
//		}
//		if (balance < -1 && val < r->right->data)
//		{
//			r->right = rightRotate(r->right);
//			return leftRotate(r);
//		}
//		return r;
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
//	void find_Node(node* r)
//	{
//		if (r == NULL)
//		{
//			return;
//		}
//		find_Node(r->left);
//		if (r->right == NULL && r->left == NULL)
//		{
//			ptr = r;
//		}
//		find_Node(r->right);
//	}
//	AVL_Trees Join(AVL_Trees& t1, AVL_Trees& t2)
//	{
//		node* temp;
//		int num = t1.count_nodes(t1.get_root());
//		for (int i = 0; i < num; i++)
//		{
//			t1.find_Node(t1.get_root());
//			temp = t1.get_node();
//			t2.root = t2.insert(t2.get_root(), temp->data);
//			t1.root = t1.Delete_node(t1.get_root(), temp->data);
//		}
//		return t2;
//	}
//	int return_largest(node* r)
//	{
//		if (r == NULL)
//		{
//			cout << " Tree is Empty! " << endl;
//			return 0;
//		}
//		node* temp = r;
//		while (temp->right != NULL)
//		{
//			temp = temp->right;
//		}
//		return temp->data;
//	}
//};
//int main()
//{
//	const int spaces = 5;
//	cout << "--------------- Welcome ----------------- " << endl<<endl;
//	AVL_Trees t1, t2;
//	cout << " ____________ Inserting the First AVL Tree ______________" << endl;
//	cout << endl;
//	int a = 0, val;
//	while (a != -1)
//	{
//		cout << " Enter the Data: ";
//		cin >> val;
//		t1.root = t1.insert(t1.get_root(), val);
//		cout << " Enter -1 when You Finish Inserting: ";
//		cin >> a;
//	}
//	cout << "               First AVL Tree is " << endl<<endl;
//	t1.Display(t1.get_root(), spaces);
//	cout << endl;
//
//	cout << " ____________ Inserting the Second AVL Tree ______________" << endl;
//	cout << endl;
//	int get = t1.return_largest(t1.get_root());
//	cout << "Note: Your Data of Second AVL Tree should be greater than " << get << endl;
//	 a = 0;
//	while (a != -1)
//	{
//		cout << " Enter the Data: ";
//		cin >> val;
//		if (val > get)
//		{
//			t2.root = t2.insert(t2.get_root(), val);
//		}
//		else
//		{
//			cout << " This Data is Not Valid in this AVL Tree " << endl;
//		}
//		cout << " Enter -1 when You Finish Inserting: ";
//		cin >> a;
//	}
//	cout << "               Second AVL Tree is " << endl << endl;
//	t2.Display(t2.get_root(), spaces);
//	cout << endl;
//	cout << "********* Union of Both Trees is ********* " << endl;
//	t2.Join(t1, t2);
//	AVL_Trees t3(t2);
//	t3.Display(t3.get_root(), spaces);
//}
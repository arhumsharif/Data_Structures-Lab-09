// #include<iostream>
//using namespace std;
// class node
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
// class AVL_Trees
// {
//	 const int s = 5;
//	 int check;
// public:
//	 node* root;
//	 AVL_Trees()
//	 {
//		 root = NULL;
//		 check = 0;
//	 }
//	 node* get_root()
//	 {
//		 return root;
//	 }
//	 int get_check()
//	 {
//		 return check;
//	 }
//	 int height(node* N)
//	 {
//		 if (N == NULL)
//		 {
//			 return 0;
//		 }
//		 return N->height;
//	 }
//	 int max(int a, int b)
//	 {
//		 if (a > b)
//		 {
//			 return a;
//		 }
//		 else
//		 {
//			 return b;
//		 }
//	 }
//	 node* newNode(int d)
//	 {
//		 node* ptr = new node;
//		 ptr->data = d;
//		 ptr->left = NULL;
//		 ptr->right = NULL;
//		 ptr->height = 1;
//		 return ptr;
//	 }
//	 node* rightRotate(node* y)
//	 {
//		 node* x = y->left;
//		 node* T2 = x->right;
//		 x->right = y;
//		 y->left = T2;
//		 y->height = max(height(y->left), height(y->right)) + 1;
//		 x->height = max(height(x->left), height(x->right)) + 1;
//		 return x;
//	 }
//	 node* leftRotate(node* x)
//	 {
//		 node* y = x->right;
//		 node* T2 = y->left;
//		 y->left = x;
//		 x->right = T2;
//		 x->height = max(height(x->left), height(x->right)) + 1;
//		 y->height = max(height(y->left), height(y->right)) + 1;
//		 return y;
//	 }
//	 int getBalance(node* N)
//	 {
//		 if (N == NULL)
//		 {
//			 return 0;
//		 }
//		 return height(N->left) - height(N->right);
//	 }
//	 node* insert(node* r, int d)
//	 {
//		 if (r == NULL)
//		 {
//			 return newNode(d);
//		 }
//
//		 if (d < r->data)
//		 {
//			 r->left = insert(r->left, d);
//		 }
//		 else if (d > r->data)
//		 {
//			 r->right = insert(r->right, d);
//		 }
//		 else
//		 {
//			 return r;
//		 }
//		 r->height = 1 + max(height(r->left), height(r->right));
//		 int balance = getBalance(r);
//		 if (balance > 1 && d < r->left->data)
//		 {
//			 return rightRotate(r);
//		 }
//
//		 if (balance < -1 && d > r->right->data)
//		 {
//			 return leftRotate(r);
//		 }
//		 if (balance > 1 && d > r->left->data)
//		 {
//			 r->left = leftRotate(r->left);
//			 return rightRotate(r);
//		 }
//		 if (balance < -1 && d < r->right->data)
//		 {
//			 r->right = rightRotate(r->right);
//			 return leftRotate(r);
//		 }
//		 return r;
//	 }
//	 void Display(node* r, int space)
//	 {
//		 if (r == NULL)
//		 {
//			 return;
//		 }
//		 space = space + s;
//		 Display(r->right, space);
//		 cout << endl;
//		 for (int i = s; i < space; i++)
//		 {
//			 cout << " ";
//		 }
//		 cout << r->data << endl;
//		 Display(r->left, space);
//	 }
//	 node* nodeOnRight(node* r)
//	 {
//		 node* temp = r;
//		 while (temp->left != NULL)
//		 {
//			 temp = temp->left;
//		 }
//		 return temp;
//	 }
//	 node* Delete_node(node* r, int val)
//	 {
//		 if (r == NULL)
//		 {
//			 return r;
//		 }
//		 else if (val < r->data)
//		 {
//			 r->left = Delete_node(r->left, val);
//		 }
//		 else if (val > r->data)
//		 {
//			 r->right = Delete_node(r->right, val);
//		 }
//		 else
//		 {
//			 check++;
//			 if (r->left == NULL)
//			 {
//				 node* temp = r->right;
//				 delete r;
//				 return temp;
//			 }
//			 else if (r->right == NULL)
//			 {
//				 node* temp = r->left;
//				 delete r;
//				 return temp;
//			 }
//			 else
//			 {
//				 node* ptr = nodeOnRight(r->right);
//				 r->data = ptr->data;
//				 r->right = Delete_node(r->right, ptr->data);
//			 }
//		 }
//		 r->height = 1 + max(height(r->left), height(r->right));
//		 int balance = getBalance(r);
//		 if (balance > 1 && val < r->left->data)
//		 {
//			 return rightRotate(r);
//		 }
//
//		 if (balance < -1 && val > r->right->data)
//		 {
//			 return leftRotate(r);
//		 }
//		 if (balance > 1 && val > r->left->data)
//		 {
//			 r->left = leftRotate(r->left);
//			 return rightRotate(r);
//		 }
//		 if (balance < -1 && val < r->right->data)
//		 {
//			 r->right = rightRotate(r->right);
//			 return leftRotate(r);
//		 }
//		 return r;
//	 }
// };
//int main()
//{
//	AVL_Trees a1;
//	int spaces = 5, a = 0, val;
//	char choice;
//	while (a != -1)
//	{
//		cout << "1. Insert " << endl;
//		cout << "2. Display " << endl;
//		cout << "3. Delete " << endl;
//		cout << "4. Clear Screen " << endl;
//		cout << " Enter: ";
//		cin >> choice;
//		if (choice == '1')
//		{
//			cout << " Enter the Value: ";
//			cin >> val;
//			a1.root=a1.insert(a1.get_root(), val);
//		}
//		else if (choice == '2')
//		{
//			a1.Display(a1.get_root(), spaces);
//		}
//		else if (choice == '3')
//		{
//			cout << " Enter the Data to be Deleted: ";
//			cin >> val;
//			a1.root = a1.Delete_node(a1.get_root(), val);
//			if (a1.get_check() > 0)
//			{
//				cout << " Your Data has been deleted " << endl;
//			}
//			else
//			{
//				cout << " Your Data does not exist on AVL Tree " << endl;
//			}
//		}
//		else if (choice == '4')
//		{
//			system("cls");
//		}
//		else
//		{
//			cout << " Invalid Choice " << endl;
//		}
//		cout << " Enter -1 to Quit: ";
//		cin >> a;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class node
//{
//public:
//	int data;
//	node* right;
//	node* left;
//	node()
//	{
//		data = 0;
//		right = NULL;
//		left = NULL;
//	}
//};
//class Binary_Search_Tree
//{
//public:
//	node* root;
//	const int s = 5;
//	Binary_Search_Tree()
//	{
//		root = NULL;
//	}
//	node* get_root()
//	{
//		return root;
//	}
//	void insertion(int val)
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
//	int height(node* r,int count)
//	{
//		if (r == NULL)
//		{
//			return 0;
//		}
//		int l_height, r_height;
//		l_height = height(r->left,count+1);
//		r_height = height(r->right,count+1);
//		if (l_height > r_height)
//		{
//			if (count == 0)
//			{
//				return l_height;
//			}
//			return l_height + 1;
//		}
//		else
//		{
//			if (count == 0)
//			{
//				return r_height;
//			}
//			return r_height + 1;
//		}
//	}
//	int balance_factor()
//	{
//		int i = 0;
//		int l_tree, r_tree;
//		l_tree = height(get_root()->left, i);
//		r_tree = height(get_root()->right, i);
//		if (get_root()->left != NULL)
//		{
//			l_tree=l_tree + 1;
//		}
//		if (get_root()->right != NULL)
//		{
//			r_tree = r_tree + 1;
//		}
//		return l_tree - r_tree;
//	}
//};
//int main()
//{
//	Binary_Search_Tree b1;
//	int spaces = 5;
//	int a = 0, val;
//	cout << "--- Inserting the Tree ---" << endl;
//	while (a != -1)
//	{
//		cout << " Enter the Value: ";
//		cin >> val;
//		b1.insertion(val);
//		cout <<endl<< " Enter -1 When You Finish Entering : " << endl;
//		cin >> a;
//	}
//	cout << endl << "--------------- Given Tree is --------------- " << endl << endl;
//	b1.Display(b1.get_root(), spaces);
//	cout << endl << " Checking Whether it is AVL or Not " << endl<<endl;
//	int result = b1.balance_factor();
//	if (result == -1 || result == 0 || result == 1)
//	{
//		cout << " ---- IT is a Valid AVL Tree -----" << endl;
//	}
//	else
//	{
//		cout << " ---- It is Not an AVL tree ----  " << endl;
//	}
//	return 0;
//}
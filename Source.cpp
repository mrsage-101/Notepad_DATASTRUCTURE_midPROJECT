#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>

using namespace std;

struct node
{
public:
	string data;
	node* left;
	node* right;
	node* up;
	node* down;

	node()
	{
		// constructor
		data = "\0";
		left = right = up = down = NULL;
	}
	~node()
	{
		// destructor
	}
};
class notepad
{
private:

	static int xloc, yloc;

public:

	// this is the head node containing the address of the first node
	node* Lhead, *Rhead, * Thead, *Bhead;
	// these are the pointer's to keep track of left, rigth, top and bottom
	node* CLP, * CRP, * CTP, * CBP;
	
	
	notepad()
	{
		// constuctor
		
		Lhead = NULL;
		Rhead = NULL;
		Thead = NULL;
		Lhead = NULL;
		Bhead = NULL;

		CLP = NULL;
		CRP = NULL;
		CTP = NULL;
		CBP = NULL;
	}
	~notepad()
	{
		// destructor
	}
	
	
	void addtext(int x_loc, int y_loc)
	{
		int reserved_x = x_loc; int reserved_y = y_loc;
		string text = "\0"; int temp_x = (x_loc - 1); int row = 0; int column = 0; int temp_y = (y_loc - 1);
		
		// first quadrant - [1], dealing with pointer's - (CLP and CTP)
		if (x_loc >= 0 && y_loc >= 0)
		{
			// Right Linked List - when there is no linked list
			if (Rhead == NULL)
			{
				node* newRnodes;

				//---------------------------------------------{  X - AXIS  }--------------------------------------------------//
				for (int i = 0; i < x_loc; i++)
				{
					if (i == 0)
					{
						newRnodes = new node();
						newRnodes->data = " ";
						// here the head is set for RIGHT nodes access
						Rhead = newRnodes;
					}
					else
					{
						// giving tail the address of head to every time insert at last after traversing
						node* Rtail = Rhead;
						newRnodes = new node();
						newRnodes->data = " ";
						while (Rtail->right != NULL)
						{
							Rtail = Rtail->right;
						}
						Rtail->right = newRnodes;
						newRnodes->left = Rtail;
						Rtail = newRnodes;
					}
					if (i == temp_x)
					{
						// this will be later used in the if(Rhead != NULL)
						xloc = x_loc;
						goto jump;
					}
				}
			}
			// when right linked list has a bunch of nodes 
			else if (Rhead != NULL)
			{
				// if right linked list head not empty
				// 1 base condition for the traversal and adding data to the exisiting node's
				if (x_loc < xloc) // 3 < 6
				{
					x_loc--;
					int k = 0;
					node* Rtraversal = Rhead;
					while (Rtraversal != NULL)
					{
						k++;
						Rtraversal = Rtraversal->right;
			
						if (x_loc == k)
						{
							if (Rtraversal->data == " ")
							{
								x_loc++;
								goto jump1;
							}
						}
					}
				}
				else if (x_loc > xloc) // 6 > 3
				{
					reserved_x = x_loc;
					x_loc = x_loc - xloc;
					for (int i = 0; i < x_loc; i++)
					{
						node* Rnode;
						node* rtraversal = Rhead;
						Rnode = new node();
						Rnode->data = " ";

						while (rtraversal->right != NULL)
						{
							rtraversal = rtraversal->right;
						}

						rtraversal->right = Rnode;
						Rnode->left = rtraversal;
						rtraversal = Rnode;
					}
					goto jump2;
				}
			}

		}
		// 1 qaudrant y-axis condition, because of break
		else if (x_loc >= 0 && y_loc >= 0)
		{	//---------------------------------------------{  Y - AXIS  }--------------------------------------------------//
			jump:
			if (Thead == NULL)
			{
				node* newTnodes;
				//---------------------------------------------{  Y - AXIS  }--------------------------------------------------//
				for (int i = 0; i < y_loc; i++)
				{
					if (i == 0)
					{
						newTnodes = new node();
						newTnodes->data = " ";
						// here the head is set for RIGHT nodes access
						Thead = newTnodes;
					}
					else
					{
						node* Ttail = Thead;
						newTnodes = new node();
						newTnodes->data = " ";
						while (Ttail->up != NULL)
						{
							Ttail = Ttail->up;
						}
						Ttail->up = newTnodes;
						newTnodes->down = Ttail;
						Ttail = newTnodes;
					}
					if (i == temp_y)
					{
						node* adata = Thead;
						COORD coord;
						coord.X = x_loc;
						coord.Y = y_loc;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						cin >> text;
						while (adata->up != NULL)
						{
							adata = adata->up;
						}
						adata->data = text;
						yloc = y_loc;
						break;
					}
				}
			}
			else if (Thead != NULL)
			{
				// if right linked list head not empty
				// 1 base condition for the traversal and adding data to the exisiting node's
			jump1:
				if (y_loc < yloc) // 3 < 4
				{
					y_loc--;
					int k = 0;
					node* ttraversal = Thead;
					while (ttraversal != NULL)
					{
						k++;
						ttraversal = ttraversal->up;

						if (y_loc == k)
						{
							if (ttraversal->data == " ")
							{
								y_loc++;
								COORD coord;
								coord.X = x_loc;
								coord.Y = y_loc;
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
								cin >> text;
								ttraversal->data = text;
								break;
							}
						}
					}
				}
			}
			else if (Thead != NULL)
			{
			jump2:
				if (y_loc > yloc) // 6 > 4
				{
					reserved_y = y_loc;
					node* Tnode = NULL;
					y_loc = y_loc - yloc;
					
					for (int i = 0; i < y_loc; i++)
					{
						node* ttraversal = Thead;
						
						while (ttraversal->up != NULL)
						{
							ttraversal = ttraversal->up;
						}

						Tnode = new node();
						Tnode->data = " ";
						ttraversal->up = Tnode;
						Tnode->down = ttraversal;
						ttraversal = Tnode;
					}

					COORD coord;
					coord.X = reserved_x;
					coord.Y = reserved_y;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					cin >> text;
					Tnode->data = text;
					x_loc = reserved_x;
					y_loc = reserved_y;
				}
			}
		}

		// reserved value
		xloc = x_loc;
		yloc = y_loc;
	}
};
int notepad::xloc = 0;
int notepad::yloc = 0;
int main()
{
	notepad NT; int XLOC = 0; int YLOC = 0;
	bool continu = true; int choice = 0;


		while (continu)
		{
			system("PAUSE");
			system("cls");

			cout << "Welcome to the world of mystery" << endl;
			cout << "-----------NOTEPAD-------------" << endl << endl;
			cout << "Press 1 to Add text" << endl;
			cout << "Press 2 to Delete text" << endl;
			cout << "Press 3 to Search words" << endl;
			cout << "Press 4 to Copy text" << endl;
			cout << "Press 5 to Paste text" << endl;
			cout << "Press 6 to Undo text" << endl;
			cout << "Press 7 to Found total words" << endl;
			cout << "Press 8 to exit program" << endl;
			cout << "------------------------------" << endl;
			cout << "Enter the choice : ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				cout << "Enter the x axis location : ";
				cin >> XLOC;
				cout << "Enter the y axis location : ";
				cin >> YLOC;
				system("cls");
				NT.addtext(XLOC, YLOC);

				break;
			}
		}

		system("PAUSE");
		return 0;
}
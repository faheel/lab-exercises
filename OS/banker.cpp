#include <iostream>

using namespace std;

const int Max_Res = 5;
const int Max_Proc = 10;

void print_need(int need[Max_Proc][Max_Res], int num_proc, int num_res)
{
	cout << "   ";
	for (j = 0; j < num_res; j++)
		cout << " " << char('A' + j) << " ";
	for (i = 0; i < num_proc; i++)
	{
		cout << "\nP" << i+1 << " ";
		for (j = 0; j < num_res; j++)
			cout << " " << need[i][j] << " ";
	}
	cout << "\n";
}

void safety_test()
{

}

int main()
{
	int total[Max_Res],
		avail[Max_Res],
		max_req[Max_Proc][Max_Res],
		alloc[Max_Proc][Max_Res],
		need[Max_Proc][Max_Res],
		num_res,
		num_proc,
		i, j;

	cout << "Enter the number of resources (max " << Max_Res << ") : ";
	cin >> num_res;

	cout << "Enter total number of each resource:\n";
	for (i = 0; i < num_res; i++)
	{
		cout << char('A' + i) << " : ";
		cin >> total[i];
	}

	cout << "Enter the number of processes (max " << Max_Proc << ") : ";
	cin >> num_proc;

	cout << "Enter max request and allocated resources for each process:";
	for (i = 0; i < num_proc; i++)
	{
		cout << "\nP" << i+1 << ":\n";
		
		cout << "Max request for resources:\n";
		for (j = 0; j < num_res; j++)
		{
			cout << char('A' + i) << " : ";
			cin >> max_req[i][j];
		}
		
		cout << "Allocated resources:\n";
		for (j = 0; j < num_res; j++)
		{
			cout << char('A' + i) << " : ";
			cin >> alloc[i][j];

			avail[j] = total[j] - alloc[i][j];
			need[i][j] = max_req[i][j] - alloc[i][j];
		}
	}

	cout << "Need matrix:\n";
	printNeed(need, num_proc, num_res);



	return 0;
}
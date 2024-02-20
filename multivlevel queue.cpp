#include <iostream>
using namespace std;
class MPQ
{
public:
	int process;		// Process Name
	int queue_priority; // Queue Priority
	int bt;				// Burst Time
	int wt;				// Waiting Time
	int tat;			// Turn Around Time
};
int main()
{
	cout << "Enter Number of Process :";
	int n;
	cin >> n;
	MPQ *p = new MPQ[n];
	// Taking Input of Burst Time and Queue Priority.
	for (int i = 0; i < n; i++)
	{
		p[i].process = i + 1;
		cout << "Enter Burst Time of Process P" << i + 1 << " :";
		cin >> p[i].bt;
		cout << "Enter Queue Priority (0/1/2) of Process P" << i + 1 << " :";
		cin >> p[i].queue_priority;
	}
	// Sorting Processes According to Queue Priority.
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].queue_priority > p[j + 1].queue_priority)
			{
				swap(p[j].bt, p[j + 1].bt);
				swap(p[j].process, p[j + 1].process);
				swap(p[j].queue_priority, p[j + 1].queue_priority);
			}
		}
	}
	// Calculating Waiting Time.
	// Setting first Waiting time = 0;
	p[0].wt = 0;
	for (int i = 1; i < n; i++)
	{
		p[i].wt = p[i - 1].bt + p[i - 1].wt;
	}
	// Calculating Turn Around Time.
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].wt + p[i].bt;
	}
	// Printing Processes Scheduling.
	cout << "P"
		 << " "
		 << "Q_P"
		 << " "
		 << "BT"
		 << " "
		 << "WT"
		 << " "
		 << "TAT"
		 << " " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "P" << p[i].process << " " << p[i].queue_priority << " " << p[i].bt << " " << p[i].wt <<" "<<p[i].tat<<endl;
	}
	// Printing Average Waiting and Turn Around time.
	int wait = 0;
	int turn = 0;
	for (int i = 0; i < n; i++)
	{
		wait += p[i].wt;
		turn += p[i].tat;
	}
	cout << "Average Waiting time is :" << (float)wait / n << endl;
	cout << "Average Turn Around time is :" << (float)turn / n << endl;
	return 0;
}

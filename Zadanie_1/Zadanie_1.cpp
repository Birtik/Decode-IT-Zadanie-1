#include <iostream>


using namespace std;

class Task
{
    unsigned int c, k, w;

public:

    void SetValues()
    {
        try
        {
            cin >> c >> k >> w;

            if (c < 1 || k < 1 || w < 1 || c > 100 || k > 100 || w > 100)
                throw 1;
        }
        catch (int x) {
            cout << "Incorrect input data!";
            exit(0);
        }
    }

    string GetValues()
    {
        if (k / w >= c) return "yes\n";

        return "no\n";
    }

};


int main()
{
    unsigned int t;

    try
    {
        cin >> t;
        if (t > 100) throw 1;
    }
    catch (int x) {
        cout << "Too much Tests!";
        exit(0);
    }

    Task** task = new Task * [t];

    for (int i = 0; i < t; i++)
    {
        task[i] = new Task;
        task[i]->SetValues();
    }

    for (int i = 0; i < t; i++)
    {
        cout << task[i]->GetValues();
        delete task[i];
    }

    delete[] task;

}

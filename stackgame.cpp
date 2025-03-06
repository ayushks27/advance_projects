#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

void createGame1(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(3);
    s2.push(1);
    s2.push(2);
    s3.push(2);
    s3.push(3);
    s3.push(1);
}

void createGame2(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(1);
    s2.push(1);
    s2.push(2);
    s3.push(2);
    s3.push(3);
    s3.push(3);
}

void createGame3(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    s1.push(3);
    s1.push(2);
    s1.push(3);
    s2.push(1);
    s2.push(2);
    s2.push(1);
    s3.push(2);
    s3.push(1);
    s3.push(3);
}

void createGame4(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    s1.push(4);
    s1.push(6);
    s1.push(5);
    s2.push(4);
    s2.push(5);
    s2.push(6);
    s3.push(5);
    s3.push(6);
    s3.push(4);
}

void createGame5(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s2.push(5);
    s2.push(4);
    s2.push(6);
    s3.push(6);
    s3.push(4);
    s3.push(5);
}

void createGame6(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s2.push(6);
    s2.push(4);
    s2.push(5);
    s3.push(5);
    s3.push(4);
    s3.push(6);
}

void createMove(stack<int> &a, stack<int> &b)
{
    if (b.empty())
    {
        b.push(a.top());
        a.pop();
    }
    else if (a.top() == b.top())
    {
        b.push(a.top());
        a.pop();
    }
    else
        cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
}

int checkStack(stack<int> s1)
{
    vector<int> v;
    while (!s1.empty())
    {
        v.push_back(s1.top());
        s1.pop();
    }
    int flag = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

int winningCondition(stack<int> &s1, stack<int> &s2, stack<int> &s3, stack<int> &s4)
{
    if (s1.empty() && checkStack(s2) && checkStack(s3) && checkStack(s4))
        return 1;
    else if (s2.empty() && checkStack(s1) && checkStack(s3) && checkStack(s4))
        return 1;
    else if (s3.empty() && checkStack(s1) && checkStack(s2) && checkStack(s4))
        return 1;
    else if (s4.empty() && checkStack(s1) && checkStack(s2) && checkStack(s3))
        return 1;
    else
        return 0;
}

void printStack(stack<int> a)
{
    while (!a.empty())
    {
        cout << a.top() << endl;
        a.pop();
    }
}

int main()
{
    cout << "RULES:" << endl;
    cout << "1. THE ELEMENTS ARE PUT INTO THREE STACKS IN RANDOM ORDER." << endl;
    cout << "2. YOU ARE GIVEN AN EXTRA EMPTY STACK." << endl;
    cout << "3. YOU CAN PUSH AN ELEMENT INTO THE STACK ONLY IF SIZE OF THE STACK IS LESS THAN 3 AND THE TOP ELEMENT EQUALS THE ELEMENT WHICH YOU WOULD BE PUSHING IN." << endl;
    cout << "4. YOUR WORK IS TO USE ALL STACKS AND CREATE A WINNING SCENARIO SUCH THAT ALL NUMBERS IN A STACK ARE EQUAL." << endl;
    cout << "5. TRY TO GET IT DONE IN MINIMUM NUMBER OF MOVES AS EVERY WRONG MOVE COUNTS." << endl;
    cout << "6. MAKE THE MOVE CONTAINS TAKES INPUT OF TWO INTEGERS: " << endl;
    cout << "7. INTEGER 1: THE STACK YOU ARE CHOOSING TO MOVE THE ELEMENT FROM." << endl;
    cout << "8. INTEGER 2: THE STACK YOU ARE CHOOSING TO MOVE THE ELEMENT IN." << endl;
    cout << "9. CODES: '1' FOR STACK 1, '2' FOR STACK 2, '3' FOR STACK 3, '4' FOR STACK 4" << endl;
    cout << "10. TYPE 'YES' IF YOU WANT TO MOVE ON TO THE NEXT LEVEL. ELSE TYPE 'NO'." << endl;
    cout << "11. TRY TO PLAY CAUTIOUSLY BECAUSE IF YOU ARRIVE AT AN UNPLAYABLE SITUATION, YOU MIGHT HAVE TO START ALL OVER AGAIN BY REFRESHING YOUR TERMINAL." << endl << endl;
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    stack<int> s4;
    createGame1(s1, s2, s3, s4);
    cout << "First Stack: " << endl;
    printStack(s1);
    cout << "Second Stack: " << endl;
    printStack(s2);
    cout << "Third Stack: " << endl;
    printStack(s3);
    cout << "Fourth Stack: " << endl;
    printStack(s4);
    cout << endl;
    int score = 0;
    int i = 0;
    do
    {
        int a, b;
        cout << "Make the move: ";
        cin >> a >> b;
        cout << endl;
        i++;
        if (a == 1 && b == 2)
        {
            if (s2.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s1, s2);
        }
        else if (a == 2 && b == 1)
        {
            if (s1.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s2, s1);
        }
        else if (a == 1 && b == 3)
        {
            if (s3.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s1, s3);
        }
        else if (a == 3 && b == 1)
        {
            if (s1.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s3, s1);
        }
        else if (a == 1 && b == 4)
        {
            if (s4.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s1, s4);
        }
        else if (a == 4 && b == 1)
        {
            if (s1.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s4, s1);
        }
        else if (a == 2 && b == 3)
        {
            if (s3.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s2, s3);
        }
        else if (a == 3 && b == 2)
        {
            if (s2.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s3, s2);
        }
        else if (a == 2 && b == 4)
        {
            if (s4.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s2, s4);
        }
        else if (a == 4 && b == 2)
        {
            if (s2.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s4, s2);
        }
        else if (a == 3 && b == 4)
        {
            if (s4.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s3, s4);
        }
        else if (a == 4 && b == 3)
        {
            if (s3.size() >= 3)
                cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
            else
                createMove(s4, s3);
        }
        else
            cout << "Invalid Move." << endl;
        cout << "First Stack: " << endl;
        printStack(s1);
        cout << "Second Stack: " << endl;
        printStack(s2);
        cout << "Third Stack: " << endl;
        printStack(s3);
        cout << "Fourth Stack: " << endl;
        printStack(s4);
        cout << endl;
        cout << "MOVES MADE: " << i << endl
             << endl;
    } while (!winningCondition(s1, s2, s3, s4));
    if (winningCondition(s1, s2, s3, s4))
        cout << "YOU WIN THE LEVEL!!!" << endl;
    cout << "TOTAL MOVES TAKEN: " << i << endl;
    score += i;
    string s;
    cout << "MOVE TO THE NEXT LEVEL (YES/NO): ";
    cin >> s;
    bool x;
    if (s == "YES" || s == "yes" || s == "Yes" || s == "YEs")
        x = true;
    else
        x = false;
    int j = 2;
    while (x)
    {
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        stack<int> s4;
        if (j == 2)
            createGame2(s1, s2, s3, s4);
        if (j == 3)
            createGame3(s1, s2, s3, s4);
        if (j == 4)
            createGame4(s1, s2, s3, s4);
        if (j == 5)
            createGame5(s1, s2, s3, s4);
        if (j == 6)
            createGame6(s1, s2, s3, s4);
        cout << "First Stack: " << endl;
        printStack(s1);
        cout << "Second Stack: " << endl;
        printStack(s2);
        cout << "Third Stack: " << endl;
        printStack(s3);
        cout << "Fourth Stack: " << endl;
        printStack(s4);
        cout << endl;
        int i = 0;
        do
        {
            int a, b;
            cout << "Make the move: ";
            cin >> a >> b;
            cout << endl;
            i++;
            if (a == 1 && b == 2)
            {
                if (s2.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s1, s2);
            }
            else if (a == 2 && b == 1)
            {
                if (s1.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s2, s1);
            }
            else if (a == 1 && b == 3)
            {
                if (s3.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s1, s3);
            }
            else if (a == 3 && b == 1)
            {
                if (s1.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s3, s1);
            }
            else if (a == 1 && b == 4)
            {
                if (s4.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s1, s4);
            }
            else if (a == 4 && b == 1)
            {
                if (s1.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s4, s1);
            }
            else if (a == 2 && b == 3)
            {
                if (s3.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s2, s3);
            }
            else if (a == 3 && b == 2)
            {
                if (s2.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s3, s2);
            }
            else if (a == 2 && b == 4)
            {
                if (s4.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s2, s4);
            }
            else if (a == 4 && b == 2)
            {
                if (s2.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s4, s2);
            }
            else if (a == 3 && b == 4)
            {
                if (s4.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s3, s4);
            }
            else if (a == 4 && b == 3)
            {
                if (s3.size() >= 3)
                    cout << "WRONG MOVE. TRY AGAIN!!!" << endl;
                else
                    createMove(s4, s3);
            }
            else
                cout << "Invalid Move." << endl;
            cout << "First Stack: " << endl;
            printStack(s1);
            cout << "Second Stack: " << endl;
            printStack(s2);
            cout << "Third Stack: " << endl;
            printStack(s3);
            cout << "Fourth Stack: " << endl;
            printStack(s4);
            cout << endl;
            cout << "MOVES MADE: " << i << endl
                 << endl;
        } while (!winningCondition(s1, s2, s3, s4));
        if (winningCondition(s1, s2, s3, s4))
            cout << "YOU WIN THE LEVEL!!!" << endl;
        cout << "TOTAL MOVES TAKEN: " << i << endl;
        score += i;
        j++;
        if (j==7) break;
        cout << "MOVE TO THE NEXT LEVEL (YES/NO): ";
        cin >> s;
        if (s == "YES" || s == "yes" || s == "Yes" || s == "YEs")
            x = true;
        else
            x = false;
    }
    cout << endl << "YOUR TOTAL SCORE IS: " << score << endl;
}
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int value;
    ListNode *next;
};

void insertion(ListNode *&head, int value)
{
    ListNode *p;
    if (head == nullptr)
    {
        p = new ListNode;
        p->value = value;
        p->next = nullptr;
        head = p;
    }
    else
    {
        ListNode *q = head;
        while (q->next)
            q = q->next;

        p = new ListNode;
        p->value = value;
        p->next = nullptr;
        q->next = p;
    }
}
void printList(ListNode *&head)
{
    ListNode *p = head;
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        while (p != nullptr)
        {
            cout << p->value << "  ";
            p = p->next;
        }
        cout << endl;
    }
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *p = head;
    ListNode *q = head;

    int i = 1;
    while (q->next != nullptr)
    {
        if (i > n)
            p = p->next;
        q = q->next;
        i++;
    }
    
    if (i == n)
        return head->next;
    
    p->next = p->next->next;
    return head;
}

int main()
{
    vector<int> input = {1, 2};
    ListNode *head = nullptr;

    for (int i = 0; i < input.size(); i++)
    {
        insertion(head, input[i]);
    }
    head = removeNthFromEnd(head, 2);
    printList(head);
}
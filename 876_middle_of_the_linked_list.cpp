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

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6};
    ListNode *head = nullptr;

    for (int i = 0; i < input.size(); i++)
    {
        insertion(head, input[i]);
    }
    head = middleNode(head);
    printList(head);
}
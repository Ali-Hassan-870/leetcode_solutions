#include <iostream>
#include <vector>
#include <unordered_map>
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

/*using hashmap*/
// bool hasCycle(ListNode*head)
// {
//     unordered_map<ListNode*, bool> track;
//     ListNode *p = head;
//     while (p!=nullptr)
//     {
//         if(track.count(p))
//             return true;
//         track[p] = true;
//         p = p->next;
//     }
//     return false;

// }

/*using two pointers*/
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6};
    ListNode *head = nullptr;

    for (int i = 0; i < input.size(); i++)
    {
        insertion(head, input[i]);
    }
    printList(head);
    cout << head << endl;
}
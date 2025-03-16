#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void insertion(ListNode *&head, int val)
{
    ListNode *p;
    if (head == nullptr)
    {
        p = new ListNode;
        p->val = val;
        p->next = nullptr;
        head = p;
    }
    else
    {
        ListNode *q = head;
        while (q->next)
            q = q->next;

        p = new ListNode;
        p->val = val;
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
            cout << p->val << "  ";
            p = p->next;
        }
        cout << endl;
    }
}

ListNode *mergeFunction(ListNode *first, ListNode *second)
{
    ListNode *curr1 = first;
    ListNode *forw1 = curr1->next;
    ListNode *curr2 = second;
    ListNode *forw2 = curr2->next;

    while (forw1 != nullptr && curr2 != nullptr)
    {
        if (curr2->val >= curr1->val && curr2->val <= forw1->val)
        {
            curr1->next = curr2;
            forw2 = curr2->next;
            curr2->next = forw1;
            curr1 = curr2;
            curr2 = forw2;
        }
        else
        {
            curr1 = forw1;
            forw1 = forw1->next;
            if (forw1 == nullptr)
                curr1->next = curr2;
        }
    }
    return first;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return list2;

    if (list2 == nullptr)
        return list1;

    if (list1->val <= list2->val)
        return mergeFunction(list1, list2);

    return mergeFunction(list2, list1);
}




int main()
{
    vector<int> input1 = {2};
    vector<int> input2 = {1};
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;

    for (int i = 0; i < input1.size(); i++)
    {
        insertion(head1, input1[i]);
    }

    for (int i = 0; i < input2.size(); i++)
    {
        insertion(head2, input2[i]);
    }
    // head = removeNthFromEnd(head, 2);
    // printList(head1);
    // printList(head2);
    ListNode *output = mergeTwoLists(head1, head2);
    printList(output);
}
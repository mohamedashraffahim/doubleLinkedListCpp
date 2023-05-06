#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data = 0;
    node *next = NULL, *prev = NULL;
};

class dll
{
    node *head = NULL, *tail = NULL;

public:
    dll()
    {
        head = new node;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
    }
    dll(int n, node *in = 0)
    {
        head = new node;
        tail = head;
        head->data = n;
        head->next = in;
        in->prev = head;
        if (in)
            tail = in;
    }
    node *getHead()
    {
        return head;
    }
    node *getTail()
    {
        return tail;
    }
    void insertAtHead(int n)
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = new node;
            tmp->data = n;
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
            tmp = NULL;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            head->data = n;
            return;
        }
        else
        {
            head = new node;
            head->data = n;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
            return;
        }
    }
    void insertAtTail(int n)
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = new node;
            tmp->data = n;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
            tmp = NULL;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            head->data = n;
            return;
        }
        else
        {
            head = new node;
            head->data = n;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
        }
    }
    int doubleLinkedListSize()
    {
        int count = 0;
        node *tmp = head;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        tmp = NULL;
        delete tmp;
        return count;
    }
    void insertAt(int n, int index)
    {
        if (index == 1)
        {
            insertAtHead(n);
            return;
        }
        if (index == doubleLinkedListSize() + 1)
        {
            insertAtTail(n);
            return;
        }
        node *tmp = new node, *tmp2 = head;
        tmp->data = n;
        while (--index)
            tmp2 = tmp2->next;
        tmp->next = tmp2;
        tmp->prev = tmp2->prev;
        tmp2->prev->next = tmp;
        tmp2->prev = tmp;
        tmp = NULL;
        tmp2 = NULL;
        delete tmp;
    }
    void removeAtHead()
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = head;
            head = head->next;
            head->prev = NULL;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            delete head;
            delete tail;
            return;
        }
    }
    void removeAtTail()
    {
        if (head != NULL && head->data != 0)
        {
            node *tmp = head;
            while (tmp != tail)
            {
                tmp = tmp->next;
            }
            tail = tail->prev;
            tail->next = NULL;
            delete tmp;
            return;
        }
        else if (head != NULL && head->data == 0)
        {
            delete head;
            delete tail;
            return;
        }
    }
    void removeAt(int i)
    {
        node *tmp = head;
        if (i == 1)
        {
            removeAtHead();
            return;
        }
        if (i == doubleLinkedListSize())
        {
            removeAtTail();
            return;
        }
        while (--i)
            tmp = tmp->next;
        if (tmp != NULL)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        }
    }
    int retrieveAt(int i)
    {
        node *tmp = head;
        while (--i)
            tmp = tmp->next;
        return tmp->data;
    }
    void replaceAt(int a, int i)
    {
        node *tmp = head;
        while (--i)
            tmp = tmp->next;
        tmp->data = a;
    }
    bool isExist(int i)
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == i)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    bool isItemAtEqual(int a, int i)
    {
        node *tmp = head;
        while (--i)
            tmp = tmp->next;
        if (tmp->data == a)
            return true;
        return false;
    }
    void swap(int i1, int i2)
    {
        node *tmp = head, *tmp2 = head;
        int y = 0;
        if ((i1 == 1 && i2 == 2) || (i1 == 2 && i2 == 1))
        {
            tmp = head->next;
            head->next = tmp->next;
            tmp->next->prev = head;
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
            tmp->prev = NULL;
        }
        else if ((i1 == 1 && i2 == doubleLinkedListSize()) || (i1 == doubleLinkedListSize() && i2 == 1))
        {
            tmp = tail->prev;
            tmp->next = head;
            tail->next = head->next;
            head->next->prev = tail;
            head->prev = tmp;
            head = tail;
            tail = tmp->next;
            head->prev = NULL;
            tail->next = NULL;
        }
        else if ((i1 == 1 && i2 != 1) || (i2 == 1 && i1 != 1))
        {
            if (i1 == 1 && i2 != 1)
            {
                while (--i2)
                    tmp = tmp->next;
                tmp2 = head->next;
                tmp->next->prev = head;
                tmp->prev->next = head;
                head->next->prev = tmp;
                head->next = tmp->next;
                head->prev = tmp->prev;
                tmp->next = tmp2;
                tmp->prev = NULL;
                head = tmp;
            }
            else
            {
                while (--i1)
                    tmp = tmp->next;
                tmp2 = head->next;
                tmp->next->prev = head;
                tmp->prev->next = head;
                head->next->prev = tmp;
                head->next = tmp->next;
                head->prev = tmp->prev;
                tmp->next = tmp2;
                tmp->prev = NULL;
                head = tmp;
            }
        }
        tmp = NULL;
        delete tmp;
    }
    void clear()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            removeAtHead();
        }
        delete tmp;
    }
    void forwardTraversal()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        tmp = NULL;
        delete tmp;
    }
    void backwardTraversal()
    {
        node *tmp = tail;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }
        tmp = NULL;
        delete tmp;
    }
    friend ostream &operator<<(ostream &out, dll &a)
    {
        node *tmp = a.getHead();
        while (tmp != NULL)
        {
            out << tmp->data << " ";
            tmp = tmp->next;
        }
        tmp = NULL;
        delete tmp;
        return out;
    }
};

int main()
{
    dll a;
    a.insertAtHead(2);
    a.insertAtHead(1);
    a.insertAtTail(3);
    a.insertAtTail(4);
    a.insertAt(55, 1);
    // a.removeAtHead();
    // a.removeAtTail();
    // a.removeAt(4);
    a.swap(1, 5);
    // a.insertAt(55, 5);
    // a.replaceAt(55, 4);
    // cout << a.isExist(5);
    // cout << a.isItemAtEqual(5, 1);
    // a.swap(2, 1);
    a.forwardTraversal();
    cout << endl;
    a.backwardTraversal();
    // a.insertAt(555, 4);
    // a.removeAt(1);
    // cout << a.retrieveAt(1);
    // a.insertAtHead(3);
    // cout << a;
    return 0;
}
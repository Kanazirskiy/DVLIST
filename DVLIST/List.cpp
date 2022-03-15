#include "List.h"

List::Node::Node()
{
    value = 0;
    next = nullptr;
    prev = nullptr;
}

List::Node::Node(int valuex, Node* nextx, Node* prevx)
{
    value = valuex;
    next = nextx;
    prev = prevx;
}

List::List()
{
    sizep = 0;
    head = nullptr;
    tail = nullptr;
}
List::~List()
{
    while (sizep)
        pop_front();
}

List::List(const List& other)
{
    *this=other;
}

void List::push_back(int element)
{
    if (head == nullptr)
    {
        head = new Node(element);
        tail = head;
    }
    else {
        Node* curr = tail;
        curr->next = new Node(element);
        tail = curr->next;
        tail->prev = curr;
    }
    sizep++;
}

void List::push_front(int element)
{
    head = new Node(element, head);
    sizep++;
}

void List::insert(size_t i, int element)
{
    if (i == 0)
        push_front(element);
    else if (i == (sizep - 1))
        push_back(element);
    else {
        Node* tmp = head;
        for (size_t k = 0; k < i - 1; ++k)
        {
            tmp = tmp->next;
        }

        Node* newNode = new Node(element, tmp->next,tmp);
        tmp->next->prev = newNode;
        tmp->next = newNode;
        sizep++;
    }

}

void List::erase(size_t i)
{
    if (i == 0)
        pop_front();
    else
    {
        Node* last = head;
        for (size_t k = 0; k < i - 1; ++k)
            last = last->next;

        Node* tmp = last->next;
        last->next = tmp->next;
        if (!(i == (sizep - 1)))
            tmp->next->prev = last;
        else
            tail = last;
        delete tmp;
        sizep--;
    }
}

void List::pop_back()
{
    erase(sizep - 1);
}

void List::pop_front()
{
    Node* tmp = head;
    if (sizep != 1)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete tmp;
    sizep--;
}

void List::assign(List& other)
{
    while (sizep)
        pop_front();
    if (other.sizep != 0)
    {
        head = new Node(other.head->value);
        tail = head;
        sizep++;
        Node* tmp2 = other.head;
        for (size_t i = 1; i < other.sizep; i++)
        {
            tmp2 = tmp2->next;
            push_back(tmp2->value);
        }
    }
    else
    {
        sizep = 0;
    }
}

void List::resize(size_t n,int x)
{
    size_t temp = sizep;
    if (temp > n)
    {
        for (temp; temp > n; temp--)
            pop_back();
    }
    else if (temp < n)
    {
        for (temp; temp < n; temp++)
            push_back(x);
    }   
}

int& List::operator[] (size_t n)
{

    if (n >= sizep)
        throw std::runtime_error("index out of range");
    size_t count = 0;
    Node* tmp = head;
    while (tmp != nullptr)
    {
        if (count == n)
            return tmp->value;
        tmp = tmp->next;
        count++;
    }
    return head->value;

}

List& List::operator=(const List& other)
{
    while (sizep)
        pop_front();
    if (other.sizep != 0)
    {
        head = new Node(other.head->value);
        tail = head;
        sizep++;
        Node* tmp2 = other.head;
        for (size_t i = 1; i < other.sizep; i++)
        {
            tmp2 = tmp2->next;
            push_back(tmp2->value);
        }
    }
    else
    {
        sizep = 0;
    }
    return *this;
}

void List::reverse()
{
    Node* tmp = head;
    Node* tmp2;
    for (size_t i = 0; i < size(); ++i)
    {
        tmp2 = tmp->prev;
        tmp->prev = tmp->next;
        tmp->next = tmp2;
        tmp = tmp->prev;
    }
    tmp = head;
    head = tail;
    tail = tmp;
}

void List::swap(List& other)
{
    List c(*this);
    (*this) = other;
    other = c;
}

void List::clear()
{
    while (sizep)
        pop_front();
}

bool List::empty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

int& List::front()
{
    return head->value;
}
int& List::back()
{
    return tail->value;
}
size_t List::size()
{
    return sizep;
}
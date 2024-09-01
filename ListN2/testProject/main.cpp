//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include <iostream>





struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List(): m_head(new ListNode(static_cast<int>(0))), m_size(0), m_tail(new ListNode(0, m_head)) { }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

//юнит-тест
TEST_CASE("PushBack") {
   
    List L;
    REQUIRE(L.Empty());
    L.PushBack(9);
    L.PushBack(50);
    REQUIRE(L.Size() == 2);
    REQUIRE(!L.Empty());
  
}

TEST_CASE("PushFront") {

    List L;
    REQUIRE(L.Empty());
    L.PushFront(9);
    L.PushFront(50);
    REQUIRE(L.Size() == 2);
    REQUIRE(!L.Empty());

}

TEST_CASE("PopBack") {

    List L;
    CHECK(L.Empty());
    CHECK_THROWS_AS(L.PopBack(), std::runtime_error); //(L.PopBack() == 0);
    L.PushBack(9);
    CHECK(L.Size() == 1);
    L.PushBack(53);
    CHECK(L.Size() == 2);
    CHECK(L.PopBack() == 53);
    CHECK(L.PopBack() == 9);
    CHECK_THROWS_AS(L.PopBack(), std::runtime_error); //(L.PopBack() == 0);
    CHECK(L.Empty());
    CHECK(L.Size() == 0);

}

TEST_CASE("PopFront") {

    List L;
    CHECK(L.Empty());
    CHECK_THROWS_AS(L.PopFront(), std::runtime_error); 
    L.PushFront(9);
    CHECK(L.Size() == 1);
    L.PushFront(53);
    CHECK(L.Size() == 2);
    CHECK(L.PopFront() == 53);
    CHECK(L.PopFront() == 9);
    CHECK_THROWS_AS(L.PopFront(), std::runtime_error); 
    CHECK(L.Empty());
    CHECK(L.Size() == 0);

}

TEST_CASE("Complex test") {

    List L;
    L.PushBack(5);   // 5
    L.PushFront(6);  // 6, 5
    L.PushBack(8);   // 6, 5, 8
    L.PushFront(9);  // 9, 6, 5, 8
    CHECK(L.Size() == 4);

    CHECK(L.PopFront() == 9); // 6, 5, 8
    CHECK(L.PopBack() == 8);  // 6, 5
    CHECK(L.Size() == 2);

    CHECK(L.PopFront() == 6); // 5
    CHECK(L.PopBack() == 5);   // empty
    CHECK(L.Size() == 0);
    CHECK(L.Empty());
}
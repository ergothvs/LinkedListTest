// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.h"
void PrintInLinkedOrder(Node* firstNode);
Node* SortLowHighNumber(Node* firstNode);
void InsertAtIndex(Node* firstNode, Node* node, int index);
Node* RemoveAtIndex(Node* firstNode, int index);
std::vector<Node*> getNodesWithData(Node* firstNode, int data);
void printNodes(std::vector<Node*> nodes);
int main()
{
    Node* one = new Node();
    one->data = 1;
    Node* three = new Node();
    three->data = 3;
    Node* two = new Node();
    two->data = 2;
    Node* eight = new Node();
    eight->data = 8;
    Node* ten = new Node();
    ten->data = 10;
    one->nextNode = three;
    three->nextNode = two;
    two->nextNode = eight;
    eight->nextNode = ten;

    PrintInLinkedOrder(one);

    Node* twelve = new Node();
    twelve->data = 2;
    PrintInLinkedOrder(one);
    Node* newFirst2 = SortLowHighNumber(one);
    PrintInLinkedOrder(newFirst2);
    std::cout << "removing item at index 1\n";
    Node* newFirst = RemoveAtIndex(newFirst2, 1);
    PrintInLinkedOrder(newFirst);
    std::vector<Node*> nodes = getNodesWithData(newFirst, 2);
    std::cout << "Adding 2 at index 3\n";
    InsertAtIndex(newFirst, twelve, 3);
    PrintInLinkedOrder(newFirst);


}


void InsertAtIndex(Node* firstNode, Node* node, int index)
{
    Node* curNode = firstNode;
    for (int i = 0; i < index; i++)
    {
        curNode = curNode->nextNode;
    }
    Node* nextNode = curNode->nextNode;
    curNode->nextNode = node;
    curNode->nextNode->nextNode = nextNode;
}

Node* RemoveAtIndex(Node* firstNode, int index)
{
    Node* curNode = firstNode;
    Node* prevNode = nullptr;
    for (int i = 0; i < index; i++)
    {
        prevNode = curNode;
        curNode = curNode->nextNode;
    }
    if (prevNode == nullptr)
    {
        Node* newFirst = curNode->nextNode;
        delete curNode;
        return newFirst;
    }
    else
    {
        prevNode->nextNode = curNode->nextNode;
        delete curNode;
        return firstNode;
    }
}

std::vector<Node*> getNodesWithData(Node* firstNode, int data)
{
    Node* curNode = firstNode;
    std::vector<Node*> nodes;
    while (curNode != nullptr)
    {
        if (curNode->data == data)
        {
            nodes.push_back(curNode);
        }
        if (curNode->nextNode != nullptr)
        {
            curNode = curNode->nextNode;
        }
        else
        {
            printNodes(nodes);
            return nodes;
        }
    }
    printNodes(nodes);
    return nodes;
}

void printNodes(std::vector<Node*> nodes)
{
    printf("Amount of nodes with data 2: %i \n", nodes.size());
}


void PrintInLinkedOrder(Node* firstNode) {
    std::cout << "printing current order\n";
    Node* curNode = firstNode;
    while (curNode != nullptr)
    {
        std::cout << curNode->data<< std::endl;
        if (curNode->nextNode != nullptr)
        {
            curNode = curNode->nextNode;
        }
        else
        {
            return;
        }
    }

}
Node* SortLowHighNumber(Node* firstNode)
{
    std::cout << "Ordering the list from low number to high\n";
    Node* curNode = firstNode;
    std::vector<int> datas;
    while (curNode != nullptr)
    {
        datas.push_back(curNode->data);
        curNode = curNode->nextNode;
    }
    for (int i = 0; i < datas.size(); i++)
    {
        sort(datas.begin(), datas.end());
    }
    std::vector<Node*> newNodeOrder;
    newNodeOrder.resize(datas.size());

    //Order all nodes in a vector
    for (int i = 0; i < datas.size(); i++)
    {
        curNode = firstNode;
        for (int j = 0; j < datas.size(); j++)
        {
            int curData = datas.at(i);
            if (curNode->data == curData && newNodeOrder.at(i) == nullptr)
            {
                newNodeOrder.at(i) = curNode;
                j = datas.size();
            }
            if (curNode->nextNode != nullptr)
            {
                curNode = curNode->nextNode;
            }
            else
            {
                j = datas.size();
            }
        }
    }
    //Properly set the links
    for (int i = 0; i < newNodeOrder.size() - 1; i++) {
        Node* curNode = newNodeOrder.at(i);
        if (i < newNodeOrder.size())
        {
            curNode->nextNode = newNodeOrder.at(i + 1);
        }
        else
        {
            curNode->nextNode = nullptr;
        }
    }
    return newNodeOrder.at(0);

}
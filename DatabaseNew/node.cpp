//By Ethan Paek and Carter Duncan
#ifndef ITEM_CPP
#define ITEM_CPP

#include "node.h"

namespace coen79_lab7
{
    node::node(const std::string &itemName, const float &newPrice, node *nextNode) {
        name = itemName;
        price = newPrice;
        link = nextNode;
    }
    
    void node::setName(const std::string &newName) {
        name = newName;
    }
    
    void node::setPrice(const float &newPrice) {
        price = newPrice;
    }
    
    void node::setLink(node *new_next) {
        link = new_next;
    }
    
    node* node::getLink() {
        return link;
    }
    
    const node* node::getLink() const {
        return link;
    }
    
    std::string node::getName() const{
        return name;
    }
    
    float node::getPrice() const {
        return price;
    }
    
    
    void list_init(node*& head, node*& tail, const std::string& newName, const float& newPrice) {
        head = new node(newName, newPrice, NULL);
        tail = head;
    }
    
    
    void list_tail_insert(node*& tail, const std::string &newName, const float &newPrice) {
        node* tmp = new node(newName,newPrice);
        tail->setLink(tmp);
        tail = tail->getLink();
    }
    
    
    void list_clear(node*& head) {
        while(head!=NULL)
            list_head_remove(head);
    }
    
    
    void list_copy(const node *old_head, node* &new_head, node* &new_tail) {
        new_head = NULL;
        new_tail = NULL;
        const node *cur = old_head;
        node* temp;
        while (cur != NULL) {
            temp = new node(cur->getName(), cur->getPrice(), NULL);
            if (new_head == NULL) {
                new_head = temp;
                new_tail = temp;
            }
            else {
                new_tail->setLink(temp);
                new_tail = temp;
            }
            cur = cur->getLink();
        }
    }
    
    
    void list_head_remove(node*& head) {
        node* tmp = head;
        head = head->getLink();
        delete tmp;
    }
    
    
    void list_print(node *head) {
        node *cur = head;
        while (cur != NULL) {
            std::cout << "- " << cur->getName() << ", where the price is $" << cur->getPrice() << std::endl;
            cur = cur->getLink();
        }
    }
    
    
    bool list_contains_item(node *head_ptr, const std::string& newName) {
        return (list_search(head_ptr, newName) != NULL);
    }
    
    
    node* list_search(node* head_ptr, const std::string& target)
    {
        node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }
    
    
    const node* list_search(const node* head_ptr, const std::string & target)
    {
        const node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }
    
}

#endif

#include <iostream>

struct Node{
    int value;
    Node* next;
};

Node* create_empty_linked_list(){
    return nullptr;
}

Node* add_to_end(Node* head, int val){
    Node* current = head;
    Node* new_node = new Node();
    if(current == nullptr){
        current = new_node;
        new_node->value = val;
        new_node->next = nullptr;
        return head;
    }else{
        while(current->next != nullptr){
            current = current->next;
        }
    }
    current->next = new_node;
    new_node->value = val;
    new_node->next = nullptr;
    return head;
}

Node* add_to_beginning(Node* head, int val){
    Node* new_first_node = new Node();
    new_first_node->next = head;
    new_first_node->value = val;
    head = new_first_node;
    return head;
}

Node* traverseLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    return head;
}

Node* lengthLinkedList(Node* head){
    Node* current = head;
    int length = 0;
    while(current != nullptr){
        length ++;
        current = current->next;
    }
    std::cout << "Dlugosc linked listy to: "<< length << std::endl;
    return head;
}

Node* findInList(Node* head, int val){
    Node* current = head;
    int position = 0;
    bool found = false;
    while(current != nullptr){
        position ++;
        if(current->value == val){
            std::cout << "Wartość jest na pozycji: " << position << " i jej wartość wynosi: " << val << std::endl;
            found = true;
            break;
        }
        current = current->next;
    }
    if(found == false){
        std::cout << "Nie znalezion wartości: " << val << " w LinkedLiscie" << std::endl;
    }
    return head;
}

Node* add_to_certain_place(Node* head, int val, int pos){
    Node* current = head;
    int position = 0;
    while(current != nullptr && current->next != nullptr){
        position ++;
        if(current->next->value == pos && current->next != nullptr){
            Node* new_node = new Node();
            new_node->value = val;
            new_node->next = current->next;
            current->next = new_node;
            break;
        }   else{
            add_to_end(head, val);
            break;
        }
        current = current->next;
    }
    return head;
}

int main() {
    Node* head = new Node();
    head->value = 1;
    head->next = nullptr;
    
    head = add_to_beginning(head, 4);
    head = add_to_end(head, 2);
    head = add_to_end(head, 3);
    traverseLinkedList(head);
    lengthLinkedList(head);
    findInList(head, 1);
    head = add_to_certain_place(head, 5, 3);
    traverseLinkedList(head);
    return 0;
}
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
    new_node->value = val;
    
    if(head == nullptr){
        new_node->next = new_node;
        return new_node;
    }

    while(current->next != head && current->next != nullptr){
        current = current->next;
    }
    current->next = new_node;
    new_node->next = head;
    return head;
}

Node* add_to_beginning(Node* head, int val){
    Node* new_first_node = new Node();
    new_first_node->value = val;

    if(head == nullptr){
        new_first_node->next = new_first_node;
        return new_first_node;
    }

    Node* current = head;
    while(current->next != head && head != nullptr){
        current = current->next;
    }

    current->next = new_first_node;
    new_first_node->next = head;
    return new_first_node;
}

Node* traverseLinkedList(Node* head) {
    Node* current = head;
    if(head == nullptr){
        return head;
    }
    do{
        std::cout << current->value << " ";
        current = current->next;
    }while(current != head);
    std::cout << std::endl;
    return head;
}

Node* lengthLinkedList(Node* head){
    if(head == nullptr){
        std::cout << "Długość CircularLinkedList to: 0" << std::endl;
        return head;
    }

    int length = 0;
    Node* current = head;
    do{
        length++;
        current = current->next;
    }while(current != head);

    std::cout << "Długość CircularLinkedList to: " << length << std::endl;
    return head;
}

Node* findInList(Node* head, int val){
    if(head == nullptr){
        std::cout << "Nie znalezion wartości: " << val << " w CircularLinkedList. CircularLinkedList jest pusta." << std::endl;
        return head;
    }

    Node* current = head;
    int position = 1;
    do{
        if(current->value == val){
            std::cout << "Wartość "<< val <<" jest na pozycji: " << position << std::endl;
            return head;
        }
        position++;
        current = current->next;
    }while(current != head);

    std::cout << "Nie znalezion wartości: " << val << " w CircularLinkedList" << std::endl;
    return head;
}

Node* add_to_certain_place(Node* head, int val, int pos){
    Node* new_node = new Node();
    new_node->value = val;
    if(head == nullptr){
        head = new_node;
        new_node->next = new_node;
        return new_node;
    }

    Node* current = head;
    Node* prev = nullptr;

    do{
        if (current->value == pos) {
            new_node->next = current;

            if (prev == nullptr) {
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = new_node;
                return new_node; 
            } else {
                prev->next = new_node;
                return head;
            }
        }
        prev = current;
        current = current->next;
    }while(current != head);
    return add_to_end(head, val);
}

int main() {
    Node* head = new Node();
    head->value = 1;
    head->next = head;
    
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
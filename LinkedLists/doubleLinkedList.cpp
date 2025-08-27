#include <iostream>

struct Node{
    int value;
    Node* next;
    Node* previous;
};

Node* create_empty_linked_list(){
    return nullptr;
}

Node* add_to_end(Node* head, int val){
    Node* current = head;
    Node* new_node = new Node();
    new_node->value = val;
    new_node->next = nullptr;
    new_node->previous = nullptr;

    if(head == nullptr){
        return new_node;
    }

    while(current->next != nullptr){
        current = current->next;
    }
    
    current->next = new_node;
    new_node->previous = current;

    return head;
}

Node* add_to_begining(Node* head, int val){
    Node* new_node = new Node();
    new_node->value = val;

    if(head == nullptr){
        head = new_node;
        new_node->previous = nullptr;
        new_node->next = nullptr;
        return new_node;
    }

    new_node->next = head;
    new_node->previous = nullptr;
    head->previous = new_node;
    return new_node;
}

Node* traverseLinkedList(Node* head){
    if(head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return head;
    }

    Node* current = head;
    do{
        std::cout << current->value << " ";
        current = current->next;
    }while(current != nullptr);
    std::cout << std::endl;
    return head;
}

Node* lengthLinkedList(Node* head){
    if(head == nullptr){
        std::cout << "Długość DoubleLinkedList wynosi: 0." << std::endl;
        return head;
    }

    Node* current = head;
    int length = 0;

    do{
        length ++;
        current = current->next;
    }while(current != nullptr);
    std::cout << "Długość DoubleLinkedList wynosi: " << length << std::endl;
    return head;
}

Node* findInList(Node* head, int val){
    if(head == nullptr){
        std::cout << "Wartości: " << val << " nie znaleziono. Lista jest pusta." << std::endl;
        return head;
    }

    Node* current = head;
    int position = 1;

    do{
        if(current->value == val){
            std::cout << "Znaleziono element " << val << " na pozycji " << position << std::endl;
        }
        current = current->next;
        position++;
    }while(current != nullptr);
    return head;
}

Node* add_to_certain_place(Node* head, int val, int pos){
    if(head == nullptr){
        return add_to_end(head, val);
    }

    Node* new_node = new Node();
    new_node->value = val;
    Node* current = head;

    do{
        if(current->value == pos){
            if(current == head){
                new_node->previous = nullptr;
                new_node->next = current;
                current->previous = new_node;
                return new_node;
            }   else{
                Node* prev_node = current->previous;
                prev_node->next = new_node;
                new_node->previous = prev_node;
                new_node->next = current;
                current->previous = new_node;
                return head;
            }
        }
        current = current->next;
    }while(current != nullptr);

    return add_to_end(head, val);
}

int main(){
    Node* head = new Node();
    head->value = 1;
    head->next = nullptr;
    head->previous = nullptr;

    traverseLinkedList(head);
    head = add_to_end(head, 2);
    traverseLinkedList(head);
    head = add_to_begining(head, 3);
    traverseLinkedList(head);
    lengthLinkedList(head);
    findInList(head, 3);
    head = add_to_certain_place(head, 4, 2);
    traverseLinkedList(head);
    return 0;
}
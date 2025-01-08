// Group 9: Anders Liavåg Martinsen, Isak Wardenær Rønningen, Per Simen Reed, Preben Birkeland Wassbakk
#include <iostream>
using namespace std;

//number of nodes in the circular list
int nodes = 10;

// Struct which contains the data variable and a pointer to the next node
struct Node{
    int data;
    Node* next;
};

class JosephusCircle{
    Node* head;
public:
    JosephusCircle(){
        head = NULL;
    }

    // function that adds a person as the last element of the linked list
    void addPerson(int id){
        Node* newNode = new Node();
        newNode->data = id;
        newNode->next = nullptr;
        Node* tmp;

        // If no nodes has been added, head will become the first node
        if(head == nullptr){
            head = newNode;
        }
        else{
            tmp = head;
            // If there is other nodes in the list, the function will find the last element and add a new node.
            while(tmp != nullptr){
                if(tmp->next == nullptr){
                    tmp->next = newNode;
                    if(id == nodes){
                        newNode->next = head;
                        return;
                    }
                    return;
                }
                tmp = tmp->next;
            }
        }
    }


    void eliminateKthPerson(int k) {
        Node *tmp = head;

        while (tmp->next != tmp) {  //initial thought to check length of list for every loop until length = 1, but this requires to go through the whole list for every loop...
            for (int i = 0; i < k - 2; i++) { //skipping elements until we end up at the k-1 element, the kth element (tmp->next) will be deleted
                tmp = tmp->next;
            }
            Node *nodeToDelete = tmp->next; //make a new pointer to the node to be deleteed
            tmp->next = tmp->next->next; //secure a pointer to the node after the one deleted
            delete nodeToDelete; //deleting
            tmp = tmp->next; //updating the previous node's next pointer, we have successfully cut out the "middle" node
        }
        getLastRemainingPerson(tmp->data); //when tmp->next == tmp we know that we only have one node left and can call the getLastRemainingPerson function
    }

    int getLastRemainingPerson(int lastPerson){ //taking in tmp->data and printing it
        cout << "Last remaining ID: " << lastPerson << endl;
        return 0;
    }
};
int main(){
    int k;
    JosephusCircle circle;

    cout << "Give a number k, where the kth person will be eliminated each turn" << endl;
    cin >> k;

    for(int i = 1; i<=nodes; i++) { //calling on the addPerson() function and passing the id variable, also incrementing id for every person we add
        circle.addPerson(i);
    }
    circle.eliminateKthPerson(k); //calling to simulate the problem with the k as input from the user
}
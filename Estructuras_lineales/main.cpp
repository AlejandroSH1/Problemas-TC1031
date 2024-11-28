#include <iostream>

using namespace std;

struct Node {
    char problem;    
    Node* prev;      
    Node* next;     

    Node(char p) : problem(p), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addProblem(char problem) {
        if (exists(problem)) return;

        Node* newNode = new Node(problem);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool exists(char problem) {
        Node* current = head;
        while (current) {
            if (current->problem == problem) return true;
            current = current->next;
        }
        return false;
    }

    int size() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        DoublyLinkedList list;

        for (char problem : s) {
            list.addProblem(problem);
        }

        int uniqueProblems = list.size();
        int totalBalloons = uniqueProblems * 2 + (n - uniqueProblems);

        cout << totalBalloons << endl;

        list.clear();
    }

    return 0;
}

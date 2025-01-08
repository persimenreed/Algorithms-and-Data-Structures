#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class creating new elements based on user input
class E {
public:
    int priority;
    string name;
    string task;
};

// Fill in user input
E& getData(int i, vector<E>& tasks) {
    E* e = new E();
    cout << "-Task " << i+1 << "-" << endl;
    e->task = "Task"+to_string(i+1);
    // Check for duplicate names
    while (true) {
        cout << "Input a unique name for this task: " << endl;

        std::getline(std::cin, e->name);
        bool isUnique = true;
        for (const E& task : tasks) {
            if (task.name == e->name) {
                isUnique = false;
                cout << "A task with the same name already exists. Please choose a unique name." << endl;
                break;
            }
        }
        if (isUnique) {
            break;
        }
    }
    std::string prioTemp;
    bool correct = false;

    while (!correct) {
        std::cout << "Input the priority of the task: " << std::endl;
        cin >> prioTemp;
        if (!prioTemp.empty()) {
            bool isInteger = true;
            for (char c : prioTemp) {
                if (!std::isdigit(c)) {
                    isInteger = false;
                    break;
                }
            }

            if (isInteger) {
                int priority = std::stoi(prioTemp);
                correct = true;
            } else {
                std::cout << "Invalid input. Please enter an integer." << std::endl;
            }
        }
    }
    e->priority = stoi(prioTemp);
    return *e;
}

// Create the heap
void heapify(vector<E>& tasks, int& n, int i) {
    int largest = i;
    int left, right = 0;
    left = 2 * i + 1; //Left child of element
    right = 2 * i + 2; // Right child of element
    if (left < n && tasks[largest].priority < tasks[left].priority)
        largest = left;
    if (right < n && tasks[largest].priority < tasks[right].priority)
        largest = right;
    if (largest != i) {
        swap(tasks[i], tasks[largest]);
        heapify(tasks, n, largest);
    }
}

// Print the heap tree.
void printMaxHeap(const vector<E>& tasks, int n) {

    cout << "--------Task with the highest priority----------" << endl;
    cout << tasks[0].task << ": ";
    cout << tasks[0].name << ", Priority: " << tasks[0].priority << endl << endl;
    cout << "--------Next 3 Tasks in queue after " << tasks[0].name << "-------- " << endl;

    for (int i = 1; i < n; i++) {
        cout << tasks[i].task << ": ";
        cout << tasks[i].name << ", Priority: ";
        cout << tasks[i].priority << endl;
    }
    cout << endl << endl;
}



// Build the heap tree. This is only done once user is finished inputting.
void buildHeap(vector<E>& tasks, int& n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(tasks, n, i);
    }
}

// Function that prints all the tasks with top priority.
void printTopPriority(const vector<E>& tasks, int n){

    cout << tasks[0].task << ": ";
    cout << tasks[0].name << ", ";
    cout << "Priority: " << tasks[0].priority << " " << endl;

}

int main() {
    vector<E> tasks;

    while (true) {
        static int i = 0;
        E task = getData(i, tasks);

        tasks.push_back(task);

        // User interface to add more tasks or execute already added.
        cout << "Press 1 to input another task" << endl;
        cout << "Press 2 to go to execute menu" << endl;


        string choice;
        bool more = true;

        // Clear the input buffer by reading and discarding characters until a newline
        while (cin.get() != '\n');

        while (true) {
            choice = "";
            cin >> choice;

            if (choice == "2") {
                more = false;
                break;
            } else if (choice == "1") {
                while (cin.get() != '\n');
                more = true;
                break;
            } else {
                cout << "Invalid input, please enter 1 or 2, to add another task or go to execute menu" << endl;
            }
        }
        if (!more)
            break;
        i++;
    }

    int n = tasks.size();

    // Build heap when user presses 2.
    buildHeap(tasks, n);

    string nAmountOfTasks;
    string userInputMenu;
    while (cin.get() != '\n');

    while (true){
        cout << "enter 1 to print highest priority task" << endl;
        cout << "enter 2 to print n number of tasks in the heap" << endl;
        cout << "enter 3 to execute top task" << endl;
        cout << "enter 4 to exit program" << endl;
        cin >> userInputMenu;
        if (userInputMenu == "1") {
            printTopPriority(tasks, n);
        } else if (userInputMenu == "2") {
            bool correct = false;
            while (!correct) {
                std::cout << "Enter number of tasks to print " << std::endl;
                cin >> nAmountOfTasks;
                if (!nAmountOfTasks.empty()) {
                    bool isInteger = true;
                    for (char c : nAmountOfTasks) {
                        if (!std::isdigit(c)) {
                            isInteger = false;
                            break;
                        }
                    }
                    if (isInteger) {
                        int priority = std::stoi(nAmountOfTasks);
                        correct = true;
                    } else {
                        std::cout << "Invalid input. Please enter an integer." << std::endl;
                    }
                }
            }

            if(stoi(nAmountOfTasks)<=n)
                printMaxHeap(tasks, stoi(nAmountOfTasks));
            else
                cout << "You only have " << n << " tasks so you cannot print out " << nAmountOfTasks << endl << endl;
        } else if(userInputMenu == "3") {
            if(!tasks.empty()) {
                tasks.erase(tasks.begin());;
                n--;
                heapify(tasks, n, 0);
                cout << endl << "Executed and removed the highest-priority task." << endl;
                printMaxHeap(tasks, n);
            }else
                cout << "You have no more tasks in the queue" << endl;

        }
            else if(userInputMenu == "4") {
                cout << "exiting program"<< endl;
                return 0;

        }
            else
                cout << "Please enter a valid input"<< endl << endl;
    }


    return 0;
}
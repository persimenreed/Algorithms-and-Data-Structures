#include <iostream>
#include <string>

using namespace std;

const int inf = 999999; // defining inf to a high number
const int vertices = 7; // num of vertices, can be changed if user wants to try with different matrix

struct RoutingTableEntry {
    int destination;
    int nextHop;
    int totalCost;
};

void printRoutingTable(RoutingTableEntry routingTable[][vertices], int origMatrix[][vertices]); // defining function for the printRoutingTable, to use later in code

void floydWarshall(RoutingTableEntry routingTable[][vertices], int origMatrix[][vertices]) { // The main part of the code: The Floyd-Warshall-algorithm.
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) { // Here the routing table is updated based on the matrix
            routingTable[i][j].destination = j + 1;
            routingTable[i][j].nextHop = (i != j && origMatrix[i][j] != inf) ? i + 1 : -1;
            routingTable[i][j].totalCost = origMatrix[i][j];
        }
    }

    for (int i = 0; i < vertices; i++) { // These are the nested loops updating the adjacency matrix. This gives the timecomplexity of O(v)
        for (int j = 0; j < vertices; j++) {
            for (int k = 0; k < vertices; k++) {
                if (routingTable[j][k].totalCost > (routingTable[j][i].totalCost + routingTable[i][k].totalCost) &&
                    (routingTable[i][k].totalCost != inf && routingTable[j][i].totalCost != inf)) {
                    routingTable[j][k].totalCost = routingTable[j][i].totalCost + routingTable[i][k].totalCost;
                    routingTable[j][k].nextHop = (routingTable[j][k].totalCost == routingTable[j][i].totalCost + routingTable[i][k].totalCost) ? i + 1: routingTable[j][k].nextHop;
                }
            }
        }
    }
    cout << "The final matrix (R = Router)" << endl; // Printing the final matrix after it is done updating.
    cout << "|      |";
    for (int i = 0; i < vertices; i++) {
        cout << " |  R" << i + 1 << " |";
    }
    cout << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "|  R" << i + 1 << "  | ";
        for (int j = 0; j < vertices; j++) {
            if (routingTable[i][j].totalCost == inf) {
                cout << "| inf | ";
            } else if (routingTable[i][j].totalCost >= 10) {
                cout << "|  " << routingTable[i][j].totalCost << " | ";
            } else
                cout << "|  " << routingTable[i][j].totalCost << "  | ";
        }
        cout << endl;
    }
    cout << endl;
    printRoutingTable(routingTable, origMatrix);
}

// Here the routing table is printed for each vertex. We can therefore see destination, next hop and total cost to get to final destination.
void printRoutingTable(RoutingTableEntry routingTable[][vertices], int origMatrix[][vertices]) {
    for (int i = 0; i < vertices; i++) {
        cout << "Router " << i + 1 << " Routing Table:" << endl;
        cout << "Destination\tNext Hop\tTotal Cost" << endl;
        for (int j = 0; j < vertices; j++) { // print the table for each table.
            if (routingTable[i][j].totalCost == inf) {
                cout << routingTable[i][j].destination << "\t\t"
                     << ((routingTable[i][j].nextHop == -1) ? "N/A" : to_string(routingTable[i][j].nextHop)) << "\t\t"
                     << "inf" << endl;
            } else if (routingTable[i][j].totalCost == origMatrix[i][j] && routingTable[i][j].totalCost != 0) {
                cout << routingTable[i][j].destination << "\t\t" << j + 1 << "\t\t" << routingTable[i][j].totalCost
                     << endl;
            } else {
                cout << routingTable[i][j].destination << "\t\t"
                     << ((routingTable[i][j].nextHop == -1) ? "N/A" : to_string(routingTable[i][j].nextHop)) << "\t\t"
                     << routingTable[i][j].totalCost << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    RoutingTableEntry routingTable[vertices][vertices]; // defining the struct for creation of routing table.

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            routingTable[i][j].destination = j + 1;
            routingTable[i][j].nextHop = (i != j) ? i + 1 : -1;
            routingTable[i][j].totalCost = (i != j) ? inf : 0;
        }
    }
    int adjMatrix[vertices][vertices];

    cout << "Enter the adjacency matrix ('inf' for infinity):\n"; // Taking the user input, doing it as a nested loop, but this could be done simply by counting vertex x vertex.
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            string input;
            cin >> input;
            if (j == i && input != "0") {
                cout << "Input << " << input << ": The diagonal of the matrix needs to contain only the value 0" << endl; // Error handling for correct input. The diagonal has to be 0
                j--;
            } else if (isalpha(input[0])) {
                bool isInf = true;
                for (int c = 0; c < input.length(); c++) {
                    if (input[c] != "inf"[c]) {
                        isInf = false;
                        break;
                    }
                }
                if (isInf) {
                    adjMatrix[i][j] = inf;
                } else {
                    cout << input << " is not a valid element, please enter element again" << endl;
                    j--;
                }
            } else {
                adjMatrix[i][j] = atoi(input.c_str());
            }
        }
    }
    cout << endl;

    // Printing the initial matrix inputted by user based on how big matrix
    cout << "Your input (R = router)" << endl;
    cout << "|      |";
    for (int i = 0; i < vertices; i++) {
        cout << " |  R" << i + 1 << " |";
    }
    cout << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "|  R" << i + 1 << "  | ";
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i][j] == inf) {
                cout << "| inf | ";
            } else if (adjMatrix[i][j] >= 10) {
                cout << "|  " << adjMatrix[i][j] << " | ";
            } else
                cout << "|  " << adjMatrix[i][j] << "  | ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            routingTable[i][j].totalCost = adjMatrix[i][j];
        }
    }

    // starting the algorithm
    floydWarshall(routingTable, adjMatrix);

    return 0;
}
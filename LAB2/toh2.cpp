#include <iostream>

using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    cout << "Steps to solve Tower of Hanoi with " << n << " disks:\n";
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

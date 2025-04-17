#include<bits/stdc++.h>
using namespace std;

void r_1(int n){

	if(n==0) return;

	cout<<"B -> "<<n<<endl;	//Going deeper
	r_1(n-1);
	cout<<"A -> "<<n<<endl;	//returning (here every step is related with- corresponding(going deeper) step)
}


void r_2(int n, vector<int> v) {
    if (n == 0) return; // Base case

    // Modify vector while going deeper
    v.push_back(n);
    cout << "B: { ";
    for (int num : v) cout << num << " ";
    cout << "}" << endl;

    r_2(n - 1, v); // Recursive call

    // Modify vector while returning
    cout << "A: { ";
    for (int num : v) cout << num << " ";
    cout << "}" << endl;
    v.pop_back();

}



void r_3(int n, vector<int>& v) {
    if (n == 0) return; // Base case

    v.push_back(n);  // Modify vector while going deeper
    r_3(n - 1, v); // Recursive call

    v[5] *= 2;  // Modify v[5] while returning
}


int r_4(int n) {
    if (n == 0) return 0;  // Base case

    cout << "Going deeper -> " << n << endl;
    int result = n + r_4(n - 1); // Return value from deeper step
    cout << "Returning -> " << result << endl;

    return result; // Return accumulated sum
}

int r_5(int n) {
    if (n == 0) return 0;  // Base case
    return n + r_5(n - 1); // Directly returning recursive call
}


int main(){

	// r_1(5);
	// vector<int> v;
    // r_2(3, v);

    // r_3(9, v); // Start recursion

    // Print final vector
    // cout << "Final modified vector: ";
    // for (int num : v) cout << num << " ";
    // cout << endl;

    // r_4(5);
    cout<<r_5(5);

}
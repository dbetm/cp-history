#include <bits/stdc++.h>
// https://maps20.kattis.com/problems/maps20.litespace
// Tag(s): Implementation, automatas, strings
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
int pointer = 0;
stack<int> pila;
string s;

void process();
int binToDecimal(string bin);
void leerEntero();

int main() {
    fastIO
    cin >> s;
    process();
	return 0;
}

void process() {
    int n = s.size();
    while(pointer < n) {
        // watch(pointer)
        // watch(s[pointer])
        if(s[pointer] == 'S') {
            if(pointer + 1 < n && s[pointer + 1] == 'S') {
                pointer++;
                leerEntero();
            }
            else if(pointer + 2 < n && s[pointer + 2] == 'S') {
                if(pila.empty()) cout << "Invalid copy operation" << endl;
                else {
                    pila.push(pila.top());
                }
                pointer += 3;
            }
            else if(pointer + 2 < n && s[pointer + 2] == 'T') {
                if(pila.empty() || pila.size() < 2)
                    cout << "Invalid swap operation" << endl;
                else {
                    int aux = pila.top();
                    pila.pop();
                    int aux2 = pila.top();
                    pila.pop();
                    pila.push(aux);
                    pila.push(aux2);
                }
                pointer += 3;
            }
            else if(pointer + 2 < n && s[pointer + 2] == 'N') { // pop
                if(pila.empty()) cout << "Invalid remove operation" << endl;
                else {
                    pila.pop();
                }
                pointer += 3;
            }
        }
        else { // Tab
            if(pointer + 1 < n && s[pointer + 1] == 'N') {
                pointer += 4;
                if(pila.empty()) cout << "Invalid print operation" << endl;
                else {
                    cout << pila.top() << endl;
                    pila.pop();
                }
            }
            else if(pointer + 2 < n && s[pointer + 2] == 'T') {
                if(pila.empty() || pila.size() < 2)
                    cout << "Invalid division operation" << endl;
                else if(pila.top() == 0)
                    cout << "Division by zero" << endl;
                else {
                    int aux = pila.top();
                    pila.pop();
                    int aux2 = pila.top();
                    pila.pop();
                    pila.push(aux2 / aux);
                }
                pointer += 4;
            }
            else if(pointer + 3 < n && s[pointer + 3] == 'S') {
                if(pila.empty() || pila.size() < 2)
                    cout << "Invalid addition operation" << endl;
                else {
                    int aux = pila.top();
                    pila.pop();
                    int aux2 = pila.top();
                    pila.pop();
                    pila.push(aux2 + aux);
                }
                pointer += 4;
            }
            else if(pointer + 3 < n && s[pointer + 3] == 'T') {
                if(pila.empty() || pila.size() < 2)
                    cout << "Invalid subtraction operation" << endl;
                else {
                    int aux = pila.top();
                    pila.pop();
                    int aux2 = pila.top();
                    pila.pop();
                    pila.push(aux2-aux);
                }
                pointer += 4;
            }
            else {
                if(pila.empty() || pila.size() < 2)
                    cout << "Invalid multiplication operation" << endl;
                else {
                    int aux = pila.top();
                    pila.pop();
                    int aux2 = pila.top();
                    pila.pop();
                    pila.push(aux * aux2);
                }
                pointer += 4;
            }
        }
    }
}

int binToDecimal(string bin) {
    int ans = 0;
    int n = bin.size();
    for (int i = 0, j = n-1; i < n; i++, j--) {
        if(bin[i] == '1') {
            ans += pow(2, j);
        }
    }
    return ans;
}

void leerEntero() {
    pointer++;
    bool positivo = (s[pointer] == 'S') ? true : false;
    string bin = "";
    while(s[++pointer] != 'N') {
        if(s[pointer] == 'S') bin += "0";
        else bin += '1';
    }
    int entero = binToDecimal(bin);
    if(!positivo) entero *= -1;
    pila.push(entero);
    pointer++;
}

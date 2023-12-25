#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    string name;
    Node* par;
    int g;
    int h;

    Node(string name, Node* par = nullptr, int g = 0, int h = 0) : name(name), par(par), g(g), h(h) {}

    void display() {
        cout << name << " " << g << " " << h << endl;
    }

    bool operator<(const Node& other) const {
        return (g + h) > (other.g + other.h);
    }

    bool operator==(const Node& other) const {
        return name == other.name;
    }
};

bool equal(Node O, Node G) {
    if (O.name == G.name)
        return true;
    return false;
}

bool checkInPriority(Node tmp, priority_queue<Node> c) {
    while (!c.empty()) {
        if (c.top() == tmp)
            return true;
        c.pop();
    }
    return false;
}

void getPath(Node O) {
    cout << O.name << endl;
    if (O.par != nullptr)
        getPath(*O.par);
}

int main() {

unordered_map<string,vector<int>> data = {{"A",{'B',2,'C',1,'D',3}},
                                          {"B",{'E',5,'F',4}},
                                          {"C",{'G','E','F',3}},
                                          {"D",{'I',2,'J',4}},
                                          {"E",{3}},
                                          {"F",{'K',2,'L',1,'M',4}},
                                          {"G",{6}},
                                          {"H",{'N',2,'O',4}},
                                          {"I",{5}},
                                          {"J",{4}},
                                          {"K",{2}},
                                          {"L",{0}},
                                          {"M",{4}},
                                           ["N"]={0},
                                           ["O"]={4}};

Node S('A');
Node G('N');

priority_queue<Node> Open;
priority_queue<Node> Closed;

S.h = data[S.name].back();
Open.push(S);

while (true) {

if (Open.empty()) {
cout << "Search failed" << endl;
return 0; 
}
Node O = Open.top();
Open.pop();
Closed.push(O);
cout << "Visited: " << O.name << ", g: " << O.g<< ", h: "<< O.h<<endl;

if (equal(O,G)) {
cout<<"Search successful"<<endl; 
getPath(O); 
cout<<"Distance: "<<(O.g+O.h)<<endl; 
return 0; 
}
for(int i=0;i<data[O.name].size()-1;i+=2){
string name(1,char(data[O.name][i]));
int g=O.g+data[O.name][i+1];
int h=data[name].back();
Node tmp(name,&O,g,h);

bool ok1=checkInPriority(tmp,Open);
bool ok2=checkInPriority(tmp,Closed);

if(!ok1 && !ok2){
Open.push(tmp); 
}
}
}
return 0; 
}

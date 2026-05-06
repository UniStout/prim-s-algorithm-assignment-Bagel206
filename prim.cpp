#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#include <algorithm>
#include <sstream>
using namespace std;
bool headNode = false;

struct Node {
public:
	int value;
	Node(int x) {
		this->value = x;
	}
};
struct Edge {
public:
	Node* source;
	Node* destination;
	int weight;
	Edge(Node* s, Node* d, int w) {
		this->weight = w;
		this->source = s;
		this->destination = d;
	}
};
vector<Edge*> edgesVector;
vector<char> visited;
vector<Edge*> tree;
void addEdge(Node* s, Node* d, int w) {
	Edge* new1 = new Edge(s, d, w);
	edgesVector.push_back(new1);
	for (int p = 0; p < edgesVector.size(); p++) {
		//cout << edgesVector[p]->weight << " ";
	}
}

void createNode(char node1, char node2, int weight) {
	if (headNode == false) {
		Node* head = new Node(node1);
		headNode = true;
		Node* new2 = new Node(node2);
		addEdge(head, new2, weight);
	}
	else {
		Node* new1 = new Node(node1);
		Node* new2 = new Node(node2);
		addEdge(new1, new2, weight);
	}
}
void swap(Edge** min, Edge** i) {
	Edge* temp = *i;
	*i = *min;
	*min = temp;
}
void selectionSort(vector<Edge*>& arr) {

	for (int i = 0; i < arr.size(); i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j]->weight < arr[min]->weight) {
				min = j;
			}
			if (i != min) {
				swap(&arr[min], &arr[i]);
			}
		}

	}
	/*for (int j = 0; j < arr.size(); j++) {
		cout << arr[j]->weight << endl;;
	}*/

}
bool sourceused;
bool destused;
void createTree(vector<Edge*> arr) {
	for (int i = 0; i < arr.size(); i++) {
		//cout << "Test2" << endl;
		sourceused = false;
		destused = false;
		for (int j = 0; j < visited.size(); j++) {
			if (arr[i]->source->value == visited[j]) {
				sourceused = true;
				//cout << "SOURCETRUE" << endl;
			}
			if (arr[i]->destination->value == visited[j]) {
				destused = true;
				//cout << "DESTTRUE" << endl;
			}
		}
		if (sourceused == true && destused == true) {
			//cout << "DOES SKIPPING OVER USED NODES WORK" << endl;
		}
		else {
			tree.push_back(arr[i]);
			visited.push_back(arr[i]->source->value);
			visited.push_back(arr[i]->destination->value);
			//cout << "Test" << endl;
		}
	}
	for (int k = 0; k < tree.size(); k++) {
		cout << tree[k]->source->value << " " << tree[k]->destination->value << " " << tree[k]->weight << endl;
	}
}


int main() {
	int vertices = 0;
	int edges = 0;
	int node1;
	int node2;
	int weight;

	//Replace string ex with the file path to your text file
	//it will not work if the file has newlines make sure it has only spaces
	string ex = "c:\\users\\bastj8645\\downloads\\input.txt";
	std::ifstream fileInput(ex);
	string text = "";
	int count = 0;
	string temp = "";
	int tempint;
	int j = 0;
	int size = 0;
	vector<int> nums;
	string text2 = "";
	//cout << endl << "Numbers it has scanned from file and pushed into vector" << endl;
	stringstream ss;
	while (getline(fileInput, text, ' ')) {
		//cout << text;

		nums.push_back(stoi(text));

	}
	//cout << endl << "every number in the vector when I iterate through it" << endl;
	for (int k = 0; k < nums.size(); k++) {
		//cout << nums[k] << " ";
	}
	//cout << endl;
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			vertices = nums[i];
			//cout << "vertices updated" << endl;

		}
		else if (i == 1) {
			edges = nums[i];
			//cout << "edges updated" << endl;
		}
		else if (i > 1) {
			if (nums.size() < i + 2) {
				break;
			}
			else {
				createNode(nums[i], nums[i + 1], nums[i + 2]);
				//cout << "Used " << nums[i] << " " << nums[i + 1] << " " << nums[i + 2] << endl;

				i += 2;
			}
		}
	}
	//cout <<"vertices: "<< vertices << endl;
	//cout <<"edges: "<< edges << endl;
	selectionSort(edgesVector);
	cout << "Spanning Tree:" << endl;
	createTree(edgesVector);
	return 0;
}
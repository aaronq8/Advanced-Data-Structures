/* 
This Trie is used to store strings and was used to solve a codechef problem
https://www.codechef.com/JUNE18B/problems/SHKSTR
The Character # is used to check if end-of-string has been reached
*/

class Node {
public:
	lli R;
	Node* x[26];
	bool end;
	lli end_R;
	Node() {
		R = 0;
		for (int i = 0; i < 26; i++)x[i] = NULL;
		end = false;
		end_R = -1;
	}
};
class Trie {
public:
	Node * root;
	Trie() {
		root = new Node();
	}
	void insert(string element, lli query) {
		Node* cur_ptr = root;
		for (int q = 0; q < element.length(); q++) {
			int index = element[q] - 'a';
			if (cur_ptr->x[index] == NULL) {
				cur_ptr->x[index] = new Node();
			}
			cur_ptr = cur_ptr->x[index];
			if (cur_ptr->R == 0)cur_ptr->R = query;
		}
		cur_ptr->end = true;
		if (cur_ptr->end_R == -1)cur_ptr->end_R = query;
	}
	string search(string key, lli query) {
		Node* cur_ptr = root;
		string out; out.resize(10, '#'); int out_index = 0;
		string map = "abcdefghijklmnopqrstuvwxyz";
		bool cond1 = false, cond2 = false; int store_index;
		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - 'a';
			store_index = index;
			if (cur_ptr->x[index] == NULL) {
				//cant continue
				cond1 = true;
				store_index = index;
				break;
			}
			if (query < cur_ptr->x[index]->R) {
				//cant continue
				cond2 = true;
				store_index = index;
				break;
			}
			cur_ptr = cur_ptr->x[index];
			out[out_index++] = map[index];
		}
		if (cond1 == false && cond2 == false && cur_ptr->end == true && cur_ptr->end_R <= query) return out;
		while ((cur_ptr->end == true && cur_ptr->end_R >query) || (cur_ptr->end_R == -1)) {
			for (int i = 0; i < 26; i++) {
				if (cur_ptr->x[i] != NULL && cur_ptr->x[i]->R <= query) {
					cur_ptr = cur_ptr->x[i];
					out[out_index++] = map[i];
					break;
				}
			}
		}
		return out;
	}
};

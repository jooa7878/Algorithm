#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		string s = skill_trees[i];
		int idx = 0;
		int pos = 0;
		bool check;
		int flag = -1;
		while (idx < skill.length()) {
			
			check = true;
			for (int j = 0; j < s.length(); j++) {
				if (skill[idx] == s[j]) {
					if (flag == -1) {
						if (idx != pos) {
							check = false;
							break;
						}
						else {
							flag = j;
							pos++;
						}
							
					}
					else {
						if (j < flag || idx!= pos) {
							check = false;
							break;
						}
						else {
							flag = j;
							pos++;
						}
					}

				}
			}
			if (check == false) break;

			idx++;
		}
		if (check == true) { answer++; }

	}

	return answer;
}

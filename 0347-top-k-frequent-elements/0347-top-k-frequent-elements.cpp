class Solution {
public:
void merge(vector<pair<int, int>>& input, int a, int m, int z) {
    vector<pair<int, int>> result;
    vector<pair<int, int>> left(input.begin() + a, input.begin() + m + 1);
    vector<pair<int, int>> right(input.begin() + m + 1, input.begin() + z + 1);
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].second <= right[j].second) {
            result.push_back(left[i]);
            i++;
        }
        else {
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    for (int k = a; k <= z; k++) {
        input[k] = result[k - a];
    }
}

void mergeSort(vector<pair<int, int>>& inp, int a, int z) {
    if (z > a) {
        int m = a + (z - a) / 2;
        mergeSort(inp, a, m);
        mergeSort(inp, m + 1, z);
        merge(inp, a, m, z);
    }
}

vector<int> topKFrequent(vector<int> nums, int k) {
	vector<pair<int, int>> temp;
	vector<int>result;
	map <int, int> input;
	for (int x : nums) {
		input[x]++;
	}
	for (pair<int, int> x : input) {
		pair<int, int> t;
		t.first = x.first;
		t.second = x.second;
		temp.push_back(t);
	}

	mergeSort(temp, 0, temp.size()-1);

	while (k--) {
		result.push_back(temp.back().first);
		temp.pop_back();
	}

	return result;

}

};
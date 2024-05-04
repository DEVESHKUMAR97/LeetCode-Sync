class Solution {
public:
	// O(n * log(n)) Time | O(log(n)) based upon sorting algorithm
int numRescueBoats(vector<int>& people, int limit) {
	// sorted the peoples based on the weights in non-decreasing order
	sort(people.begin(), people.end());
	int n = people.size();
	int i = 0, j = n - 1;
	int boatsCount = 0;
	while(i <= j) {
		int sum = people[i] + people[j];
		if(sum <= limit) {
			// ith and jth people sit together
			boatsCount++;
			i++; j--;
		} else {
			// only jth people can sit
			boatsCount++;
			j--;
		}
	}
	return boatsCount;
}
};










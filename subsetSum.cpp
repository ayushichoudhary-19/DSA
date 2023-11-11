void solution(int sum, int index, vector<int> &ans, vector<int> &num){
	if(index==num.size()){
		ans.push_back(sum);
		return;
	}
	//exclude - means proceed without adding to the sum
	solution(sum, index+1, ans, num);

	//include - means add num[index] to the sum
	sum+=num[index];
	solution(sum,index+1,ans,num);
	sum-=num[index];
}
vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	int sum=0;
	solution(0,0,ans,num);
	sort(ans.begin(),ans.end());
	return ans;
}

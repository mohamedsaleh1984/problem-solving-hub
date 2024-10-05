#include<bits/stdc++.h>

/*
meta

https://www.metacareers.com/profile/coding_practice_question/?problem_id=2869293499822992&psid=275492097255885&practice_plan=0&p=GENERAL_SWE&b=0011122
 */

using namespace std; 

// Add any helper functions you may need here
int searchRevIndex(vector<int>& arr);
int binarySearch(vector<int>& vec, int target);
int binarySearchHelper(vector<int>& vec, int target, int l,int r);


bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
    int revIndexInB = searchRevIndex(array_b);
    if(revIndexInB  == -1){
      return false;    
    }
    
    int startIndex = binarySearch(array_a, array_b[revIndexInB]);
  
    if(startIndex == -1){
      return false;
    }
  
    int subArrayLen = array_b.size() - revIndexInB;
  
    for(int bIndex = revIndexInB, aIndex = startIndex;
        bIndex <= subArrayLen
        ;bIndex++, --aIndex)
    {
      if(array_a[aIndex] != array_b[bIndex]){
        return false;
      }
    }
    return true;
}

int searchRevIndex(vector<int>& arr){
   int index  = -1;
   for(int i = 0 , j = 1 ; j < arr.size() ; ++i,++j){
     if(arr[j] < arr[i]){
       return i;
     }
   } 
   return index;
}

int binarySearch(vector<int>& vec, int target){
  int index = -1;   
  index = binarySearchHelper(vec,target,0,vec.size()-1);
  return index;
}

int binarySearchHelper(vector<int>& vec, int target, int l,int r){
  if(l > r)
     return -1;
  
  if(l == r && r >=vec.size())
    return -1;
  
  int midIndex = (l+ r)/2;
  
  //check the middle of the array
  if(target == vec[midIndex] )
    return midIndex;
  //right side of the array
  else if(target > vec[midIndex]){
    return binarySearchHelper(vec,target,midIndex + 1, r);
  }else
   //left side of the array
  {
    return binarySearchHelper(vec,target,l, midIndex - 1);
  }
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main(){
  vector <int> array_a_1{1, 2, 3, 4};
  vector <int> array_b_1{1, 4, 3, 2};
  bool expected_1 = true;
  bool output_1 = areTheyEqual(array_a_1, array_b_1); 
  check(expected_1, output_1); 

  vector <int> array_a_2{1, 2, 3, 4};
  vector <int> array_b_2{1, 4, 3, 3};
  bool expected_2 = false;
  bool output_2 = areTheyEqual(array_a_2, array_b_2); 
  check(expected_2, output_2);

  // Add your own test cases here
  
  return 0; 
}
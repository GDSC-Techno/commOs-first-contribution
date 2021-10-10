#include<bits/stdc++.h>
using namespace std;

int instructions = 0;
int divide=0,conquer=0,combine=0,counti=0;

void merging(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;
  counti+=2;
  int LeftArray[n1], RightArray[n2];

  //combine= combine + n1 + n2 + 2;
  for (int i = 0; i < n1; i++)
    LeftArray[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    RightArray[j] = arr[q + 1 + j];


  int i, j, k;
  i = 0;
  j = 0;
  k = p;
 counti+=3;
  while (i < n1 && j < n2) {
  counti++;//while condition true;

    if (LeftArray[i] >= RightArray[j]) {
    counti++;//if condition
    arr[k++] = LeftArray[i++];
    counti++;
    } else {
       counti++; //if condition false
      arr[k++] = RightArray[j++];
      counti++;//instruction
    }
  }
  counti++;//false in while loop

  while (i < n1) {
        counti+=2;
    arr[k++] = LeftArray[i++];
  }
counti++;
  while (j < n2) {
        counti+=2;
    arr[k++] = RightArray[j++];
  }
  counti++;
}

void mergeSort(int arr[], int l, int r) {
    conquer++;
    counti++;
  if (l < r) {

    int m = l + (r - l) / 2;
    divide++;
    counti++;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merging(arr, l, m, r);
    combine++;
    counti++;
  }

}
vector<int> get_change(int money,int numberOfCoins, int coins[]){
    vector<int> solSet;
    int sum = 0;
    int i = 0;
    int count = 0;
    instructions+=3;
    while(sum!=money&&i<numberOfCoins){
            instructions++;//condition true
        if(coins[i]<=money-sum){
              instructions++;//if condition true
              sum = sum + coins[i];
              count++;
              solSet.push_back(coins[i]);
              instructions+=3;
        }else{
            instructions++;//if condition false
            i++;
            instructions++;
        }
    }
    instructions++;//while condition false
    instructions++;//if condition
    if(sum!=money){
        cout<<"Not possible to give a change of given amount\n";
        exit(0);
    }
    cout<<"Coins req are "<<count<<"\n";
    instructions++;//return statement
    return solSet;
}

int main() {
  int money,numberOfCoins;
  cout<<"Enter amount to be exchanged ";
  cin >> money;
  cout<<"Enter number of denomination available ";
  cin>>numberOfCoins;
  cout<<"Enter denomination of coins ";
  int coins[numberOfCoins];
  for(int i =0;i<numberOfCoins;i++){
    cin>>coins[i];
  }

  mergeSort(coins, 0, numberOfCoins - 1);

  vector<int> solSet;
  solSet = get_change(money,numberOfCoins,coins);
  instructions++;
  cout<<"Coins used are : ";
  for(int i=0;i<solSet.size();i++){
    cout<<solSet[i]<<",";
  }
  cout<<"\nThe total number of instruction executed are : "<<instructions+divide+conquer+combine+counti;
}


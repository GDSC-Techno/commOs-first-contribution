#include <bits/stdc++.h>
using namespace std;
int instructions = 0;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  instructions+=2;
  vector<double> vperw(n);

instructions++;
  for (int i = 0; i < n; i++) {
        instructions++;
    vperw[i] = (double)values[i]/weights[i];
    //cout<<vperw[i]<<" ";
    instructions++;
  }instructions++;


    int x,key1,key2,y;
    double key;
    for (x = 1; x < n; x++)
    {
        key = vperw[x];
        key1 = weights[x];
        key2 = values[x];
        y = x - 1;
        instructions+=4;

        while (y >= 0 && vperw[y] < key)
        {
            instructions++;
            vperw[y + 1] = vperw[y];
            weights[y + 1] = weights[y];
            values[y + 1] = values[y];
            y = y - 1;
            instructions+=4;
        }
        instructions++;
        vperw[y + 1] = key;
        weights[y + 1] = key1;
        values[y + 1] = key2;
        instructions+=3;
    }

  instructions++;//condition false
  int j =0;
  instructions++;
  while(capacity>0 && j<n){
        instructions++;//condition false
        instructions++;//if condition check
        if(weights[j]<=capacity){
            capacity=capacity - weights[j];
            value = value +(double)values[j];
            instructions+=2;
                //cout<<value<<" ";
        }else{
            value = value + ((double)capacity*vperw[j]);
            capacity = 0;
            instructions+=2;
                //cout<<value<<" ";
        }
        j++;
        instructions++;
    }

  instructions++;//for loop condition false

  instructions++;
  return value;
}

int main() {
  int n;
  int capacity;
  cout<<"Enter no. of items and capacity of knapsack\n";
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  cout<<"Enter value and weight of each item\n";
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  instructions++;//function call

  cout <<"\nMaximum value of loot is : "<<optimal_value;
  cout<<"\nTotal number of instructions are : "<<instructions;
  return 0;
}

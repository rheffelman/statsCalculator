#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(vector<int> nums);
int numberGreaterThanAverage(vector<int> nums);
int greatestCommonDivisor(vector<int> nums);
bool isSorted(vector<int> nums);

int main()
{
    //get the numbers from the user
    vector<int> numbers = getNumbers();

    //process the numbers and print results
    cout<<"Most frequent number: "<<findMostFrequentNumber(numbers)<<endl;
    
    cout<<"There are "<<numberGreaterThanAverage(numbers)<<" numbers greater than the average."<<endl;
    
    cout<<"The greatest common divisor is: "<<greatestCommonDivisor(numbers)<<endl;
    
    if(isSorted(numbers))
    {
        cout<<"The numbers are sorted."<<endl;
    }
    else
    {
        cout<<"The numbers are not sorted."<<endl;
    }

    return 0;
}
//--
vector<int> getNumbers()
{
    vector<int> nums;
    int num;
    cout << "Enter numbers (0 to stop): ";
    while (cin >> num && num != 0)
    {
        nums.push_back(num);
    }
    return nums;

}
//--
int findMostFrequentNumber(vector<int> nums)
{
    // TODO: Student 1
    return -1;
}
//--
int numberGreaterThanAverage(vector<int> nums)
{
    // TODO: Student 2
    return 0;
}
//--
int greatestCommonDivisor(vector<int> nums)
{
    //This if statement asks if the vector is empty, then quit the program.
    if (nums.empty()) return 0;

    //greatCD is a placeholder name for this int value
    int greatCD = nums[0];

    //This loop iterates through all the numbers in the vector 
    for (int i = 1; i < nums.size(); i++) {
        //This while loop continues until nums[i] is equal to 0
        while(nums[i] !=0) {
            int temp = nums[i];
            nums[i] = greatCD % nums[i];
            greatCD = temp;
        }
    }
    return greatCD;
}
//--
bool isSorted(vector<int> nums)
{
    //Create enum to keep track of direction
    enum Direction {UNDEFINED, ASCENDING, DESCENDING};
    Direction dir = UNDEFINED;
    
    //Check if the size of nums less than or equal to 1
    if (nums.size() <= 1)
    {
        return true;
    }
    //loop through nums, -1 because we check ahead with nums[i+1]
    for(int i = 0; i < nums.size() - 1; i++)
    {
        //Check if dir is defined and if the elements are equal
        if(dir == UNDEFINED && nums[i] != nums[i + 1])
        {
            //assign dir value
            if (nums[i] > nums[i+1])
            {
                dir = DESCENDING;
            }
            else
            {
                dir = ASCENDING;
            }
        }
        else if (dir != UNDEFINED && nums[i] != nums[i+1])
        {
            //check if current i defies the current assined value on dir
            if(dir == DESCENDING && nums[i] < nums[i + 1])
            {
                return false;
            }
            else if (dir == ASCENDING && nums[i] > nums[i + 1])
            {
                return false;
            }
        }
    }

    return true;
}
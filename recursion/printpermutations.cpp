// 16.4 Enumerate permutations
#include <climits>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printArray(const vector<int> &numbers)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

// move the item at index from to index to
// and shift everything to the right
void moveFront(vector<int> &numbers, size_t from, size_t to)
{
    cout << "Moving item at " << from << " (" << numbers[from] << ")" 
    << " to " << to << " (" << numbers[to] << ")" << endl;

    printArray(numbers);

    int src = numbers[from];

    //for (size_t i = numbers.size() - 1; i > to; i--)
    for (size_t i = from; i > to; i--)
    {
        numbers[i] = numbers[i-1];
    }

    numbers[to] = src;

    printArray(numbers);
}

void printperms(vector<int> numbers, size_t depth)
{
    cout << __FUNCTION__ << " depth = " << depth << endl;
    printArray(numbers);
    cout << "Printed input array" << endl;

    if (depth != numbers.size() - 1)
    {
        printperms(numbers, depth + 1);
        for (size_t k = depth+1; k < numbers.size(); k++)
        {
            vector<int> numbers2 = numbers;
            moveFront(numbers2, k, depth);
            printperms(numbers2, depth + 1);
        }
    }
    else
    {
        cout << "perm: ";
        printArray(numbers);
    }

}

void PermutationsHelper(size_t i, vector<int> *A,
                        vector< vector<int> > *result)
{
    if (i == A->size())
    {
        result->push_back(*A);
    }

    for (size_t j = i; j < A->size(); j++)
    {
        swap((*A)[i], (*A)[j]);
        PermutationsHelper(i+1, A, result);
        swap((*A)[i], (*A)[j]);
    }
}

vector< vector<int> > Permutations(vector<int> A)
{
    vector< vector<int> > result;
    PermutationsHelper(0, &A, &result);
    return result;
}

void printResult(const vector< vector<int> > &result)
{
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    vector<int> numbers;

    for (int i = 1; i < argc; i++)
    {
        numbers.push_back(atoi(argv[i]));
    }

    printperms(numbers, 0);
    // This is the solution from the textbook which does not 
    // yield the permutations in dictionary order
    //vector< vector<int> > result = Permutations(numbers);
    //printResult(result);
    return 0;
}


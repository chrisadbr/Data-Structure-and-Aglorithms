#include <iostream>

using namespace std;
void displayMessage(int n)
{
    if (n > 0)
    {
        cout << "Hello testing recursion: " << n << endl;
        displayMessage(n - 1);
    }
}
int frequencyCounter(char ch, string phrase, int times)
{
    if (phrase.length() == times)
        return 0;
    if (phrase[times] == ch){
        return 1 + frequencyCounter(ch, phrase, times + 1);
    }else
        return frequencyCounter(ch, phrase, times + 1);
}
int calculateGcd(int a, int b){
    if (a % b == 0)
        return b;
    else
        return calculateGcd(b, a % b);
}
int calcFib(int a, int b, int n){
    if (n == 1){
        return a;
    }else if (n == 2){
        return b;
    }else
        return calcFib(a, b, n - 1) + calcFib(a, b, n - 2);
}
int main()
{
    string word = "tanzania";
    char ch = 'a';
    displayMessage(5);
    cout << "Character " << ch << " appears "
         << frequencyCounter(ch, word, 0) << " times";
    cout << endl;
    cout << "GCD: " << calculateGcd(28, 49);
    cout << "\nFibonnacci: " << calcFib(1, 2, 7);
    return 0;
}

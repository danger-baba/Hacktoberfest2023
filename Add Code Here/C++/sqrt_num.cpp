
// to find the square root of any number;

#include<bits/stdc++.h>
using namespace std;

long long int sqrtInterger(int n) // yaha long long is liyai use kr rahai kyo ki integer overflow nahh ho jayai
{
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;   // ye mid ka formula hai isai hamko mid mil jayaiga
     long long int ans = -1;   // answer -1 se start hoga

    while (s <= e)   // jab start end se chota hoga 
    {
        long long int square = mid * mid;  // square root find krne k liyai iska jaruat hota hai

        if ( square == n)  // jab mid hi square root ho number ka tab mid return kr do
        {
          return mid;
        }

        if ( square < n) // jab square chota ho tab left side mai jayingai or start ko mid + 1 tak check karengai
        {
            ans = mid;
            s = mid + 1;
        }

        else {
            e = mid - 1; // nhi to agai mid se agai or end se piche takk
        }
        mid = s + (e-s)/2;  // fir mid ko update kr dengai 
    }

    return ans;  // answer ko return 
}

// aab yaha se decimal k agai ka v value mil jayaiga is chej se
double morePercision(int n, int precision, int tempsol)  // ekk double name ka fuction banaa liyai
{
    double factor = 1;
    double ans = tempsol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor/10;  // ismai ham jese 10/100 se divide karengai to 0.1 fir 0.01 fir 0.001 ese badhtai rahaiga
        
         for (double j = ans; j*j<n; j = j+factor)   // ismai j ka value store karwa lengai
         {
            ans =j;
         }
    }
    return ans;  // answer ko return kar dengai
}

int main()
{
    int n;
    cout << " Enter the number" << endl;
    cin >> n;

    int tempsol = sqrtInterger(n);
    cout << "Answer is " << morePercision(n, 3, tempsol) << endl; // n = number ; 3 = decimal k bdd kaha takk ka value chahiyai, or function ka naam
    return 0;
}
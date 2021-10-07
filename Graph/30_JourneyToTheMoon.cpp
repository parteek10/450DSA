//Problem Link : https://www.hackerrank.com/challenges/journey-to-the-moon/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
 
 int dfs(unordered_map<int ,vector<int> > &mp , unordered_map<int , bool > &visited , int i )  {
     int count = 0 ; 
     visited[i] = true ; 
     for(auto ele : mp[i])  {
         if(visited[ele] == false )  {
             count += dfs(mp , visited , ele) ;
         }
     }
     return count+1 ; 
 }

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int i , j , k = 0 , p = astronaut.size() ; 
    unordered_map<int , vector<int> > mp ;
    
    for(i = 0 ; i < p ; i++ )  {
        mp[astronaut[i][0]].push_back(astronaut[i][1]) ; 
        mp[astronaut[i][1]].push_back(astronaut[i][0]) ; 
    }
    
    int count = 0 , tcount = 0 ;
    unordered_map<int , bool> visited ; 
    vector<int> country_astr ;
    
    for(auto ele : mp) {
        if(visited[ele.first] == false )  {
            count = dfs(mp , visited , ele.first) ; 
            country_astr.push_back(count) ;
            tcount += count; 
        }
    }
    
    while(tcount < n) {
        country_astr.push_back(1) ; 
        tcount++ ; 
    }
    
    
    k = country_astr.size() ; 
    for(i = k-2 ; i>=0 ; i-- )  
       country_astr[i] += country_astr[i+1] ; 
       
    long long ans = 0 ; 
    for(i = 1 ; i<k ;i++ ) 
       ans += (country_astr[i-1]-country_astr[i])*country_astr[i] ; 
    
    return ans ; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

#include <bits/stdc++.h> 
using namespace std; 

struct meeting { 
    int start; 
    int end; 
    int pos; 
}; 

//this function is used to sort the meeting schedules acc to their finsih time 
bool comparator(struct meeting m1, meeting m2) 
{ 
    return (m1.end < m2.end); 
} 

void maxMeeting(vector<int> start_time, vector<int> finish_time, int n) 
{ 
    struct meeting meet[n]; 
    for (int i = 0; i < n; i++) 
    {  
    	meet[i].pos = i + 1; 
        meet[i].start = start_time[i]; 	 
        meet[i].end = finish_time[i]; 
    } 

    sort(meet, meet + n, comparator); 

    vector<int> possible_meeting; 	//this vector will store the position number of the possible meeting

    possible_meeting.push_back(meet[0].pos); 

    int time_limit = meet[0].end; 

    for (int i = 1; i < n; i++) { 
        if (meet[i].start >= time_limit) 	// this meeting is possible
        { 
            possible_meeting.push_back(meet[i].pos); 
            time_limit = meet[i].end; 
        } 
    } 
 
 	cout<<"Max meeting: "<<possible_meeting.size()<<"\n";
    for (int i = 0; i < possible_meeting.size(); i++) { 
        cout << possible_meeting[i] << "\n"; 
    } 
} 

int main() 
{ 
    vector<int> start_time = { 1, 4 ,5 ,6, 9, 12 }; 
    vector<int> finish_time = { 2, 7, 8, 12, 14, 18 }; 
    
    int n_meeting = start_time.size(); 

    maxMeeting(start_time, finish_time, n_meeting); 

    return 0; 
} 

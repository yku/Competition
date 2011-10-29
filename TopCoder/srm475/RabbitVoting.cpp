#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class RabbitVoting {
public:
    string getWinner(vector<string> names, vector<string> votes) {
        int elems = names.size();
        int vote;
        int max_vote = -1;
        map<string, int> pairs;
        vector<string> winner;
        for(int i = 0; i < elems; i++){
            pairs.insert(map<string, int>::value_type(names[i], 0));
        }
        for(int i = 0; i < elems; i++){
            if (  names[i].compare( votes[i] ) == 0 ) { 
                continue;
            } else {
                cout << votes[i] << endl;
                pairs[votes[i]]++;
                cout << "Name:" << votes[i] << "Vote:" << pairs[votes[i]] << endl;
                if (max_vote < pairs[votes[i]])
                    max_vote = pairs[votes[i]];
            }
        }
        map<string, int>::iterator it = pairs.begin();
        while(it != pairs.end()){
            cout << max_vote << endl;
            if ((*it).second == max_vote){
                cout << (*it).first;
                winner.push_back((*it).first);
            }
            it++;
        }
        if (winner.size() == 1)
            return winner[0];
        else
            return "";
    }
    
};

int main(){
    vector<string> names;
    vector<string> votes;
    RabbitVoting *rv = new RabbitVoting();

    names.push_back("Alice");
    names.push_back("Bill");
    names.push_back("Carol");
    names.push_back("Dick");

    votes.push_back("Bill");
    votes.push_back("Dick");
    votes.push_back("Alice");
    votes.push_back("Alice");

    cout << rv->getWinner(names, votes);
}

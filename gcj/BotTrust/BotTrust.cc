#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class BotTrust {
public:
int getMinSequenceTime(vector<char> colors, vector<int> seq) {
    int time;
    vector<int> o_seq, b_seq;
    int o_idx, b_idx, c_idx;
    int o_pos, b_pos;

    for(int i = 0; i < colors.size(); i++) {
        if(colors[i] == 'O') o_seq.push_back(seq[i]);
        else                 b_seq.push_back(seq[i]);
    }

    time = o_pos = b_pos = 1;
    o_idx = b_idx = c_idx = 0;
    while(1) {
        bool color_flag = false;
        if(o_idx < o_seq.size()){
        if(o_pos < o_seq[o_idx]) {
            o_pos++;
        }else if(o_pos == o_seq[o_idx]) {
            if(colors[c_idx] == 'O') {
                o_idx++;
                color_flag = true;
            }
        }else{
            o_pos--;
        }
        }
        
        if(b_idx < b_seq.size()){
        if(b_pos < b_seq[b_idx]) {
            b_pos++;
        }else if(b_pos == b_seq[b_idx]){
            if(colors[c_idx] == 'B') {
                b_idx++;
                color_flag = true;
            }
        }else{
            b_pos--;
        }
        }
        if(color_flag) c_idx++;
        if(c_idx >= colors.size()) break;
        time++;
    }
    
    return time;
}
};

int main()
{
    BotTrust bot;
    ifstream fin("A-large.in");
    string str;
    int cases;

    fin >> str;
    cases = strtol(str.c_str(), NULL, 0); 
    for(int i = 0; i < cases; i++) {
        int values;
        int ret;
        vector<char> colors;
        vector<int> sequence;
        fin >> str;
        
        values = strtol(str.c_str(), NULL, 0);
        for(int j = 0; j < values; j++) {
            fin >> str;
            colors.push_back(str[0]);
            
            fin >> str;
            sequence.push_back(strtol(str.c_str(), NULL, 0));
        }
        ret = bot.getMinSequenceTime(colors, sequence);
        cout << "Case #" << i+1 << ": " << ret << endl;
    }
}

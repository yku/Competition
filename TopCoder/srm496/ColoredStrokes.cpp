#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ColoredStrokes {
public:
int getLeast(vector <string> picture) {
    int blue = 0;
    int red = 0;
    int i, j;
    
    int h = picture.size();
    int w = picture[0].length();

    for(j = 0; j < w; j++) {
        char prev = picture[0][j];
        if(prev == 'B' || prev == 'G') blue++;
        for(i = 0; i < h; i++) {
            char c = picture[i][j];
            if(c == 'B' || c == 'G') {
                if(prev == 'R' || prev == '.') blue++;
            }
            prev = c;
        }
    }

    for(i = 0; i < h; i++) {
        char prev = picture[i][0];
        if(prev == 'R' || prev == 'G') red++;
        for(j = 0; j < w; j++) {
            char c = picture[i][j];
            if(c == 'R' || c == 'G') {
               if(prev == 'B' || prev == '.') red++;
            }
            prev = c;
        }
    }
    return blue + red;
}
};

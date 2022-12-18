#include "../aoc2022.h"
#include <ncurses.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define width 10
#define height 10

void prt_sc(string val) {
    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {
            cout << val;
        }
        cout << endl;
    }
}

void clear_terminal(int numRows, double delay) {
    for (int i=0; i<numRows; i++) {
        printf("\033[A\33[2K\r");
    }
    usleep(delay*1000000); // Seconds to microseconds
}

int main() {
//    vector<string> s{". ",", ","; ","[ ","] ","- "};
////    for (int j=0; j<s.size(); j++) {
//        prt_sc(s[0]);
////        clear_terminal(10,0.5);
//        printf("\033[A\033[A\bA\033[B\033[B");
////    }

    initscr();
    printw("Hello World");
    refresh();
    endwin();
    return 0;
}
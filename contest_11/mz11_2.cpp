#include <iostream>
#include <string>
#include <stdio.h>

/*
 * S -> 1A0
 * A -> 1A0 | 0B1
 * B -> 0B1 | eps
 */


void print_char(char ch) {
    std::cout << ch;
}

void B(char &ch) {
    if (ch == '0') {
        print_char('1');
        ch = getchar();
        B(ch);

        if (ch == '1') {
            ch = getchar();
        } else {
            throw ch;
        }
        print_char('0');
    }
}


void A(char &ch) {
    if (ch == '1') {
        ch = getchar();
        A(ch);
        
        if (ch == '0') {
            ch = getchar();
        } else {
            throw ch;
        }

        print_char('0');
    } else if (ch == '0'){
        print_char('1');
        ch = getchar();
        B(ch);
        
        if (ch == '1') {
            ch = getchar();
        } else {
            throw ch;
        }

        print_char('0');
    } else {
        throw ch;
    }
}

void S(char &ch) {
    if (ch == '1') {
        ch = getchar();
        A(ch);
    } else {
        throw ch;   
    }

    if (ch == '0') {
        ch = getchar();
        print_char('0');
    } else {
        throw ch;
    }
}

int main() {
    char ch;

    while ((ch = getchar()) != EOF) {
        while (isspace(ch)) {
            ch = getchar();
        }
        try {
            S(ch);
            std::cout << std::endl;
        } catch (char ch) {
            std::cout << "WRONG INPUT" << std::endl;
        }
    }
}

#include <iostream>

using namespace std;

char board[3][3];
char current_player;


void initialize_board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '1' + (i * 3 + j);
        }
    }
}

void display_board() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n";
}


bool check_win() {

    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool check_draw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switch_player() {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

bool make_move(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_player;
        return true;
    } else {
        return false;
    }
}

void play_game() {
    int position;
    bool game_over = false;

    while (!game_over) {
        display_board();
        cout << "Player " << current_player << "'s turn. Enter position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9 || !make_move(position)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (check_win()) {
            display_board();
            cout << "Player " << current_player << " wins!" << endl;
            game_over = true;
        } else if (check_draw()) {
            display_board();
            cout << "It's a draw!" << endl;
            game_over = true;
        } else {
            switch_player();
        }
    }
}

bool play_again() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return choice == 'y' || choice == 'Y';
}

int main() {
    do {
        initialize_board();
        current_player = 'X';
        play_game();
    } while (play_again());

    return 0;
}

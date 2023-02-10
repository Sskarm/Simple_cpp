#include <iostream>
#include <vector>
#include <unistd.h>

const int WIDTH = 80;
const int HEIGHT = 40;

std::vector<std::vector<bool>> board(HEIGHT, std::vector<bool>(WIDTH, false));

int count_neighbors(int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      int r = (y + i + HEIGHT) % HEIGHT;
      int c = (x + j + WIDTH) % WIDTH;
      count += board[r][c];
    }
  }
  count -= board[y][x];
  return count;
}

int main() {
  board[HEIGHT / 2][WIDTH / 2] = true;

  while (true) {
    std::vector<std::vector<bool>> new_board = board;
    for (int y = 0; y < HEIGHT; ++y) {
      for (int x = 0; x < WIDTH; ++x) {
        int count = count_neighbors(x, y);
        if (board[y][x] && (count < 2 || count > 3)) {
          new_board[y][x] = false;
        } else if (!board[y][x] && count == 3) {
          new_board[y][x] = true;
        }
      }
    }
    board = new_board;

    for (int y = 0; y < HEIGHT; ++y) {
      for (int x = 0; x < WIDTH; ++x) {
        std::cout << (board[y][x] ? "*" : " ");
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;

    usleep(100000);
  }

  return 0;
}

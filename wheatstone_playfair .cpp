#include <iostream>
#include <string>

using namespace std;

int main() {
  // Get the plaintext message from the user.
  string plaintext;
  cout << "Enter the plaintext message: ";
  getline(cin, plaintext);

  // Get the key from the user.
  string key;
  cout << "Enter the key: ";
  getline(cin, key);

  // Create the Playfair square.
  char playfairSquare[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      playfairSquare[i][j] = ' ';
    }
  }

  // Add the letters of the key to the Playfair square.
  for (char c : key) {
    if (c != 'J') {
      playfairSquare[c - 'A'][0] = c;
    }
  }

  // Add the remaining letters of the alphabet to the Playfair square.
  for (char c = 'A'; c <= 'Z'; c++) {
    if (c != 'J' && playfairSquare[c - 'A'][0] == ' ') {
      playfairSquare[c - 'A'][0] = c;
    }
  }

  // Encrypt the plaintext message.
  string ciphertext;
  for (int i = 0; i < plaintext.length(); i += 2) {
    char firstLetter = plaintext[i];
    char secondLetter = plaintext[i + 1];

    // If the two letters are the same, add a "Z" to the end of the first letter.
    if (firstLetter == secondLetter) {
      ciphertext += firstLetter;
      ciphertext += 'Z';
    } else {
      // Find the row and column of the first letter.
      int firstRow = firstLetter - 'A' / 5;
      int firstColumn = firstLetter - 'A' % 5;

      // Find the row and column of the second letter.
      int secondRow = secondLetter - 'A' / 5;
      int secondColumn = secondLetter - 'A' % 5;

      // If the two letters are in the same row, move the first letter right one column.
      if (firstRow == secondRow) {
        secondColumn = (secondColumn + 1) % 5;
      }

      // If the two letters are in the same column, move the first letter down one row.
      if (firstColumn == secondColumn) {
        firstRow = (firstRow + 1) % 5;
      }

      // Get the encrypted letters.
      char encryptedFirstLetter = playfairSquare[firstRow][secondColumn];
      char encryptedSecondLetter = playfairSquare[secondRow][firstColumn];

      // Add the encrypted letters to the ciphertext.
      ciphertext += encryptedFirstLetter;
      ciphertext += encryptedSecondLetter;
    }
  }

  // Print the ciphertext message.
  cout << "The ciphertext message is: " << ciphertext << endl;

  return 0;
}

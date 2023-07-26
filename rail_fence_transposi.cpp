#include <iostream>
#include <string>

using namespace std;

int main() {
  // Get the plaintext message from the user.
  string plaintext;
  cout << "Enter the plaintext message: ";
  getline(cin, plaintext);

  // Get the number of rails from the user.
  int numRails;
  cout << "Enter the number of rails: ";
  cin >> numRails;

  // Encrypt the plaintext message.
  string ciphertext;
  for (int i = 0; i < plaintext.length(); i++) {
    // Check if the current character is on the current rail.
    bool onRail = (i % numRails == 0);

    // If the current character is on the current rail, add it to the ciphertext.
    if (onRail) {
      ciphertext += plaintext[i];
    }
  }

  // Print the ciphertext message.
  cout << "The ciphertext message is: " << ciphertext << endl;

  return 0;
}

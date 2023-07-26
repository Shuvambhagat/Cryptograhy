#include <iostream>
#include <string>

using namespace std;

int main() {
  // Get the plaintext message from the user.
  string plaintext;
  cout << "Enter the plaintext message: ";
  getline(cin, plaintext);

  // Get the shift value from the user.
  int shift;
  cout << "Enter the shift value: ";
  cin >> shift;

  // Encrypt the plaintext message.
  string ciphertext;
  for (char c : plaintext) {
    ciphertext += (char)((c - 'A' + shift) % 26 + 'A');
  }

  // Print the ciphertext message.
  cout << "The ciphertext message is: " << ciphertext << endl;

  return 0;
}

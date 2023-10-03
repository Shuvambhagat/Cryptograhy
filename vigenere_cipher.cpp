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

  // Encrypt the plaintext message.
  string ciphertext;
  for (int i = 0; i < plaintext.length(); i++) {
    ciphertext += (char)((plaintext[i] - 'A' + key[i % key.length()] - 'A' + 26) % 26 + 'A');
  }

  // Print the ciphertext message.
  cout << "The ciphertext message is: " << ciphertext << endl;

  return 0;
}
